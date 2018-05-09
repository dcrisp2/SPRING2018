#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using std::cout; using std::endl; using std::cin;
using std::string;
using std::pow;
using std::sort;

string abbreviate(string loc){
  string l = loc, oldl="";
  string::size_type indx=1;

  // iterate until you hit the end of the string
  while (indx < l.size()){
    sort(l.begin(), l.end()); // make sure sorted

    // when two letters match
    if (l[indx] == l[indx-1]){
      oldl = l;
      //cout << "pre:"<<oldl<<endl;
      // get substring up to but not including repeat characters
      l = oldl.substr(0,indx-1);
      //cout << "no repeat:"<<l<<endl;
      // replace the repeating characters with the char + 1
      l.push_back(static_cast<char>(oldl[indx]+1)) ;
      //cout << "with pushback:"<<l<<endl;
      // get the rest of the string past the repeats
      l += oldl.substr(indx+1);
      //cout << "post:"<<l<<endl;
    }
    else
      indx += 1;
  }
  return l;
}

long loc_to_dec(string loc){
  long sum=0;
  sort(loc.begin(), loc.end()); // make sure sorted
	// iterate through string
  for (auto ch : loc)
    sum += pow(2,ch-'a'); // use char math to get exponent
  return sum;
}

string dec_to_loc(long dec){
  /* use this form of the string constructor
  * where it create a dec-long string of a's
  * then abbreviate this to get your result
  */
  string result(dec,'a');
  return abbreviate(result);
}

long add_loc(string loc1, string loc2){
  string result = loc1 + loc2; // add two strings together
  result = abbreviate(result);
  return loc_to_dec(result);
}

int main () {
  string loc_str;
  long l;
  cin >> loc_str >> l;
  cout << loc_to_dec (loc_str) << " "
       << abbreviate (loc_str) << " "
       << dec_to_loc (l) << " "
       << add_loc(loc_str, loc_str)
       << endl;

  /*
  cout << "abcd to loc:"<< loc_to_dec("abcd")<<endl;
  cout << "Abbrev: aaaa:"<<abbreviate("aaaa")<<endl;
  temp_str = dec_to_loc(123);
  cout << "Int 123: "<<temp_str<<endl;
  temp_long = loc_to_dec(temp_str);
  cout << "Loc of:"<<temp_str<<": "<<temp_long<<endl;
  temp_long = add_loc("abc","cde");
  cout << "Sum of abc and cde is:"<<temp_long<<endl;
  */
}