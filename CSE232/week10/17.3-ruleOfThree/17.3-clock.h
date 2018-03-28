#ifndef CLOCK_H
#define CLOCK_H

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::ostream;

class Clock{
 private:
  int minutes_ = 0;
  int hours_ = 0;
  string period_;
  void adjust_clock(int, int, string);
  
 public:
  Clock()=default;
  Clock(int, int, string);
  explicit Clock(string s);
  ~Clock() {};         // destructor. Does nothing yet  

  Clock(const Clock&); // copy constructor

  // overloaded operator= method
  Clock& operator=(const Clock&);

  // getters
  int hours() const {return hours_;}
  int minutes() const {return minutes_;}
  string period() const {return period_;} 
  
  // setters, defined elsewhere
  void hours(int);
  void minutes(int);
  void period(string);
  
  // members
  void add_minutes(int);

  
  // friends
  friend string clk_to_string(const Clock &);
};

// plain functions
string clk_to_string(const Clock &);
void split(const string &, vector<string> &, char);

#endif
