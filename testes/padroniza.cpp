#include <iostream>
#include <fstream>

using namespace std;

//funcao para retirar espaco e comentario de uma linha
//e colocar em caixa alta
/*string padroniza(string linha)
{
    //Fazer um recorte da linha que tem cometario
    linha = linha.substr(0, linha.find("\n"));
    return linha;
}*/
int main()
{   string teste = "leonardo;";
    teste = teste.substr(0,teste.find(";"));

    for (size_t i = 0; i < teste.size(); i++)
    {
        teste[i] = toupper(teste[i]); 
    }
   cout << teste << endl;
    return 0 ;
}