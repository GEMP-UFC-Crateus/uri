// https://www.urionlinejudge.com.br/judge/en/problems/view/2982

#include <bits/stdc++.h>

using namespace std;

int main(){
  
  long long n, v, result=0;
  char c;
  
  cin >> n;
  
  while(n--){
    
    cin >> c >> v;
    
    // Checking if it's a govern grant or an university expense, and updating the 'credit':
    if(c=='G'){
      
      result -= v;
    }
    else{
      
      result += v;
    }
  }
  
  // If the result (credit) is positive, the money granted by the government covers university expenses:
  if(result>=0){
    
    cout << "A greve vai parar.";
  }
  // Otherwise, the students are going to fight in order to revert this situation:
  else{
    
    cout << "NAO VAI TER CORTE, VAI TER LUTA!";
  }
  
  cout << "\n";
  
  return 0;
}