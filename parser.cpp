#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//Global token vars
enum token_type{ vowel, consonant, root };		//type creation
token_type saved_token;					//buffer, default is empty
bool token_available = true;				//flag, default is available

//General functions
void scanner():		//not sure where this comes into play yet
void next_token();	//go to next token
bool match(char);	//find and remove from text

//Parse function declarations
void T();	//Text (Sentences)
void S();	//Sentence (Words)
void W();	//Word (Syllables)
void Y();	//Syllable
void V();	//Vowel
void C();	//Consonants, X on paper
void R();	//Root

int main()
{
	ofstream toParse;
	text.open("parse.txt");		//open test file

	scanner(toParse);		//starts scanning for tokens???
	
	text.close();			//close file

	return 0;
}

void scanner()	//grabs next token
{

}

token next_token()	//she has token here in her notes, part of enum I think
{
	string lexeme;

	if(!token_available)
	{
		scanner(saved_token, lexeme);
		token_available = true;
	}
	return saved_token;
}

bool match(char matchThis)
{
	if(next_token() != matchThis)	//mismatch
	{
		//syntax error messages
		
		//match fails	
		printf("Expected char %c...", matchThis);

		//switch goes to default
		printf("Major error detected. Ending parse...");
	}
	else //matched
	{
		token_available = false;	//remove token
		return true;
	}
}

void T()
{
	//might be unnecessary, just to test for empty file?
	//could do that on opening?
}

void S()
{
	
}

void W()
{

}

void Y()
{

}

void V()
{

}

void C()
{

}

void R()
{

}
