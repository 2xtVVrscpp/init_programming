#include<iostream>
using namespace std;

int main(void){
  int length;

  cout << "length: ";
  cin >> length;

  for(int j=0;j<length;j++){
    for(int i=0;i<length-j-1;i++){
      cout << " ";
    }
    for(int i=0;i<2*j+1;i++){
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}