#include <iostream>
#include <fstream>
#include <conio.h>
#include "ArregloPropietarios.cpp"
using namespace std;



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


int main(){
  bool existe=true;
  while (existe){
    string codigo=to_string(globCodigo)+"txt";
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
    }else{
      existe=false;
    }
    globCodigo++;
  }

}
