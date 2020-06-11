#include <iostream>
#include <vector>

using namespace std;

/*Estrutura para armazenar os pontos*/
struct Ponto{
    int x;/*Coordenada X do ponto*/
    int y;/*Coordenada Y do ponto*/
};

/*Fun��o para retornar o m�nimo entre dois par�metros*/
int min (int a, int b){
    if (a<=b) return a;
    else return b;}

/*Fun��o para retornar o m�ximo entre dois par�metros*/
int max (int a, int b){
    if (a>=b) return a;
    else return b;}

/*Fun��o que verifica se a propriedade existe ou n�o para aquela inst�ncia*/
int verifica (int c, int m, int n){

    bool v=0;
    int a,b,i,j,k,z,x,y,q1,q2,q3,q4;
    bool mat[m+2][n+2];/*Mapa de todos os pontos do plano cartesiano*/

    /*Inicializando todos os pontos como n�o existentes*/
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            mat[i][j]=false;
    }
    }

    Ponto p[c+1];/*Vetor com c posi��es do tipo Ponto*/

    i=0;
    while (i<c){/*Captura os c pontos*/
        cin >> a >> b;

        (p[i].x)=a;/*Eixo x do ponto*/
        (p[i].y)=b;/*Eixo y do ponto*/
        mat[a][b]=true; /*Marca aquele ponto como existente*/
        i++;
    }

    if (c==1) {return 1;}/*Se tiver s� um ponto, a propriedade � verdadeira por vacuidade.*/

    else{

    for(i=0;i<c-1;i++){

        for(j=i+1;j<c;j++){

          v=0;/*Teste para um novo par. Se esse zero n�o for substitu�do, ent�o o par (i,j) n�o atende �
          propriedade*/

          if (p[i].x==p[j].x || p[i].y==p[j].y) {v=1;}/*Mesma linha ou mesma coluna*/

          else{/*Se n�o est�o na mesma linha ou coluna, temos que procurar algum ponto dentro do "quadrado"*/
              q1=min(p[i].x,p[j].x); /*Linha do canto esquerdo inferior*/
              q2=min(p[i].y,p[j].y); /*Coluna do canto esquerdo inferior*/
              q3=max(p[i].x,p[j].x); /*Linha do canto esquerdo superior*/
              q4=max(p[i].y,p[j].y); /*Coluna do canto esquerdo superior*/

              for (k=q1;k<=q3;k++){/*Verifica se algu�m est� no ret�ngulo formado pelos pontos i e j*/

                  for (z=q2;z<=q4;z++){/*Verifica se algu�m est� no ret�ngulo formado pelos pontos i e j*/

                      if (mat[k][z]==true){

                         if ( ((k!=p[i].x) || (z!=p[i].y)) && ((k!=p[j].x) || (z!=p[j].y)) ){
                             v=1;/*Sinaliza que existe um ponto dentro do "quadrado" que n�o � nem i e nem j*/
                             k=q3+1;/*Para sair do for*/
                             z=q4+1;/*Para sair do for*/
                        }
                }
            }
        }

    }
        /*Se v==0, ent�o i e j n�o atendem � propriedade*/
        if (v==0) {return 0;}
    }
}

/*Se chegou at� aqui, ent�o possui a propriedade.*/
if (v==1) return 1;}
}

int main()
{
    int i,a,b,c;
    vector<string> saida;/*Vetor para guardar as sa�das a serem exibidas*/

while (cin >> a >> b >> c){/*Enquanto estiver lendo entrada...*/

     /*Chama a fun��o para verificar a propriedade. Se a fun��o retorna 0, n�o possui a propriedade.*/
     if (verifica(c,a,b)==0) {saida.push_back("N");}
     /*Se retorna 1, possui a propriedade*/
     else {saida.push_back("Y");}}

    /*Imprime as sa�das armazenadas*/
    i=0;
    while (i<saida.size()){
        cout << saida[i] << "\n";
        i++;
    }
    return 0;
}
