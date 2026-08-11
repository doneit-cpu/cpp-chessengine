// transfer all the moves here chess piece moves

#include<iostream>
#include<vector>
#include<random>
using namespace std;

void jojo(int &i) {
    int x=i-59;  // king number - 9 -given postion in inner circle 
    x=abs(x);     
    cout << x << "\n";
    int y=(x/8)*3+(x-(x/8)*8);   // (x-(x/8)*8) this work like remaider , and at y is number of map key which repesent the king inner circle 
    cout << y << "\n";
}


int main(){
  int n;
  cin >> n;
  vector<vector <int>> a(n);
  a.reserve(n);
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a[i].push_back(i*n+j);
        
      }        
  }
  for(auto i: a){
    for(auto j: i){
      cout << j  << " ";
    }
    cout << "\n";
  }

  int j=3;
  for(int i=0;i<3;i++){
    jojo(random())
  }

  return 0;

}