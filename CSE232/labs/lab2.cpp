#include<iostream>
using std::cout; using std::cin; using std::endl;

int main () {
    long num;
    long sum;
    long cnt;

    cin >> num;
    // error if negative number
    if (num <= 0)
      cout << "Error"<<endl;
    // single digit only has an additive persistance of 0 and additive root is the number
    else if (num < 10){
      cout << 0 << " " << num << endl;
    }
    // calculate additive persistance and root
    else{
      while (num >= 10){
        cnt = 0;
        // cout << "Additive root"<<endl;
        // repeatedly find the sum of the digits until it is a single digit
        while (num >= 10){
          sum = 0;
          // get the sum of the digits
          while (num > 0){
            sum = sum + (num % 10); // add the last digit
            num = num/10; // remove the first digit
          }
          num = sum;
          cnt++; // count cycles for additive persistance
          // cout << "Sum:"<<sum<<", pass:"<<cnt<<endl;
        }
      }
      cout << cnt << " " << num << endl;
    }
}