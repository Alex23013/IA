#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <utility>   
using namespace std;

class Celda{
  public:
  int x;
  int y;
  int isTarget;
  char name;
  vector<pair<Celda*,int> > vecinos;
  
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
  
  void printVecinos(){
  cout<<"\nvecinos de "<<name<<" : ";
    for(int i =0;i < vecinos.size();i++){
      cout<<vecinos[i].first->name<<"_";
    }
  }
  
  int distancia(Celda otraCelda){
    return abs(otraCelda.x-this->x)+abs(otraCelda.y-this->y);
  }
  
  void conectar(Celda& V, int distancia){
    vecinos.push_back(make_pair(&V,distancia));
    V.vecinos.push_back(make_pair(this,distancia));
  }
  
  bool operator == (Celda other){
    return this->x == other.x && this->y == other.y && this->name == other.name ;
  }
  
  bool operator != (Celda other){
    return this->x != other.x && this->y != other.y && this->name != other.name ;
  } 
  
  bool pertenece(Celda other){
    bool esta = false;
    for(int i =0;i < vecinos.size();i++){
      if (vecinos[i].first->name == other.name){esta= true;}
      }
      return esta;
    }
  };
