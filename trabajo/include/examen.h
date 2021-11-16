
#include "grafo-escena.h"
#include "ig-aux.h"

class examen : public NodoGrafoEscena 
{
   protected:
      Matriz4f * giro   = nullptr;
      void actualizarEstadoParametro(const unsigned iParam, const float t_sec);
   public:
      int n;
      examen(int n);
      unsigned leerNumParametros() const;
      void gir(const float ngiro);
};

class conos : public NodoGrafoEscena
{
   public:
      conos(int n);
};
