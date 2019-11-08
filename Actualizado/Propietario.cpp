#include "Propietario.hpp"
//Consturctores
Propietario::Propietario(){
   nombre="";
   apellido="";
   telefono="";
   direcccion="";
   codigo=0;
   cantidad=0;
   mascotas=new Animal[cantidad];
}

Propietario::Propietario(string nombre_,string apellido_,string telefono_,string direcccion_,int codigo_,bool existente=1){
  nombre=nombre_;
  apellido=apellido_;
  telefono=telefono_;
  direcccion=direcccion_;
  codigo=codigo_;
  cantidad=0;
  mascotas=new Animal[cantidad];
  if(!existente){
    string archivo=to_string(codigo)+".txt";
    ofstream crear(archivo);
    crear<<codigo<<endl;
    crear<<nombre<<endl;
    crear<<apellido<<endl;
    crear<<telefono<<endl;
    crear<<direcccion<<endl;
  }
}

Propietario::Propietario(const Propietario &otro){
  nombre=otro.nombre;
  apellido=otro.apellido;
  telefono=otro.telefono;
  direcccion=otro.direcccion;
  codigo=otro.codigo;
  cantidad=otro.cantidad;
  mascotas=new Animal[cantidad];
  copiarArr(mascotas,otro.mascotas,cantidad);
}

Propietario::~Propietario(){
}

//Obtencion de datos
string Propietario::getNombre(){
  return nombre;
}

string Propietario::getApellido(){
  return apellido;
}

string Propietario::getTelefono(){
  return telefono;
}

string Propietario::getDireccion(){
  return direcccion;
}

int Propietario::getCodigo(){
  return codigo;
}

int Propietario::getNumeroMascotas(){
  return cantidad;
}

Animal Propietario::getMascota(int pos){
  return mascotas[pos];
}

//Edicion de datos
void Propietario::editNombre(string nombre_){
  nombre=nombre_;
}

void Propietario::editApellido(string apellido_){
  apellido=apellido_;
}

void Propietario::editTelefono(string telefono_){
  telefono=telefono_;
}

void Propietario::editDireccion(string direcccion_){
  direcccion=direcccion_;
}

void Propietario::editCodigo(int codigo_){
  codigo=codigo_;
}

//Metodos privados
void Propietario::copiarArr(Animal a[],Animal b[],int tam){
  for(int i=0;i<tam;i++){
    a[i]=b[i];
  }
}

void Propietario::addCantidad(){
  Animal *guar=new Animal[cantidad];
  copiarArr(guar,mascotas,cantidad);
  delete[] mascotas;
  mascotas=new Animal[cantidad+1];
  copiarArr(mascotas,guar,cantidad);
  cantidad++;
  delete[] guar;
}

void Propietario::deleteCantidad(){
  Animal *guar=new Animal[cantidad];
  copiarArr(guar,mascotas,cantidad);
  delete[] mascotas;
  mascotas=new Animal[cantidad-1];
  copiarArr(mascotas,guar,cantidad-1);
  cantidad--;
  delete[] guar;
}

//Edicion del arreglo
void Propietario::addMascota(Animal nuevo){
  addCantidad();
  mascotas[cantidad-1]=nuevo;
}

void Propietario::deleteMascota(int pos){
  mascotas[pos].~Animal();
  for(int i=pos;i<cantidad-1;i++){
    mascotas[i]=mascotas[i+1];
  }
  deleteCantidad();
}

void Propietario::chanceMAscota(Animal nuevo,int pos){
  mascotas[pos].~Animal();
  mascotas[pos]=nuevo;
}
