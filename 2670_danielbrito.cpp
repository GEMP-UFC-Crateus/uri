// https://www.urionlinejudge.com.br/judge/en/problems/view/2670

#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int a1, a2, a3;
  
  cin >> a1;
  cin >> a2;
  cin >> a3;
  
  // Calculating the time spent if the coffee machine is at the 'A1' floor:
  int resA1 = a2*2 + a3*2*2;
  
  // Calculating the time spent if the coffee machine is at the 'A2' floor:
  int resA2 = a1*2 + a3*2;
  
  // Calculating the time spent if the coffee machine is at the 'A3' floor:
  int resA3 = a1*2*2 + a2*2;
  
  // Our goal is to minimize the time spent to reach the coffee machine by the employees:
  if(resA1<=resA2 && resA1<=resA3){
    
    cout << resA1 << "\n";
  }
  else
  if(resA2<=resA1 && resA2<=resA3){
    
    cout << resA2 << "\n";
  }
  else
  if(resA3<=resA1 && resA3<=resA2){
    
    cout << resA3 << "\n";
  }
  
  return 0;
}