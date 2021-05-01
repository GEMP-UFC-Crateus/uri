// https://www.urionlinejudge.com.br/judge/en/problems/view/2544

#include <bits/stdc++.h>

using namespace std;

int main(){
   
  int n;
  
  while(cin >> n){
    
    // Just a little mathematical insight, beacause the number of clones grows exponentially:
    cout << log2(n) << "\n";
  }
  
  return 0;
}