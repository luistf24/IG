#include "ig-aux.h"
#include "prueba.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"
#include <cmath>

prueba :: prueba()
{
   ponerNombre("Prueba");
   agregar(new qloq(gir,gir1));
}

void prueba::giro(const float ngiro)
{
   *gir=MAT_Rotacion(ngiro, 0.0, 1.0, 1.0);
}

void prueba::giro1(const float ngiro)
{
   *gir1=MAT_Rotacion(ngiro, 1.0, 1.0, 0.0);
}

unsigned prueba::leerNumParametros() const
{
   return 2;
}

void prueba::actualizarEstadoParametro( const unsigned iParam, const float t_sec )
{
   if(iParam == 0)
   {
      giro(12*M_PI*t_sec);
   }
   if (iParam == 1)
      giro1(12*M_PI*t_sec);

}

toro1::toro1(Matriz4f * &gir)
{
   ponerNombre("Toro1");
   unsigned g;
   g=agregar(MAT_Rotacion(0.0, 0.0, 1.0, 1.0));
   agregar(new Toro(40,40));
   gir=leerPtrMatriz(g);
}

toro2::toro2(Matriz4f * &gir1)
{
   ponerNombre("Toro2");
   unsigned h;
   h=agregar(MAT_Rotacion(0.0, 1.0, 1.0, 0.0));
   agregar(new Toro(40,40));
   gir1=leerPtrMatriz(h);
}

qloq::qloq(Matriz4f * &gir, Matriz4f * &gir1)
{
   agregar(new toro1(gir));
   agregar(new toro2(gir1));
}

/*qloq::qloq(Matriz4f * &gir, Matriz4f * &gir1)*/
/*{*/
   /*unsigned test,test1;*/
   /*test=agregar(MAT_Rotacion(0.0, 0.0, 1.0, 0.0));*/
   /*test1=agregar(MAT_Rotacion(0.0, 1.0, 0.0, 0.0));*/
   /*ponerNombre("Prueba");*/
   /*//agregar(*gir);*/
   /*agregar(MAT_Traslacion(4.0, 0.0, 0.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(-4.0, 0.0, 4.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(-4.0, 0.0, -4.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(4.0, 0.0, -4.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(0.0, 0.0, 4.0));*/
   /*agregar(new Cilindro(20, 20));*/
   /*agregar(MAT_Traslacion(0.0, 4.0, 0.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(0.0, -8.0, 0.0));*/
   /*agregar(new Esfera(20, 20));*/
   /*agregar(MAT_Traslacion(0.0, 4.0, 0.0));*/
   /*agregar(new Toro(30,30));*/
   /*agregar(MAT_Traslacion(0.0, 2.0, 0.0));*/
   /*agregar(new Cilindro(20,20));*/
   /*agregar(MAT_Traslacion(0.0, -4.0, 0.0));*/
   /*agregar(new Cilindro(20,20));*/
   /*agregar(MAT_Traslacion(0.0, 2.0, 0.0));*/
   /*agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));*/
   /*agregar(new Cilindro(20, 20));*/
   /*agregar(new Toro(30, 30));*/
   /*gir = leerPtrMatriz(test);  */
   /*gir1 = leerPtrMatriz(test1);*/

/*}*/
