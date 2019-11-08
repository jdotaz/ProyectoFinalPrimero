#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Animal {
private:
  //Instancias
  int codPropietario;
  string nombre;
  int especie;
  string raza;
  string color;
  int nacimiento[3];
  int sexo;
  //Metodos privados

public:
  //Constructores
  Animal();
  Animal(int codigo_,string nombre_,int especie_,string raza_,string color_,int day,int month, int year,int sexo_,bool existente);
  Animal(const Animal &otro);
  ~Animal();
  //Obtencion de datos
  int getCodigoPropietario();
  string getNombre();
  string getEspecie();
  string getRaza();
  string getColor();
  int getNacimiento(int pos);
  string getSexo();
  //Edicion de datos
  void editCodigoProietario(int codigo_);
  void editNombre(string nombre_);
  void editEspecie(int especie_);
  void editRaza(string raza_);
  void editColor(string color_);
  void editNacimiento(int day,int month, int year);
  void editSexo(int sexo_);
};


#endif
