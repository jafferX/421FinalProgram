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
token_type saved_token;			//buffer, default is empty
string saved_lexeme;
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
bool match(token_type);	//find and remove from text

//Nonterminal functions
//Done by: ***
void story()
{

}

//Done by: ***
void s0()
{
	
}

//Done by: ***
void s1()
{
	
}

//Done by: ***
void s2()
{
	
}

//Done by: ***
void s3()
{
	
}

//Done by: ***
void noun()
{
	
}

//Done by: ***
void verb()
{
	
}

//Done by: ***
void be()
{
	
}

//Done by: ***
void tense()
{
	
}

//Syntax Errors
//Done by: Paul
void syntaxerror1()	//when match() function does not match
{

}

//Done by: Paul
void syntaxerror2()	//when a switch statement goes to default
{

}

//Scanner functions
string scanner(token_type& the_type, string& word)	//grabs next token
{
	//parser calls this repeatedly
}

//Done by: Aaron
token next_token()	//she has token here in her notes, part of enum I think
{
	if(!token_available)	//no saved token
	{
		scanner(saved_token, saved_lexeme);	//finds next token
		token_available = true;		//now has saved token
	}
	return saved_token;	//return found token
}

//Done by: Aaron
bool match(char matchThis)
{
	if(next_token() != matchThis)	//mismatch
	{
		//syntax error messages
		//match fails	
		syntaxerror1();
		//switch goes to default
		syntaxerror2();
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

	if(!toParse.is_open())	//check if file opened
	{
		printf("Error opening file. Ending program...\n");
		exit(EXIT_FAILURE);
	}
	
	story();		//begin parse
	
	toParse.close();	//close file

	return 0;
}
