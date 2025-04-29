#include <stdio.h>

int main(){
    //Texto (cores normais)
    #define PRETO     "\e[30m"
    #define VERMELHO  "\e[31m"
    #define VERDE     "\e[32m"
    #define AMARELO   "\e[33m"
    #define AZUL      "\e[34m"
    #define MAGENTA   "\e[35m"
    #define CIANO     "\e[36m"
    #define BRANCO    "\e[37m"

    // Texto (cores claras)
    #define PRETO_CLARO     "\e[90m"
    #define VERMELHO_CLARO  "\e[91m"
    #define VERDE_CLARO     "\e[92m"
    #define AMARELO_CLARO   "\e[93m"
    #define AZUL_CLARO      "\e[94m"
    #define MAGENTA_CLARO   "\e[95m"
    #define CIANO_CLARO     "\e[96m"
    #define BRANCO_CLARO    "\e[97m"

    //Fundo (cores normais)
    #define BG_PRETO     "\e[40m"
    #define BG_VERMELHO  "\e[41m"
    #define BG_VERDE     "\e[42m"
    #define BG_AMARELO   "\e[43m"
    #define BG_AZUL      "\e[44m"
    #define BG_MAGENTA   "\e[45m"
    #define BG_CIANO     "\e[46m"
    #define BG_BRANCO    "\e[47m"

    //Fundo (cores claras)
    #define BG_PRETO_CLARO     "\e[100m"
    #define BG_VERMELHO_CLARO  "\e[101m"
    #define BG_VERDE_CLARO     "\e[102m"
    #define BG_AMARELO_CLARO   "\e[103m"
    #define BG_AZUL_CLARO      "\e[104m"
    #define BG_MAGENTA_CLARO   "\e[105m"
    #define BG_CIANO_CLARO     "\e[106m"
    #define BG_BRANCO_CLARO    "\e[107m"

    //Estilos e reset
    #define RESET      "\e[0m"
    #define NEGRITO    "\e[1m"
    #define SUBLINHADO "\e[4m"
    #define INVERTIDO  "\e[7m"    
}