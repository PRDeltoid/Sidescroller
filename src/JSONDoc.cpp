#include "JSONDoc.hpp"


JSONDoc::JSONDoc(string json_file) :
    json_file_(json_file)
{
    Json::Reader reader;
    std::ifstream file(json_file.c_str());
    string json((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());    
    reader.parse(json, root_);
}

void JSONDoc::load(string json_file) {
    json_file_ = json_file;
    Json::Reader reader;
    std::ifstream file(json_file.c_str());
    string json((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());    
    reader.parse(json, root_);
}

Value JSONDoc::get(string value_name) {
    return root_[value_name];
}
