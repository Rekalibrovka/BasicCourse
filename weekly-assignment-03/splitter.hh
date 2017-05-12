#ifndef SPLITTER_HH
#define SPLITTER_HH
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const unsigned int SPLIT_ERROR = 0;

class Splitter {
public:
    Splitter(const string& string_to_split = "");
    void set_string_to_split(const string& string_to_split);
    vector<string> split(char separator, bool ignore_empty = false);
    unsigned int number_of_fields(const vector <string> &splitted_string) const;
    string fetch_field(unsigned int field_index) const;

private:
    string string_;
};

void Splitter::set_string_to_split(const string &string_to_split){
    string_ = string_to_split;
}

vector<string> Splitter::split(char separator, bool ignore_empty){
    size_t start = 0, end = 0;
    vector<string> splitted_string;
    if (ignore_empty){
        while ((end = string_.find(separator, start)) != string::npos) {
            if (end != start) {
              splitted_string.push_back(string_.substr(start, end - start));
            }
            start = end + 1;
        }
        if (end != start) {
           splitted_string.push_back(string_.substr(start));
        }
        return splitted_string;
    }else{
        while ((end = string_.find(separator, start)) != string::npos) {
            if (end != start) {
              splitted_string.push_back(string_.substr(start, end - start));
            }
            start = end + 1;
        }
        if (end != start) {
           splitted_string.push_back(string_.substr(start));
        }
        return splitted_string;
    }
}

unsigned int Splitter::number_of_fields(const vector <string> &splitted_string) const {
    return splitted_string.size();
}

#endif // SPLITTER_HH
