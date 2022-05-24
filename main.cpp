#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <typeinfo>
#include <string>
#include <chrono>
#include "functions.cpp"

using namespace std;



int main()
{
  string archivo;
  cout<<"Escribe el nombre del archivo a leer"<<endl;
  cin>>archivo;
  string filename(archivo+".txt");
  vector<string> lines;
  string line;
  

  ifstream input_file(filename);
  
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '"
        << filename << "'" << endl;
    return EXIT_FAILURE;
  }

  while (getline(input_file, line)){
    lines.push_back(line);
  }

  input_file.close();

  auto start = chrono::high_resolution_clock::now();

  //Crear archivo HTML
  //Insertar inicio de archivo <div>
  ofstream file;
  file.open("Output.html");
  file<< "<!DOCTYPE html>"<<endl;
  file<< "<html>"<<endl;
  file<< "<head>"<<endl;
  file<< "<style>"<<endl;
  file<< "body {background-color: #262626;}"<<endl;
  file<< ".Entero {color: orange; display: inline;}"<<endl;
  file<< ".Flotante {color: #d330e6; display: inline;}"<<endl;
  file<< ".Operador {color: #00f7ff; display: inline;}"<<endl;
  file<< ".Identificador {color: yellow; display: inline;}"<<endl;
  file<< ".Simbolo {color: #97ff5e; display: inline;}"<<endl;
  file<< ".Comentario {color: #adadad; display: inline;}"<<endl;
  file<< ".Error {color: red; display: inline;}"<<endl;

  file<< "</style>"<<endl;
  file<< "</head>"<<endl;
  file<< "<body>"<<endl;

  file<< "<p class=\"Entero\">Entero</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Flotante\">Flotante</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Operador\">Operador</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Identificador\">Identificador</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Simbolo\">Simbolo</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Comentario\">Comentario</p>"<<endl<<"<p />"<<endl;
  file<< "<p class=\"Error\">Error</p>"<<endl<<"<p />"<<endl;

  int state = 0;
  bool spc = false;
  bool exp = false;
  int pCnt = 0;
  int type = 0;
  string vari = "";
  bool del = false;
  for (int n=0;n<lines.size();n++){
    cout<<n+1<<" ";
    for (int m=0;m<lines[n].size();m++){
      if(pCnt < 0) state=404;
      type = 0;
      switch (state)
      {
        case 0: Init(state,type,lines[n][m]); break;
        case 1: VarI(state,type,lines[n][m],spc); break;
        case 2: Asign(state,type,lines[n][m], pCnt); break;
        case 3: Int(state,type,lines[n][m],spc, pCnt, exp); break;
        case 4: Float(state,type,lines[n][m],spc, pCnt, exp); break;
        case 5: Var(state,type,lines[n][m],spc, pCnt); break;
        case 6: Neg(state,lines[n][m], pCnt, exp); break;
        case 7: ParA(state,type,lines[n][m], pCnt); break;
        case 8: Pnt(state,lines[n][m]); break;
        case 9: Sum(state,type,lines[n][m], pCnt); break;
        case 10: Res(state,type,lines[n][m], pCnt); break;
        case 11: Mult(state,type,lines[n][m], pCnt); break;
        case 12: Div(state,type,lines[n][m], pCnt); break;
        case 13: Pot(state,type,lines[n][m], pCnt); break;
        case 14: CommI(state,lines[n][m]); break;
        case 15: Comm(state,lines[n][m]); break;
        case 16: ParC(state,type, lines[n][m], pCnt); break;
        case 17: Exp(state,lines[n][m],exp); break;
        case 404: break;
      } //Switch
      if (type != 0){
        
        del = true;
        switch (type)
        {
          case 1: cout<<" Entero "; file<< "<p class=\"Entero\">"; break;
          case 2: cout<<" Flotante "; file<< "<p class=\"Flotante\">"; break;
          case 3: cout<<" Operador "; file<< "<p class=\"Operador\">"; break;
          case 4: cout<<" Identificador "; file<< "<p class=\"Identificador\">"; break;
          case 5: cout<<" Simbolo "; file<< "<p class=\"Simbolo\">"; break;
          case 6: cout<<" Comentario "; file<< "<p class=\"Comentario\">"; break;
        }
        cout<<vari;
        file<<vari;
        file<< "</p>"<<endl;
        vari = "";
      }
      vari += lines[n][m];
    } 
    if(pCnt != 0){
      state = 404;
    }
    switch (state)
    {
      case 3: if(!exp){ cout<<" Entero "<<vari; file<< "<p class=\"Entero\">"; file<<vari; file<<"</p>"<<endl; break;} else{cout<<" Flotante "<<vari; file<< "<p class=\"Flotante\">"; file<<vari; file<< "</p>"<<endl;break;}
      case 4: if(!exp) cout<<" Flotante "<<vari; file<< "<p class=\"Flotante\">"; file<<vari; file<< "</p>"<<endl;break;
      case 5: cout<<" Identificador "<<vari; file<< "<p class=\"Identificador\">"; file<<vari; file<< "</p>"<<endl;break;
      case 0: cout<<""; break;
      case 15: cout<<" Comentario "<<vari; file<< "<p class=\"Comentario\">"; file<<vari; file<< "</p>"<<endl;break;
      case 16: cout<<" Simbolo "<<vari; file<< "<p class=\"Simbolo\">"; file<<vari; file<< "</p>"<<endl;break;
      default: cout<<" Error al final de la linea "<<vari<<n+1; file<<"<p class=\"Error\">"; file<<vari; break;
    }
    cout<<endl;
    spc=false;
    exp=false;
    pCnt=0;
    state=0;
    vari="";
    file << "<p/>"; 
  }

file<< "</body>"<<endl;
file<< "</html>"<<endl;
file.close();
auto end = chrono::high_resolution_clock::now();
cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
return EXIT_SUCCESS;
}