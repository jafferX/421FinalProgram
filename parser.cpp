/*****************parser.cpp**************/
//Author: Aaron Brunette, Paul Rowe, Erik Leung
//Github: abrunette
//Last updated: 2017/11/26
//Compiled with g++
//Written on vim, visual studio, github
//Purpose:	Parse a file of romanji for proper spelling
// and sentence structure.
//
//				MIT License
/***************************************/

#include <iostream>		//i/o
#include <cstdio>		//printf, i/o
#include <cstdlib>		//exit()
#include <fstream>		//fstream
#include <string>		//string
#include <unordered_map>	//grammar table
using namespace std;

//=================================================
// File parser.cpp written by Group Number: 03
//=================================================

// ** Be sure to put the name of the programmer above each function
// i.e. Done by:

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)

// ** Need the updated match and next_token (with 2 global vars)

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function


//Global
token_type saved_token;			//buffer, default is empty
string saved_lexeme;
bool token_available = false;		//flag, default is unavailable
fstream toParse;			//global stream to parse file
int trace = 1;			//trace on by default

//token vars
enum token_type { //type creation
	PERIOD, EOFM, VERB, VERBNEG, VERBPASTNEG,
	IS, WAS, OBJECT, SUBJECT, DESTINATION,
	PRONOUN, CONNECTOR
};

//reservedwords array initialization
const int arraySize = 38;
string reservedwords[arraySize] = {
	"masu", "VERB", "masen", "VERBNEG", "mashita", "VERBPAST",
	"masendeshita", "VERBPASTNEG", "desu", "IS", "deshita", "WAS",
	"o", "OBJECT", "wa", "SUBJECT", "ni", "DESTINATION",
	"watashi", "PRONOUN", "anata", "PRONOUN", "kare", "PRONOUN",
	"kanojo", "PRONOUN", "sore", "PRONOUN", "mata", "CONNECTOR",
	"soshite", "CONNECTOR", "shikashi", "CONNECTOR",
	"dakara", "CONNECTOR", "eofm", "EOFM" };

//General functions
string scanner();	//parser calls this repeatedly
void next_token();	//go to next token
bool match(token_type);	//find and remove from text

//Nonterminal functions
//Done by: ***
void story()
{
	if (trace != 0)
		printf("Processing <story>\n\n");
}

//Done by: ***
void s0()
{
	if (trace != 0)
		printf("Processing <s0>\n\n");
}

//Done by: ***
void s1()
{
	if (trace != 0)
		printf("Processing <s1>\n\n");
}

//Done by: ***
void s2()
{
	if (trace != 0)
		printf("Processing <s2>\n\n");
}

//Done by: ***
void s3()
{
	if (trace != 0)
		printf("Processing <s3>\n\n");
}

//Done by: ***
void noun()
{
	if (trace != 0)
		printf("Processing <noun>\n\n");
}

//Done by: ***
void verb()
{
	if (trace != 0)
		printf("Processing <verb>\n\n");
}

//Done by: ***
void be()
{
	if (trace != 0)
		printf("Processing <be>\n\n");
}

//Done by: ***
void tense()
{
	if (trace != 0)
		printf("Processing <tense>\n\n");
}

//Syntax Errors
//Done by: Paul
void syntaxerror1()	//when match() function does not match
{
	//mismatch
}

//Done by: Paul
void syntaxerror2()	//when a switch statement goes to default
{
	printf("Switch default. Major error, ending program...");
	exit(EXIT_FAILURE);
}


/*****************************Scanner Functions**********************************/

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

	if (w[charpos + 1] == 'n')	//Vn
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

	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'i' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//CV
	{
		state = 2;
		charpos++;
	}
	if (state == 0 && w[charpos] == 'y')	//Cy
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'o')) //CyV
	{
		state = 2;
		charpos++;
	}
	if (state == 2 && w[charpos] == 'n')	//-n
	{
		charpos++;
		state = 3;
	}
	if (state == 2 || state == 3)
		return true;
	else
		return false;
}

bool sRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && w[charpos] == 'h')	//sh
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && (w[charpos] == 'a' || w[charpos] == 'i' || w[charpos] == 'u' || w[charpos] == 'o'))	//sha shi shu sho
	{
		state = 2;
		charpos++;
	}
	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//sa su se so
	{
		state = 2;
		charpos++;
	}
	if (state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}
	if (state == 2 || state == 3)
		return true;
	else
		return false;
}

bool zRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'e' || w[charpos] == 'o'))	//sa su se so
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'n')	//-n
	{
		state = 2;
		charpos++;
	}
	if (state == 1 || state == 2)
		return true;
	else
		return false;
}

bool jRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && w[charpos] == 'i')	//ji
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'n')	//jin
	{
		state = 2;
		charpos++;
	}
	if (state == 1 || state == 2)
		return true;
	else
		return false;
}

bool tRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && w[charpos] == 's')	//ts
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'u')	//tsu
	{
		state = 2;
		charpos++;
	}
	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'e' || w[charpos] == 'o'))	//ta te to
	{
		state = 2;
		charpos++;
	}
	if (state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}
	if (state == 2 || state == 3)
		return true;
	else
		return false;
}

bool dRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'e' || w[charpos] == 'o'))	//da de do
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'n')
	{
		state = 2;
		charpos++;
	}
	if (state == 1 || state == 2)
		return true;
	else
		return false;
}

bool cRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && w[charpos] == 'h')	//ch
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'i')	//chi
	{
		state = 2;
		charpos++;
	}
	if (state == 2 && w[charpos] == 'n')	//-n
	{
		state = 3;
		charpos++;
	}

	if (state == 2 || state == 3)
		return true;
	else
		return false;
}

bool wRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && w[charpos] == 'a')	//wa
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'n')	//wan
	{
		state = 2;
		charpos++;
	}
	if (state == 1 || state == 2)
		return true;
	else
		return false;
}

bool yRoot(string w, int& charpos)
{
	int state = 0;
	charpos++;

	if (state == 0 && (w[charpos] == 'a' || w[charpos] == 'u' || w[charpos] == 'o'))	//ya yu yo
	{
		state = 1;
		charpos++;
	}
	if (state == 1 && w[charpos] == 'n')	//yan yun yon
	{
		state = 2;
		charpos++;
	}
	if (state == (1 || 2))
		return true;
	else
		return false;
}

bool startstate(string w)	//also final state
{
	int charpos = 0;
	bool result = true;		//result of going through bools

	while (w[charpos] != '\0')
	{
		switch (w[charpos])
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
		if (w[charpos] == 'E' || w[charpos] == 'I')	//WORD2 check
			return true;
		if (result == false)				//failed in bools
			return false;
	}
	return true;
}

//Done by: Aaron & Erik
void dictionary(tokentype &a, string w)
{
	string rWord;	//hold word
	string rType;	//hold word type

	//while reservedwords can read in
	for (int i; i < arraySize; i++)
	{
		if (reservedwords[i] == w)
		{
			i++;
			if (reservedwords[i] == "VERB")
				a = VERB;
			else if (reservedwords[i] == "VERBNEG")
				a = VERBNEG;
			else if (reservedwords[i] == "VERBPAST")
				a = VERBPAST;
			else if (reservedwords[i] == "VERBPASTNEG")
				a = VERBPASTNEG;
			else if (reservedwords[i] == "IS")
				a = IS;
			else if (reservedwords[i] == "WAS")
				a = WAS;
			else if (reservedwords[i] == "OBJECT")
				a = OBJECT;
			else if (reservedwords[i] == "SUBJECT")
				a = SUBJECT;
			else if (reservedwords[i] == "DESTINATION")
				a = DESTINATION;
			else if (reservedwords[i] == "PRONOUN")
				a = PRONOUN;
			else if (reservedwords[i] == "CONNECTOR")
				a = CONNECTOR;

			return;
		}i++;
	}
	return;
}

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
void scanner(tokentype& a, string& w)
{
	toParse >> w;  //read word

	bool result = true;	//default, word is assumed valid

	if (w == ".")	//period calls period DFA
	{
		period(a);
		return;
	}

	result = startstate(w);		//enter DFA

	if (result == false)	//result of DFA is false, word is invalid
	{
		a = ERROR;
	}
	else	//word is valid
	{
		if (isupper(w[w.size() - 1]))	//check last character in word for Uppercase
		{
			a = WORD2;
		}
		else				//not uppercase so default WORD1, check against reservedwords array
		{
			a = WORD1;
			dictionary(a, w);
		}
	}
}//the end

/*******************************************************************************/

//Done by: Aaron
token next_token()	//she has token here in her notes, part of enum I think
{
	if (!token_available)	//no saved token
	{
		scanner(saved_token, saved_lexeme);	//finds next token
		token_available = true;		//now has saved token
	}
	return saved_token;	//return found token
}

//Done by: Aaron
bool match(char matchThis)
{
	if (next_token() != matchThis)	//mismatch
	{
		syntaxerror1();
		//fix error here somehow? continue parse as if the right one was called?
	}
	else //matched
	{
		token_available = false;	//remove token
		return true;
	}
}

//Done by: Aaron
int main()
{
	//- opens the input file
	//- calls the <story> to start parsing
	//- closes the input file 

	string uInput;	//user input name of file to open

	printf("Please enter the name of the file you'd like to parse: ");
	getline(cin, uInput);

	toParse.open(uInput.c_str());		//open test file

	if (!toParse.is_open())	//check if file opened
	{
		printf("Error opening file. Ending program...\n");
		exit(EXIT_FAILURE);
	}

	printf("Would you like the parse to be traced?\nEnter 0 to turn off trace: ");
	cin >> trace;	//option to turn trace off

	story();		//begin parse

	toParse.close();	//close file

	return 0;
}