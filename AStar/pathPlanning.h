#include <iostream>
#include <map>
#include "grilla.h"
class PathPlanning{
public:
  Grilla* myMap;
  map<Celda,int> distanciaAlObjetivo;
  vector<Celda*> resultado;
  Celda* fin;
  
  PathPlanning(){  
  myMap = new Grilla(5);
  myMap->print();
  myMap->printTargets();
  }
  
  void conectarGrafo(){
    for(int i = 0;i < myMap->numTargets-1 ;i++){
      for(int j = 1;j < myMap->numTargets;j++){
        int dTmp = myMap->targets[i].distancia(myMap->targets[j]);
        if(dTmp<5){
          cout<<"d<5\n";
          myMap->targets[i].conectar(&(myMap->targets[j]), dTmp);
        }
      }
    }
  }
  
  void mostrarRespuesta(){
    for(int i = 0;i < resultado.size();i++){
      cout<<resultado[i]->name<<" - ";
    }
  }
  
  void preCalculatePath(char A, char B){
    bool isA = false;
    bool isB = false;
    int i = 0;
    while(i<myMap->numTargets && (!isA || !isB)){
      //cout<<myMap->targets[i].name<<endl;
      
      if(myMap->targets[i].name == A){
        //cout<<"\nfound a";
        resultado.push_back(&myMap->targets[i]);
        isA = true;
      }
      
      if(myMap->targets[i].name == B){
        //cout<<"\nfound b";
        fin = &myMap->targets[i]; 
        isB = true;
      }
    i++;
    }
    //TODO: arreglar esta inserción en mapa
   /* for(int i=0; i<myMap->numTargets;i++){
      int tmp = fin->distancia(myMap->targets[i]);
      distanciaAlObjetivo.insert ( std::pair<Celda,int>(myMap->targets[i], tmp));
    }*/
    cout<<"distanciaAlObjetivo: "<<distanciaAlObjetivo.size();
  }
  
  void calculatePath(){ //TODO: revisar,  mejor el primero y luego aStar
  cout<<"\ncalculatePath";
  Celda* actual = resultado[0];
  int min = 1000;
  Celda* next;
  while(actual != fin){
    for(int i = 0;i< actual->vecinos.size();i++){
      next = actual->vecinos[i];
      int tmp = actual->pesoVecinos[i];//mas mapDistance
      if(tmp<min){min = tmp;}
    }
    resultado.push_back(next);
    actual = next;
    cout<<"{";
  }
  
  }
};
