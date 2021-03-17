#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string retira_vazio(string linha)
{
    // Declara nova string
    string linhaNova;
    // Percorre string elemento a elemento
    if(linha.size() == 0)
    {
        return linha;
    }
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
    string linha = "section    		DATA";
    string newLine;
    newLine = retira_vazio(linha);

    newLine.push_back('+');
    cout << newLine << endl;
    return 0;
}