#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  /*l_linha corresponde ao lambda linha*/
  double l_linha,s,v,c=300000000;

  cin >> v;

  s=((sqrt((c-v)/(c+v)))-1);/*Parte à direita da equação*/
  l_linha=700*(s+1);/*Equação isolando o lambda linha*/

  if (l_linha<400) cout << "invisivel\n";
  if (l_linha>=400 && l_linha<425) cout << "violeta\n";
  if (l_linha>=425 && l_linha<445) cout << "anil\n";
  if (l_linha>=445 && l_linha<500) cout << "azul\n";
  if (l_linha>=500 && l_linha<575) cout << "verde\n";
  if (l_linha>=575 && l_linha<585) cout << "amarelo\n";
  if (l_linha>=585 && l_linha<620) cout << "laranja\n";
  if (l_linha>=620 && l_linha<750) cout << "vermelho\n";
  if (l_linha>=750) cout << "invisivel\n";

  return 0;
}
