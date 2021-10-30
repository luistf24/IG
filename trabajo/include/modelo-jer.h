#include "grafo-escena.h"
#include "ig-aux.h"

class C : public NodoGrafoEscena 
{
   public:
      C();
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


