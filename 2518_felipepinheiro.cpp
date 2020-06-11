#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>

using namespace std;

int main(){
int N;
float H,C,L,hip;
    while(cin >> N && cin >> H && cin >> C && cin >> L) // Utilização do EOF
    {
C = C * N; // Vou achar o comprimento do primeiro degrau ao ultimo
H = H * N; // Vou achar a altura da escada

/* O comprimento da rampa será dado por meio da diagonal do triangulo, com isso devo usar a formula
H^2 = C^2 + H^2
*/
 
hip = sqrt((C*C) + (H*H)); //Utilização da formula
hip = (hip * L) / 10000; // Metros em centimetros
cout << fixed << setprecision(4); // Formatação de 4 casa decimais
cout << hip << endl;
    }
}
