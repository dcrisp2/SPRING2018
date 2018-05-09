#include<iostream>
using std::cout; using std::endl;
#include<iomanip>
using std::setw; using std::left; using std::right;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "lab07_functions.h"

// Return string representation of matrix
string matrix_to_str(const matrix &m1, size_t width){
  ostringstream oss;
  oss << right;
  for (auto row : m1){ // For every row
    for (auto e : row) // For every element in row
      oss << setw(width) << e; // Output with certain width
    oss << endl;
  }
  string s = oss.str(); // Convert to string to return
  s = s.substr(0, s.size()-1); //Remove last endl
  return s;
}

// Check if two matricies are same size
bool same_size(matrix &m1, matrix &m2){
  // cout << "inside same size" << endl;
  if ( m1.size() != m2.size() ){ // Check for num of rows
    // cout << "row diff" << endl;
    return false;
  }
  else
		// Check for number of elements in row
    for(size_t i = 0; i<m1.size(); ++i)
      if (m1[i].size() != m2[i].size()){
				// cout << "col diff" << endl;
      	return false;
      }
  return true;
}

// Add two matricies together
matrix add(matrix &m1, matrix &m2){
  // cout << "add" << endl;
  matrix result;
  if (m1.empty() == false){
    // cout << "not empty" << endl;
    if (same_size(m1,m2) ){ // Have to be same size to add
      // cout << "same size" << endl;
      size_t row_cnt = m1.size();
      size_t col_cnt = m1[0].size();
      matrix_row row;
      for (size_t i = 0; i<row_cnt; ++i){
				for (size_t j = 0; j<col_cnt; ++j)
			  	row.push_back(m1[i][j] + m2[i][j]); // Add matching indecies
				result.push_back(row); // Add row onto index
				row.clear(); // Clear row for next additions
      }
    }
  }
  return result;
}

// Do scalar multiplication on a matrix
matrix scalar_multiply(matrix &m, long val){
  if (! m.empty() ){
    matrix_row r;
    matrix result;
    for (auto row : m){
      for (auto e : row)
				r.push_back(e * val); // Multiply elemenet by constant
      result.push_back(r);
      r.clear();
    }
    return result;
  }
  else
    return m;
}