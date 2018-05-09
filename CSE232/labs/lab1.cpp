/*
 wfp 8/27/13
 Voyager calculation
 */

#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
  long days;
  double distance_km, distance_mi;
    const double au_distance = 39.33;
    const double km_per_sec = 14.24;
    const double mi_per_sec = 8.85;
    const long km_per_au = 149598000;
    const long mi_per_au = 92955800;
    const double sol_km_sec = 299792.458;
    // const double miles_per_km = 0.621371;
    const long sec_in_day = 24 * 60 * 60;
    // cout << "Enter the number of days since 09-19-14:";
    cin >> days;
		// calculate the distance in km
    distance_km = (au_distance * km_per_au) + (km_per_sec * sec_in_day * days);
		// calculate the distance in mi
    distance_mi = (au_distance * mi_per_au) + (mi_per_sec * sec_in_day * days);
		// output as fixed and to 2 decimal points
    cout << fixed << setprecision(2);
    cout <<  distance_km << endl;
    cout << distance_mi << endl;
		// calculate the round trip
    cout << 2.0 * (distance_km/sol_km_sec) / 3600 << endl;
}