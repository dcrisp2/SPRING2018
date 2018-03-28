#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iterator>
using std::back_inserter; using std::ostream_iterator; using std::distance;
#include<functional>
using std::greater;
#include<algorithm>
using std::sort; using std::binary_search; using std::lower_bound;
using std::next_permutation;

// weird, compare on last letter
bool cmp_fn(string s1, string s2){
  return s1.back() < s2.back();
}

int main(){
  vector<string> v_s={"this","is","a","big","hard","long","test","a","nasty","test"};
  sort(v_s.begin(), v_s.end());
  copy(v_s.begin(), v_s.end(), ostream_iterator<string>(cout, ", "));
  cout << endl;

  // functional, now in largest to smallest order
  sort( v_s.begin(), v_s.end(), greater<string>() );
  copy(v_s.begin(), v_s.end(), ostream_iterator<string>(cout, ", "));
  cout << endl;
  
  // cmp, less than on last character in string
  sort(v_s.begin(), v_s.end(), cmp_fn);
  copy(v_s.begin(), v_s.end(), ostream_iterator<string>(cout, ", "));
  cout << endl;

  // lambda, compare on string length
  sort(v_s.begin(),
       v_s.end(),
       [](const string& s1, const string& s2){
	   return s1.size() < s2.size();
       }
    );
  copy(v_s.begin(), v_s.end(), ostream_iterator<string>(cout, ", "));
  cout << endl;

  // algorithms requiring sorted
  vector<long> v_l{1,2,3,4,5,6,7,8,9,10};
  cout << boolalpha;

  cout << "Is 5 there? " << binary_search(v_l.begin(), v_l.end(), 5) << endl;
  cout << "Is 100 there? " << binary_search(v_l.begin(), v_l.end(), 100) << endl;

  auto val = lower_bound(v_l.begin(), v_l.end(), 7.5);
  if (*val == 7.5){
    cout << "7.5 is already in there" << endl;
    cout << "Index is:" << distance(v_l.begin(), val) << endl;
  }
  else{
    cout << "7.5 would go between " << *(val-1) << " and " << *val << endl;
    cout << "Thats between index: "<< distance(v_l.begin(), val-1)
	 << " and " << distance(v_l.begin(), val) << endl;
  }

  long permutation_cnt = 1; // the present sorted version counts
  next_permutation( v_l.begin(), v_l.end() );
  copy(v_l.begin(), v_l.end(), ostream_iterator<long>(cout, ", ") );
  cout << endl;
  next_permutation( v_l.begin(), v_l.end() );
  copy(v_l.begin(), v_l.end(), ostream_iterator<long>(cout, ", ") );
  cout << endl;
  next_permutation( v_l.begin(), v_l.end() );
  copy(v_l.begin(), v_l.end(), ostream_iterator<long>(cout, ", ") );
  cout << endl;

  // do until back to sorted
  while (next_permutation( v_l.begin(), v_l.end() ) )
    permutation_cnt++;
  // add the one outside the loop
  cout << endl << permutation_cnt+3 << " permutations"<<endl;
}
