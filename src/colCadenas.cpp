/* 5088530 */
#include "../include/colCadenas.h"
#include "../include/cadena.h"

struct _rep_colCadenas {
  TCadena c[CANT_CADS];
};

TColCadenas crearColCadenas() {
  TColCadenas col = new _rep_colCadenas;
  for (int i = 0; i < CANT_CADS; i++) {
    col->c[i] = NULL;
  }
  return col;
}

/* en siguientes tareas
void liberarColCadenas(TColCadenas col) {
}
*/
nat cantidadColCadenas(nat pos, TColCadenas col) {
  return cantidadEnCadena(col->c[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
  bool presente = false;
  int i = 0;
  while (i < CANT_CADS && presente == false) {
    i = i + 1;
    if (estaEnCadena(natural,col->c[pos])) {presente = true;}
  }
  return presente;
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos, TColCadenas col) {
  col->c[pos] = insertarAlInicio(natural,real,col->c[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return infoCadena(natural,col->c[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->c[pos] = removerDeCadena(natural,col->c[pos]);
  return col;
}
