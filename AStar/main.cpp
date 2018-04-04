#include <iostream>
#include "pathPlanning.h"
using namespace std;

int main(){
PathPlanning aStar;
aStar.conectarGrafo();
char a,b;
cout<<"\nPunto de inicio? ";
cin>>a;
cout<<"\nPunto de fin? ";
cin>>b;
aStar.preCalculatePath(a,b);
//aStar.printDistanciasAlObjetivo(); // para ver los valores con lo que calculamos el A*
aStar.calculatePath();
return 0;

}
