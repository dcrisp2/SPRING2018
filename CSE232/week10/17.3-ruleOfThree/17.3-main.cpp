#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;

#include "17.3-clock.h"

int main(){
    Clock my_clk;                
    Clock a_clk(2,2,"AM");
    Clock cpy_clk(a_clk);       // direct call to copy
    a_clk.add_minutes(10);
    cout << "Orig:"<< clk_to_string(a_clk) << endl
	 << "Copy:" << clk_to_string(cpy_clk) << endl;

    my_clk = a_clk;             // assign op
    cout <<"Assign result:"<< clk_to_string(my_clk) << endl;

    Clock test_clk(30,6,"PM");
    my_clk = a_clk = test_clk;
    cout <<"Chain result:"<< clk_to_string(my_clk) << endl
	 << ", "<< clk_to_string(a_clk) <<endl
	 << ", "<< clk_to_string(test_clk) << endl;

}
