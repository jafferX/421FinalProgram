#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

vector <string> reservedWords;	//vector holds reserved words
vector <string> reservedTypes;	//hold reserved word types

//=====================================================
// File scanner.cpp written by: Group Number: 3 
//=====================================================

//Enumerated token types
typedef enum tokentype {ERROR, WORD1, WORD2, PERIOD};

// Period found, returns token
// ** Done by: Aaron & Erik
bool period(tokentype& a)
{
	tokentype = PERIOD;	//sets token
	return;
}

/******************************************************/

//boolean DFA functions
bool stateZero(&string w)
{
	switch(w)
	{
		case s:
			stateEight();
		case m: case n: case k: case b: case h: case g: case p: case f:
			stateTen();
		case y:
			stateEleven();
		case a: case i: case u: case e: case o:
			stateTwelve();
		case t:
			stateTwo();
		case r: case k: case o: case m: case n: case p: case h:
			stateFour():
		case d:
			stateSix();
		case s:
			stateEight();	
	}
}

/******************************************************/

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
int scanner(tokentype& a, string& w)
{
	bool result = true;	//default, word is assumed valid
	
     		if(w[0] == ('a' || 'i' || 'u' || 'e' || 'o'))
		{
			result = statetwelve(w);
		}
		else if(w[0] == ('b' || 'g' || 'h' || 'j' || 'k' || 'm' || 'n' || 'p' || 'r'))
		{
			result = stateZero(w);
		}
		else if(w[0] == 't')
		{
		
		}
		else if(w[0] == 'c')
		{}
		else if(w[0] == 'd')
		{}
		else if(w[0] == 's')
		{}
		else if(w[0] == 'z')
		{}
		else if(w[0] == 'w')
		{}
		else if(w[0] == 'y')
		{}
		else if(w[0] == '.')
			return period(a); 
		else
		{
			a = ERROR;
			return;
		}	
	if(result == false)
	{
		tokentype = ERROR;
		return;
	}
	else if(tokem)	//valid
	{
		tokentype = WORD1;
		result = dictionary(tokentype a, string w);
	}
}//the end

//
//Done by: Aaron & Erik
bool dictionary(tokentype &a, string w)
{
	for(int count = 0; count <= reservedWord.length(); count++)
	{
		if(reservedWord[count] == w)
		{
			tokentype = reservedType[count];
			return;
		}
	}
}

// The test driver to call the scanner repeatedly  
// ** Done by:  Aaron & Erik
int main()
{
  	tokentype thetype;
  	string theword; 
	
	string inputfile;
	printf("Please enter the file name to be scanned: ");
	getline(cin, inputfile);
	
	ofstream toRead;
	toRead.open(inputfile.data());
	
	string reserved;
	ofstream dictionary;
	dictionary.open()
	
	while(dictionary)	//fill reserved word vector
	{
		string rWord; 
		string rType;
		dictionary >> rWord >> rType;
		
		reservedWord.push_back(rWord);
		reservedType.push_back(rType);
	}
		
	dictionary.close();

	while (toRead)
	{
		toRead >> theword;
	      	scanner(thetype, theword);  // call the scanner

	       	cout << "Type is:" << thetype << endl;
	       	cout << "Word is:" << theword << endl;   
    	}
	toRead.close();
}// end
