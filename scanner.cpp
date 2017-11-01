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
bool stateZero(&string w)	//start
{
	switch(w)
	{
		case s:
			stateEight(w);
			break;
		case m: case n: case k: case b: case h: case g: case p: case f: case r: case p:
			stateTen(w);
			break;
		case a: case i: case u: case e: case o:
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
			break;
		case t:
			stateTwo(w);
			break;
		case d:
			stateSix(w);
			break;
		case y:
			stateFour();			/////////
			break;
		case w:
			state();			////////
			break;
	}
}

stateOne(i)	//Ts
{
	switch(&array[i])
	{
		case u:
			i++;
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateTwo(i)	//T
{
	switch(&array[i])
	{
		case e: case a: case o:
			i++;
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
			break;
		case s:
			i++;
			stateOne();
			break;
	}
}

stateFour(i)	//
{
	switch(&array[i])
	{
		case y:
			i++;
			stateEleven();
	}
}

stateFive(i)
{
	switch(&array[i])
	{
		case i: case u: case o:
			i++;
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateSix(i)	//d
{
	switch(&array[i])
	{
		case e: case a: case o:
			i++;
			
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateSeven(i)
{
	switch(&array[i])
	{
		case n: case a: case i: case e: case u:
			i++;
			stateZero();
	}
}

stateEight(i)	//s
{
	switch(&array[i])
	{
		case h:
			i++;
			stateNine();
			break;
		case a: case u: case e: case o:
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateTen(i)	//consonants or y-root
{
	switch(&array[i])
	{
		case y:
			i++;
			stateEleven();
			break;
		case a: case i: case e: case o: case u:
			i++;
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateEleven(i)
{
	switch(&array[i])
	{
		case a: case u: case o:
			i++;
			if(array[i+1] == 'n')
				stateThirteen();
			else
				stateZero();
	}
}

stateThirteen(i)	//N
{
	switch(&array[i])
	{
		case n:
			i++;
			stateZero();
	}
}

/******************************************************/

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
int scanner(tokentype& a, string& w)
{
	bool result = true;	//default, word is assumed valid
	
     		
		if(w[0] == '.')
			return period(a); 
		else
		{
			a = ERROR;
			return;
		}
	stateZero(w);
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
