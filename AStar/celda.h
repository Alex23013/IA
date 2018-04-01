#include <iostream>
using namespace std;

class Celda{
  public:
  int x;
  int y;
  int isTarget;
  char name;
  ///---vector<int> pesosVecinos;
  ///---vector<Celdas> vecinos;
  
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
  
  
  };
