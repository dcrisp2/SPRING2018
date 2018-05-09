#include<cmath>
#include<string>
using std::sqrt;
using std::string; using std::to_string;

#include "lab09_vector.h"

// Constructor
MathVector::MathVector(long xval, long yval){
  x=xval;
  y=yval;
}

// Add two vectors together
MathVector MathVector::add(const MathVector &v2){
  MathVector result;
  result.x = x + v2.x; // Add x parts
  result.y = y + v2.y; // Add y parts
  return result;
  //return MathVector(x + v2.x, y + v2.y);
}

// Scalar multiplication
MathVector MathVector::mult(long scalar){
  MathVector result;
  result.x = x * scalar; // Multiply x by constant
  result.y = y * scalar; // Multiply y by constant
  return result;
  // return MathVector(x * scalar, y * scalar);
}

// Dot product
// You can overload functions where they have the same name
// but different function bodies for different input
long MathVector::mult(const MathVector &v2){
  return (x*v2.x) + (y*v2.y);
}

double MathVector::magnitude(){
  return sqrt((x*x) + (y*y));
}

string vec_to_str(const MathVector &v){
  return to_string(v.x)+":"+to_string(v.y);
}