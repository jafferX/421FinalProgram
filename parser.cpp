#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>	//grammar stack //maybe make this vector
#include <array>	//parsing table?
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
stack <char> gStack;	//initialize stack, maybe make this a vector for access
string PTable [3][3];	//parse table, default 3x3 to be changed as needed
token_type saved_token;			//buffer, default is empty
bool token_available = false;		//flag, default is unavailable
fstream toParse;			//global stream to parse file

//token vars
enum token_type{ //type creation
	PERIOD, EOFM, VERB, VERBNEG, VERBPASTNEG, 
	IS, WAS, OBJECT, SUBJECT, DESTINATION,
	PRONOUN, CONNECTOR};

//General functions
string scanner();	//parser calls this repeatedly
void next_token();	//go to next token
bool match(char);	//find and remove from text

//Nonterminal functions


//Stack functions
void fillStack();	//fills stack with parse characters

//Syntax error functions
void syntaxerror1(/*two args here*/);		//when match() function does not match
void syntaxerror2(/*two args here*/);		//when a switch statement goes to default

void fillStack()
{

}

//Done by:
void syntaxerror1()
{

}

//Done by:
void syntaxerror2()
{

}

string scanner(token_type& the_type, string& word)	//grabs next token
{
	//parser calls this repeatedly
}

//Done by: ***
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

//Done by: ***
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

//Done by: ***
int main()
{
	//- opens the input file
 	//- calls the <story> to start parsing
  	//- closes the input file 

	gStack.push('$');	//push terminating character onto stack
	
	string uInput;
	
	printf("Please enter the name of the file you'd like to parse: ");
	getline(cin, uInput);

	if(toParse.fail())
	{
		//error opening file, end program
	}

	toParse.open(uInput.c_str());		//open test file

	//calls <story>
	
	toParse.close();			//close file

	return 0;
}
