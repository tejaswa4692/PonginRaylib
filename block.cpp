#include <iostream>
using namespace std;

class block{
  public:
    int l = 30;
    int w = 20;
    
    int findarea(){
      return l * w;
    }

};



int main (int argc, char *argv[]) {
  block myepicblock;
  int area = myepicblock.findarea();
  cout << area;
  return 0;
}
