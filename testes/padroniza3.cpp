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
string retira_vazio(string linha)
{
    // Declara nova string
    string linhaNova;
    // Percorre string elemento a elemento
    for (size_t i = 0; i < linha.length(); i++)
    {
        if(linha[i] == ' ' && linha[i+1] == ' ')
        {
          continue;
        }else{
            linhaNova.push_back(linha[i]);
        }
    }
    //Retirar o ultimo espaço, caso tenha
    if(linhaNova[linhaNova.size()-1] == ' '){
        linhaNova = linhaNova.substr(0, linhaNova.size()-1);
    }
    return linhaNova;    
}

int main()
{   
    fstream arquivo_asmIN;
    fstream arquivo_asmOUT;
    string linhaMaiscula, linhaSemEspaco;
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
            //transforma em maiscula a linha sem comentario
            linhaMaiscula = maiuscula(linhaMaiscula.substr(0,linhaMaiscula.find(";")));
            linhaSemEspaco = retira_vazio(linhaMaiscula);
            arquivo_asmOUT << linhaSemEspaco << endl;
        }
        //fechar os arquivos
        arquivo_asmIN.close();
        
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    } 

    return 0;
}