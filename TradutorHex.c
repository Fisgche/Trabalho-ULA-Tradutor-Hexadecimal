#include <stdio.h>
#include <string.h>
#include <stdlib.h>



 char operacao(char texto[]){
   if(strncmp("An",texto,2)==0){
     return '0';
   }
    else if(strncmp("nAoB;",texto,5)==0){
     return '1';
   }
    else if(strncmp("AnB;",texto,4)==0){
     return '2';
   }
   else if(strncmp("zeroL;",texto,5)==0){
     return '3';
   }
   else if(strncmp("nAeB;",texto,5)==0){
     return '4';
   }
   else if(strncmp("Bn;",texto,3)==0){
     return '5';
   }
   else if(strncmp("AxB;",texto,4)==0){
     return '6';
   }
   else if(strncmp("ABn;",texto,4)==0){
     return '7';
   }
   else if(strncmp("AnoB;",texto,5)==0){
     return '8';
   }
   else if(strncmp("nAxB;",texto,5)==0){
     return '9';
   }
   else if(strncmp("B;",texto,2)==0){
     return 'A';
   }
   else if(strncmp("AB;",texto,3)==0){
     return 'B';
   }
   else if(strncmp("umL;",texto,4)==0){
     return 'C';
   }
   else if(strncmp("AoBn;",texto,5)==0){
     return 'D';
   }
   else if(strncmp("AoB;",texto,4)==0){
     return 'E';
   }
    else if(strncmp("A;",texto,2)==0){
     return 'F';
   }

   return '0';

}



int main(){
    char texto[30];
    FILE *arq;
    char *result;
    char x,y,z;
    char vetor[1000];
    int cont1=0;
    int cont2=0;

    arq = fopen("testeula.ula", "rt");
    if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  int i = 1;
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(texto, 1000, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if(strncmp("inicio",texto,6)!=0 && strncmp("fim",texto,3)!=0){


      if(texto[0]=='X')
      x=texto[2];
      else if(texto[0]=='Y')
      y=texto[2];
      else if(texto[0]!='X' && texto[0]!='Y' ){
        z=operacao(texto);
        vetor[cont1]=x;
        vetor[cont1+1]=y;
        vetor[cont1+2]=z;
        cont1=cont1+3;
        cont2++;
      }
      }
      i++;
  }
  fclose(arq);
            FILE *arquivo;
            arquivo=fopen("testeula.txt", "w");
            if (arquivo == NULL)  // Se houve erro na abertura
        {
            printf("Problemas na abertura do arquivo\n");
            return;
        }
        else{
            int j=0;

            for(int i=0;i<(cont2*3);i++){
            if(j==3){
                fprintf(arquivo,"\n");
                j=0;
            }
                fprintf(arquivo,"%c", vetor[i]);
                j++;
            }
        }
        fclose(arquivo);

}
