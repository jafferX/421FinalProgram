#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

//God Bless this spaghetti mess

//=====================================================
// File scanner.cpp written by: Group Number: 3 
//=====================================================

//Enumerated token types
typedef enum tokentype {ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

vector <string> reservedWords;	//vector holds reserved words
vector <string> reservedTypes;	//hold reserved word types

bool dictionary(tokentype&, string);	//search dictionary for valid reserved words

// Period found, returns token
// ** Done by: Aaron & Erik
void period(tokentype& a)
{
	a = PERIOD;	//sets token
	return;
}

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
int scanner(tokentype& a, string& w)
{
	bool result = true;	//default, word is assumed valid
	int i = 0;
     	
	if(w == "eofm")
		return -1;	
	else if(w == ".")
	{
		period(a);
		return 1;
	} 
	else
	{
		a = ERROR;
		return 1;
	}
	result = stateZero(w, i);
	if(result == false)
	{
		a = ERROR;
	}
	else	//valid
	{
		a = WORD1;
		result = dictionary(a, w);
	}
}//the end

//
//Done by: Aaron & Erik
bool dictionary(tokentype &a, string w)
{
	for(int count = 0; count <= reservedWords.size(); count++)
	{
		if(reservedWords[count] == w)
		{
			if(reservedTypes[count] == "VERB")
				a = VERB;
			else if(reservedTypes[count] == "VERBNEG")
				a = VERBNEG;
			else if(reservedTypes[count] == "VERBPAST")
				a = VERBPAST;
			else if(reservedTypes[count] == "VERBPASTNEG")
				a = VERBPASTNEG;
			else if(reservedTypes[count] == "IS")
				a = IS;
			else if(reservedTypes[count] == "WAS")
				a = WAS;
			else if(reservedTypes[count] == "OBJECT")
				a = OBJECT;
			else if(reservedTypes[count] == "SUBJECT")
				a = SUBJECT;
			else if(reservedTypes[count] == "DESTINATION")
				a = DESTINATION;
			else if(reservedTypes[count] == "PRONOUN")
				a = PRONOUN;
			else if(reservedTypes[count] == "CONNECTOR")
				a = CONNECTOR;
			return true;
		}
		else
			return false;
	}
}

// The test driver to call the scanner repeatedly  
// ** Done by:  Aaron & Erik
int main()
{
	int eof = 1;
  	tokentype thetype;
  	string theword; 
	
	string inputfile;
	printf("Please enter the name of file to be scanned: ");
	getline(cin, inputfile);

	fstream toRead;
	toRead.open(inputfile.c_str());
	
	string reserved;
	fstream dictionary;
	dictionary.open("reservedwords.txt");
	
	while(dictionary)	//fill reserved word vector
	{
		string rWord; 
		string rType;
		dictionary >> rWord >> rType;
		
		reservedWords.push_back(rWord);
		reservedTypes.push_back(rType);
	}
		
	dictionary.close();

	while (toRead)
	{
		toRead >> theword;
	      	eof = scanner(thetype, theword);  // call the scanner

		if(eof == -1)
			break;

		if(thetype == ERROR)	
	       		cout << "Type is:" << "ERROR" << endl;
		else if(thetype == WORD1)
			cout << "Type is:" << "WORD1" << endl;
		else if(thetype == WORD2)
			cout << "Type is:" << "WORD2" << endl;
	       	else if(thetype == PERIOD)
			cout << "Type is:" << "PERIOD" << endl;
		cout << "Word is:" << theword << endl;   
    	}
	toRead.close();
}// end

bool mytoken(string s)	//edit this
{ 
  int state = 0;
  int charpos = 0;

  cout << "Trying the mytoken machine..." << endl;  
 
  while (s[charpos] != '\0') 
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;
 
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}
