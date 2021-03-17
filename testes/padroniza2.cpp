#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string maiuscula(string linha)
{
    linha = linha.substr(0, linha.find("\n"));

    for (size_t i = 0; i < linha.size(); i++)
    {
        linha[i] = toupper(linha[i]); 
    }
    return linha;
}

int main()
{   
    fstream arquivo_asmIN;
    fstream arquivo_asmOUT;
    string linhaMaiscula;
    char c;
    //abre o arquivo de entrada
    arquivo_asmIN.open("bin.asm");
    //verifica para acessar o arquivo de entrada
    if(arquivo_asmIN.is_open())
    {   //arquivo de saida
        arquivo_asmOUT.open("bin.txt", ios::app);
        //acessa o arquivo de entrada para modificar
        while(getline(arquivo_asmIN, linhaMaiscula))
        {   
            for (size_t i = 0; i < linhaMaiscula.length(); i++)
            {
                if(linhaMaiscula[i] == ' ' && linhaMaiscula[i+1] != ' ')
                {
                    linhaMaiscula[i] = linhaMaiscula[i];
                }
            }
            
            //transforma em maiscula a linha sem comentario
            linhaMaiscula = maiuscula(linhaMaiscula.substr(0,linhaMaiscula.find(";")));
            arquivo_asmOUT << linhaMaiscula << endl;
        }
        //fechar os arquivos
        arquivo_asmIN.close();
        
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    } 

    return 0;
}