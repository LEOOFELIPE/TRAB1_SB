#include <iostream>
#include <fstream>

using namespace std;

int main()
{   //variaveis
    /*ofstream arquivo_asmS;

    arquivo_asmS.open("criaArquivo.txt");//ios::app

    arquivo_asmS << "Leonardo Felipe de Oliveira\n";
    arquivo_asmS << "Leonardo Felipe de Oliveira\n";
    arquivo_asmS << "Leonardo Felipe de Oliveira\n";
    arquivo_asmS.close();*/

    ifstream arquivo_asmE;
    string linha;

    arquivo_asmE.open("criaArquivo.txt");
    if(arquivo_asmE.is_open())
    {
        while(getline(arquivo_asmE, linha))
        {
            cout << linha << endl;
        }
        arquivo_asmE.close();
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }
    return 0 ;
}