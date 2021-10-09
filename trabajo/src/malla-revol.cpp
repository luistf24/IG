// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "tuplasg.h"
#include "lector-ply.h"
#include "matrices-tr.h"
#include "malla-revol.h"

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   // COMPLETAR: Práctica 2: completar: creación de la malla....
   Matriz4f rotacion;
   Tupla3f vertice;
   int m=perfil.size();

   for (unsigned i=0; i<num_copias; i++)
   {
      rotacion = MAT_Rotacion((360.0*i)/(num_copias-1), 0.0, 1.0, 0.0); //El eje de rotación es el Y 
      
      for (int j=0; j<m; j++)
      {   
         vertice = rotacion*perfil[j]; //Rotamos el vertice
         vertices.push_back(vertice);  //Metemos el nuevo vertice rotado en los vertices 
      }
   }

   int k;
   for (unsigned i=0; i<num_copias-1; i++)
   {
      for (int j=0; j<m-1; j++)
      {
         k=i*m + j;
         triangulos.push_back(Tupla3i (k, k+m, k+m+1));
         triangulos.push_back(Tupla3i (k, k+m+1, k+1));
      }
   }



}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   // ...........................
   vector<Tupla3f> perfil;
   LeerVerticesPLY(nombre_arch, perfil);
   inicializar(perfil,nperfiles);
}

Cilindro::Cilindro
(
 const int num_verts_per,
 const unsigned nperfiles 
)
{
   ponerNombre(std::string("Cilindro"));
   assert(num_verts_per >= 4);

   vector<Tupla3f> perfil;
   float y;
   perfil.push_back({0.0, -1.0, 0.0});
   for (int i=0; i<num_verts_per-2; i++)
   {
      y=-1.0+(2.0*(float)i/(num_verts_per-3));
      
      perfil.push_back({1.0, y, 0.0});
   }
      perfil.push_back({0.0, 1.0, 0.0});
      inicializar(perfil, nperfiles);
}

Cono::Cono
(
 const int num_verts_per,
 const unsigned nperfiles
)
{
   ponerNombre(std::string("Cono"));
   assert(num_verts_per >= 3);
   
   vector<Tupla3f> perfil;
   /*perfil.push_back({0.0, 0.0, 0.0});*/

   for (int i=0; i<num_verts_per; i++)
      perfil.push_back({1-(float)i/(num_verts_per-1), (float)i/(num_verts_per-1), 0.0});  

   inicializar(perfil, nperfiles);
}

Esfera::Esfera
(
 const int num_verts_per,
 const unsigned nperfiles
)
{
   ponerNombre(std::string("Esfera"));
   assert(num_verts_per >= 3);

   Tupla3f p;
   Matriz4f rotacion;

   vector<Tupla3f> perfil;
   perfil.push_back({0.0, -1.0, 0.0});

   for (int i=0; i<num_verts_per; i++)
   {
      rotacion= MAT_Rotacion((180.0*i)/(num_verts_per-1), 1.0, 0.0, 0.0);
      p = rotacion * perfil[0];
      perfil.push_back(p);
   }

   inicializar(perfil,nperfiles);
}
