#include<iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::sin; using std::acos; using std::abs; using std::pow;

const long double pi = acos(static_cast<long double>(-1));

// formula of the graph
double fn(double x){
  return -6*(x*x) + 5*x + 3;
}

// integral of fn
double integral(double x){
    return -2*pow(x,3)+5/2.0*pow(x,2) + 3*x;
}

/* use trapezoids to estimate the area under a curve
 * the interval will be from a to b (0 to 1 for the lab)
 * N is the number of trapezoids for estimation
 * higher N gives more accurate estimates
 */
double trap(double a, double b, long N){
  double interval = (b-a)/N;
  double result = fn(a);
  for(double i=a+interval;i<b;i+=interval){
    result += 2*fn(i);
  }
  result += fn(b);
  result = (result * interval)/2.0;
  return result;
}

int main(){
  double b = 1.0, a = 0.0;
  double true_val;
  double result;
  double tolerance;
  long traps;

  cout << fixed << setprecision(6);

  // calculate the true area with integrals
  true_val = integral(b) - integral(a);
  /*  cout << "Tolerance:";
  cin >> tolerance;
  cout << "Initial trapezoid count:";
  */
  cin >> tolerance >> traps;
  result = trap(0,1,traps);
  /* add more trapezoids until you get the desired tolerance between
     the true value and estimation */
  while (abs(true_val - result) > tolerance){
    // cout << "Result:"<<result<<", traps:"<<traps<<", diff:"<<abs(true_val -result)<<endl;
    traps *= 2;
    result = trap(0,1,traps);
  }
  // cout << "Trap count:"<<traps<<", estimate:"<<result<<", exact:"<<true_val<<", tolerance:"<<tolerance<<endl;
  cout <<traps<<" "
       <<result<<" "
       <<true_val<< " "
       <<tolerance<<endl;

  // cout << fn(123) << endl;
  // cout << integral(123) << endl;
}