#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// ** MYTOKEN DFA to be replaced by the WORD DFA
// ** Done by:
// ** RE:
bool mytoken(string s)
{
  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}

// ** Add the PERIOD DFA here
// ** Done by:


// ** Update the tokentype to be WORD1, WORD2, PERIOD and ERROR.
typedef enum tokentype {ERROR, };

// ** Need the lexicon to be set up here (to be used in Part C)
// ** Need the reservedwords list to be set up here
// ** Do not require any file input for these.
// ** a.out should work without any additional files.

// Scanner processes only one word each time it is called
// ** Done by: 
int scanner(tokentype& a, string& w)
{

  // ** Grab the next word from the file

  /* 
  2. Call the token functions one after another (if-then-else)
     And generate a lexical error if both DFAs failed.
     Let the token_type be ERROR in that case.
  3. Make sure WORDs are checked against the reservedwords list
     If not reserved, token_type is WORD1 or WORD2.
  4. Return the token type & string  (pass by reference)
  */

}//the end



// The test driver to call the scanner repeatedly  
// ** Done by:  Aaron Brunette**
int main()
{
  tokentype thetype;
  string theword; 

  /*
1. get the input file name from the user
2. open the input file which contains a story written in Japanese (fin.open).
3. call Scanner repeatedly until the EOF marker is read, and
     each time cout the returned results
     e.g. STRING TOKEN-TYPE
          =====  ===========
          watashi PRONOUN  (from the first call)
          wa      SUBJECT  (from the second call)
          gakkou  WORD1
          etc.
  */

	string inputfile;
	printf("Please enter the file name to be scanned: ");
	getline(cin, inputfile);
	
	fstream toRead;
	toRead.open(inputfile.txt | ou);
	
  while (true)
    {
      scanner(thetype, theword);  // call the scanner

       cout << "Type is:" << thetype << endl;
       cout << "Word is:" << theword << endl;   

       // ** display the actual type instead of a number

    }

  // ** close the input file

}// end



