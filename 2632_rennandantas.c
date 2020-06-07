#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*Função para verificar se o retângulo é alcançado pela circunferência*/
int verifica(int r, int x0, int y0, int x1, int y1, int cx, int cy){

bool v=0;
int i;
signed long int a,b,c,d;
double r1,r2;

/*Trataremos o retângulo como 4 retas. Consideraremos a reta inteira e não somente o segmento de reta que forma o retângulo.
Para descobrir se existe intersecção entre o retângulo e a circunferência, verificaremos se existe intersecção entre cada uma das
retas com a cirfunferência. A intersecção entre a equação de cada reta e a equação da circunferência, gera uma função do segundo grau.
Aplicaremos Bháskara para descobrir se existem pontos de intersecção e, se existem, quantos e quais são. Depois verificaremos se esses
pontos pertencem ao retângulo.*/

/*Equação da reta x0: xo é a coordenada no eixo x do primeiro ponto do retângulo. Passado pelo usuário.*/

/*Definindo os coeficientes para aplicar Bháskara. É conseguido a partir da equação da intersecção entre a reta e a circunferência.*/
a=1;
b=-2*cy;
c=pow(x0,2)-(2*x0*cx)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*Cálculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){/*Existe pelo menos um ponto de intersecão*/

    r1=((-b-sqrt(d))/(2*a));/*primeira coordenada y da circunferência que intersecta a reta*/
    r2=((-b+sqrt(d))/(2*a));/*segunda coordenada y da circunferência que intersecta a reta*/

    /*Verifica se essa(s) coordenada(s) y está(ão) entre a menor e a maior coordenada y do retângulo. Se
    estiver(em), então o retângulo é alcançado pela circunferência. O que faremos para a equação das retas x1,y0 e y1 é semelhante.*/
    if (r1<=y1 && r1>=y0) {v=1;}
    else {if (r2<=y1 && r2>=y0) {v=1;}}
}

/*Equação da reta x1*/

/*Definindo os coeficientes para aplicar Bháskara*/
a=1;
b=-2*cy;
c= pow(x1,2)-(2*x1*cx)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*Cálculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada y da circunferência que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada y da circunferência que intersecta a reta

    if (r1<=y1 && r1>=y0) {v=1;}
    else {if (r2<=y1 && r2>=y0) {v=1;}}
}

/*Equação da reta y0*/

/*Definindo os coeficientes para aplicar Bháskara*/
a=1;
b=-2*cx;
c= pow(y0,2)-(2*y0*cy)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*Cálculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada x da circunferência que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada x da circunferência que intersecta a reta

    if (r1<=x1 && r1>=x0) {v=1;}
    else {if (r2<=x1 && r2>=x0) {v=1;}}
}

/*Equação da reta y1*/

/*Definindo os coeficientes para aplicar Bháskara*/
a=1;
b=-2*cx;
c= pow(y1,2)-(2*y1*cy)+pow(cx,2)+pow(cy,2)-pow(r,2);

//Cálculo do delta
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada x da circunferência que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada x da circunferência que intersecta a reta

    if (r1<=x1 && r1>=x0) {v=1;}
    else {if (r2<=x1 && r2>=x0) {v=1;}}
}

/*Apesar de todos os testes que fizemos até aqui, existem duas possibilidades que os testes acima não conseguem identificar: o caso em que
a circunferência está totalmente dentro do retângulo e o caso em que o retângulo está totalmente dentro da circunferência. Nesses
dois casos, não há intersecção entre a borda dos dois.*/

/*Teste para ver se a circunferência está dentro do retângulo*/
if ((x0<=cx) && (cx<=x1) && (y0<=cy) && (cy<=y1)) {v=1;}

/*Teste para verificar se oquadrado está totalmente dentro da circunferência.*/
if (v==0){
   if ((x0>=cx-r) && (x0<=cx+r) && (y0>=cy-r) && (y0<=cy+r) && (x1<=cx+r) && (x1>=cx-r)  && (y1>=cy-r) && (y1<=cy+r))
   {v=1;}
}

/*Se passou em algum dos testes, então v recebeu 1.*/

if (v==1) {return 1;}
else {return 0;}
}

int main()
{
    int x0,y0,x1,y1,cx,cy,l,k,v,w,h,T;
    string tipo;
    vector<int> dano;/*Dano que a torre causa*/

    cin >> T;/*Número de entradas informadas pelo usuário*/

    for (k=0;k<T;k++){

    cin >> w >> h >> x0 >> y0;/*Cada linha da entrada são 4 inteiros*/

    cin >> tipo >> l >> cx >> cy;/*Na linha seguinte, temos mais uma string e três inteiros*/
    /*A partir da largura e da altura do retângulo e das coordenadas de origem, construímos as coordenadas máximas do mesmo*/
    x1=x0+w;
    y1=y0+h;

    if (tipo=="fire"){/*Se for do tipo fogo, então verifica o nível...*/
        if (l==1){/*Se estiver no nível 1,então o alcance da torre é 20. Passamos esse valor e as demais coordenadas para a
            função verifica. Se a função verifica identificar que o retângulo não é alcançado pela cirfunferência, então
            o dano 0 causado pela torre vai para o vetor de danos causados. Caso contrário, quem vai para o vetor é o valor 200.
            Para os demais níveis e tipos de torre, a verificação será semelhante.*/
           if (verifica(20,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(200);}
        if (l==2){
           if (verifica(30,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(200);}
        if (l==3){
           if (verifica(50,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(200);}
    }


    if (tipo=="water"){
        if (l==1){
           if (verifica(10,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(300);}
        if (l==2){
           if (verifica(25,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(300);}
        if (l==3){
           if (verifica(40,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(300);}
    }

    if (tipo=="earth"){
        if (l==1){
           if (verifica(25,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(400);}
        if (l==2){
           if (verifica(55,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(400);}
        if (l==3){
           if (verifica(70,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(400);}
    }

    if (tipo=="air"){
        if (l==1){
           if (verifica(18,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(100);}
        if (l==2){
           if (verifica(38,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(100);}
        if (l==3){
           if (verifica(60,x0,y0,x1,y1,cx,cy)==0) {dano.push_back(0);}
           else dano.push_back(100);}
    }
    }

    /*Mostrando na tela os danos causados*/
    k=0;
    for (k=0;k<dano.size();k++){
        cout << dano[k] << "\n";
    }
    return 0;
}
