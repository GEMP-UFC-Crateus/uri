// https://www.urionlinejudge.com.br/judge/en/problems/view/1144

#include <iostream>

using namespace std;

int main(){

  int n, count=0;
  
  cin >> n;

  for(int i=1; i<=n; i++){
    
    // Because we have to print the the value of 'i' twice (in the beginning of each line):
    while(count<2){
      
      // If it's the first line with the number 'i', we print it, then print it squared and cubed:
      if(count==0){
        
        cout << i << " " << i*i << " " << i*i*i << "\n";
        count++;
      }
      // If it's the second line with the number 'i', we just print it, then print it squared+1 and cubed+1:
      else{
        
        cout << i << " " << i*i+1 << " " << i*i*i+1 << "\n";
        count++;
      }
    }
    
    // Restarting the counter to print the next two lines of a given number in the sequence:
    count = 0;
  }
  
  return 0;
}
