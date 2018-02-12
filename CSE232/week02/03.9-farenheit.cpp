#include <iostream>
using std::cout;using std::cin;using std::endl;using std::fixed;
#include <iomanip>
using std::setprecision;using std::setw;

/*
  wfp 7/23/13
  wfp updated 1/19/15
  for loops and setw
   Purpose:  Display tables of equivalent temperatures.
   Output:   The tables of temperatures in Fahrenheit and celsius
*/


int main(){
  long fahren;          // temperature in degrees fahrenheit
  double celsius;      // temperature in degrees celsius
  long lower, upper;    // lower, upper bounds on range of fahrenheit temps

  cout << fixed << setprecision( 1 );

  cout << endl;
  cout << "Degrees F    Degrees C" << endl;
  cout << "---------    ---------" << endl;

  for (fahren = -20; fahren <= 170; fahren += 10){
    celsius = (5.0 / 9.0) * double (fahren - 32);
    cout << setw( 9 ) << fahren << "    " << setw( 9 ) << celsius << endl;
  }

  cout << endl;
  cout << "Degrees F    Degrees C" << endl;
  cout << "---------    ---------" << endl;

  for (celsius = 100.0; celsius > 0.0; celsius -= 5){
    fahren = static_cast<long>( celsius * 1.8 + 32.0);
    cout << setw( 9 ) << fahren << "    " << setw( 9 ) << celsius << endl;
  }

  cout << endl << "Please enter a range of fahrenheit temperatures: ";
  cin >> lower >> upper;

  cout << endl;
  cout << "Degrees F    Degrees C" << endl;
  cout << "---------    ---------" << endl;

  for (fahren = lower; fahren <= upper; fahren += 10){
    celsius = (5.0 / 9.0) * double (fahren - 32);
    cout << setw( 9 ) << fahren << "    " << setw( 9 ) << celsius << endl;
  }
}
