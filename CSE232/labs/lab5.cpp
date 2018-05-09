#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include<iterator>
using std::ostream_iterator;

#include "splitter-functions.h"

// Split function using istringstream and getline
vector<string> split(const string &s, char delim) {
    istringstream ss(s); // Works similar to cin where it's an input stream
    string item;
    vector<string> tokens;
    // Splits the stringstream by a delim and push the strings onto tokens
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

// Split function using find and substr
/*
vector<string> split(const string& s, char delim) {
    auto i = 0;
    auto pos = s.find(delim); // Place to split
    vector<string> tokens;

    // Keep spliting until there are no more places to split at
    while (pos != string::npos) {
      tokens.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      // Add on last portion
      if (pos == string::npos)
         tokens.push_back(s.substr(i, s.length()));
    }
    return tokens;
}
*/

// Print vector
void print_vector (ostream &out, const vector<string> &v){
    copy(v.begin(), v.end(), ostream_iterator<string>(out, "\n"));
}