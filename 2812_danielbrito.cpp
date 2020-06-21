// https://www.urionlinejudge.com.br/judge/en/problems/view/2812

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n, m, x, i, j, len;
  
  cin >> n;
  
  while(n--){
    
    vector<int> v;
    
    cin >> m;
    
    while(m--){
      
      cin >> x;
      
      // Storing just odd values:
      if(x%2==1) v.push_back(x);
    }
    
    // Sorting the array to optimize the result printing:
    sort(v.begin(), v.end());
    
    // Storing the size to avoid multiple function calls:
    len = v.size();
    
    // None of the values were odd:
    if(len==0){
      
      cout << "\n";
    }
    // Otherwise, we'll have some logic:
    else{
      
      // If the array has an even amount of numbers we just need 'intercalate' them:
      if(len%2==0){
        
        // We set up the 'j' to go from right to left (descending order) and 'i' to go from left to right (ascending order).
        // Then, we traverse the array until they achieve its middle point.
        for(i=0, j=len-1; i<=j; i++, j--){
          
          cout << v[j] << " " << v[i];
          
          // Here, we just need to print the space if it's not the last number of the sequence:
          if(i<j-1){
            
            cout << " ";
          }
        }
      }
      // Otherwise, we have to change the process a little bit:
      else{
        
        // Here, we do the same as before:
        for(i=0, j=len-1; i<=j; i++, j--){
          
          // Then, we print all the numbers from right to left and left to right (again) until 'i' is different of 'j'.
          if(i!=j){
            
            cout << v[j] << " " << v[i] << " ";
          }
          // When they become equal, we just need to print the value at the 'j' position.
          // Now, notice that the value at the 'i' position is the same as in the 'j' position.
          // In other words, it'd be printed twice. 
          else{
            
            cout << v[j];
          }
        }
      }
      
      cout << "\n";
    }
  }
  
  return 0;
}
