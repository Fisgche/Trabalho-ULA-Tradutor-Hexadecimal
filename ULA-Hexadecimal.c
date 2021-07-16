char vetor[1000];
char c='a';
int a = 0;   
int b = 0;   
int op = 0;
int led4 = 13;
int led3 = 12;
int led2 = 11;
int led1 = 10;
int saida;
bool vai1=false;
int cont=0;
int i=3;
int cont1=0;
int cont2=0;
int retorno;

void setup() {
        Serial.begin(9600);     
        pinMode(led4,OUTPUT);
  		pinMode(led3,OUTPUT);
 		pinMode(led2,OUTPUT);
  		pinMode(led1,OUTPUT);
  		vetor[0]='0';
  		vetor[1]='0';
  		vetor[2]='0';        
}
void loop() {

  if (Serial.available() > 0) {
		c=Serial.read();
		vetor[i]=c;
		cont++;
		i++;
		cont1++;
                 
                 
        }
  else{			
   		imprimir(vetor,cont);
    	if(cont1!=0){
          if(cont1!=cont2){
      	retorno=resolve(vetor[cont2+3],vetor[cont2+4],vetor[cont2+5]);	
        vetor[1]=vetor[cont2+3];
        vetor[2]=vetor[cont2+4];
        char r=converteInt(retorno);
        vetor[0]=r;                                        
		cont2=cont2+3;
          }
      }
  }
      
}
void imprimir(char vetor[],int cont){
	for(int j=0;j<cont+3;j++)
		Serial.print(vetor[j]);
		Serial.println(); 
  		delay(3000);

}
int resolve(char a, char b, char op){
  int A;
  int B;
  int OP;
  int ret;
  A=converteChar(a);
  B=converteChar(b);
  OP=converteChar(op);
  
  if(OP==0){
    ret=portanot(A);  
  }
  else if(OP==1){
  	ret=portaor(A,B);
    ret=portanot(ret);
  }
  else if(OP==2){
  	ret=portanot(A);
    ret=portaand(ret,B);
  }
  else if(OP==3){
  	ret=0;
  }
  else if(OP==4){
  	ret=portaand(A,B);
    ret=portanot(ret);
  }
  else if(OP==5){
  	ret=portanot(B);
  }
  else if(OP==6){
  	ret=portaxor(A,B);
  }
  else if(OP==7){
  	ret=portanot(B);
    ret=portaand(A,ret);
  }
  else if(OP==8){
  	ret=portanot(A);
    ret=portaor(ret,B);
  }
  else if(OP==9){
  	ret=portaxor(A,B);
    ret=portanot(ret);
  }
  else if(OP==10){
  	ret=B;
  }
  else if(OP==11){
  	ret=portaand(A,B);
  }
  else if(OP==12){
  	ret=1;
  }
  else if(OP==13){
  	ret=portanot(B);
    ret=portaor(ret,A);
  }
  else if(OP==14){
  	ret=portaor(A,B);
  }
  else if(OP==15){
  	ret=A;
  }
  acendeLed(ret);
  return ret;
}
void acendeLed(int a){
  if(a==0){
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
  }
  else if(a==1){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
  }
  else if(a==2){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
  }
  else if(a==3){
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
  }
  else if(a==4){
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
  }
  else if(a==5){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
  }
  else if(a==6){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
  }
  else if(a==7){
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,0);
  }
  else if(a==8){
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
  }
  else if(a==9){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
  }
  else if(a==10){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
  }
  else if(a==11){
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,0);
    digitalWrite(led4,1);
  }
  else if(a==12){
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
  }
  else if(a==13){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
  }
  else if(a==14){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
  }
          else if(a==15){
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
  }
}
int converteChar(char a){
	if(a=='0')
      return 0;
  	else if(a=='1')
      return 1;
      else if(a=='2')
      return 2;
      else if(a=='3')
      return 3;
      else if(a=='4')
      return 4;
      else if(a=='5')
      return 5;
      else if(a=='6')
      return 6;
      else if(a=='7')
      return 7;
      else if(a=='8')
      return 8;
      else if(a=='9')
      return 9;
      else if(a=='A')
      return 10;
      else if(a=='B')
      return 11;
      else if(a=='C')
      return 12;
      else if(a=='D')
      return 13;
      else if(a=='E')
      return 14;
      else if(a=='F')
      return 15;
   
}
char converteInt(int a){
	if(a==0)
      return '0';
  	else if(a==1)
      return '1';
      else if(a==2)
      return '2';
      else if(a==3)
      return '3';
      else if(a==4)
      return '4';
      else if(a==5)
      return '5';
      else if(a==6)
      return '6';
      else if(a==7)
      return '7';
      else if(a==8)
      return '8';
      else if(a==9)
      return '9';
      else if(a==10)
      return 'A';
      else if(a==11)
      return 'B';
      else if(a==12)
      return 'C';
      else if(a==13)
      return 'D';
      else if(a==14)
      return 'E';
      else if(a==15)
      return 'F';
   
}


int portaxor(int a, int b)
{
  return(a^b);
}
bool Vai1(int a, int b){
 if(a==1 && b==1)
   return true;
 return false; 
}
int portaor(int a, int b)
{
  return(a|b);
}

int portaand(int a, int b)
{
  return(a&b);
}

int portanot(int a)
{
  return(~a)+16;  
}

