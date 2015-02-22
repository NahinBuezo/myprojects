#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void jugar(char*);
void comprobar(char*,char[], char*);
void dibujar(int,char**);

int main(int argc, char*argv[]){
    vector <char*> diccionario;
	srand(time(0));
    
	char* lista;
	char*lista2;
    
    int respuesta=1;
    int op;
    bool existe=false;
    char* palabra;
    ifstream fe("palabras.txt",ifstream::in);
    
    while(fe>>lista2);
    fe.close();
    lista=strtok(lista2," ,");
    
    while(lista!=NULL){
        diccionario.push_back(lista);
        lista=strtok(NULL," ,");
        
    }
    
    
    
     while(respuesta==1){
    
        cout<<"Opciones\n1. Palabras aleatorias\n2. Ingresar palabra"<<endl;
        cin>>op;
        while(op!=1&&op!=2){
           cout<<"Opciones\n1. Palabras aleatorias\n2. Ingresar palabra"<<endl;
           cin>>op;
        }

        if(op==1){
          int num=rand()%diccionario.size();
          palabra=diccionario.at(num);
          //palabra=new char[diccionario.at(num).length()+1];
         // string copia=diccionario.at(num);
          //strcpy(palabra,copia.c_str());
      
          jugar(palabra);
        }
        if(op==2){
        /**   char nueva[30]="";
           cout<<"Ingrese palabra: "<<endl;
           cin>>nueva;
           diccionario.push_back(nueva);
           jugar(nueva);
           **/
            
        }
        cout<<"Desea seguir jugando? 1=si"<<endl;
        cin>>respuesta;
     }
 
    return 0;
}

void jugar(char* palabra){
    
    bool terminar=false;
    bool completo=false;
    int contador=strlen(palabra);
    int faltantes;
    int intentos=5;
    char secreto[strlen(palabra)];
    char *dibujo[20];
    for(int i=0; i<20;i++){
        dibujo[i]=new char[20];
    }
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            dibujo[i][j]=' ';
        }
    }
     for(int i=0; i<strlen(palabra); i++){
         secreto[i]='_';
     }
     while(terminar==false){
       char letra[50];
       completo=true;
       faltantes=contador;
       contador=strlen(palabra);
       for(int i=0; i<strlen(palabra); i++){
         cout<<secreto[i];
       }
       cout<<endl;
       cout<<"Numero de intetos: "<<intentos<<endl;
       cout<<"Ingrese una lentra: "<<endl;
       cin>>letra;
    
         comprobar(letra,secreto,palabra);
         for(int i=0; i<strlen(palabra);i++){
            if(secreto[i]!='_'){
              contador--;
            }
         }
         if(faltantes==contador){
          intentos--;
          dibujar(intentos, dibujo);
         }
         /**cuendo el juego termine se libera el espacio de memoria reservado por la matris de char  en
         la cual se realizo el dibujo
         **/
         if(intentos<=0){
           cout<<"FIN DEL JUEGO, PERDISTE"<<endl;
           cout<<"Palabra secreta: "<<palabra<<endl;
           terminar=true;
           for(int i=0; i<20; i++){
              delete[]dibujo[i];
           }
          
         }

         for(int i=0;i<strlen(palabra); i++){
          if(secreto[i]=='_'){
              completo=false;
          }
         }
         /**de igual manera soi el usuario gana, la memoria reservada par ael dibujo es liberada ya sea
         que el usuario vuelva a jugar o no, pues si juega se vuelve a reservar la memoria
         **/
         if(completo==true){
          terminar=true;
          cout<<"************FELICIDADES GANASTE*********";
           for(int i=0; i<20; i++){
              delete[]dibujo[i];
           }
         }

       

     }
}


void comprobar(char* letra,char secreto[], char* palabra){
  for(int j=0; j<strlen(letra);j++){
    for(int i=0; i<strlen(palabra);i++){
        if(letra[j]==palabra[i]){
            secreto[i]=letra[0];
        }
    }
  } 

}


void dibujar(int intentos, char** dibujo){
   if(intentos==4){
    //creacion de arbol y soga
     for(int i=0; i<2; i++){
        for(int j=0; j<20;j++){
            dibujo[i][j]='$';
        }
     }
     for(int i=0; i<20; i++){
        for(int j=0; j<2;j++){
            dibujo[i][j]='$';
        }
     }

   }
   if(intentos==3){
      for(int i=2; i<7; i++){
           dibujo[i][10]='@';
     }
   }
   //creacion de cabeza y tronco
   if(intentos==2){
     dibujo[7][11]='*';
     dibujo[7][10]='*';
     dibujo[7][9]='*';
     dibujo[8][8]='*';
     dibujo[9][8]='*';
     dibujo[10][9]='*';
     dibujo[10][10]='*';
     dibujo[10][11]='*';
     dibujo[9][12]='*';
     dibujo[8][12]='*';
     //tronco
     dibujo[11][10]='*';
     dibujo[12][10]='*';
     dibujo[13][10]='*';
     dibujo[14][10]='*';
     dibujo[15][10]='*';
    

   }
   //creacion de brazos y piernas
   if(intentos==1){
    dibujo[12][9]='*';
    dibujo[13][8]='*';
    dibujo[12][11]='*';
    dibujo[13][12]='*'; 
   }
   if(intentos==0){
    dibujo[16][9]='*';
    dibujo[17][8]='*';
    dibujo[16][11]='*';
    dibujo[17][12]='*';
   }
   for(int i=0; i<20; i++){
    for(int j=0; j<20; j++){
        cout<<dibujo[i][j];
    }
    cout<<endl;
   }
}
