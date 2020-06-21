#include <iostream>
#include <limits>

using namespace std;

int main(){

  int n;
  
  // Here, we have to pay attention to use the correct data types.
  // Notice that the minimum value is initialized with a huge number.
  // In this way, we guarantee that any input will be smaller than this first value.
  double p, g, x, min=numeric_limits<float>::max();
  
  cin >> n;
  
  while(n--){
    
    cin >> p >> g;
    
    // Using the formula 'given' in the text:
    x = (1000/g)*p;
    
    // If 'x' is smaller than 'min', we update the value of 'min':
    if(x<min) min = x;
  }
  
  // Finally, we print the result with two decimal places:
  printf("%.2f\n", min);
  
  return 0;
}
