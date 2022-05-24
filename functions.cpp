#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//Case 0
void Init(int  &state, int  &type, char c){
  if(isalpha(c)){
    state = 1;
    //temp<<"Variable ";
  }

  else if (c == '/'){
    state = 14;
  }

  else if(c != ' '){
    state = 404;
  }
  
}

// Case 1
void VarI(int  &state, int  &type, char c, bool &spc ){
  if ((isdigit(c) || isalpha(c)) && !spc){
    state = 1;
  }
  else if (c == '='){
    state = 2;
    spc = false;
    //temp<<"Asignacion ";
    type = 4;
  }
  else if(c == ' '){
    spc = true;
  }
  else{
    state = 404;
  }
}

// Case 2
void Asign(int  &state, int  &type, char c, int &pCnt){
  bool token = true;
  if(isdigit(c)){  
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  }
  else if(c == ' '){
    state=2;
    token = false;
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
    //temp << "Parentesis que abre ";
  }
  else {
    state = 404;
  }
  if (token){
    type = 3;
  }
}

// Case 3
void Int(int &state, int  &type, char c, bool &spc, int &pCnt, bool exp){
  bool exp2 = exp;
  bool token = true;
  if(c == '.' && !exp){
    state = 4;
    spc = false;
    token = false;
  }
  else if(isdigit(c) && !spc){
    state = 3;
    token = false;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    //temp1if(!exp) //temp<<"Entero " <<"Potencia ";
    //temp1else //temp<<"Potencia ";
    exp = false;
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    //temp1if(!exp) //temp<<"Entero " <<"Suma ";
    //temp1else //temp<<"Suma ";
    exp = false;
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    //temp1if(!exp) //temp<<"Entero " <<"Resta ";
    //temp1else //temp<<"Resta ";
    exp = false;
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false;
    //temp1 if(!exp) //temp<<"Entero " <<"Multiplicacion ";
    //temp1 else //temp<<"Multiplicacion "; 
    exp = false;
  }
  else if(c =='/'){
    state = 12; 
    spc=false; 
    if(!exp) //temp<<"Entero ";
    exp = false;
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    //temp1 if(!exp) //temp<<"Entero " <<"Parentesis que cierra ";
    //temp1 else //temp<<"Parentesis que cierra ";
    exp = false;
    pCnt--;
  }
  else if (c == 'E' && !exp){ 
    state = 17; 
    spc=false; 
    //temp<<"Real ";
    token = false;
  }
  else if (c == ' '){
    state = 3; 
    spc=true;
    token = false;
  }
  else{
    state = 404;
  }
  if(token && !exp2){
    type = 1;
  }
  else if(token && exp2){
    type = 2;
  }
}

// Case 4
void Float(int &state, int  &type, char c, bool &spc, int &pCnt, bool exp){
  bool token = true;
  if(isdigit(c) && !spc){
    state = 4;
    token = false;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    //temp1 if(!exp) //temp<<"Real " <<"Potencia ";
    //temp1 else //temp<<"Potencia ";
    exp = false;
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    //temp1if(!exp) //temp<<"Real " <<"Suma ";
    //temp1 else //temp<<"Suma ";
    exp = false;
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    //temp1if(!exp) //temp<<"Real " <<"Resta ";
    //temp1else //temp<<"Resta ";
    exp = false;
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false; 
    //temp1 if(!exp) //temp<<"Real " <<"Multiplicacion ";
    //temp1 else //temp<<"Multiplicacion ";
    exp = false;
  }
  else if(c == '/'){
    state = 12; 
    spc=false; 
    if(!exp) //temp<<"Real ";
    exp = false;
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    //temp1 if(!exp) //temp<<"Real "<<"Parentesis que cierra "; 
    //temp1 else //temp<<"Parentesis que cierra ";
    exp = false;
    pCnt--;
  }
  else if (c == 'E' && !exp){ 
    state = 17; 
    spc=false; 
    //temp<<"Real ";
    token = false;
  }
  else if (c == ' '){
    state = 4; 
    spc=true;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 2;
  }
}

// Case 5
void Var(int &state, int  &type, char c, bool &spc, int &pCnt){
  bool token = true;
  if(isdigit(c) && !spc){
    state = 5;
    token = false;
  }
  else if(isalpha(c) && !spc){
    state = 5;
    token = false;
  }
  else if(c == '^'){
    state = 13; 
    spc=false; 
    //temp<<"Variable " <<"Potencia ";
  }
  else if(c == '+'){
    state = 9; 
    spc=false; 
    //temp<<"Variable " <<"Suma ";
  }
  else if (c == '-'){
    state = 10;
    spc=false; 
    //temp<<"Variable " <<"Resta ";
  }
  else if (c == '*'){ 
    state = 11; 
    spc=false; 
    //temp<<"Variable " <<"Multiplicacion ";
  }
  else if(c == '/'){
    state = 12; 
    spc=false; 
    //temp<<"Variable ";
  }
  else if (c == ')'){
    state = 16; 
    spc=false; 
    //temp<<"Variable "<<"Parentesis que cierra "; 
    pCnt--;
  }
  else if (c == ' '){
    state = 5; 
    spc=true;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 4;
  }
}

// Case 6
void Neg(int &state, char c, int &pCnt, bool exp){
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c) && !exp){
    state = 5;
  }
  else if(c == '.' && !exp) {
    state = 8;
  }
  else if (c == ' ' && !exp){
    state = 10;
  }
  else{
    state = 404;
  }
}

// Case 7
void ParA(int &state, int  &type, char c, int &pCnt){
  bool token = true;
  if(isdigit(c)){
    state = 3;
  }
  else if(isalpha(c)){
    state = 5;
  } 
  else if(c == ' '){
    state=7;
    token = false;
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
    //temp << "Parentesis que abre ";
    
  }
  else{
    state = 404;
  }
  if(token){
    type = 5;
  }
}

// Case 8
void Pnt(int &state, char c ){
  if(isdigit(c)){
    state = 4;
  }
  else{
    state = 404;
  }
}

// Case 9
void Sum(int &state, int  &type, char c, int &pCnt){
  bool token = true;
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
    //temp<<"Parentesis que abre";
  }
  else if(c == ' '){
    state = 9;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 3;
  }
}

// Case 10
void Res(int &state, int  &type, char c, int &pCnt){
  bool token = true;
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
    //temp<<"Parentesis que abre ";
  }
  else if (c == ' '){
    state = 10;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 3;
  }
}

// Case 11
void Mult(int &state, int  &type, char c, int &pCnt){
  bool token = true;
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
    //temp<<"Parentesis que abre ";
  }
  else if (c == ' '){
    state = 11;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 3;
  }
}

// Case 12
void Div(int &state, int  &type, char c, int &pCnt){
  bool token = true;
  if(isdigit(c)){
    state = 3;
    //temp<<"Division ";
  }
  else if(isalpha(c)){
    state = 5;
    //temp<<"Division ";
  }
  else if(c == '.') {
    state = 8;
    //temp<<"Division ";
  }
  else if(c == '-') {
    state = 6;
    //temp<<"Division ";
  }
  else if(c == '(') {
    state = 7;
    //temp<<"Division ";
  }
  else if(c == ' ') {
    state = 12;
    token = false;
  }
  else if(c == '/'){
    state = 15;
    //temp<<"Comentario ";
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 3;
  }
}

// Case 13
void Pot(int &state, int  &type, char c, int &pCnt){
  bool token = true;
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
    //temp<<"Parentesis que abre ";
  }
  else if(c == ' ') {
    state = 13;
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 3;
  }
}

// Case 14
void CommI(int &state, char c ){
  if(c == '/'){
    state = 15;
    //temp<<"Comentario "; 
  }
  else{
    state = 404;
  }
}

// Case 15
void Comm(int &state, char c ){
  state = 15; // Innecesario pero por si acaso
}

// Case 16
void ParC(int &state, int  &type, char c, int &pCnt){
  bool token = true;
  if (c == '^'){
    state = 13;
    //temp << "Potencia ";
  }
  else if (c == '*'){
    state = 11;
    //temp << "Multiplicacion ";
  }
  else if (c == '/'){
    state = 12;
  }
  else if (c == '+'){
    state = 9;
    //temp << "Suma ";
  }
  else if (c == '-'){
    state = 10;
    //temp << "Resta ";
  }
  else if (c == ')'){
    state = 16;
    pCnt--;
    //temp << "Parentesis que cierra ";
  }
  else if (c == 'E'){
    state = 17;
    //temp << "Real ";
  }
  else if (c == ' '){
    state = 16;
    //temp << "Parentesis que cierra ";
    token = false;
  }
  else{
    state = 404;
  }
  if(token){
    type = 5;
  }
}

// Case 17
void Exp(int &state, char c, bool &exp){
  exp = true;
  if (isdigit(c)){
    state = 3;
  }
  else if(c == '-') {
    state = 6;
  }
  else{
    state = 404;
  }
}