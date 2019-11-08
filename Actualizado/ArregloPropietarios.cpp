#include "ArregloPropietarios.hpp"
//Constructores
ArregloPropietarios::ArregloPropietarios(){
  cantidad=0;
  lista=new Propietario[cantidad];
}

ArregloPropietarios::ArregloPropietarios(int cantidad_){
  cantidad=cantidad_;
  lista=new Propietario[cantidad];
}

ArregloPropietarios::ArregloPropietarios(const ArregloPropietarios &otro){
  cantidad=otro.cantidad;
  copiarArr(lista,otro.lista,cantidad);
}

ArregloPropietarios::~ArregloPropietarios(){
}

int ArregloPropietarios::getCantidad(){
  return cantidad;
}

Propietario ArregloPropietarios::getPropietario(int pos){
  return lista[pos];
}
//Metodos privados
void ArregloPropietarios::copiarArr(Propietario a[],Propietario b[],int tam){
  for(int i=0;i<tam;i++){
    a[i]=b[i];
  }
}

void ArregloPropietarios::addCantidad(){
  Propietario *guar=new Propietario[cantidad];
  copiarArr(guar,lista,cantidad);
  delete[] lista;
  lista=new Propietario[cantidad+1];
  copiarArr(lista,guar,cantidad);
  cantidad++;
  delete[] guar;
}

void ArregloPropietarios::deleteCantidad(){
  Propietario *guar=new Propietario[cantidad];
  copiarArr(guar,lista,cantidad);
  delete[] lista;
  lista=new Propietario[cantidad-1];
  copiarArr(lista,guar,cantidad-1);
  cantidad--;
  delete[] guar;
}

//Edicion del arreglo
void ArregloPropietarios::addPropietario(Propietario nuevo){
  addCantidad();
  lista[cantidad-1]=nuevo;
}

void ArregloPropietarios::deletePropietario(int pos){
  lista[pos].~Propietario();
  for(int i=pos;i<cantidad-1;i++){
    lista[i]=lista[i+1];
  }
  deleteCantidad();
}

void ArregloPropietarios::chancePropietario(Propietario nuevo,int pos){
  lista[pos].~Propietario();
  lista[pos]=nuevo;
}

void ArregloPropietarios::addMascotaAPropietario(int codigo_,Animal mascota){
  for(int i=0;i<cantidad;i++){
    if (lista[i].getCodigo()==codigo_){
      lista[i].addMascota(mascota);
    }
  }
}
