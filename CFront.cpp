#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//===----------------------------------------------------------------------===//
// Lexer
//===----------------------------------------------------------------------===//

// Starting Point
// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
  tok_eof = -1,

  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  tok_number = -5,
};

static string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number

//TODO: Complete the lexer
static int gettok() {
    static int LastChar = ' ';
    // Skip whitespace in lastChar
    // HINT 1: USE C getChar() to get the next char in the code
    // HINT 2: use isspace(c) to see if c is a whitespace

    // recognize Strings append the characters to IdentifierStr

    // recognize Numbers assign the value to NumVal
    // Hint use strtod to get the number value


    // disacrd comments
    if (LastChar == '#') {
    // Comment until end of line.
    do
      LastChar = getchar();
    while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

    if (LastChar != EOF)
      return gettok();
  }

   // Check for end of file.  Don't eat the EOF.
  if (LastChar == EOF)
    return tok_eof;

  // Otherwise, just return the character as its ascii value.
  int ThisChar = LastChar;
  LastChar = getchar();
  return ThisChar;
}

// In case you struggle
// https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl01.html