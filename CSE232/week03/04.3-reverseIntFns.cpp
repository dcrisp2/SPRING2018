#include<iostream>
using std::cout; using std::endl; using std::cin;
/*
  wfp, 8/11/13
  wfp update 1/26/15
  reverse an int with a function
*/


int reverse_int(long number){
  // reverse an integer using modulo math. Assumes base 10
  long result=0,remainder;
  
  while(number >= 1){
    remainder = number % 10;
    result = result * 10 + remainder;
    number /= 10;
  }
  return result;
}

int main () {
  long number, result;
  cout << "Reverse what integer:";
  cin >> number;
  result = reverse_int(number);
  cout << "The reverse of "<<number<<" is "<< result << endl;
}