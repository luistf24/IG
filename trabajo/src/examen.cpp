#include "ig-aux.h"
#include "modelo-jer.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include <cmath>
#include "examen.h"

examen::examen(int n)
{
   unsigned a;
   a=agregar(MAT_Rotacion(0,0.0, 0.0, 1.0));
   agregar(new conos(n));
   giro=leerPtrMatriz(a);
}

unsigned examen::leerNumParametros() const
{
   return 1;
}

void examen::actualizarEstadoParametro(const unsigned iParam, const float t_sec)
{
   if(iParam == 0)
      gir(100*M_PI*t_sec);
}

void examen::gir(const float ngiro)
{
   *giro= MAT_Rotacion(ngiro, 0.0, 0.0, 1.0);
}

conos::conos(int n)
{
   Matriz4f giro; 
   for(int i=0; i<n; i++)
   {
      agregar (MAT_Traslacion(cos(2*M_PI*i/n + M_PI/2),sin(2*M_PI*i/n + M_PI/2),0.0));
      agregar(MAT_Escalado(0.25, 0.25, 0.25));
      agregar(MAT_Rotacion(360*i/n, 0.0, 0.0, 1.0));   
      agregar(new Cono(20, 20));
      agregar(MAT_Rotacion(-360*i/n,0.0, 0.0, 1.0));
      agregar(MAT_Escalado(4, 4, 4));
      agregar (MAT_Traslacion(-cos(2*M_PI*i/n + M_PI/2),-sin(2*M_PI*i/n + M_PI/2),0.0)); 
      //agregar(MAT_Escalado(1.0, 1.0, 1.0));
   }
   agregar(MAT_Traslacion(-1, -1, 0.0));
   agregar(MAT_Escalado(2, 2, 2));
   agregar(new estrellaZ(n));

}
