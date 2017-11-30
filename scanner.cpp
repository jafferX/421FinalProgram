#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 3 
//=====================================================

//Enumerated token types
enum tokentype{
ERROR, WORD1, WORD2, PERIOD, 
VERB, VERBNEG, VERBPAST, VERBPASTNEG, 
IS, WAS, OBJECT, SUBJECT, DESTINATION, 
PRONOUN, CONNECTOR, EOFM};

//global file streams
fstream toRead;

//reservedwords array initialization
const int arraySize = 38;
string reservedwords[arraySize] = {
"masu", "VERB", "masen", "VERBNEG", "mashita", "VERBPAST", 
"masendeshita", "VERBPASTNEG", "desu", "IS", "deshita", "WAS", 
"o", "OBJECT", "wa", "SUBJECT", "ni", "DESTINATION", 
"watashi", "PRONOUN", "anata", "PRONOUN", "kare", "PRONOUN", 
"kanojo", "PRONOUN", "sore", "PRONOUN", "mata", "CONNECTOR", 
"soshite", "CONNECTOR", "shikashi", "CONNECTOR", 
"dakara", "CONNECTOR", "eofm", "EOFM"};

//word checker prototype
bool dictionary(tokentype&, string);

// Period found, returns token
// ** Done by: Aaron & Erik
void period(tokentype& a)
{
	a = PERIOD;	//sets token
	return;
}

//bools: rewritten by Aaron
//check vowels
bool vowels(string w, int& charpos)
{
	int state = 0;
	
	if(w[charpos + 1] == 'n')	//Vn
	{
		charpos++; charpos++;
		return true;
	}
	else
	{
		charpos++;
		return true;
	}
}

//check consonants
bool consonants(string w, int& charpos)
{	
	int state = 0;
	charpos++;

	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'i' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//CV
	{	
		state = 2;
		charpos++;
	}
	if(state == 0 && w[charpos] == 'y')	//Cy
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'o')) //CyV
	{
		state = 2;
		charpos++;
	}
	if(state == 2 && w[charpos] == 'n')	//-n
	{
		charpos++;
		state = 3;
	}
  	if(state == 2 || state == 3) 
		return true;
   	else 
		return false;
}

bool sRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;
	
	if(state == 0 && w[charpos] == 'h')	//sh
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && (w[charpos] == 'a' || w[charpos] == 'i' || w[charpos] == 'u' || w[charpos] == 'o'))	//sha shi shu sho
	{
		state = 2;
		charpos++;
	}
	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//sa su se so
	{
		state = 2;
		charpos++;
	}
	if(state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}
	if(state == 2 || state == 3)
		return true;
	else
		return false;
}

bool zRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//sa su se so
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'n')	//-n
	{
		state = 2;
		charpos++;
	}
	if(state == 1 || state == 2)
		return true;
	else
		return false;
}

bool jRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if(state == 0 && w[charpos] == 'i')	//ji
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'n')	//jin
	{
		state = 2;
		charpos++;
	}
	if(state == 1 || state == 2)
		return true;
	else 
		return false;
}

bool tRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;
	
	if(state == 0 && w[charpos] == 's')	//ts
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'u')	//tsu
	{
		state = 2;
		charpos++;
	}
	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'e' || w[charpos] == 'o'))	//ta te to
	{
		state = 2;
		charpos++;
	}
	if(state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}
	if(state == 2 || state == 3)
		return true;
	else
		return false;
}

bool dRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'e' || w[charpos] == 'o'))	//da de do
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'n')
	{
		state = 2;
		charpos++;
	}
	if(state == 1 || state == 2)
		return true;
	else
		return false;
}

bool cRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;
	
	if(state == 0 && w[charpos] == 'h')	//ch
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'i')	//chi
	{
		state = 2;
		charpos++;
	}
	if(state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}

	if(state == 2 || state == 3)
		return true;
	else
		return false;
}

bool wRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if(state == 0 && w[charpos] == 'a')	//wa
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'n')	//wan
	{
		state = 2;
		charpos++;
	}
	if(state == 1 || state == 2)
		return true;
	else
		return false;
}

bool yRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;
	
	if(state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'o'))	//ya yu yo
	{
		state = 1;
		charpos++;
	}
	if(state == 1 && w[charpos] == 'n')	//yan yun yon
	{
		state = 2;
		charpos++;
	}
	if(state == (1 || 2))
		return true;
	else
		return false;
}

bool startstate(string w)	//also final state
{
	int charpos = 0;
	bool result = true;		//result of going through bools

	while(w[charpos] != '\0')
	{
		switch(w[charpos])
		{
			case 'a': case 'i': case 'u': case 'e': case 'o':
				result = vowels(w, charpos);
				break;
			case 'k': case 'n': case 'h': case 'm': case 'r': case 'g': case 'b': case 'p':
				result = consonants(w, charpos);
				break;
			case 's':
				result = sRoot(w, charpos);
				break;
			case 'z':
				result = zRoot(w, charpos);
				break;
			case 'j':
				result = jRoot(w, charpos);
				break;
			case 't':
				result = tRoot(w, charpos);
				break;
			case 'd':
				result = dRoot(w, charpos);
				break;
			case 'c':
				result = cRoot(w, charpos);
				break;
			case 'w':
				result = wRoot(w, charpos);
				break;
			case 'y':
				result = yRoot(w, charpos);
				break;
			default:		//invalid character
				return false;
		}
		if(w[charpos] == 'E' || w[charpos] == 'I')	//WORD2 check
			return true;
		if(result == false)				//failed in bools
			return false;
	}
	return true;
}

//Done by: Aaron & Erik
bool dictionary(tokentype &a, string w)
{	
	string rWord;	//hold word
	string rType;	//hold word type

	//while reservedwords can read in
	for(int i; i < arraySize; i++)
	{
		if(reservedwords[i] == w)
		{
			i++;	
			//overload viable here?
			if(reservedwords[i] == "VERB")
				a = VERB;
			else if(reservedwords[i] == "VERBNEG")
				a = VERBNEG;
			else if(reservedwords[i] == "VERBPAST")
				a = VERBPAST;
			else if(reservedwords[i] == "VERBPASTNEG")
				a = VERBPASTNEG;
			else if(reservedwords[i] == "IS")
				a = IS;
			else if(reservedwords[i] == "WAS")
				a = WAS;
			else if(reservedwords[i] == "OBJECT")
				a = OBJECT;
			else if(reservedwords[i] == "SUBJECT")
				a = SUBJECT;
			else if(reservedwords[i] == "DESTINATION")
				a = DESTINATION;
			else if(reservedwords[i] == "PRONOUN")
				a = PRONOUN;
			else if(reservedwords[i] == "CONNECTOR")
				a = CONNECTOR;

			return true;
		}i++;
	}
	return false;
}

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
int scanner(tokentype& a, string& w)
{
  	toRead >> w;  //read word

	bool result = true;	//default, word is assumed valid
	//int i = 0;
     	
	if(w == "eofm")		//if end of file
		return -1;	
	else if(w == ".")	//period calls period DFA
	{
		period(a);
		return 1;
	}
 
	result = startstate(w);		//enter DFA

	if(result == false)	//result of DFA is false, word is invalid
	{
		a = ERROR;
	}
	else	//word is valid
	{
		if(isupper(w[w.size()-1]))	//check last character in word for Uppercase
		{
			a = WORD2;
		}	
		else				//not uppercase so default WORD1, check against reservedwords.txt
		{
			a = WORD1;
			result = dictionary(a, w);
		}
	}
}//the end

// The test driver to call the scanner repeatedly  
// ** Done by:  Aaron & Erik
int main()
{
  	tokentype thetype;	//hole the type of the word being scanned
  	string theword; 	//hold the word being scanned
	int eof = 1;		//eof int

	string inputfile;	//user input filename
	printf("Please enter the name of file to be scanned: ");
	getline(cin, inputfile);

	/*while(toRead.fail(inputfile.c_str()))	//input checking
	{
		printf("Error opening inputfile: %s \nEnding program...", inputfile);
		return -1;
	}*/

	toRead.open(inputfile.c_str());	//open user input file

	while (true)	//while eof has not been reached
	{
		eof = scanner(thetype, theword);  // call the scanner

		if(eof == -1)
			return 0;
	
		//optimize this with operator overload
		if(thetype == ERROR)	
                {
			cout << "Lexical error: " << theword << " is not a valid token" << endl;
	       		cout << "Type is: " << "ERROR   ";
		}
		else if(thetype == WORD1)
			cout << "Type is: " << "WORD1   ";
		else if(thetype == WORD2)
			cout << "Type is: " << "WORD2   ";
	       	else if(thetype == PERIOD)
			cout << "Type is: " << "PERIOD   ";
		else if(thetype == VERB)
			cout << "Type is: " << "VERB   ";
		else if(thetype == VERBPAST)
			cout << "Type is: " << "VERPAST   ";
		else if(thetype == VERBNEG)
			cout << "Type is: " << "VERBNEG   ";
		else if(thetype == VERBPASTNEG)
			cout << "Type is: " << "VERBPASTNEG   ";
		else if(thetype == IS)
			cout << "Type is: " << "IS   ";
		else if(thetype == WAS)
			cout << "Type is: " << "WAS   ";
		else if(thetype == OBJECT)
			cout << "Type is: " << "OBJECT   ";
		else if(thetype == SUBJECT)
			cout << "Type is: " << "SUBJECT   ";
		else if(thetype == DESTINATION)
			cout << "Type is: " << "DESTINATION   ";
		else if(thetype == PRONOUN)
			cout << "Type is: " << "PRONOUN   ";
		else if(thetype == CONNECTOR)
			cout << "Type is: " << "CONNECTOR   ";

		cout << "Word is: " << theword << endl << endl;   
    	}
	toRead.close();		//close user input file
}// end
