#include <fstream> 
#include <iostream>
#include <list>
#include <lexer.h>

using namespace std;
string stage = "";
string filename = "";
int main (int argc, char *argv[])
{
  //cout << "argc:" + std::to_string(argc) + "\n";
  string help = "Usage: Compiler [--lex|--parse|--codegen] <filename>";
  if (argc == 2){
    if (argv[1] == "--help"){
      cout << help <<  "\n";
      return 0;
    }
    /* filename only*/
    filename = argv[1];
  }else
  if (argc == 3){
    /* intermediate stage plus filename*/
    stage = argv[1];
    if (stage != "--lex" && stage != "--parser" && stage != "--codegen"){
     cerr << "Unrecognized option\n";
     cerr << help << "\n";
     return -1; 
    }
    filename = argv[2];
  }else{
    cerr << "Compiler:Unrecognized command line\n";
    cerr << help << "\n";
    return -1;
  }

  if (stage == "" || stage == "--parse" || stage == "--codegen"){
    cerr << "I cannot do that yet...\n";
    cerr << "I can only do: Compile --lex <filename>\n";
    return -1;
  }

  if (stage != "--lex"){
    cerr << "I don't know what you're saying....\n";
    return -1;
  }

  ifstream inputFile(filename); 
  
    // Check if the file is successfully opened 
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return -1; 
    } 
  
    string line = "";
    string lines = "";
    while (getline(inputFile, line)) { 
        lines += line + "\n";
    } 
    inputFile.close(); 
    //cout << "Program:" << lines << "\n";

  //string program = "int    main(void){return 2;}";
  string program = lines;
  std::list<std::string> lexed_result;
  int rv = lexer(program, lexed_result);
  if ( rv == 0)
  {
    std::list<string>::iterator itr;
    for (itr = lexed_result.begin(); itr != lexed_result.end();  itr++){
      cout << *itr << "\n";
    }
  }
  else{
    cerr << "Compiler:error somewhere\n";
    return -1;
  }
  return 0;
}
