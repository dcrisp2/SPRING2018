#include<iostream>
using std::cout; using std::cin; using std::flush;
int main(){
  char c;

  while(cin.get(c)){
    if ( cin.peek() == tolower(c) ){
      cin.unget();
      cin.ignore(2, '\n');
    }
    else{
      cout.put(c);
      cout << flush;
    }
  } // of while
}
