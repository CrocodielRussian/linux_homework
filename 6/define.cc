#define M1
#define M2 (1+2)
#define M3(x) ((x)+2)
// Всегда в маккросах ставим скобки!!!
int main(){ return M3(2+2);}
