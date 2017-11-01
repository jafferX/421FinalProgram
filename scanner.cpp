#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

//God Bless this spaghetti mess

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
bool stateZero(&string w, int i)	//start
{
	bool result = false;

	
	switch(w)
	{
		case s:
			result = stateEight(w, i);
			break;
		case m: case n: case k: case b: case h: case g: case p: case f: case r: case p:
			result = stateTen(w, i);
			break;
		case a: case i: case u: case e: case o:
			if(array[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		case t:
			result = stateTwo(w, i);
			break;
		case d:
			result = stateSix(w, i);
			break;
		case y:
			result = stateFour(w, i);			/////////
			break;
		case w:
			result = stateFive(w, i);			////////
			
			break;
		default:
			return false;
	}
}

bool stateOne(string w, int& i)	//Ts
{
	bool result = false;
	
	switch(w[i])
	{
		case u:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateTwo(string w, int& i)	//T
{
	bool result = false;
	
	switch(w[i])
	{
		case e: case a: case o:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		case s:
			i++;
			result = stateOne(w, i);
			break;
		default:
			return false;
	}
}

bool stateFour(string w, int& i)	//
{
	bool result = false;
	
	switch(w[i])
	{
		case a: case u: case o:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateFive(string w, int& i)
{
	bool result = false;
	
	switch(w[i])
	{
		case a:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateSix(string w, int& i)	//d
{
	bool result = false;
	
	switch(w[i])
	{
		case e: case a: case o:
			i++;
			
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateSeven(string w, int& i)
{
	bool result = false;
	
	switch(w[i])
	{
		case n: case a: case i: case e: case u:
			i++;
			result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateEight(string w, int& i)	//s
{
	bool result = false;
	
	switch(w[i])
	{
		case h:
			i++;
			result = stateNine(w, i);
			break;
		case a: case u: case e: case o:
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateTen(string w, int& i)	//consonants or y-root
{
	bool result = false;
	
	switch(w[i])
	{
		case y:
			i++;
			result = stateEleven(w, i);
			break;
		case a: case i: case e: case o: case u:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateEleven(string w, int& i)
{
	bool result = false;
	
	switch(w[i])
	{
		case a: case u: case o:
			i++;
			if(w[i+1] == 'n')
				result = stateThirteen(w, i);
			else
				result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

bool stateThirteen(string w, int& i)	//N
{
	bool result = false;
	
	switch(w[i])
	{
		case n:
			i++;
			result = stateZero(w, i);
			break;
		default:
			return false;
	}
}

/******************************************************/

// Scanner processes only one word each time it is called
// ** Done by: Aaron & Erik
int scanner(tokentype& a, string& w)
{
	bool result = true;	//default, word is assumed valid
	int i = 1;
     		
		if(w[0] == '.')
			return period(a); 
		else
		{
			a = ERROR;
			return;
		}
	stateZero(w, i);
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
