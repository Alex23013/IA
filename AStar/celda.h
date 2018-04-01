#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

class Celda{
  public:
  int x;
  int y;
  int isTarget;
  char name;
  vector<int> pesoVecinos;
  vector<Celda*> vecinos;
  
  Celda(){
  this-> x = 0;
  this-> y = 0;
  this-> isTarget = 0;
  this-> name = '-';
  }
  
  void setCelda(int x, int y, int isTarget, char name){
  this-> x = x;
  this-> y = y;
  this-> isTarget = isTarget;
  this-> name = name;
  }
  
  void printPos(){
    cout<<"("<< x<< ","<<y<<") ";
  }
  
  void printIsTarget(){
    cout<<isTarget<<" ";
  }
  
  void printName(){
    cout<<name<<" ";
  }
  
  int distancia(Celda otraCelda){
    return abs(otraCelda.x-this->x)+abs(otraCelda.y-this->y);
  }
  
  void conectar(Celda* V, int distancia){
    vecinos.push_back(V);
    pesoVecinos.push_back(distancia);
    V->vecinos.push_back(this);
    V->pesoVecinos.push_back(distancia);
  }
  
  };
