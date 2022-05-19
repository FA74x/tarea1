/* 5088530 */

#include "../include/cadena.h"
#include "../include/colCadenas.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena {
  TInfo i;
  TCadena p;
};

TCadena crearCadena() {
  TCadena cad = NULL;
  return cad;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/

nat cantidadEnCadena(TCadena cad) {
  TCadena aux = cad;
  nat contador = 0;
  while (aux != NULL) {
    aux = aux->p;
    contador = contador + 1;
  }
  return contador;
}

bool estaEnCadena(nat natural, TCadena cad) {
  TCadena aux = cad;
  bool presente = false;
  while ((presente == false) && (aux != NULL)) {
    if (natInfo(aux->i) == natural) {presente = true;}
    aux = aux->p;
  }
  return presente;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  TCadena aux = new _rep_cadena;
  aux->i = crearInfo(natural,real);
  aux->p = cad;
  return aux;
}

TInfo infoCadena(nat natural, TCadena cad) {
  TCadena aux = cad;
  while((aux != NULL) && (natInfo(aux->i) != natural)) {
    aux = aux->p;
  }
  return aux->i;
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  TCadena auxborrar = cad;
  TCadena aux = NULL;
  while((auxborrar != NULL) && ((natInfo(auxborrar->i) != natural))) {
    aux = auxborrar;
    auxborrar = auxborrar->p;
  }
  if(aux == NULL) {cad = cad->p;}
  else {aux->p = auxborrar->p;}
  delete auxborrar;
  return cad;
}

void imprimirCadena(TCadena cad) {
  TCadena aux = cad;
  while (aux != NULL) {
    printf("(%u,%0.2f)",natInfo(aux->i),realInfo(aux->i));
    aux = aux->p;
  }
  printf("\n");
}
