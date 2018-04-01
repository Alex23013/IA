#include <iostream>
#include "grilla.h"
class PathPlanning{
public:
  Grilla* map;
  //hacer vector de pair(Celda,distancia al objetivo)
  
  PathPlanning(){  
  map = new Grilla(5);
  map->print();
  map->printTargets();
  }
  
  void calculatePath();
};
