#include<iostream>
using std::cout; using std::endl;
#include<random>
using std::mt19937_64;
using std::uniform_int_distribution;
using std::random_device;

int roll_dice(mt19937_64& reng){
  uniform_int_distribution<int> dist(1,6);
  return dist(reng);
}

int main(){
  long snake_eyes=0, sevens=0, rolls=100000;
  int die1, die2;
  random_device rd;
  mt19937_64 reng( rd() );
  
  for(int i=0; i<rolls; i++){
    die1 = roll_dice(reng);
    die2 = roll_dice(reng);

    if (die1 == 1 && die2 == 1)
      ++snake_eyes;
    else if (die1 + die2 == 7)
      ++sevens;
  }
  cout << snake_eyes << " snake eyes and " << sevens
       << " sevens in "<< rolls << " rolls" << endl;
}
