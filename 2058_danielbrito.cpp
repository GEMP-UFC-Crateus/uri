// https://www.urionlinejudge.com.br/judge/en/problems/view/2058

#include <iostream>

using namespace std;

int main(){
  
  unsigned long long int n, sumAngles=0;

  cin >> n;
  
  // The sum of the internal angles of a convex polygon (with n sides) is given by: (n-2)*180°
  sumAngles = (n-2)*180;
  
  // Finally, knowing that the sum of the internal angles of a triangle is 180°, we just need to divide:
  cout << sumAngles/180 << "\n";
  
  return 0;
}
