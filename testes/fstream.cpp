#include <iostream>
#include <fstream>

using namespace std;

int main()
{   
    fstream arquivo;
    char opc = 's';
    string nome, linha;
    arquivo.open("fstream.txt", ios::out | ios:: app);

    while((opc == 's') or (opc == 'S'))
    {
        cout << "Digite alguma coisa: ";
        cin >> nome;
        arquivo << nome << endl;
        cout << "\n Digitar um novo nome ? [S/N]";
        cin >> opc;
        system("CLS");
    }
    arquivo.close();

    arquivo.open("fstream.txt", ios::in);

    cout << "Nomes Digitados" << endl;
    if(arquivo.is_open())
    {
        while(getline(arquivo, linha))
        {
            cout << linha << endl;
        }
        arquivo.close();
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }

    arquivo.close();

    return 0;
}