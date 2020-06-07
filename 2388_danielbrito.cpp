// https://www.urionlinejudge.com.br/judge/en/problems/view/2388

#include <iostream>

using namespace std;

int main(){

  int n, t, v;
  long int totalDistance=0;
  
  cin >> n;
  
  while(n--){
    
    cin >> t >> v;
    
    // They pratically give the solution in the text:
    totalDistance += v*t;
  }
  
  cout << totalDistance << "\n";
  
  return 0;
}
