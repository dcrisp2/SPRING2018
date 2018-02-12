#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::pow; using std::atan;
/* 
   wfp, 9/8/13
   calc radius of a circle
   const ref params
*/

double circ_area(const double &radius, const double &pi){
  // radius += 2;
  return pow(radius,2) * pi;
}

int main(){
  double r;
  const double pi = atan(1.0)*4.0;  // no pi constant in cmath
  cout << "Give me a radius:";
  cin>>r;
  cout << setprecision(15);
  cout <<"Circle of radius "<<r<<" has area of:"
       <<circ_area(r,pi)<<endl;
}
