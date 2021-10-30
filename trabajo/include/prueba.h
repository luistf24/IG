#include "grafo-escena.h"
#include "ig-aux.h"

class prueba : public NodoGrafoEscena
{
   protected:
      Matriz4f * gir   = nullptr;
      Matriz4f * gir1  = nullptr;
      void actualizarEstadoParametro( const unsigned iParam, const float t_sec );
   public:
      prueba();
      unsigned leerNumParametros() const;
      void giro(const float ngiro);
      void giro1(const float ngiro);
};

class toro1 : public NodoGrafoEscena 
{
   public:
      toro1(Matriz4f * &gir);
};

class toro2 : public NodoGrafoEscena
{
   public:
      toro2(Matriz4f * &gir1);
};

class qloq : public NodoGrafoEscena 
{
   public:
      qloq(Matriz4f * &gir, Matriz4f * &gir1);
};

/*class prueba1 : public NodoGrafoEscena*/
/*{*/
   /*public:*/
      /*prueba1( const int num_verts, const unsigned nperfiles);*/
/*};*/

/*class prueba2 : public NodoGrafoEscena */
/*{*/
   /*public:*/
      /*prueba2( const int num_verts, const unsigned nperfiles);*/
/*}*/;
