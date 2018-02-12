#include<iostream>
using std::cout; using std::endl; using std::cin; using std::fixed;
#include<cmath>
using std::sqrt; using std::abs;
#include<iomanip>
using std::setprecision;
/*
  wfp, 8/11/13
  newton iterative approximation, square root
*/

int main (){
  double start_num, guess;
  long iterations, i;

  cout << "Square root of what number:";
  cin >> start_num;
  cout << "How many iterations:";
  cin >> iterations;
  
  guess = start_num/2;
  for (i=0;i<iterations;i++)
    guess = 0.5 * (start_num/guess + guess);

  cout << fixed << setprecision(10);
  cout << "Guessing sqrt of "<< start_num <<" is:" << guess << endl;
  cout << "C++ math routine says:"<< sqrt(start_num) <<endl;
  cout << "Difference is:"<< sqrt(start_num) - guess <<endl;
}