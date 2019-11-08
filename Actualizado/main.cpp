#include <iostream>
#include <fstream>
#include <conio.h>
#include "ArregloPropietarios.cpp"
using namespace std;

void pausa(){
  cout<<"Pulsa una tecla para continuar...";
  getch();
}

void cargar(int &glob,ArregloPropietarios &general_){
  bool existe=true;
  while (existe){
    string codigo=to_string(glob)+".txt";
    fstream nuevo(codigo);
    if(nuevo.is_open()){
      int codigo;
      string nombre;
      string apellido;
      string telefono;
      string direccion;
      nuevo>>codigo;
      nuevo>>nombre;
      nuevo>>apellido;
      nuevo>>telefono;
      nuevo>>direccion;
      Propietario nuevoP(nombre,apellido,telefono,direccion,codigo);
      while(!nuevo.eof()){
        int codPropietario;
        string nombre;
        int especie;
        string raza;
        string color;
        int day;
        int month;
        int year;
        int sexo;
        nuevo>>codPropietario;
        nuevo>>nombre;
        nuevo>>especie;
        nuevo>>raza;
        nuevo>>color;
        nuevo>>day;
        nuevo>>month;
        nuevo>>year;
        nuevo>>sexo;
        Animal nuevoA(codPropietario,nombre,especie,raza,color,day,month,year,sexo);
        if(!nuevo.eof()){
          nuevoP.addMascota(nuevoA);
        }
      }
      general_.addPropietario(nuevoP);
      glob++;
    }else{
      existe=false;
    }

  }
}

bool compararString(string buscando,string porEncontrar){
  int tam;
  (buscando.length()<=porEncontrar.length())?tam=buscando.length():tam=porEncontrar.length();
  for(int i=0;i<tam;i++){
    int n=static_cast<int>(buscando[i]);
    if ((n>=65)and(n<=90)){
      buscando[i]=static_cast<char>(n+32);
    }
    n=static_cast<int>(porEncontrar[i]);
    if ((n>=65)and(n<=90)){
      porEncontrar[i]=static_cast<char>(n+32);
    }
    if(buscando[i]!=porEncontrar[i]){
      return false;
    }
  }
  return true;
}

Propietario crearPropietario(int codigo){
  string nombre;
  string apellido;
  string telefono;
  string direccion;
  cout<<"Crear nuevo Propietario:"<<endl;
  cout<<"   Ingrese el nombre del propietario: ";
  fflush(stdin);
  getline(cin,nombre);
  cout<<"   Ingrese el apellido del propietario: ";
  fflush(stdin);
  getline(cin,apellido);
  cout<<"   Ingrese el telefono del propietario: ";
  fflush(stdin);
  getline(cin,telefono);
  cout<<"   Ingrese la direccion del propietario: ";
  fflush(stdin);
  getline(cin,direccion);
  Propietario nuevoP(nombre,apellido,telefono,direccion,codigo,0);
  return nuevoP;
}

Animal crearAnimal(int codigoPropietario){
  string nombre;
  int especie;
  string raza;
  string color;
  int day;
  int month;
  int year;
  int sexo;
  cout<<"Crear nuevo animal:"<<endl;
  cout<<"   Ingrese el nombre del animal: ";
  fflush(stdin);
  getline(cin,nombre);
  cout<<"   Ingrese la especie del animal: "<<endl;
  cout<<"     1.Perro"<<endl;
  cout<<"     2.Gato"<<endl;
  cout<<"     3.Otro"<<endl;
  cin>>especie;
  cout<<"   Ingrese la raza del animal: ";
  fflush(stdin);
  getline(cin,raza);
  cout<<"   Ingrese el color del animal: ";
  fflush(stdin);
  getline(cin,color);
  cout<<"   Ingrese la fecha de nacimiento del animal:"<<endl;
  cout<<"     -Dia: ";
  cin>>day;
  cout<<"     -Mes: ";
  cin>>month;
  cout<<"     -Ano: ";
  cin>>year;
  cout<<"   Ingrese el sexo del animal:"<<endl;
  cout<<"     1.Macho"<<endl;
  cout<<"     2.Hembra"<<endl;
  cin>>sexo;
  Animal nuevoA(codigoPropietario,nombre,especie,raza,color,day,month,year,sexo,0);
  return nuevoA;
}




main(){
  bool bucle=true;
  int globCodigo=0;
  ArregloPropietarios general;
  cargar(globCodigo,general);

  while (bucle){
    system("cls");
    cout<<globCodigo;
    cin.clear();
    cout<<"           Bienvenido al Sistema de la Veterinaria ObVet"<<endl;
    cout<<"Eliga una opcion:"<<endl;
    cout<<" 1.Inscribir nueva mascota."<<endl;
    cout<<" 2.Buscar una mascota."<<endl;
    cout<<" 3.Lista de Propietario."<<endl;
    cout<<" 4.Salir."<<endl;
    int opcionPrincipal;
    cin>>opcionPrincipal;
    switch (opcionPrincipal) {
      case 1:{
        system("cls");
        cout<<"El propietario ya ha sido registrado?"<<endl;
        cout<<" 1.Si"<<endl;
        cout<<" 2.No"<<endl;
        int opcionCaso1;
        cin>>opcionCaso1;
        switch (opcionCaso1) {
          case 1:{
            system("cls");
            cout<<"Escriba el nombre: ";
            string busqNombre;
            fflush(stdin);
            getline(cin,busqNombre);
            ArregloPropietarios busqueda;
            for(int i=0;i<general.getCantidad();i++){
              if (compararString((general.getPropietario(i)).getNombre(),busqNombre)){
                busqueda.addPropietario(general.getPropietario(i));
              }
            }
            system("cls");
            cout<<"Se han encontrado "<<busqueda.getCantidad()<<" propietarios:"<<endl;
            for(int i=0;i<busqueda.getCantidad();i++){
              cout<<"   "<<i+1<<"."<<(busqueda.getPropietario(i)).getNombre()<<" "<<(busqueda.getPropietario(i)).getApellido()<<endl;
            }
            cout<<"Cual Propietario escoje?: ";
            int opc;
            cin>>opc;
            system("cls");
            cout<<"Regristrando nueva mascota para "<<(busqueda.getPropietario(opc-1)).getNombre()<<" "<<(busqueda.getPropietario(opc-1)).getApellido()<<endl;
            int nuevocodigo=(busqueda.getPropietario(opc-1)).getCodigo();
            general.addMascotaAPropietario(nuevocodigo,crearAnimal(nuevocodigo));
            pausa();
            break;
          }
          case 2:{
            system("cls");
            general.addPropietario(crearPropietario(globCodigo));
            system("cls");
            general.addMascotaAPropietario(globCodigo,crearAnimal(globCodigo));
            globCodigo++;

          }
        }
        break;
      }
      case 2:{
        system("cls");
        cout<<"ingrese el nombre del propietario: ";
        string busqNombre;
        fflush(stdin);
        getline(cin,busqNombre);
        ArregloPropietarios busqueda;
        for(int i=0;i<general.getCantidad();i++){
          if (compararString((general.getPropietario(i)).getNombre(),busqNombre)){
            busqueda.addPropietario(general.getPropietario(i));
          }
        }
        system("cls");
        cout<<"Se han encontrado "<<busqueda.getCantidad()<<" propietarios:"<<endl;
        for(int i=0;i<busqueda.getCantidad();i++){
          cout<<"   "<<i+1<<"."<<(busqueda.getPropietario(i)).getNombre()<<" "<<(busqueda.getPropietario(i)).getApellido()<<endl;
        }
        cout<<"Cual Propietario escoje?: ";
        int opc;
        cin>>opc;
        system("cls");
        Propietario escogido=busqueda.getPropietario(opc-1);
        cout<<"Se han encontrado "<<escogido.getNumeroMascotas()<<" mascotas:"<<endl;
        for(int i=0;i<escogido.getNumeroMascotas();i++){
          cout<<"   "<<i+1<<"."<<(escogido.getMascota(i)).getNombre()<<"."<<endl;
        }
        cout<<"Cual desea consultar?: ";
        int otraOpcionMas;
        cin>>otraOpcionMas;
        Animal escogidoA=escogido.getMascota(otraOpcionMas-1);
        system("cls");
        cout<<"     Ficha medica de "<<escogidoA.getNombre()<<endl;
        cout<<"Especie: "<<escogidoA.getEspecie()<<endl;
        cout<<"Raza: "<<escogidoA.getRaza()<<endl;
        cout<<"Color: "<<escogidoA.getColor()<<endl;
        cout<<"Fecha de nacimiento: "<<escogidoA.getNacimiento(0)<<"/"<<escogidoA.getNacimiento(1)<<"/"<<escogidoA.getNacimiento(2)<<endl;
        cout<<"Sexo: "<<escogidoA.getSexo()<<endl;
        pausa();
        break;
      }
      case 3:{
        system("cls");
        for(int i=0;i<general.getCantidad();i++){
          cout<<"   "<<i+1<<"."<<(general.getPropietario(i)).getNombre()<<" "<<(general.getPropietario(i)).getApellido()<<endl;
        }
        pausa();
        break;
      }
      case 4:{
        system("cls");
        bucle=false;
        cout<<"Adios!! :D"<<endl;
      }

    }
  }
}
