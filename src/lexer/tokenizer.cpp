#include <regex>
#include <iostream>
#include <string>
#include <util.h>
#include "global.h"
#include "tokenizer.h"

using namespace std;


 tokenS tokenizer(const std::string & program)
{

  tokenS t;

  // ECMAScript is the default, so not needed as in:
  //  ...... regex r("regex", regex_constants::ECMAScript);
  
  regex identifierRegex("^[a-zA-Z_]\\w*\\b");
  regex constantRegex("^[0-9]+\\b");
  regex intKeywordRegex("^int\\b");
  regex voidKeywordRegex("^void\\b");
  regex returnKeywordRegex("^return\\b");
  regex openParenRegex("^\\(");
  regex closeParenRegex("^\\)");
  regex openBraceRegex("^\\{");
  regex closeBraceRegex("^\\}");
  regex semicolonRegex("^;");
  regex slashslashRegex("^//.*\\n");
  regex slashstarstarslashRegex("^/\\*(?:.|\\n)*\\*/");
  
  
  smatch m;
  string tmp;
  string raw = program;

  raw = ltrim(raw);
  if (raw.length() == 0){
    // This is a SUCCESS in the sense that there was nothing but blanks
    t.returnCode = SUCCESS;
    t.name ="";
    t.value="";
    t.remaining = raw;
    return t;
  }
  //cout << raw << "\n";
  regex_search(raw, m, intKeywordRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "KEYWORD:INT"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
 
  regex_search(raw, m, voidKeywordRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "KEYWORD:VOID"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }

  
  regex_search(raw, m, returnKeywordRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "KEYWORD:RETURN"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, identifierRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "IDENTIFIER"; 
    t.value =  m[0];
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, constantRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "CONSTANT"; 
    t.value =  m[0];
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, openParenRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "OPENPAREN"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, closeParenRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "CLOSEPAREN"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, openBraceRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "OPENBRACE"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, closeBraceRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "CLOSEBRACE"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }
  
  regex_search(raw, m, semicolonRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "SEMICOLON"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }

  regex_search(raw, m, slashslashRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "COMMENT"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }

  regex_search(raw, m, slashstarstarslashRegex);
  if (!m.empty()){
    t.returnCode = SUCCESS;
    t.name = "COMMENT"; 
    t.value = "";
    t.remaining = m.suffix();
    return t;
  }


  std::cerr << "\n***Tokenizer:ERROR:not recognized==>" << raw << "<==\n";
  t.returnCode = ERROR;
  t.remaining = raw;
  return t;
}

