#include<iostream>
using std::cout; using std::endl; using std::cin;
/*
  wfp, 8/11/13
  swap functions, pass pointers
*/

void swap (long *first, long *second){    // params are pointers
  // a pointer is a variable, whose value is a memory address
  long temp;
  cout << "Value of first is:"<<first<<" which references "<<*first << endl;
  temp = *first;         // must derefernce a pointer with *
  *first = *second;
  *second = temp;
}

int main (){
  long one=100, two=200;
  cout << "Pre swap, one has value:"<<one<<", two has value:"<<two<<endl;
  swap(&one, &two);   // here & is an operator, address-of
  cout << "Post swap, one has value:"<<one<<", two has value:"<<two<<endl;

}
