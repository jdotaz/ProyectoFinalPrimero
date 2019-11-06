#include "Animal.hpp"
//Constructores
Animal::Animal(){
  codPropietario=0;
  nombre="";
  especie=0;
  raza="";
  color="";
  nacimiento[0]=0;
  nacimiento[1]=0;
  nacimiento[2]=0;
  sexo=0;
}

Animal::Animal(int codigo_,string nombre_,int especie_,string raza_,string color_,int day,int month, int year,int sexo_){
  codPropietario=codigo_;
  nombre=nombre_;
  especie=especie_;
  raza=raza_;
  color=color_;
  nacimiento[0]=day;
  nacimiento[1]=month;
  nacimiento[2]=year;
  sexo=sexo_;
}

Animal::Animal(const Animal &otro){
  codPropietario=otro.codPropietario;
  nombre=otro.nombre;
  especie=otro.especie;
  raza=otro.raza;
  color=otro.color;
  nacimiento[0]=otro.nacimiento[0];
  nacimiento[1]=otro.nacimiento[1];
  nacimiento[2]=otro.nacimiento[2];
  sexo=otro.sexo;
}

Animal::~Animal(){
}

//Obtencion de datos
int Animal::getCodigoPropietario(){
  return codPropietario;
}

string Animal::getNombre(){
  return nombre;
}

string Animal::getEspecie(){
  if (especie==1){
    return "Perro";
  }else if(especie==2){
    return "Gato";
  }
  return "Otro";
}

string Animal::getRaza(){
  return raza;
}

string Animal::getColor(){
  return color;
}

int Animal::getNacimiento(int pos){
  return nacimiento[pos];
}

string Animal::getSexo(){
  if (sexo==1){
    return "Macho";
  }
  return "Hembra";
}
//Edicion de datos
void Animal::editCodigoProietario(int codigo_){
  codPropietario=codigo_;
}

void Animal::editNombre(string nombre_){
  nombre=nombre_;
}

void Animal::editEspecie(int especie_){
  especie=especie_;
}

void Animal::editRaza(string raza_){
  raza=raza_;
}

void Animal::editColor(string color_){
  color=color_;
}

void Animal::editNacimiento(int day,int month, int year){
  nacimiento[0]=day;
  nacimiento[1]=month;
  nacimiento[2]=year;
}

void Animal::editSexo(int sexo_){
  sexo=sexo_;
}
