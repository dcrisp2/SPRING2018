#ifndef CLOCK_H
#define CLOCK_H

#include<string>
using std::string;

struct Clock{
  int minutes;
  int hours;
  string period;
};

string clk_to_string(const Clock &c);

#endif
