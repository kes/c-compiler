#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <list>
#include "global.h"
#include "tokenizer.h"

using namespace std;

int lexer(std::string program, std::list<std::string> & lexed)
{

  tokenS t; 
  string raw = program;
  //cout << "let's go" << endl;
  t = tokenizer(raw);
  //cout << t.returnCode << endl;
  while (t.returnCode.compare(SUCCESS) == 0){
  //  cout << "Okay:" ;
    //cout << t.name << endl;
    if (t.name.length() != 0 ){
      if (t.name != "COMMENT"){
        t.value.length() > 0 ? lexed.push_back(t.name + ":" + t.value) : lexed.push_back(t.name);
      }
      t = tokenizer(t.remaining);
    }else break;
  }
  
  if (t.returnCode == ERROR){
    std::cerr << "\n***lexer:ERROR ==>" << t.remaining  << "<==\n";
    return 1;
  }else{
     return 0;
  }
}

