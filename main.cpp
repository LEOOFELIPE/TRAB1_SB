#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//-------------------------------- FUNÇÕES PREPROCESSAMENTO --------------------------------------
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
string retira_vazio_dois_pontos(string linha)
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
        if(linha[i] == ' ' && linha[i+1] == ':')
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
    for (size_t i = flag_text+1 ; i < vetor_line.size(); i++)// adcionando TUDO DEPOIS DA SECTION TEXT
    {
        vetor_line_novo.push_back(vetor_line[i]);
    } 
    for (size_t i = 0; i < flag_text ; i++)// adcionando TODA A SECTION DATA
    {
        vetor_line_novo.push_back(vetor_line[i]);
    }

    return vetor_line_novo;
}

//-------------------------------- FUNÇÕES PRIMEIRA PASSAGEM --------------------------------------

//SPLIT 

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

class instrucao
{   
    public:
    int opc, tamanho, operandos;
    string nome;
    instrucao(string opc_nome, int opcode, int tam, int operando)
    {
        nome = opc_nome;
        opc = opcode;
        tamanho = tam;
        operandos = operando;
    }
};

class diretiva
{   
    public:
    int tamanho, operandos;
    string nome;
    diretiva(string name, int tam, int operando)
    {   
        nome = name;
        tamanho = tam;
        operandos = operando;
    }
};

vector <instrucao*> vetorInstrucao(vector <instrucao*> tabela_instrucao)
{   
    instrucao* ADD = new instrucao("ADD", 1, 2, 1); //ADD
    tabela_instrucao.push_back(ADD);
    instrucao* SUB = new instrucao("SUB", 2, 2, 1); //SUB
    tabela_instrucao.push_back(SUB);
    instrucao* MUL = new instrucao("MUL", 3, 2, 1); //MUL
    tabela_instrucao.push_back(MUL);
    instrucao* DIV = new instrucao("DIV", 4, 2, 1); //DIV
    tabela_instrucao.push_back(DIV);
    instrucao* JMP = new instrucao("JMP", 5, 2, 1); //JMP
    tabela_instrucao.push_back(JMP);
    instrucao* JMPN = new instrucao("JMPN", 6, 2, 1); //JMPN
    tabela_instrucao.push_back(JMPN);
    instrucao* JMPP = new instrucao("JMPP", 7, 2, 1); //JMPP
    tabela_instrucao.push_back(JMPP);
    instrucao* JMPZ = new instrucao("JMPZ", 8, 2, 1); //JMPZ
    tabela_instrucao.push_back(JMPZ);
    instrucao* COPY = new instrucao("COPY", 9, 3, 2); //COPY
    tabela_instrucao.push_back(COPY);
    instrucao* LOAD = new instrucao("LOAD", 10, 2, 1); //LOAD
    tabela_instrucao.push_back(LOAD);
    instrucao* STORE = new instrucao("STORE", 11, 2, 1); //STORE
    tabela_instrucao.push_back(STORE);
    instrucao* INPUT = new instrucao("INPUT", 12, 2, 1); //INPUT
    tabela_instrucao.push_back(INPUT);
    instrucao* OUTPUT = new instrucao("OUTPUT", 13, 2, 1); //OUTPUT
    tabela_instrucao.push_back(OUTPUT);
    instrucao* STOP = new instrucao("STOP", 14, 1, 0); //STOP
    tabela_instrucao.push_back(STOP);


    return tabela_instrucao;
}

vector <diretiva*> vetorDiretiva(vector <diretiva*> tabela_diretiva)
{   
    diretiva* SPACE = new diretiva("SPACE", 1, 0); //SPACE
    tabela_diretiva.push_back(SPACE);
    diretiva* CONST = new diretiva("CONST", 1, 1); //CONST
    tabela_diretiva.push_back(CONST);

    return tabela_diretiva;
}

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

string retorna_rotulo(string l)
{   string rot;
    for (size_t i = 0; i < l.size(); i++)
    {
        if(l[i] == ':')//EH ROTULO
        {   
            string aux = l;
            vector <string> split_rotulo = split(aux,":");
            rot = split_rotulo[0];    
        }
    }
    return rot;
}

int eh_instrucao_OU_diretiva(string inst)
{
    vector <diretiva*> diretivas = {};
    diretivas = vetorDiretiva(diretivas);
    vector <instrucao*> instrucoes = {};
    instrucoes = vetorInstrucao(instrucoes);

    for (size_t i = 0; i < instrucoes.size(); i++)
    {
        if(inst == instrucoes[i] -> nome)
        {
            return 1;
        }
    }
    for (size_t i = 0; i < diretivas.size(); i++)
    {
        if(inst == diretivas[i] -> nome)
        {
            return 2;
        }
    }
    return 0;
}

int verifica_char_rotulo(string rot)
{   
    int iasn, eh_invalido = 0;
    
    for (size_t i = 0; i < rot.size(); i++)
    {   iasn = isalnum(rot[i]);
        if(iasn != 0 || rot[i] == '_')
        {
            continue;
        }
        else{
            eh_invalido = 1;
            break;
        } 
    }
    if(rot[0] == '0'|| rot[0] == '1'|| rot[0] == '2'|| rot[0] == '3' || rot[0] == '4' || rot[0] == '5'|| rot[0] == '6'|| rot[0] == '7' || rot[0] == '8'|| rot[0] == '9')
    {
        eh_invalido = 1;    
    }
    return eh_invalido;
}

int valida_operando(string operando, vector<symbol*> TS)
{   int eh_operando_valido = 0;
    for (size_t i = 0; i < TS.size(); i++)
    {
        if(operando == TS[i] -> rotulo)
        {
            eh_operando_valido = 1;
            break;
        }
        else{
            eh_operando_valido = 0;
        }
    }
    return eh_operando_valido;
}

int valida_instrucao(string inst, vector <instrucao*> TI)
{
    int eh_instrucao_valida = 0;
    for (size_t i = 0; i < TI.size(); i++)
    {
        if (inst == TI[i] -> nome)
        {
            eh_instrucao_valida = 1;
            break;
        }
        else
        {
            eh_instrucao_valida = 0;
        }
        
    }
    return eh_instrucao_valida;
}

int pegaPC_inst(string inst, vector <instrucao*> TI)
{
    int PC_inst = 0;
    for (size_t i = 0; i < TI.size(); i++)
    {
        if (inst == TI[i] -> nome)
        {
            PC_inst = TI[i] -> tamanho;
        }
    }
    return PC_inst;
}

int  tamanho_operando_inst(string inst, vector <instrucao*> TI)
{
    int quantidade_operando = 0;
    for (size_t i = 0; i < TI.size(); i++)
    {
        if (inst ==  TI[i] -> nome)
        {
            quantidade_operando = TI[i] -> operandos;
        } 
    }
    return quantidade_operando;
}
int OPCODE_inst(string inst, vector <instrucao*> TI)
{
    int OPCODE = 0;
    for (size_t i = 0; i < TI.size(); i++)
    {
        if(inst == TI[i] -> nome)
        {
            OPCODE = TI[i] -> opc;
        }
    }
    return OPCODE;
}
int procura_diretiva_naTD(string dire, vector <diretiva*> TD)
{
    int eh_diretiva_valida = 0;
    for (size_t i = 0; i < TD.size(); i++)
    {
        if(dire == TD[i] -> nome)
        {
            eh_diretiva_valida = 1;
            break;
        }
    }
    return eh_diretiva_valida;
}

int pegaPC_diretiva(string dire, vector <diretiva*> TD)
{
    int PC_diretiva = 0;
    for (size_t i = 0; i < TD.size(); i++)
    {
        if(dire == TD[i] -> nome)
        {
            PC_diretiva = TD[i] -> tamanho;
        }
    }
    return PC_diretiva;
}
int pegaPC_Operando(string operando, vector<symbol*> TS)
{   int PC_operando = 0;
    for (size_t i = 0; i < TS.size(); i++)
    {
        if(operando == TS[i] -> rotulo)
        {
            PC_operando = TS[i] -> posicao;
        }
    }
    return PC_operando;
}

int verificaSpaceConst(string dire)
{   int spaceorconst;
    if(dire == "SPACE")
    {
        spaceorconst = 1;
    }
    else{
        spaceorconst = 0;
    }
    return spaceorconst;
}
//---------------------------------------------------------------- INICIO DA MAIN ---------------------------------------------
int main(int argc, char *argv[])
{   
    fstream arquivo_asmIN;
    string linhaBin;
    int i = 1;
    vector <linha*> vetorLinhas = {};
    
    //abre o arquivo de entrada
    arquivo_asmIN.open(argv[1]);
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

    vetorLinhas = arrumaVetor(vetorLinhas);
    for (size_t i = 0; i < vetorLinhas.size(); i++)
    {
        cout << vetorLinhas[i] ->textLinha << " --- " << vetorLinhas[i] -> numeroLinha <<endl;
    }
    cout << "------------------------------------------------------" << endl;

    //---------------------------- PRIMEIRA PASSAGEM -----------------------

    vector <diretiva*> diretivas = {};
    diretivas = vetorDiretiva(diretivas);
    vector <instrucao*> instrucoes = {};
    instrucoes = vetorInstrucao(instrucoes);
    int contador_programa = 0;
    linha* linha_1passagem;
    string linha_1passagem_text;
    int linha_1passagem_pos = 0;
    vector <string> split_linha;
    vector <symbol*> vetorSimbolo = {};
    symbol* simbolo;
    int contador_linha = 1;
    
    for (size_t i = 0; i < vetorLinhas.size(); i++)
    {    
        linha_1passagem = vetorLinhas[i];
        linha_1passagem_text = linha_1passagem -> textLinha;
        linha_1passagem_pos = linha_1passagem -> numeroLinha;

        if(linha_1passagem_text != "SECTION DATA" && linha_1passagem_text != "SECTION TEXT")
        {
            linha_1passagem_text = retira_vazio_dois_pontos(linha_1passagem_text);
            split_linha = split(linha_1passagem_text, " ");
            string parse1 = split_linha[0];
            int eh_label = 0;
            
            for (size_t i = 0; i < parse1.size(); i++)
            {
                if(parse1[i] == ':')
                {
                    eh_label = 1;
                }
            }
            string rotulo = retorna_rotulo(parse1);
            int verifica_rotulo = eh_instrucao_OU_diretiva(rotulo);
            int eh_rotulo_invalido = verifica_char_rotulo(rotulo);
            if(eh_rotulo_invalido == 1)
            {
                cout << "ERRO: Rotulo com caracteres especiais --- Linha: " << linha_1passagem_pos << endl;
            }
            if( verifica_rotulo != 0)
            {
                cout << "ERRO: Rotulo Invalido --- Linha: " << linha_1passagem_pos  << endl;
            }
            if(rotulo.size() > 50)
            {
                cout << "ERRO: Rotulo com mais de 50 caracteres --- Linha: " << linha_1passagem_pos << endl;
            }
            if ((eh_label == 1) && (verifica_rotulo == 0) && (rotulo.size() < 50))
            {   
                
                int flag_rot = 1;
                
                for (size_t i = 0; i < vetorSimbolo.size(); i++)
                {
                    if(rotulo == vetorSimbolo[i] -> rotulo)
                    {   
                        flag_rot = 0;
                        
                    }
                }
                if (flag_rot != 1)
                {
                    cout << "ERRO Semantico: Redefinicao de Rotulo --- Linha: " << linha_1passagem_pos << endl;
                }
                else{
                    symbol* simbolo = new symbol(contador_programa, rotulo);
                    vetorSimbolo.push_back(simbolo);
                }
                
                
                if (split_linha.size() > 1)
                {   int eh_inst_dire = eh_instrucao_OU_diretiva(split_linha[1]);
                    if (eh_inst_dire == 1)
                    {
                        for (size_t i = 0; i < instrucoes.size(); i++)
                        {
                            if(split_linha[1] == instrucoes[i] -> nome)
                            {
                                contador_programa += instrucoes[i] -> tamanho;
                            }
                        }   
                    }
                    else if(eh_inst_dire == 2)
                    {
                        for (size_t i = 0; i < diretivas.size(); i++)
                        {
                            if(split_linha[1] == diretivas[i] -> nome)
                            {
                                contador_programa += diretivas[i] -> tamanho;
                            }    
                        }
                    }
                    else
                    {
                        cout << "ERRO Semantico: Instrucao ou Diretiva Incorreta -- Linha: " << linha_1passagem_pos << endl;
                    }   
                }          
            }
            else
            {   
                int eh_inst_dire2 =  eh_instrucao_OU_diretiva(parse1);
                if(eh_inst_dire2 == 1)
                {
                    for (size_t i = 0; i < instrucoes.size(); i++)
                    {
                        if(parse1 == instrucoes[i] -> nome)
                        {
                            contador_programa += instrucoes[i] -> tamanho;
                        }    
                    }
                }
                else if(eh_inst_dire2 == 2)
                {
                    for (size_t i = 0; i < diretivas.size(); i++)
                    {
                        if(parse1 == diretivas[i] -> nome)
                        {
                            contador_programa += diretivas[i] -> tamanho;
                        }    
                    }
                }
                else
                {
                    cout << "ERRO Semantico: Instrucao ou Diretiva Incorreta -- Linha: " << linha_1passagem_pos << endl;
                } 
            }
        }
        contador_linha+=1;
    }
    
    cout << "TABELA DE SIMBOLOS" << endl;
    for (size_t i = 0; i < vetorSimbolo.size(); i++)
    {   
        cout << vetorSimbolo[i]->rotulo <<" -- "<< vetorSimbolo[i] ->posicao  << endl;
    }

    //------------------------------------------------------ SEGUNDA PASSAGEM -------------------------------------------

    vector <int> OPC_inst = {};
    
    linha* linha_2passagem;
    for (size_t i = 0; i < vetorLinhas.size(); i++)
    {   
        linha_2passagem = vetorLinhas[i];
        string linha_2passagem_text = linha_2passagem -> textLinha;
        int linha_2passagem_pos = linha_2passagem -> numeroLinha;

        if(vetorLinhas[i]->textLinha != "SECTION DATA" && vetorLinhas[i]->textLinha != "SECTION TEXT")
        {
            linha_2passagem_text = retira_vazio_dois_pontos(linha_2passagem_text);
            vector <string> split_linha2 = split(linha_2passagem_text, " ");
            string parse2 = split_linha2[0];
            //cout << parse2 << endl;
            
            int eh_label2 = 0;
            int pos_PC_operando, pos_PC_operando1 = 0;
            int retorna_OPCODE_inst,retorna_OPCODE_inst1 = 0;

            for (size_t i = 0; i < parse2.size(); i++)
            {
                if(parse2[i] == ':')
                {
                    eh_label2 = 1;
                }
            }
            
            if(eh_label2 == 1 && split_linha2.size() > 1)//Ignora o label e trata a instrução ou diretiva
            {   //cout << parse2 << endl;
                //cout << split_linha2[0] << "---" << split_linha2[1] << "6"<< endl;
                //verfico se é inst ou diretiva
                //cout << "ola" << endl;
                int eh_instrucao = valida_instrucao(split_linha2[1], instrucoes);
                
                int eh_diretiva = procura_diretiva_naTD(split_linha2[1], diretivas);
                if(eh_instrucao == 1)
                {   //cout << split_linha2[0] << "---" << split_linha2[1] << "6"<< endl;
                    string operando_caso1 = split_linha2[2];
                    //cout << operando_caso1 << endl;
                    int operando_tam2;
                    vector <string> operando_split1 = split(operando_caso1,",");
                    if(operando_split1.size() == 2)
                    {//eh COPY
                        operando_tam2 = 2;
                    }else
                    {
                        operando_tam2 = 1;
                    }
                    int verifica_tam_operando_inst = tamanho_operando_inst(split_linha2[1], instrucoes);
                    if(operando_tam2 == verifica_tam_operando_inst)
                    {   
                        pos_PC_operando1 = pegaPC_Operando(operando_caso1, vetorSimbolo);
                        retorna_OPCODE_inst1 = OPCODE_inst(split_linha2[1], instrucoes);
                        OPC_inst.push_back(retorna_OPCODE_inst1);
                        OPC_inst.push_back(pos_PC_operando1);
                    }
                    else{
                        cout << "ERRO SINTATICO: QUANTIDADE DE OPERANDO INVALIDA11111" << endl;
                    }
                }
                else
                {   //cout << eh_diretiva << endl;
                    if(eh_diretiva == 1)
                    {
                        //EXECUTA DIRETIVA
                        int eh_space1 = verificaSpaceConst(split_linha2[1]);
                        
                        if(eh_space1 == 1)//eh space
                        {
                            OPC_inst.push_back(0);
                        }
                        else
                        {   //eh const
                            int constante = stoi(split_linha2[2]);
                            OPC_inst.push_back(constante);
                        }
                    }
                    else
                    {
                        cout << "ERRO SEMANTICO: INSTRUCAO OU DIRETIVA NAO IDENTIFICADA ---- " << linha_2passagem_pos << endl;
                    }
                }

            }
            else
            {   //cout << "ola" << endl;
                if(parse2 == "STOP")//eh stop
                {   //cout << "ola" << endl;
                    string inst_STOP = parse2;
                    //cout << parse2 << endl;
                    retorna_OPCODE_inst = OPCODE_inst(inst_STOP, instrucoes);
                    OPC_inst.push_back(retorna_OPCODE_inst);
                }
                else{
                    //cout << "ola" << endl;
                    string operando = split_linha2[1];
                    //cout << operando << endl;
                    int operando_tam = 0;
                    int operando_copy1;
                    int operando_copy2;
                    int operando_COPY;
                    int pos_PC_operando_copy1,pos_PC_operando_copy2;
                    vector <string> operando_split = split(operando,",");
                    if(operando_split.size() == 2)//eh COPY
                    {
                        operando_tam = 2;
                        operando_copy1 = valida_operando(operando_split[0], vetorSimbolo);
                        operando_copy2 = valida_operando(operando_split[1], vetorSimbolo);
                        if(operando_copy1 == 1 && operando_copy2 == 1){
                            operando_COPY = 1;
                        }

                    }
                    else
                    {
                        operando_tam = 1;
                    }
                    int operando_valido = valida_operando(operando, vetorSimbolo);
                    if(operando_valido == 0 && operando_tam == 1)
                    {
                        cout << "ERRO SEMANTICO: SIMBOLO INDEFINIDO" << endl;
                    }
                    else if(operando_COPY == 0 && operando_tam == 2)
                    {
                        cout << "ERRO SEMANTICO: SIMBOLO INDEFINIDO" << endl;
                    }
                    
                    else
                    {
                        string inst = split_linha2[0];
                        int inst_valida = valida_instrucao(inst, instrucoes);
                        if(inst_valida == 1)
                        {
                            int verifica_tam_operando_inst = tamanho_operando_inst(inst, instrucoes);
                            if(verifica_tam_operando_inst == 1)
                            {   
                                pos_PC_operando = pegaPC_Operando(operando, vetorSimbolo); 
                                retorna_OPCODE_inst = OPCODE_inst(inst, instrucoes);
                                OPC_inst.push_back(retorna_OPCODE_inst);
                                OPC_inst.push_back(pos_PC_operando);
                            }
                            else if(verifica_tam_operando_inst == 2)
                            {
                                string operando1 = operando_split[0];
                                string operando2 = operando_split[1];
                                retorna_OPCODE_inst = OPCODE_inst(inst, instrucoes);
                                OPC_inst.push_back(retorna_OPCODE_inst);
                                pos_PC_operando_copy1 = pegaPC_Operando(operando1, vetorSimbolo);
                                OPC_inst.push_back(pos_PC_operando_copy1);
                                pos_PC_operando_copy2 = pegaPC_Operando(operando2, vetorSimbolo);
                                OPC_inst.push_back(pos_PC_operando_copy2);   
                            }
                            else{
                                cout << "ERRO SINTATICO: QUANTIDADE DE OPERANDO INVALIDA" << endl;
                            }
                        }
                        else
                        {   string diretiva = split_linha2[0];
                            int eh_diretiva_valida = procura_diretiva_naTD(diretiva, diretivas);
                            if(eh_diretiva_valida == 1)
                             {
                                //EXECUTA DIRETIVA
                                int eh_space = verificaSpaceConst(split_linha2[1]);
                                if(eh_space == 1)//eh space
                                {
                                    OPC_inst.push_back(0);
                                }
                                else
                                {   //eh const
                                    int constante = stoi(split_linha2[2]);
                                    OPC_inst.push_back(constante);
                                }
                            }
                            else
                            {
                                cout << "ERRO SEMANTICO: INSTRUCAO OU DIRETIVA NAO IDENTIFICADA" << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    //cria arquivo objeto

    fstream arquivo_objeto;
    vector <string> objeto_name = split(argv[1], ".");

    arquivo_objeto.open(objeto_name[0]+".obj", ios::out);
    if(arquivo_objeto.is_open())
    {
        for (size_t i = 0; i < OPC_inst.size(); i++)
        {
            arquivo_objeto << OPC_inst[i]  << " ";
        }
    }
    else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }

    /*cout << "------------------ CODIGO OBJETO --------------------" << endl;
    for (size_t i = 0; i < OPC_inst.size(); i++)
    {
        cout << OPC_inst[i]  << " ";
    }*/

    //cria arquivo preprocessado

    /*fstream arquivo_preprocessado;
    arquivo_preprocessado.open("bin_pp.txt",  ios::out | ios:: app);
    if(arquivo_preprocessado.is_open())
    {
        for (size_t i = 0; i < vetorLinhas.size(); i++)
        {
            arquivo_preprocessado << vetorLinhas[i] ->textLinha << endl;
        }
    }else{
        cout << "N foi possivel abrir o seu arquivo" << endl;
    }*/
    
    return 0;
}