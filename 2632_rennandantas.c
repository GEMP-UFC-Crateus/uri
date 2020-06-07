#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*Fun��o para verificar se o ret�ngulo � alcan�ado pela circunfer�ncia*/
int verifica(int r, int x0, int y0, int x1, int y1, int cx, int cy){

bool v=0;
int i;
signed long int a,b,c,d;
double r1,r2;

/*Trataremos o ret�ngulo como 4 retas. Consideraremos a reta inteira e n�o somente o segmento de reta que forma o ret�ngulo.
Para descobrir se existe intersec��o entre o ret�ngulo e a circunfer�ncia, verificaremos se existe intersec��o entre cada uma das
retas com a cirfunfer�ncia. A intersec��o entre a equa��o de cada reta e a equa��o da circunfer�ncia, gera uma fun��o do segundo grau.
Aplicaremos Bh�skara para descobrir se existem pontos de intersec��o e, se existem, quantos e quais s�o. Depois verificaremos se esses
pontos pertencem ao ret�ngulo.*/

/*Equa��o da reta x0: xo � a coordenada no eixo x do primeiro ponto do ret�ngulo. Passado pelo usu�rio.*/

/*Definindo os coeficientes para aplicar Bh�skara. � conseguido a partir da equa��o da intersec��o entre a reta e a circunfer�ncia.*/
a=1;
b=-2*cy;
c=pow(x0,2)-(2*x0*cx)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*C�lculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){/*Existe pelo menos um ponto de intersec�o*/

    r1=((-b-sqrt(d))/(2*a));/*primeira coordenada y da circunfer�ncia que intersecta a reta*/
    r2=((-b+sqrt(d))/(2*a));/*segunda coordenada y da circunfer�ncia que intersecta a reta*/

    /*Verifica se essa(s) coordenada(s) y est�(�o) entre a menor e a maior coordenada y do ret�ngulo. Se
    estiver(em), ent�o o ret�ngulo � alcan�ado pela circunfer�ncia. O que faremos para a equa��o das retas x1,y0 e y1 � semelhante.*/
    if (r1<=y1 && r1>=y0) {v=1;}
    else {if (r2<=y1 && r2>=y0) {v=1;}}
}

/*Equa��o da reta x1*/

/*Definindo os coeficientes para aplicar Bh�skara*/
a=1;
b=-2*cy;
c= pow(x1,2)-(2*x1*cx)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*C�lculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada y da circunfer�ncia que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada y da circunfer�ncia que intersecta a reta

    if (r1<=y1 && r1>=y0) {v=1;}
    else {if (r2<=y1 && r2>=y0) {v=1;}}
}

/*Equa��o da reta y0*/

/*Definindo os coeficientes para aplicar Bh�skara*/
a=1;
b=-2*cx;
c= pow(y0,2)-(2*y0*cy)+pow(cx,2)+pow(cy,2)-pow(r,2);

/*C�lculo do delta*/
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada x da circunfer�ncia que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada x da circunfer�ncia que intersecta a reta

    if (r1<=x1 && r1>=x0) {v=1;}
    else {if (r2<=x1 && r2>=x0) {v=1;}}
}

/*Equa��o da reta y1*/

/*Definindo os coeficientes para aplicar Bh�skara*/
a=1;
b=-2*cx;
c= pow(y1,2)-(2*y1*cy)+pow(cx,2)+pow(cy,2)-pow(r,2);

//C�lculo do delta
d=pow(b,2)-(4*a*c);

if (d>=0){

    r1=((-b-sqrt(d))/(2*a));//primeira coordenada x da circunfer�ncia que intersecta a reta
    r2=((-b+sqrt(d))/(2*a));//segunda coordenada x da circunfer�ncia que intersecta a reta

    if (r1<=x1 && r1>=x0) {v=1;}
    else {if (r2<=x1 && r2>=x0) {v=1;}}
}

/*Apesar de todos os testes que fizemos at� aqui, existem duas possibilidades que os testes acima n�o conseguem identificar: o caso em que
a circunfer�ncia est� totalmente dentro do ret�ngulo e o caso em que o ret�ngulo est� totalmente dentro da circunfer�ncia. Nesses
dois casos, n�o h� intersec��o entre a borda dos dois.*/

/*Teste para ver se a circunfer�ncia est� dentro do ret�ngulo*/
if ((x0<=cx) && (cx<=x1) && (y0<=cy) && (cy<=y1)) {v=1;}

/*Teste para verificar se oquadrado est� totalmente dentro da circunfer�ncia.*/
if (v==0){
   if ((x0>=cx-r) && (x0<=cx+r) && (y0>=cy-r) && (y0<=cy+r) && (x1<=cx+r) && (x1>=cx-r)  && (y1>=cy-r) && (y1<=cy+r))
   {v=1;}
}

/*Se passou em algum dos testes, ent�o v recebeu 1.*/

if (v==1) {return 1;}
else {return 0;}
}

int main()
{
    int x0,y0,x1,y1,cx,cy,l,k,v,w,h,T;
    string tipo;
    vector<int> dano;/*Dano que a torre causa*/

    cin >> T;/*N�mero de entradas informadas pelo usu�rio*/

    for (k=0;k<T;k++){

    cin >> w >> h >> x0 >> y0;/*Cada linha da entrada s�o 4 inteiros*/

    cin >> tipo >> l >> cx >> cy;/*Na linha seguinte, temos mais uma string e tr�s inteiros*/
    /*A partir da largura e da altura do ret�ngulo e das coordenadas de origem, constru�mos as coordenadas m�ximas do mesmo*/
    x1=x0+w;
    y1=y0+h;

    if (tipo=="fire"){/*Se for do tipo fogo, ent�o verifica o n�vel...*/
        if (l==1){/*Se estiver no n�vel 1,ent�o o alcance da torre � 20. Passamos esse valor e as demais coordenadas para a
            fun��o verifica. Se a fun��o verifica identificar que o ret�ngulo n�o � alcan�ado pela cirfunfer�ncia, ent�o
            o dano 0 causado pela torre vai para o vetor de danos causados. Caso contr�rio, quem vai para o vetor � o valor 200.
            Para os demais n�veis e tipos de torre, a verifica��o ser� semelhante.*/
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
