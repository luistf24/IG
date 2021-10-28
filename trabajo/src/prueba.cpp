/*class C : public NodoGrafoEscena*/
/*{*/
   /*protected:*/
      /*Matriz4f * traslacion   = nullptr;*/

      /*void actualizarEstadoParametro(const unsigned iParam, const float t_sec);*/

   /*public:*/
      /*C();*/


/*};*/

/*class prueba1 : public NodoGrafoEscena*/
/*{*/
   /*public:*/
      /*prueba1( const int num_verts, const unsigned nperfiles);*/
/*};*/

/*class prueba2 : public NodoGrafoEscena */
/*{*/
   /*public:*/
      /*prueba2( const int num_verts, const unsigned nperfiles);*/
/*};*/
#include "ig-aux.h"
#include "prueba.h"
#include "malla-ind.h"
#include "malla-revol.h"
#include "matrices-tr.h"

C :: C()
{
   ponerNombre("Prueba");
   agregar(MAT_Traslacion(4.0, 0.0, 0.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(-4.0, 0.0, 4.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(-4.0, 0.0, -4.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(4.0, 0.0, -4.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(0.0, 0.0, 4.0));
   agregar(new Cilindro(20, 20));
   agregar(MAT_Traslacion(0.0, 4.0, 0.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(0.0, -8.0, 0.0));
   agregar(new Esfera(20, 20));
   agregar(MAT_Traslacion(0.0, 4.0, 0.0));
   agregar(new Toro(30,30));
   agregar(MAT_Traslacion(0.0, 2.0, 0.0));
   agregar(new Cilindro(20,20));
   agregar(MAT_Traslacion(0.0, -4.0, 0.0));
   agregar(new Cilindro(20,20));
   agregar(MAT_Traslacion(0.0, 2.0, 0.0));
   agregar(MAT_Rotacion(90, 1.0, 0.0, 0.0));
   agregar(new Cilindro(20, 20));
   agregar(new Toro(30, 30));
}

