#include<iostream>
using std::cout; using std::endl;
#include<initializer_list>
using std::initializer_list;
#include<utility>
using std::pair;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iterator>
using std::back_inserter; using std::ostream_iterator;
#include<algorithm>
using std::copy;

// note initializer_list is templated, must be set!
long fun1(initializer_list<long> l){
  long total=0;
  for (auto element : l)
    total += element;
  return total;
}

//copy is a good thing for initializer_lists
void fun2(initializer_list<long> il, vector<long>&v){
  if (il.size() <= v.size() )
    copy(il.begin(), il.end(), v.begin() );
  else
    copy(il.begin(), il.end(), back_inserter(v) );
}

// using a nested initializer_list
string fun3(initializer_list<pair<string,string>> l){
  string result = "";
  for (auto element : l){
    if (element.first > element.second)
      result = result + ":"+ element.first;
    else
      result = result + ":"+ element.second;
  }
  return result;
}

struct MyStruct{
  vector<long> v;

  // ctor, init the vector with the values in the initializer_list
  MyStruct(initializer_list<long> l) : v(l) {};
};

int main (){
  // 4 examples
  cout << fun1({1,2,3,4,5}) << endl;
  
  vector<long> v;
  fun2({1,2,3,4,5}, v);
  copy(v.begin(), v.end(), ostream_iterator<long>(cout, ", ") );
  cout << endl;
  
  cout << fun3(
	       {
		 {"abc", "def"},
		 {"mom", "dad"},
		 {"freddy", "amy"}
	       }
	       )
       << endl;

  
  MyStruct ms({1,2,3,4,5});
}
