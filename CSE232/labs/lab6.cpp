#include<vector>
using std::vector;
#include<iterator>
using std::ostream_iterator;

#include "vecops-functions.h"

vector<long> vector_ops(const vector<long>& v1, const vector<long>& v2, char op){

  // Want to keep track of the shorter vector to make sure indecies match
  vector<long> shorter, longer;
  if (v1.size() < v2.size()){
    shorter = v1;
    longer = v2;
  }
  else{
    longer = v1;
    shorter = v2;
  }

  vector<long> result;
  long temp;
  unsigned int i;

  // Has to be + or - operation, return empty vector
  if ((op != '+') && (op != '-'))
    return result;
  else{
    // Add or subtract elements of matching index
    for (i=0; i<shorter.size(); ++i){
      if (op == '+')
	temp = longer[i] + shorter[i];
      else
	temp = longer[i] - shorter[i];
      result.push_back(temp);
    }
    // Push back the rest
    for (; i<longer.size(); ++i)
      result.push_back(longer[i]);
  }
  return result;
}

void print_vector(ostream &out, const vector<long> &v){
  copy(v.begin(), v.end(), ostream_iterator<long>(out, "\n") );
}