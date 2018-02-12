#include<iostream>
using std::cout;using std::endl;
/*
wfp, 7/16/13
basic pointers
*/

int main (){

  long my_long = 123;
  long *p_long = nullptr;
  long *ptr_long, a_long; // * means pointer, a_long just an long
  double my_double = 3.14159, *p_double;

  cout << "Size of long ptr:"<<sizeof(p_long)<<endl;
  cout << "Size of double ptr:"<<sizeof(p_double)<<endl;
  
  // & is "address of"
  cout << "Before setting pointer value"<<endl;
  cout << "Addr of long:"<<&my_long<<", Val of long:"<<my_long<<endl;
  cout << "Addr of ptr:"<<&p_long<<", Val of ptr:"<<p_long<<endl;
  p_long = &my_long;
  cout << "After setting pointer value"<<endl;
  cout << "Addr of long:"<<&my_long<<", Val of long:"<<my_long<<endl;
  cout << "Addr of ptr:"<<&p_long<<", Val of ptr:"<<p_long<<endl;

  // * is "points to"
  cout << "Val of ptr:"<<p_long<<", ptr points to:"<<*p_long<<endl;
  *p_long = 456;     // change the value which p_long "points to"
  cout << "Val of long:"<<my_long<<", val of ptr:"<<*p_long<<endl;

  // now a reference
  long &r_long = *p_long;  // p_long is obj, so is what it points to. So OK
  cout << "Addr of long:"<<&my_long<<", Val of long:"<<my_long<<endl;
  cout << "Addr of ptr:"<<&p_long<<", Val of ptr:"<<p_long
       <<", Pointer points to:"<< *p_long<<endl;
  cout << "Addr of ref:"<<&r_long<<", Val of ref:"<<r_long<<endl;

}