#include "ig-aux.h"
#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include <cmath>

C :: C(int a, int l)
{
   ponerNombre("Grua");
   altura=a;
   longitud=l;
   agregar(new columna(altura));
   agregar(new arriba(longitud, altura, giro, mover, movc));
}

unsigned C :: leerNumParametros() const
{
   return 3;
}

void C :: actualizarEstadoParametro(const unsigned iParam, const float t_sec)
{
   switch(iParam)
   {
      case 0:
         gir(180*(1+sin(0.25*M_PI*t_sec)));
         break;
      case 1:
         mov((longitud+1)/2+longitud*0.5*sin(M_PI*t_sec));
         break;
      case 2:
         movcu((longitud-3)/2*(1+sin(M_PI*t_sec)));
         break;
   }
}

void C :: gir(const float ngiro)
{
   *giro = MAT_Rotacion(ngiro, 0.0, 1.0, 0.0);
}

void C :: mov(const float nmove)
{
   *mover = MAT_Traslacion(0.0, 0.0, -1*nmove);
}

void C :: movcu(const float nmove)
{
   *movc = MAT_Escalado(1.0,2*(nmove+1),1.0)*MAT_Traslacion(0.0,-0.44, 0.0);
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
   for (int i=0; i<tam-1; i++)
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
   agregar(MAT_Traslacion(0.0, tam-1, 0.0));
   agregar(new caja());
   agregar(MAT_Traslacion(0.0, 2, -0.5));
   agregar(MAT_Traslacion(-0.5,-0.5, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(1.0, 0.0, 0.0));
   agregar(new barrote(0.5));
   agregar(MAT_Traslacion(-0.5, 0.0, 0.0));
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(new piezatecho());
}

cable :: cable(int l, int tam, Matriz4f * &movcuerda)
{
   agregar(MAT_Traslacion(0.0, tam-1.65, -1.5));
   agregar(MAT_Traslacion(0.0, 0.5, 0.0));
   agregar(MAT_Escalado(0.2, 0.2, 0.2));
   agregar(new Cubo());
   agregar(MAT_Traslacion(0.0, -2.0, 0.0));
   unsigned a;
   agregar(MAT_Escalado(5.0,5.0,5.0));
   a = agregar(MAT_Escalado(1.0, 1.0, 1.0));
   agregar(new barrote(0.5));
   movcuerda = leerPtrMatriz(a);
}

arriba :: arriba(int l, int tam, Matriz4f * &gir, Matriz4f * &movh, Matriz4f * &movcuerda)
{
   ponerNombre("Parte de arriba");
   unsigned a,b;
   a = agregar(MAT_Rotacion(0, 0.0, 1.0, 0.0));
   agregar(new techo(l,tam));
   agregar(new parteatras(tam));
   agregar(new pinacho(tam));
   b = agregar(MAT_Traslacion(0.0, 0.0, 0.0));
   agregar(new cable(l, tam, movcuerda));
   gir=leerPtrMatriz(a);
   movh = leerPtrMatriz(b);
}
