#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<numeric>
using std::accumulate;
#include<random>
using std::random_device; using std::mt19937_64;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
#include<algorithm>
using std::max_element; using std::min_element; using std::count;


int main (){

  random_device rd;
  // cout << rd.entropy() << endl;
  cout << rd() << endl;

  // default_random_engine reng( rd() );
  mt19937_64 reng ( rd() );

  uniform_int_distribution<long> int_dist(1,100);
  normal_distribution<double> norm_dist(10,2);

  size_t sz=100000;
  vector<long> v_l(sz);
  vector<double> v_norm(sz);

  for(size_t i=0; i<sz; ++i){
    v_l[i] = int_dist(reng);
    v_norm[i] = norm_dist(reng);
  }

  cout << "int avg:"<< accumulate(v_l.begin(), v_l.end(), 0.0)/sz << endl;
  cout << "int max:"<< *max_element(v_l.begin(), v_l.end() ) << endl;
  cout << "int min:"<< *min_element(v_l.begin(), v_l.end() ) << endl;
  cout << "number of 100's:"<< count(v_l.begin(), v_l.end(), 100 ) << endl;
  cout << "number of 1's:"<< count(v_l.begin(), v_l.end(), 1 ) << endl;
  cout << "norm avg:"<< accumulate(v_norm.begin(), v_norm.end(), 0.0)/sz << endl;
  cout << "norm max:"<< *max_element(v_norm.begin(), v_norm.end() ) << endl;
  cout << "norm min:"<< *min_element(v_norm.begin(), v_norm.end() ) << endl;  
  
}
