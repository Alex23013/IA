#include <iostream>
#include "celda.h"
#include <vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

int N = 50;

class Grilla{
  public:
  Celda grilla [50][50]; //50*50
  vector<Celda> targets;
  int numTargets;
  
  Grilla(int numTargets){
  this->numTargets = numTargets;
  srand(time(NULL));
  int tmp;
  int tName=65;
  for(int i =0; i< numTargets;i++){
      tmp = rand()%(N*N+1);
      int tx = tmp/100;
      int ty = tmp%100;
      grilla[tx][ty].setCelda(tx,ty,1,tName);
      targets.push_back(grilla[tx][ty]);
      tName++;
  }
  }
  
  void print(){ //imprime el mapa
    for(int i =0; i< N;i++){
      cout<<endl;
      for(int j = 0; j < N ;j++){
        //grilla[i][j].printIsTarget();
        grilla[i][j].printName();
      }    
    }
  }
  
  void printTargets(){ //imprime las ciudades
    cout<<endl;
    for(int i =0; i< numTargets;i++){
      targets[i].printPos();
    }
  }
  
};
