#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

string saved_lexeme;
tokentype saved_token;
bool token_available;

// Type of error: match failed
// Done by: Justin Flores 
void syntaxerror1(string s, tokentype t)
{    
  cout << "SYNTAX ERROR: expected " << t << " but found " << s << endl;
}
// Type of error: switch default
// Done by: Justin Flores 
void syntaxerror2(string s, string function) 
{    
  cout << "SYNTAX ERROR: unexpected " << s << " found in " << function << endl;
}

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

// Grammar: <after object>::=<verb><tense>PERIOD|<noun>DESTINATION<verb><tense>
//PERIOD
// Done by: Justin Flores
void after_object()
{
  switch(next_token()){
  case WORD2:
    verb();
    tense();
    match(PERIOD);
    break;
  case (WORD1 || PRONOUN):
    noun();
    match(DESTINATION);
    verb();
    tense();
    match(PERIOD);
    break;
  default:
    syntaxerror2(saved_lexeme, "<after object>");
  }
}
// Grammar: <noun>::= WORD1|PRONOUN
// Done by: Justin Flores
void noun()
{
  cout << "Processing <noun>\n";
  switch(next_token()){
  case WORD1:
    match(WORD1);
    break;
  case PRONOUN:
    match(PRONOUN);
    break;
  default:
    syntaxerror2(saved_lexeme, "<noun>");
  }
}
// Grammar: <verb>:: =WORD2
// Done by: Justin Flores
void verb()
{
  cout << "Processing <verb>\n";
  match(WORD2);
}
// Grammar: <be>::= IS|WAS
// Done by: Justin Flores
void be()
{
  cout << "Processing <be>\n";
  switch(next_token()){
  case IS:
    match(IS);
    break;
  case WAS:
    match(WAS);
    break;
  default:
    syntaxerror2(saved_lexeme, "<be>");
  }
}
// Grammar: <tense>::=VERBPAST|VERBPASTNEG|VERB|VERBNEG
// Done by: Justin Flores
void tense()
{
  cout << "Processing <tense>\n";
  switch(next_token()){
  case VERBPAST:
    match(VERBPAST);
    break;
  case VERBPASTNEG:
    match(VERBPASTNEG);
    break;
  case VERB:
    match(VERB);
    break;
  case VERBNEG:
    match(VERBNEG);
    break;
  default:
    syntaxerror2(saved_lexeme, "<tense>");
}


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
