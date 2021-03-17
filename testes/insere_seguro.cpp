#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
        }
        else{
            linhaNova.push_back(linha[i]);
        }
    }
    //Retirar o ultimo espaço, caso tenha
    if(linhaNova[linhaNova.size()-1] == ' '){
        linhaNova = linhaNova.substr(0, linhaNova.size()-1);
    }
    
    if(linhaNova.size() != 0)
    {
        if(linhaNova[0] == ' ')
        {
            linhaNova = linhaNova.substr(1, linhaNova.size()-1);
        }
    }
    return linhaNova;    
}

string maiuscula(string linha)
{
    linha = linha.substr(0, linha.find("\n"));

    for (size_t i = 0; i < linha.size(); i++)
    {
        linha[i] = toupper(linha[i]); 
    }
    return linha;
}

class linha
{   
    public:
    int numeroLinha;
    string textLinha;
}; 

int main()
{   
    fstream arquivo_asmIN;
    string linhaBin;
    int i = 1;
    vector <linha*> vetorLinhas = {};
    
    //abre o arquivo de entrada
    arquivo_asmIN.open("bin2.asm");
    //verifica para acessar o arquivo de entrada
    if(arquivo_asmIN.is_open())
    {   
        //acessa o arquivo de entrada para inserir no vetorLinhas 
        while(getline(arquivo_asmIN, linhaBin))
        {   
            //vetorLinhas.push_back(linha);
            string aux = "";
            aux = maiuscula(linhaBin.substr(0, linhaBin.find(";")));
            //cout << vetorLinhas[j] << endl;
            aux = retira_vazio(aux);
            if(aux.size() != 0)
            {   
                linha* line;
                line -> textLinha = aux;
                line -> numeroLinha = i;
                vetorLinhas.push_back(line);
            }
            i++;
        }
        //fechar o arquivo
        arquivo_asmIN.close();
        
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }
    /*for (size_t i = 0; i < vetorLinhas.size(); i++)
    {
        if(i == vetorLinhas.size()-1)
        {
            cout << vetorLinhas[i] -> textLinha;
        }
        else{
            cout << vetorLinhas[i] -> numeroLinha << "--" << vetorLinhas[i] -> textLinha << endl;
        }
    }*/
    
    /*for (size_t j = 0; j < vetorLinhas.size(); j++)
    {   
        string aux = "";
        aux = maiuscula(vetorLinhas[j].substr(0, vetorLinhas[j].find(";")));
        //cout << vetorLinhas[j] << endl;
        aux = retira_vazio(aux);
        if(aux.size() != 0)
        {
            vetorLinhas.push_back(aux);
        }
        cout << vetorLinhas[j] << endl;
    }*/
    return 0;
}