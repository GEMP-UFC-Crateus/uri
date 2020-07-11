#include <iostream>

using namespace std;

int main()
{
    int c1,c2,c3,c4,c5,c6,c7,x,notas;
    cin >> notas;
    
    x=notas;
    
    c1= x/100;
    x=(x%100);
    c2= x/50;
    x=(x%50);
    c3= x/20;
    x=(x%20);
    c4= x/10;
    x=(x%10);
    c5= x/5;
    x=(x%5);
    c6= x/2;
    x=(x%2);
    c7= x/1;
    
    cout << notas << endl;
    cout << c1 << " nota(s) de R$ 100,00" << endl;
    cout << c2 << " nota(s) de R$ 50,00" << endl;
    cout << c3 << " nota(s) de R$ 20,00" << endl;
    cout << c4 << " nota(s) de R$ 10,00" << endl;
    cout << c5 << " nota(s) de R$ 5,00" << endl;
    cout << c6 << " nota(s) de R$ 2,00" << endl;
    cout << c7 << " nota(s) de R$ 1,00" << endl;
    
    return 0;
}
