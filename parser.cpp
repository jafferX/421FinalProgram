#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>	//grammar stack	//maybe make this vector
#include <array>	//parsing table?
using namespace std;

//Global token vars
enum token_type{ 	//valid token type creation
	PERIOD, EOFM, VERB, VERBNEG, VERBPASTNEG, 
	IS, WAS, OBJECT, SUBJECT, DESTINATION,
	PRONOUN, CONNECTOR};
token_type saved_token;			//buffer, default is empty
bool token_available = false;		//flag, default is unavailable
fstream toParse;			//global stream to parse file

//General functions
string scanner();		//not sure where this comes into play yet
void next_token();	//go to next token
bool match(char);	//find and remove from text

//Nonterminal functions, these are something else I think, probably change this
void V();	//Vowel
void C();	//Consonants, X on paper
void R();	//Root

//Stack functions
stack <char> gStack;	//initialize grammar stack
void fillStack();	//fills stack with parse characters

//Syntax error functions
void syntax_mismatch();		//when match() function does not match
void syntax_default();		//when a switch statement goes to default

int main()
{
	gStack.push('$');	//push terminating character onto stack

	string PTable [3][3];	//parse table, default 3x3 to be changed as needed
	string uInput;
	
	printf("Please enter the name of the file you'd like to parse: ");
	getline(cin, uInput);

	text.open(uInput.c_str());		//open test file

	//calls story???
	scanner(toParse);		//starts scanning for tokens???
	//scanner calls next_token and match in itself?
	
	text.close();			//close file

	return 0;
}

void scanner(token_type& the_type, string& word)	//grabs next token
{
	//W(); called in here?
}

token next_token()	//she has token here in her notes, part of enum I think
{
	string lexeme;	//hold next word

	if(!token_available)	//no saved token
	{
		scanner(saved_token, lexeme);	//finds next token
		token_available = true;		//now has saved token
	}
	return saved_token;	//return found token
}

bool match(char matchThis)
{
	if(next_token() != matchThis)	//mismatch
	{
		//syntax error messages
		
		//match fails	
		syntax_mismatch();
		/*printf("Expected char %c...", matchThis);*/

		//switch goes to default
		syntax_default();
		/*printf("Major error detected. Ending parse...");*/
	}
	else //matched
	{
		token_available = false;	//remove token
		return true;
	}
}

void V()	//vowel, could be followed by N
{

}

void C()	//consonant, followed by vowel
{

}

void R()	//root, followed by vowel
{

}
