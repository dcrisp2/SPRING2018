#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<fstream>
using std::ifstream; using std::ofstream;

template<typename T>
void print_val(ostream& out, T val){
  out << val << endl;
}

int main (){
  ifstream in_file ("infile.txt");
  ofstream out_file;
  out_file.open("outfile.txt");

  long l;
  if (in_file && out_file){
    while (in_file >> l){
      print_val(out_file, l);
    }
    print_val(out_file, "the end");
    print_val(cout, "finished");
  }
  else
    cout << "A file didn't open" << endl;
  
  if ( in_file.is_open() )
    in_file.close();
  if ( out_file.is_open() )
    out_file.close();
}
