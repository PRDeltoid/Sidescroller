#ifndef JSONDOC_H
#define JSONDOC_H

#include <json/json.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

using std::string;
using Json::Value;

class JSONDoc {
public:
    JSONDoc(string);
    ~JSONDoc();
    Value get(string);
private:
    string json_file_;
    Value root_;
};


#endif
