#include <iostream>
#include "pathPlanning.h"
using namespace std;

int main(){
PathPlanning aStar;
aStar.conectarGrafo();
aStar.preCalculatePath('A','H');
aStar.mostrarRespuesta();

aStar.calculatePath();
aStar.mostrarRespuesta();

aStar.myMap->targets[0].printVecinos();

/*Celda a;
a.setCelda(2,3,1,'C');

Celda b;
b.setCelda(2,3,1,'C');
if (a==b)
  cout<<"YES"<<endl;*/
return 0;

}
