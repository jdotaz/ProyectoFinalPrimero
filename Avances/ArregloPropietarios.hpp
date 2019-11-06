#ifndef ArregloPropietarios_hpp
#define ArregloPropietarios_hpp

#include <stdio.h>
#include <iostream>
#include "Propietario.cpp"
using namespace std;

class ArregloPropietarios {
private:
  Propietario *lista;
  int cantidad;
  void copiarArr(Propietario a[],Propietario b[],int tam);
  void addCantidad();
  void deleteCantidad();
public:
  ArregloPropietarios();
  ArregloPropietarios(int cantidad_);
  ArregloPropietarios(const ArregloPropietarios &otro);
  ~ArregloPropietarios();
  int getCantidad();
  Propietario getPropietario(int pos);
  void addPropietario(Propietario nuevo);
  void deletePropietario(int pos);
  void chancePropietario(Propietario nuevo,int pos);
  void addMascotaAPropietario(int codigo_,Animal mascota);
protected:

};


#endif
