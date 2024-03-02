#define M1//Если убрать M1, то условие для компиляции version 1 исчезнет
#define M2 (1+2)
#define M3(x) ((x)*2)
#define M4(x,y) x ## y
#define M5(x) #x // Превращает аргумент в строку
M4(hello,world)
M5(hello)
// Всегда в макросах ставим скобки!!!

//Условная компиляция
#if defined(M1)
version 1
#else
version 2
#endif
//С помошью ключа -D можно передвавать макросы, например: g++ -E -D define.cc
#include "main.hh"
#include "main.hh" // Пробуем вызвать второй раз

int main(){ return 0;}
