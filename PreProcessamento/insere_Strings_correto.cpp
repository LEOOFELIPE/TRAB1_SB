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
    linha(int n, string t)
    {
        numeroLinha = n;
        textLinha = t;
    }
}; 

class symbol
{   
    public:
    int posicao;
    string rotulo;
    symbol(int pos, string rot)
    {
        posicao = pos;
        rotulo = rot;
    }
}; 

vector <linha*> arrumaVetor(vector <linha*> vetor_line)
{   
    int flag_text;
    vector <linha*> vetor_line_novo;
    for (size_t i = 0; i < vetor_line.size(); i++)
    {
        if(vetor_line[i] -> textLinha  == "SECTION TEXT")// adcionando SECTION TEXT
        {   
            flag_text = i;
            vetor_line_novo.push_back(vetor_line[i]);
        }
    }
    for (size_t i = flag_text-1 ; i < vetor_line.size(); i++)// adcionando TUDO DEPOIS DA SECTION TEXT
    {
        vetor_line_novo.push_back(vetor_line[i]);
    } 
    for (size_t i = 0; i < flag_text-1 ; i++)// adcionando TODA A SECTION DATA
    {
        vetor_line_novo.push_back(vetor_line[i]);
    }     

    return vetor_line_novo;
}

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
                linha* line = new linha(i,aux);
                //cout << line -> textLinha << endl;
                vetorLinhas.push_back(line);
            }
            i++;
        }
        //fechar o arquivo
        arquivo_asmIN.close();
        
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }
    
    /*for(auto it: vetorLinhas)
    {
    cout << it->textLinha << "-" <<it->numeroLinha << endl;
    }*/

    vector <linha*> vetorLinhasNew = arrumaVetor(vetorLinhas); //vetor com .data no final
    for (size_t i = 0; i < vetorLinhasNew.size(); i++)
    {
        cout << vetorLinhasNew[i] -> textLinha << "-" << vetorLinhasNew[i] ->numeroLinha << endl; 
    }
    
    return 0;
}