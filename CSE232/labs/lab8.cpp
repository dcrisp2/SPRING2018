#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<algorithm>
using std::transform; using std::copy; using std::sort;
#include<iterator>
using std::ostream_iterator; using std::back_inserter;
#include<sstream>
using std::ostringstream;
#include<stdexcept>
using std::range_error;

#include "lab08_functions.h"

/*
  input is a positive (1 or greater) integer
  returns the next collatz number
  if number is 0 or less, throws range_error;
 */
long collatz_next(long n){
  if (n >= 1)
    return (n%2 ? 3*n+1 : n/2);
  else
    throw range_error("Collatz only accepts postive integers");
}

/*
  input is a Collatz pair (pair<long, vector<long > >)
  output is a string of the format
     number: sequence (comma separated) ending in 1
     no trailing comma
*/
string Collatz_to_string(const Collatz &p){
  ostringstream oss;
  oss << p.first << ": ";
  for(auto itr=p.second.begin(); itr!=p.second.end(); itr++)
    oss << *itr << ",";
  string ret = oss.str();
  return ret.substr(0,ret.size()-1);
}

/*
  input is a collatz map (map<long, vector<long> >)and a long
  if the number exists as a key in the map
     returns the Collatz_to_string of that pair
  else returns an empty string
*/
string sequence_in_map_to_string(map<long, vector<long> > &m, long number){
  auto itr = m.find(number);
  string result;
  if (itr != m.end() )
    result = Collatz_to_string(*itr);
  return result;
}

/*
  input is a collatz map (map<long, vector<long> >)and a long
  returns a vector<long>, the collatz sequence for that number
  Operation. As you iterate through the collatz sequence
     - uses collatz_next if the element in question is not in the map
     - if the element *is* in the map, copies the sequence from the map
       to the end of the current sequence and ends.
*/
vector<long> collatz_sequence(map<long, vector<long> > &m, long number){
  vector<long> v;
  long next = number;
  auto itr = m.begin();
  while (next != 1){
    itr = m.find(next);
    // If the sequence already exists in the map, use that instead of
    // regenerating the sequence. More efficient
    if (itr != m.end()){
      // cout << "For Collatz of "<<start<<" program copies starting from "<<itr->first<<endl;
      auto rest = itr->second;
      copy(rest.begin(), rest.end(), back_inserter(v));
      next = 1;
    }
    // Generate the next part
    else{
      next = collatz_next(next);
      v.push_back(next);
    }
  }
  return v;
}

/*
  input is a collatz map (map<long, vector<long> >)and a low and high long
  fills the map from low to high inclusive with each element's collatz sequence
  using the function collatz_sequence
*/
void collatz_range(map<long, vector<long> > &m, long low, long high){
  for(long i = low; i <= high; ++i)
    m[i] = collatz_sequence(m,i);
}

// function to help sort by longest sequence first
bool compare_pairs(const Collatz &p1, const Collatz &p2){
  return p1.second.size() > p2.second.size();
}

string longest_in_map(map<long, vector<long> > &m){
  string result;
  vector<Collatz> v;
  copy(m.begin(), m.end(), back_inserter(v));
  // sort by longest sequence
  sort(v.begin(), v.end(), compare_pairs);
  // the longest sequence will be the first element
  result = Collatz_to_string(v[0]);
  return result;
}