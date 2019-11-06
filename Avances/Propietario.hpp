#ifndef Propietario_hpp
#define Propietario_hpp

#include <stdio.h>
#include <iostream>
#include "Animal.cpp"
using namespace std;

class Propietario {
private:
  //Instancias
  string nombre;
  string apellido;
  string telefono;
  string direcccion;
  int codigo;
  int cantidad;
  Animal *mascotas;
  //Metodos privados
  void copiarArr(Animal a[],Animal b[],int tam);
  void addCantidad();
  void deleteCantidad();

public:
  //Constructores
  Propietario();
  Propietario(string nombre_,string apellido_,string telefono_,string direcccion_,int codigo_);
  Propietario(const Propietario &otro);
  ~Propietario();
  //Obtencion de datos
  string getNombre();
  string getApellido();
  string getTelefono();
  string getDireccion();
  int getCodigo();
  int getNumeroMascotas();
  Animal getMascota(int pos);
  //Edicion de datos
  void editNombre(string nombre_);
  void editApellido(string apellido_);
  void editTelefono(string telefono_);
  void editDireccion(string direcccion_);
  void editCodigo(int codigo_);
  //Edicion del arreglo
  void addMascota(Animal nuevo);
  void deleteMascota(int pos);
  void chanceMAscota(Animal nuevo,int pos);
};


#endif /* Propietario_hpp */
