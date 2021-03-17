#include <iostream>
#include <fstream>

using namespace std;

int main()
{   //variaveis
    ofstream arquivo_asm;

    arquivo_asm.open("criaArquivo.txt");//ios::app

    arquivo_asm << "Leonardo Felipe de Oliveira\n";
    arquivo_asm << "Leonardo Felipe de Oliveira\n";
    arquivo_asm << "Leonardo Felipe de Oliveira\n";
    arquivo_asm.close();

    return 0 ;
}