#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//Case 0
int Init(int  &state, char c){
  if(isalpha(c)){
    state = 1;
    cout<<"Variable ";
  }

  else if (c == '/'){
    state = 14;
  }

  else if(c != ' '){
    state = 404;
  }
  return state;
}

// Case 1
int VarI(int  &state, char c, bool &spc ){
  if ((isdigit(c) || isalpha(c)) && !spc){
    state = 1;
  }
  else if (c == '='){
    state = 2;
    spc = false;
    cout<<"Asignacion ";
  }
  else if(c == ' '){
    spc = true;
  }
  return state; 
}

// Case 2
int Asign(int  &state, char c, int &pCnt){
  if(isdigit(c)){  
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
    cout<<"Variable ";
  }
  else if(c == ' '){
    state=2;
  }
  else if(c == '.'){
    state = 8;
  }
  else if (c == '-'){
    state = 6;
  }
  else if (c == '('){ 
    state = 7;
    pCnt++;
    cout << "Parentesis que abre ";
  }
  else {
      state = 404;
  }
  return state;
}

// Case 3
int Int(int &state, char c, bool &spc, int &pCnt){
  if(c == '.'){
    state = 4;
    spc=false;
  }
  else if(isdigit(c) && !spc){
    state = 3;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    cout<<"Entero " <<"Potencia ";
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    cout<<"Entero " <<"Suma ";
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    cout<<"Entero " <<"Resta ";
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false; 
    cout<<"Entero " <<"Multiplicación ";
  }
  else if(c =='/'){
    state = 12; 
    spc=false; 
    cout<<"Entero " <<"División ";
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    cout<<"Entero "<<"Paréntesis que cierra "; 
    pCnt--;
  }
  else if (c == 'E'){ 
    state = 17; 
    spc=false; 
    cout<<"Real"<<endl;
  }
  else if (c == ' '){
    state = 19; spc=true;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 4
int Float(int &state, char c, bool &spc, int &pCnt){
  if(isdigit(c) && !spc){
    state = 4;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    cout<<"Real " <<"Potencia ";
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    cout<<"Real " <<"Suma ";
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    cout<<"Real " <<"Resta ";
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false; 
    cout<<"Real " <<"Multiplicación ";
  }
  else if(c == '/'){
    state = 12; 
    spc=false; 
    cout<<"Real " <<"División ";
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    cout<<"Real "<<"Paréntesis que cierra "; 
    pCnt--;
  }
  else if (c == 'E'){ 
    state = 17; 
    spc=false; 
    cout<<"Real "<<endl;
  }
  else if (c == ' '){
    state = 19; spc=true;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 5
int Var(int &state, char c, bool &spc, int &pCnt){
  if(isdigit(c) && !spc){
    state = 5;
  }
  else if(isalpha(c) && !spc){
    state = 5;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    cout<<"Variable" <<"Potencia ";
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    cout<<"Variable " <<"Suma ";
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    cout<<"Variable " <<"Resta ";
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false; 
    cout<<"Variable " <<"Multiplicación ";
  }
  else if(c == '/'){
    state = 12; 
    spc=false; 
    cout<<"Variable " <<"División ";
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    cout<<"Variable "<<"Paréntesis que cierra "; 
    pCnt--;
  }
  else if (c == 'E'){ 
    state = 17; 
    spc=false; 
    cout<<"Variable "<<endl;
  }
  else if (c == ' '){
    state = 19; 
    spc=true;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 6
int Neg(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.') {
    state = 8;
  }
  else if (c == ' '){
    state = 10;
  }
  else{
    switch(state){
      default: state = 404; break;
    }
  }
  return state;
}

// Case 7
int ParA(int &state, char c, int &pCnt){
  
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  } 
  else if(c == ' '){
    state=7;
  }
  else if(c == '.'){
    state = 8;
    return state;
  }
  else if (c == '-'){
    state = 6;
    return state;
  }
  else if (c == '('){ 
    state = 7;
    pCnt++;
    cout << "Parentesis que abre ";
    return state;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 8
int Pnt(int &state, char c ){
  if(isdigit(c)){
    state = 4;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 9
int Sum(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.'){ 
    state = 8; 
  }
  else if(c == '-'){
    state = 6;
  }
  else if(c == '('){
    state = 7;
  }
  else if(c == ' '){
    state = 9;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 10
int Res(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.'){
    state = 8;
  }
  else if(c == '-'){
    state = 6;
  }
  else if(c == '('){
    state = 7;
    pCnt++;
    cout<<"Paréntesis que abre ";
  }
  else if (c == ' '){
    state = 10;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 11
int Mult(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.'){
    state = 8;
  }
  else if(c == '-'){
    state = 6;
  }
  else if(c == '('){
    state = 7;
    pCnt++;
    cout<<"Paréntesis que abre ";
  }
  else if (c == ' '){
    state = 11;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 12
int Div(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.') {
    state = 8;
  }
  else if(c == '-') {
    state = 6;
  }
  else if(c == '(') {
    state = 7;
  }
  else if(c == ' ') {
    state = 12;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 13
int Pot(int &state, char c, int &pCnt){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == '.') {
    state = 8;
  }
  else if(c == '-') {
    state = 6;
  }
  else if(c == '(') {
    state = 7;
    pCnt++;
    cout<<"Paréntesis que abre ";
  }
  else if(c == ' ') {
    state = 13;
  }
  else{
    state = 404;
  }
  return state;
}

// Case 14
int CommI(int &state, char c ){
  if(c == '/'){
    state = 15;
    cout<<"Comentario "; 
  }
  else{
    state = 404;
  }
  return state;
}

// Case 15
int Comm(int &state, char c ){
  state = 15; // Inecesario pero por si acaso
  return state;
}

// Case 16
int ParC(int &state, char c, int &pCnt){
  if (c == '^'){
    state = 13;
    cout << "Potencia ";
  }
  else if (c == '*'){
    state = 11;
    cout << "Multiplicación ";
  }
  else if (c == '/'){
    state = 12;
    cout << "División ";
  }
  else if (c == '+'){
    state = 9;
    cout << "Suma ";
  }
  else if (c == '-'){
    state = 10;
    cout << "Resta ";
  }
  else if (c == ')'){
    state = 16;
    pCnt--;
    cout << "Paréntesis que cierra ";
  }
  else if (c == 'E'){
    state = 17;
    cout << "Real ";
  }
  else if (c == ' '){
    state = 16;
    cout << "Paréntesis que cierra ";
  }
  else{
    state = 404;
  }
  return state;
}

// Case 17
int Exp(int &state, char c ){ 
  if (isdigit(c)){
    state = 3;
  }
  else if(c == '-') {
    state = 6;
  }
  else{
    state = 404;
  }
  return state;
}

// // Case 18
// int SI(int &state, char c ){
//   switch(state){
//     case '=': state = 2; break;
//     case ' ': state = 18; break;
//     default: state = 404; break;
//   }
// }

// // Case 19
// int SMed(int &state, char c, int &pCnt){
//   switch(state){
//     case '^': state = 13; break;
//     case '+': state = 9; break;
//     case '-': state = 10; break;
//     case '*': state = 11; break;
//     case '/': state = 12; break;
//     case ')': state = 16; pCnt++; break;
//     case ' ': state = 19; break;
//     default: state = 404; break;
//   }
// }