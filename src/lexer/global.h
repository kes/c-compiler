#ifndef GLOBAL
#define GLOBAL
#include <string>

 const std::string SUCCESS = "SUCCESS";
 const std::string ERROR = "ERROR";

struct tokenS {
    std::string returnCode; 
    std::string name;
    std::string value;
    std::string remaining;
  } ;
#endif