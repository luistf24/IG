#include "grafo-escena.h"
#include "ig-aux.h"

class C : public NodoGrafoEscena 
{
   protected:
      Matriz4f * giro   = nullptr;
      Matriz4f * mover  = nullptr;
      Matriz4f * movc   = nullptr;
      void actualizarEstadoParametro(const unsigned iParam, const float t_sec);
   public:
      int altura;
      int longitud;
      C(int altura, int longitud);
      unsigned leerNumParametros() const;
      void gir(const float ngiro);
      void mov(const float nmove);
      void movcu(const float nomve);
};

class barrote : public NodoGrafoEscena
{
   public:
      barrote(float longitud);
};

class cubob : public NodoGrafoEscena
{
   public:
      cubob();
};

class soporte : public NodoGrafoEscena 
{
   public:
      soporte();
};

class caja : public NodoGrafoEscena 
{
   public:
      caja();
};

class columna : public NodoGrafoEscena 
{
   public:
      columna(int tam);
};

class piezatecho : public NodoGrafoEscena
{
   public:
      piezatecho();
};

class techo : public NodoGrafoEscena 
{
   public:
      techo(int l, int tam);
};

class parteatras : public NodoGrafoEscena
{
   public:
      parteatras(int tam);
};

class pinacho : public NodoGrafoEscena 
{
   public:
      pinacho(int tam);
};

class cable : public NodoGrafoEscena
{
   public:
      cable(int l, int tam, Matriz4f * &movcuerda);
};

class arriba : public NodoGrafoEscena 
{
   public:
      arriba(int l, int tam, Matriz4f * &gir, Matriz4f * &mov, Matriz4f * &movcuerda);
};
