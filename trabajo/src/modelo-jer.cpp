#include "ig-aux.h"
#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include <cmath>

C :: C()
{
   agregar(new columna(11));
   agregar(new techo(7,11));
   agregar(new parteatras(11));
   agregar(new pinacho(11));
}

barrote :: barrote(float longitud)
{
   agregar(MAT_Escalado(0.025,longitud,0.025));
   agregar(new Cilindro(20,20));
}



cubob :: cubob()
{
   agregar(MAT_Traslacion(0.5, 0.0, 0.5));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(0.0, 0.0, -1.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-0.5, 0.0, 0.5));
}
//Optimizar esto 
piezatecho :: piezatecho()
{
   agregar(MAT_Traslacion(0.0, 0.5, 0.0));
   agregar(new soporte());
   agregar(MAT_Traslacion(0.5, 0.0, 0.5));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-1.0, 0.0, 0.0));
   agregar(new barrote(0.5));

   agregar(MAT_Traslacion(0.5, -0.5, -1.0));

   agregar(MAT_Rotacion(90, 0.0, 0.0, 1.0));
   agregar(new barrote(0.5));
   agregar(MAT_Rotacion(-90, 0.0, 0.0, 1.0));
   
   
   agregar(MAT_Traslacion(0.0, 0.0, 1.0));
   agregar(MAT_Rotacion(90, 0.0, 0.0, 1.0));
   agregar(new barrote(0.5));
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(MAT_Traslacion(0.0, -0.5, -0.5));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(0.0, 0.0, 1.0));
   agregar(new barrote(0.5));
   
    agregar(MAT_Rotacion(-90, 1.0, 0.0, 0.0));
    agregar(MAT_Traslacion(1.0, 0.5, 0.5));
    agregar(new barrote(0.5));
    agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
    agregar(MAT_Traslacion(0.0, 0.5, -0.5));
    agregar(new barrote(0.5));
    agregar(MAT_Traslacion(0.0, 0.0, 1.0));
    agregar(new barrote(0.5));
   
}

soporte :: soporte()
{
   agregar(MAT_Traslacion(0.5, 0.0, 0.0));
   agregar(MAT_Rotacion(45, 1.0, 0.0, 0.0));
   agregar(new barrote(0.71));
   agregar(MAT_Rotacion(-45, 1.0, 0.0, 0.0));
   agregar(MAT_Traslacion(-1.0, 0.0, 0.0));
   agregar(MAT_Rotacion(45, 1.0, 0.0, 0.0));
   agregar(new barrote(0.71));
}

caja :: caja()
{
   agregar(MAT_Traslacion(0.0, 0.5, 0.0));
   agregar(new soporte());
   agregar(MAT_Rotacion(90, 0.0, 1.0, 0.0));
   agregar(new soporte());
   agregar(MAT_Rotacion(-90, 0.0, 1.0, 0.0));
   agregar(new cubob());
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(new cubob());
   agregar(MAT_Rotacion(90, 0.0, 0.0, 1.0));
   agregar(new cubob());
}

columna :: columna(int tam)
{
   for (int i=0; i<tam; i++)
   {
      agregar(new caja());
      agregar(MAT_Traslacion(0.0, 1, 0.0));
   }
}

techo :: techo(int l, int tam)
{
   agregar(MAT_Traslacion(0.0,tam-1,-1.0));
   agregar(MAT_Escalado(0.75,0.5,1.5));
   for (int i=0;i<l; i++)
   {
      agregar(new piezatecho());
      agregar(MAT_Traslacion(0.0,0.0,-1.0));
   }
}
parteatras :: parteatras(int tam)
{
   agregar(MAT_Traslacion(-0.5, tam-0.75, 1.0));
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-0.5, 1.0, 0.0));
   agregar(MAT_Escalado(1.0, 0.75, 0.5));
   agregar(new Cubo());
}

pinacho :: pinacho(int tam)
{
   agregar(MAT_Traslacion(0.0, tam+1, -0.5));
   agregar(MAT_Traslacion(-0.5,-0.5, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-0.5, 0.0, 0.0));
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(new piezatecho());
}
