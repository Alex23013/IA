#include <iostream>
#include <map>
#include "grilla.h"
class PathPlanning{
public:
  Grilla* myMap;
  vector<pair<Celda*,int> > alfin;
  vector<Celda> resultado;
  Celda fin;
  
  PathPlanning(){  
  myMap = new Grilla(15);
  myMap->print();
  myMap->printTargets();
  }
  
  void conectarGrafo(){
    for(int i = 0;i < myMap->numTargets-1 ;i++){
      for(int j = 1;j < myMap->numTargets;j++){
        int dTmp = myMap->targets[i].distancia(myMap->targets[j]);
        if(dTmp<5){
          myMap->targets[i].conectar(myMap->targets[j], dTmp);
        }
       // cout<<myMap->targets[i].name<<","<<myMap->targets[j].name<<"l"<<dTmp<<"\n";
      }
    }
  }
  
  void mostrarRespuesta(){
  cout<<"\nRUTA: ";
    for(int i = 0;i < resultado.size();i++){
      cout<<resultado[i].name<<" - ";
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
        resultado.push_back(myMap->targets[i]);
        isA = true;
      }
      
      if(myMap->targets[i].name == B){
        //cout<<"\nfound b";
        fin = myMap->targets[i]; 
        isB = true;
      }
    i++;
    }
    
    for(int i=0; i<myMap->numTargets;i++){
      int tmp = fin.distancia(myMap->targets[i]);
      alfin.push_back(make_pair(&myMap->targets[i],tmp));
      //cout<<alfin[i].first->name<<","<<alfin[i].second<<endl;
    }
    cout<<"distanciaAlObjetivo: "<<alfin.size();
  }
  
  int buscar(Celda* ex){
    for(int i=0; i<myMap->numTargets;i++){
      if(ex->name == alfin[i].first->name && alfin[i].first->pertenece(*ex)){
        return alfin[i].second;
      }
    }
    return 10;
  }
  
  void calculatePath(){ //TODO: revisar,  mejor el primero y luego aStar
  cout<<"\ncalculatePath";
  cout<<"Nodo inicio";
  resultado[0].printPos();
  cout<<endl;
  Celda actual;
  actual = resultado[0];
  mostrarRespuesta();
  actual.printPos();
  
  
  Celda* next;
int cont = 0;
  while(!(actual == fin) && cont <5){
    cout<<actual.name<<",,"<<fin.name<<endl;
    actual.printVecinos();
    int min = 1000;
    Celda* res;
    cout<<"numV: "<<actual.vecinos.size();
    for(int i = 0;i< actual.vecinos.size();i++){
      cout<<"i:"<<i;
      next = actual.vecinos[i].first;
      cout<<" a: "<<(*next).name;
      int tmp = buscar(next);
      //int tmp = next->vecinos[i].second;//mas mapDistance
      
      if(tmp<min){min = tmp; res = next;}
      actual=*res;
      cout<<" t:"<<tmp<<" m:"<<min<<endl;
    }
    
    resultado.push_back(*res);
    mostrarRespuesta();
    cout<<"{";
    cont++;
  }
  
  }
};
