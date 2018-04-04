#include <iostream>
#include <map>
#include <iterator>
#include "grilla.h"

class PathPlanning{
public:
  Grilla* myMap;
  vector<pair<Celda*,int> > alfin;
  //map <Celda*,int> rFin; 
  vector<Celda*> resultado;
  Celda* fin;
  
  PathPlanning(){  
  myMap = new Grilla(50); //cantidad de nodos
  myMap->print();
  //myMap->printTargets();
  }
  
  void conectarGrafo(){
    for(int i = 0;i < myMap->numTargets-1 ;i++){
      for(int j = i+1;j < myMap->numTargets;j++){
        if(i!=j){
        int dTmp = myMap->targets[i].distancia(myMap->targets[j]);
        if(dTmp<15){ //radio para la conexión
          myMap->targets[i].conectar(myMap->targets[j], dTmp);
        }
        //cout<<myMap->targets[i].name<<","<<myMap->targets[j].name<<"l"<<dTmp<<"\n";
      }}
    }
    
    /*for(int j = 0;j < myMap->numTargets;j++){
        myMap->targets[j].printVecinos(); //para comprobar que se asignan bien los vecinos
    }*/
    
  }
  
  void mostrarRespuesta(){
  cout<<"\nRUTA: ";
    for(int i = 0;i < resultado.size();i++){
      cout<<resultado[i]->name<<" - ";
    }
  }
  
  void preCalculatePath(char A, char B){
    bool isA = false;
    bool isB = false;
    int i = 0;
    while(i<myMap->numTargets && (!isA || !isB)){
      
      if(myMap->targets[i].name == A){
        resultado.push_back(&myMap->targets[i]);
        isA = true;
      }
      
      if(myMap->targets[i].name == B){
        fin = &myMap->targets[i]; 
        isB = true;
      }
    i++;
    }
  
      for(int i =0;i<myMap->numTargets;i++){
      int tmp = myMap->targets[i].distancia(*fin);
      //rFin.insert(pair <Celda*, int> (&myMap->targets[i], tmp));
      alfin.push_back(make_pair(&myMap->targets[i], tmp));
      }
    
   
  }
  
  void printDistanciasAlObjetivo(){
    cout<<"Distancia al objetivo:\n";
    for(int i =0;i<myMap->numTargets;i++){
      cout<<alfin[i].first->name<<","<< alfin[i].second<<endl;
    }
  }
  
  int buscarEnAlFin(Celda* ex){
    for(int i=0; i<myMap->numTargets;i++){
      if(ex->name == alfin[i].first->name ){
        return alfin[i].second;
      }
    }
    return -1;
  }
  
  bool esta(Celda* other){
  
  for(int i = 0; i<resultado.size();i++){
    if (other == resultado[i]){
    
       return true;
    }    
   }
   return false;
  }
  
  void calculatePath(){
  Celda* actual = resultado[0];
  int i =0;
  int pesoCamino=0;
  bool hayOtroNodo = true;
    while(actual->name != fin->name && hayOtroNodo){
      //actual->printVecinos();
      Celda* next;
      Celda* res;
      int min = 1000;
      hayOtroNodo = false;
      for(int j =0;j <actual->vecinos.size();j++){
        next = actual->vecinos[j].first;
        if(!esta(next)){
              hayOtroNodo = true;
        int tmp = buscarEnAlFin(next);// distancia con respecto al objetivo
                                      // de la estrategia mejor el primero
                                      
        //cout<<"\nn: "<<next->name<<"t: "<<tmp<<" m: "<<min;
        int pesoPorNodo =next->distancia(*actual); //A* peso por elegir el nodo
        tmp+=pesoPorNodo;
        //cout<<" ft: "<<tmp;
          if(tmp<min){
            min = tmp;
            res = next;
            pesoCamino+=pesoPorNodo;
          }
          
        }
      }
    
      actual = res;
      if(!esta(res)) resultado.push_back(res);
      i++;
    }
    if(!hayOtroNodo)cout<<"No se encontró camino, pero la ruta mas cercana es ";
    mostrarRespuesta();
    cout<<"\n lo que cuesta esta es "<<pesoCamino;
  }
  
};


