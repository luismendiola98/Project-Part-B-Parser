#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: 17
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA
// Done by: Leonardo Miranda
// RE:   ((a|e|E|i|I|o|u)|(a|e|E|i|I|o|u)n |(b|d|g|h|j|k|n|m|p|r|s|t|w|y|z)(a|e|E|i|I|o|u)|(b|d|g|h|j|k|n|m|p|r|s|t|w|y|z)(a|e|E|i|I|o|u)n|
//       (by|gy|hy|ky|my|ny|py|ry|ch|sh|ts)(a|e|E|i|I|o|u)| (by|gy|hy|ky|my|ny|py|ry|ch|sh|ts)(a|e|E|i|I|o|u)n)^+

bool word(string s) {
  
  int state = 0;
  int charpos = 0;
  // replace the following todo the word dfa  **
  while (s[charpos] != '\0')
    {
      //state 0 (final state)
      if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos]=='n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r'))
	state = 1;
      
      else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
	state = 2;
      
      else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
	state = 3;
      else if (state == 0 && s[charpos] == 't')
	state = 4;
      else if (state == 0 && s[charpos] == 's')
	state = 5;
      else if (state == 0 && s[charpos] == 'c')
	state = 6;
      //else
      else { //state 1 (qy)
	if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
	  state = 2;
	
	else if (state == 1 && s[charpos] == 'y')
	  state = 3;
		
	else { //state 2 (final state)
	  if (state == 2 && s[charpos] == 'n')		
	    state = 0;
	  
	  else if (state == 2 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos]=='n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'r'))
	    state = 1; 
				
	  else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
	    state = 2;
				
	  else if (state == 2 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' || s[charpos] == 'z'))
	    state = 3;
	  
	  else if (state == 2 && s[charpos] == 't')
	    state = 4;
	  
	  else if (state == 2 && s[charpos] == 's')
	    state = 5;
	  
	  else if (state == 2 && s[charpos] == 'c')
	    state = 6;
	  
	  else { //state 3 (qsa)
	    if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
	      state = 2;
					
	    else
	      { //state 4 (qt)                                                                                                                                                                         
		if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
		  state = 2;
		
		else if (state == 4 && s[charpos] == 's')
		  state = 3;
		
		else
		  { //state 5 (qs)                                                                                                                                        
		    if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'E' || s[charpos] == 'i' || s[charpos] == 'I' || s[charpos] == 'o' || s[charpos] == 'u'))
		      state = 2;
							
		    else if (state == 5 && s[charpos] == 'h')
		      state = 3;
		    
		    else
		      { //state 6 (qc)                  
			if (state == 6 && s[charpos] == 'h')
			  state = 3;
			else
			  return false;								
		      }
		  }
	      }
	  }
	}
      }
      charpos++;
    }//end of while
  // where did I end up????
  if (state == 2|| state ==0) return(true);  // end in a final state
  else return(false);	 
}
// PERIOD DFA
// Done by: Leonardo Miranda
bool period(string s)
{  // complete this **
  int state = 0;
  int charpos = 0;
  
  //checks each character of the word to test if is a expression of a single period "."
  while (s[charpos] != '\0'){
    if (state == 0 && s[charpos] == '.')
      state = 1;
    else
      return(false);
    ++charpos;
  }
	
  if (state == 1) return(true);
  else return(false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Leonardo Miranda

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "VERB", "VERBNEG","VERBPAST","VERBPASTNEG","IS","WAS", "OBJECT", "SUBJECT","DESTINATION", "PRONOUN", "CONNECTOR" };

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

struct reservedwords {
	const char* string;
	tokentype token;
}

reservedwords[] = {
  {"masu",VERB},
  {"masen",VERBNEG},
  {"mashita",VERBPAST},
  {"masendeshita",VERBPASTNEG},
  {"desu",IS},
  {"deshita",WAS},
  {"o", OBJECT},
  {"wa", SUBJECT},
  {"ni", DESTINATION},
  {"watashi",PRONOUN},
  {"anata",PRONOUN},
  {"kare",PRONOUN},
  {"kanojo", PRONOUN},
  {"sore", PRONOUN},
  {"mata",CONNECTOR},
  {"soshite", CONNECTOR},
  {"shikashi", CONNECTOR},
  {"dakara", CONNECTOR}
};
// ------------ Scaner and Driver -----------------------

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by:
string scanner(tokentype& tt, string& w)
{
  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.
  
  /*  **
      2. Call the token functions (word and period)
      one after another (if-then-else).
      Generate a lexical error message if both DFAs failed.
      Let the tokentype be ERROR in that case.
      
      3. If it was a word,
      check against the reservedwords list.
      If not reserved, tokentype is WORD1 or WORD2
      decided based on the last character.
      
      4. Return the token type & string  (pass by reference)
  */
	fin >> w;
	int rowCount = sizeof reservedwords / sizeof reservedwords[0];
	cout << endl;

	if (word(w)){
	  for (int i = 0; i < rowCount; i++){
	    if (w == reservedwords[i].string){
	      tt = reservedwords[i].token;
	      return 0;}
	  }

	  char lastLetter;
	  lastLetter = w[(w.length() - 1)];
	  //checking step 3, part 2
	  if (lastLetter == 'I' || lastLetter == 'E')
	    tt = WORD2;		
	  else
	    tt = WORD1;
	}
	else if (period(w)) //checking step 2, part 2
	  tt = PERIOD;

	else if (w == "eofm")
	  return 0;
	else{
	  cout << "LEXICAL ERROR: " << w << " is not a valid token \n";
	  tt = ERROR;
	}
	return w;
}//the end of scanner


int main()
{
  tokentype thetype;
  string theword;
  string filename;
  
  cout << "Enter the input file name: ";
  cin >> filename;
  
  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
  while (true)
    {
      scanner(thetype, theword);  // call the scanner which sets
      // the arguments
      if (theword == "eofm") break;  // stop now
      cout << "\"" << theword << "\" is token type " << tokenName[thetype] << endl;
    }
  
  cout << "End of file is encountered." << endl;
  fin.close();
  
}// end

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File myparser.cpp written by Group Number: 17
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: **
// Done by: ** 
void syntaxerror1(  ){    }
// Type of error: **
// Done by: ** 
void syntaxerror2(  ) {    }

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: **
// Done by: **
token_type next_token(){}

// Purpose: **
// Done by: **
boolean match(tokentype expected) {}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **


//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
