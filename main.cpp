#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <typeinfo>
#include <string>
#include "functions.cpp"

// https://prod.liveshare.vsengsaas.visualstudio.com/join?61068C5AD74BC64CC84B23E6DF985B769333

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
  int state = 0;
  bool spc = false;
  bool err = false;
  int pCnt = 0;
  for (int n=0;n<lines.size();n++){
    for (int m=0;m<lines[n].size();m++){
      switch (state)
      {
        case 0: state=Init(state,lines[n][m]); break;
        case 1: state=VarI(state,lines[n][m],spc); break;
        case 2: state=Asign(state,lines[n][m], pCnt); break;
        case 3: state=Int(state,lines[n][m],spc, pCnt); break;
        case 4: state=Float(state,lines[n][m],spc, pCnt); break;
        case 5: state=Var(state,lines[n][m],spc, pCnt); break;
        case 6: state=Neg(state,lines[n][m], pCnt); break;
        case 7: state=ParA(state,lines[n][m], pCnt); break;
        case 8: state=Pnt(state,lines[n][m]); break;
        case 9: state=Sum(state,lines[n][m], pCnt); break;
        case 10: state=Res(state,lines[n][m], pCnt); break;
        case 11: state=Mult(state,lines[n][m], pCnt); break;
        case 12: state=Div(state,lines[n][m], pCnt); break;
        case 13: state=Pot(state,lines[n][m], pCnt); break;
        case 14: state=CommI(state,lines[n][m]); break;
        case 15: state=Comm(state,lines[n][m]); break;
        case 16: state=ParC(state,lines[n][m], pCnt); break;
        case 17: state=Exp(state,lines[n][m]); break;
        case 404: cout<<"Error en la linea "<<n+1<<" en el caracter "<<m+1<<endl; err=true; break; 
      } //Switch
    } //For 2
    if(err) break;
      //For 1
    if(err){
      cout<<endl;
      state=0;
      err=false;
      continue;
    } 
    switch (state)
    {
      case 3: cout<<"Entero "; break;
      case 4: cout<<"Real "; break;
    }
    cout<<endl;
    state=0;
  }
return EXIT_SUCCESS;

}