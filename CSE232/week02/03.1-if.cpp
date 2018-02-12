
#include<iostream>
using std::cout; using std::endl; using std::cin;
/*
wfp 7.18.13
wfp updated 1/19/15
if stmts
*/

int main (){
  long zero=0, one=1, two=2, three=3, a_long;
  double pi=3.14159, a_double;

  // basic if, only one statement when true
  if (zero < one)
    cout << "zero is smaller, who knew"<<endl;

  // do a block if true, hence curlys
  if (zero <= two){
    cout << "smaller than one"<<endl;
    cout << "and smaller/equal to two"<<endl;
  } // end of true block

  // assign both assigns and returns a value. Return is not 0, so true.
  if (a_long = one + two){   
    cout << "sum is:"<<a_long<<endl;
    cout <<"remember assign both assigns and returns a value. only 0 is false"<<endl;
  } // end of true block

  //else, only one statement, no blocks
  cout << "Give me an int:";
  cin >> a_long;
  if (one > a_long)
    cout << a_long << " is bigger"<<endl;
  else
    cout << a_long << " is smaller"<<endl;

  // blocks for if and else
  cout << "Give me a double:";
  cin >> a_double;
  if (a_double > pi){
    cout << "you entered:"<<a_double<<endl;
    cout << "that is bigger than:"<<pi<<endl;
  } // true block
  else{
    cout << "you entered:"<<a_double<<endl;
    cout << "that is smaller than:"<<pi<<endl;    
  } // of else block

  // nested
  cout << "Enter another int";
  cin >> a_long;
  if (a_long > a_double){
    cout << "the long:"<<a_long<<" is bigger than "<<a_double<<endl;
    if (a_long > three){
      cout << "The long is:"<<a_long<<endl;
      cout << "That long is bigger than three"<<endl;
    }// nested true
    else if (a_long > two){
      cout << "a_long:"<<a_long<<endl;
      cout << "Bigger than two, less than three";
    } // nested else
    else { // to nested if
      cout << "a_long:"<<a_long<<endl;
      cout << "is less than two"<<endl;
    }// of outer if
  }
  else // to outer if
    cout << "a_double:"<<a_double<<" is bigger that "<<a_long<<endl;
         
} // of main 
    