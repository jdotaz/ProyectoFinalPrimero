#include <iostream>
#include <conio.h>
#include "ArregloPropietarios.cpp"
using namespace std;

void pausa(){
  cout<<"Pulsa una tecla para continuar...";
  getch();
}

Propietario crearPropietario(int codigo){
  string nombre;
  string apellido;
  string telefono;
  string direccion;
  cout<<"Crear nuevo Propietario:"<<endl;
  cout<<"   Ingrese el nombre del propietario: ";
  cin.ignore();
  getline(cin,nombre);
  cout<<"   Ingrese el apellido del propietario: ";
  cin.ignore();
  getline(cin,apellido);
  cout<<"   Ingrese el telefono del propietario: ";
  cin.ignore();
  getline(cin,telefono);
  cout<<"   Ingrese la direccion del propietario: ";
  cin.ignore();
  getline(cin,direccion);
  Propietario nuevoP(nombre,apellido,telefono,direccion,codigo);
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
  cin.ignore();
  getline(cin,nombre);
  cout<<"   Ingrese la especie del animal: "<<endl;
  cout<<"     1.Perro"<<endl;
  cout<<"     2.Gato"<<endl;
  cout<<"     3.Otro"<<endl;
  cin>>especie;
  cout<<"   Ingrese la raza del animal: ";
  cin.ignore();
  getline(cin,raza);
  cout<<"   Ingrese el color del animal: ";
  cin.ignore();
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
  Animal nuevoA(codigoPropietario,nombre,especie,raza,color,day,month,year,sexo);
  return nuevoA;
}

void cargarDatos(ArregloPropietarios &general_,int codigos){
  Propietario nuevo("Jose","Quispe","123456789","casa1",0);
  general_.addPropietario(nuevo);

  Propietario nuevo2("Jose","Reyes","2236458769","casa2",1);
  general_.addPropietario(nuevo2);

  Propietario nuevo3("Edgar","Alarcon","435678567","casa3",2);
  general_.addPropietario(nuevo3);

  Propietario nuevo4("Camila","Casas","506956780","casa4",3);
  general_.addPropietario(nuevo4);

  Propietario nuevo5("Roberto","Perez","577456789","casa5",4);
  general_.addPropietario(nuevo5);

  Propietario nuevo6("Alejandra","Diaz","230459678","casa6",5);
  general_.addPropietario(nuevo6);

  Propietario nuevo7("Dimitri","Vladimir","405967124","casa7",6);
  general_.addPropietario(nuevo7);
}


main(){
  bool bucle=true;
  int globCodigo=7;
  ArregloPropietarios general;
  cargarDatos(general,globCodigo);

  while (bucle){
    system("cls");
    cin.clear();
    cout<<"           Bienvenido al Sistema de la Veterinaria ObVet"<<endl;
    cout<<"Eliga una opcion:"<<endl;
    cout<<" 1.Inscribir nueva mascota."<<endl;
    cout<<" 2.Buscar una mascota."<<endl;
    cout<<" 3.Salir."<<endl;
    int opcionPrincipal;
    cin>>opcionPrincipal;
    switch (opcionPrincipal) {
      case 1:{
        system("cls");
        cout<<"El propietario ya ha sido registrado?"<<endl;
        cout<<" 1.Si"<<endl;
        cout<<" 1.No"<<endl;
        int opcionCaso1;
        cin>>opcionCaso1;
        switch (opcionCaso1) {
          case 1:{
            system("cls");
            cout<<"Escriba el nombre: ";
            string busqNombre;
            cin.ignore();
            getline(cin,busqNombre);
            ArregloPropietarios busqueda;
            for(int i=0;i<general.getCantidad();i++){
              if ((general.getPropietario(i)).getNombre()==busqNombre){
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
            general.addMascotaAPropietario(globCodigo,crearAnimal(globCodigo++));

          }
        }
        break;
      }
      case 2:{
        system("cls");
        cout<<"ingrese el nombre del propietario: ";
        string busqNombre;
        cin.ignore();
        getline(cin,busqNombre);
        ArregloPropietarios busqueda;
        for(int i=0;i<general.getCantidad();i++){
          if ((general.getPropietario(i)).getNombre()==busqNombre){
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
      }
      case 3:{
        system("cls");
        bucle=false;
        cout<<"Adios!! :D"<<endl;
      }
    }
  }
}
