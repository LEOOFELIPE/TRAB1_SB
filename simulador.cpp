#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <string> split (string linha, string delimitador)
{
    int inicio_linha = 0;
    int pos_linha = 0;
    int size_delimitador = delimitador.length();
    vector <string> termo_linha;
    string linha_split = linha;
    string aux;

    while((pos_linha = linha_split.find(delimitador, inicio_linha)) != string::npos)
    {
        aux = linha_split.substr(inicio_linha, pos_linha - inicio_linha);
        inicio_linha = pos_linha + delimitador.length(); //retira o limitador
        termo_linha.push_back(aux); //salva termo a termo
    }
 
    termo_linha.push_back(linha_split.substr(inicio_linha)); 
    return termo_linha;
}

int main(int argc, char *argv[])
{   
    fstream arquivo_obj;
    arquivo_obj.open(argv[1]);
    string line, line_obj;
    vector <string> split_line_obj = {};
    int ACC = 0;
    int contador_programa = 0;
    if (arquivo_obj.is_open())
    {
        while(getline(arquivo_obj, line))
        {
            line_obj = line;
        }
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }
    int inteiro_input, inteiro_output = 0;
    split_line_obj = split(line_obj, " ");
    vector <string> pega_output = {};
    while (split_line_obj[contador_programa] != "14")
    {   //cout << split_line_obj[contador_programa] << endl;
        if(split_line_obj[contador_programa] == "1")//ADD
        {   //cout << "add" << endl;
            int operando_ADD = stoi(split_line_obj[contador_programa+1]);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            ACC += stoi(split_line_obj[operando_ADD]);
            cout << "ACC <- " << ACC << endl; 

        }
        else if(split_line_obj[contador_programa] == "2")//SUB
        {   //cout << "sub" << endl;
            int operando_SUB = stoi(split_line_obj[contador_programa+1]);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            ACC = ACC - stoi(split_line_obj[operando_SUB]);
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "3")//MUL
        {   //cout << "mul" << endl;
            int operando_MUL = stoi(split_line_obj[contador_programa+1]);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            ACC = int(ACC*stoi(split_line_obj[operando_MUL]));
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "4")//DIV
        {
            //cout << "div" << endl;
            int operando_DIV = stoi(split_line_obj[contador_programa+1]);
            ACC =  int(ACC/stoi(split_line_obj[operando_DIV]));
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "5")//JMP
        {   //cout << "jmp" << endl;
            int operando_JMP = stoi(split_line_obj[contador_programa+1]);
            contador_programa = stoi(split_line_obj[operando_JMP]);
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "6")//JMPN
        {   //cout << "jmpn" << endl;
            if(ACC < 0)
            {
                int operando_JMPN = stoi(split_line_obj[contador_programa+1]);
                contador_programa = stoi(split_line_obj[operando_JMPN]);
            }
            else
            {
                contador_programa += 2;
            }
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "7")//JMPP
        {   //cout << "jumpp" << endl;
            if(ACC > 0)
            {
                int operando_JMPP = stoi(split_line_obj[contador_programa+1]);
                contador_programa = stoi(split_line_obj[operando_JMPP]);
            }
            else
            {
                contador_programa += 2;
            }
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "8")//JMPZ
        {   //cout << "jmpz" << endl;
            if(ACC == 0)
            {
                int operando_JMPZ = stoi(split_line_obj[contador_programa+1]);
                contador_programa = stoi(split_line_obj[operando_JMPZ]);
            }
            else
            {
                contador_programa += 2;
            }
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "9")//COPY
        {   
            //cout << "copy" << endl;
            int operando_COPY1 = stoi(split_line_obj[contador_programa+1]);
            int operando_COPY2 = stoi(split_line_obj[contador_programa+2]);
            split_line_obj[operando_COPY2] = split_line_obj[operando_COPY1];
            contador_programa += 3;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;

        }
        else if(split_line_obj[contador_programa] == "10")//LOAD
        {
            //cout << "load" << endl;
            int operando_LOAD = stoi(split_line_obj[contador_programa+1]);
            ACC = stoi(split_line_obj[operando_LOAD]);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "11")//STORE
        {   //cout << "store" << endl;
            int operando_STORE = stoi(split_line_obj[contador_programa+1]);
            split_line_obj[operando_STORE] = to_string(ACC);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
        }
        else if(split_line_obj[contador_programa] == "12")//INPUT
        {   //cout << "input" << endl;
            cout << "Digite um inteiro: ";
            cin >> inteiro_input;
            int operando_INPUT = stoi(split_line_obj[contador_programa+1]);
            split_line_obj[operando_INPUT] = to_string(inteiro_input);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;    
        }
        else if(split_line_obj[contador_programa] == "13")//OUTPUT
        {   //cout << "output" << endl;
            int operando_OUTPUT = stoi(split_line_obj[contador_programa+1]);
            contador_programa += 2;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
            cout << "OUTPUT: " << split_line_obj[operando_OUTPUT] << endl;
            pega_output.push_back(split_line_obj[operando_OUTPUT]);
            
        }
        else if(split_line_obj[contador_programa] == "14")//STOP
        {   //cout << "stop" << endl;
            contador_programa += 1;
            cout << endl;
            cout << "PC  <- " << contador_programa << endl;
            cout << "ACC <- " << ACC << endl;
            break;
        }
    }
    contador_programa += 1;
    cout << endl;
    cout << "PC  <- " << contador_programa << endl;
    cout << "ACC <- " << ACC << endl;
    //cria arquivo de saida

    string nome_arquivo_saida = split(argv[1], ".")[0];
    fstream arquivo_de_saida;
    arquivo_de_saida.open(nome_arquivo_saida +".out",  ios::out | ios:: app);
    if(arquivo_de_saida.is_open())
    {
        for (size_t i = 0; i < pega_output.size(); i++)
        {
            arquivo_de_saida << pega_output[i] << endl;
        }
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }

    return 0;
}