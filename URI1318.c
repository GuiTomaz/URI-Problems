#include <stdio.h>
#include <stdlib.h>
void ordena(int* lista, int tam);
void busca(int* lista, int tam);
int main(void){
  int N,M;
  while(N!=0 && M !=0){
    scanf("%d%d",&N,&M);
    if(M == 0 && N == 0){
      break;
    }
    int v[M];
    for(int i = 0;i<M;i++){
      scanf("%d",&v[i]);
    }
    ordena(v, M);
    busca(v, M);
  }
  return 0;
}

void ordena(int* lista, int tam){
  int aux;
  for(int i =0;i<tam;i++){
    for(int k =i+1;k<tam;k++){
      if(lista[i]>lista[k]){
        aux = lista[i];
        lista[i] = lista[k];
        lista[k] = aux;
      }
    }
  }
}

void busca(int* lista, int tam){
  int inicio = 0;
  int meio = (tam-inicio)/2; // 2
  int rep = 0;
  int ultimoRep = 0;
  int salto;
  //Para casos em que tenhamos numeros repetidos ate o meio da lista
  if(lista[inicio] == lista[tam-1]){
    rep = 1;
  }else{
    while(inicio<tam-1){
      salto = 0;
      if(lista[inicio] == lista[meio]){
        for(int i=inicio+1;i<tam;i++){
          if(lista[inicio] == lista[i]){
            if(lista[i] != ultimoRep){
              rep++;
              ultimoRep = lista[i];
            }
            salto++;
          }

        }
        inicio = inicio + salto+1;
      }else{
        for(int k = meio;k>inicio;k--){
            if(lista[inicio] == lista[k]){
              if(lista[k] != ultimoRep){
                rep++;
                ultimoRep = lista[k];
              }
              salto++;
            }
          }
        inicio = inicio + salto +1;
      }
      meio = (tam + inicio)/2;
    }
  }
    printf("%d\n", rep);
  }