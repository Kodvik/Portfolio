/*

1) Crie um programa em linguagem C++, usando orientação a objetos, para registro de veículos em
um estacionamento. Os registros deverão implementados como Classe que deverá ter os seguintes
campos/atributos:

- Código (int) – Auto numerável
- Placa (char(7))
- Modelo (char(30))
- Entrada (>> Classe Data (dia, mes, ano, hora, minuto)
- Saída (>> Classe Data (dia, mes, ano, hora, minuto)
- Valor pago (float) - Preenchido automaticamente (R$1 por hora estacionada)
- Cliente.
    Caso o cliente e identifique e seja fidelizado/cadastrado, deverá ser aplicado um desconto de 10%).
    Caso o cliente não deseje ser identificado, então não receberá desconto. Cliente também deverá ser uma classe com atributos (cpf, nome, data de cadastro)

O sistema deverá apresentar opções para:
a) CRUD para cliente
b) Registro de entrada de veículo
c) Registro de saída de veículo (a partir da placa, pesquisa e atualizar a data de saída e valor pago)
d) Geração de um arquivo com os veículos que ainda estão no estacionamento
e) Geração de um arquivo com o valor total pago pelos clientes durante um determinado mês informado pelo usuário.
A Sigla CRUD significa (Create, Read, Update, Delete), ou seja, você terá que oferecer opções de Inserção, Pesquisa por código/nome, atualização e exclusão.

*/

#include <iostream>
using std::cerr;
using std::endl;
#include <fstrem>
using std::ofstream;
#include <cstdlib>


using namespace std;

class Data{
private:
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
};

class CadastroCliente{
private:
    char CPF[14];
    char nome[50];
    Data cadastro;
};


class Veiculo{
private:
    int Codigo;
    char Placa[7];
    char Modelo[30];
    Data Entrada;
    Data Saida;
    float ValorPago;
    CadastroCliente Cliente;
};

void SistemaCRUD(){
    system("cls");
    int OpcaoDeSaida=0,OpcaoMenu;

    /*Impressão do menu no console e coleta de opção de menu*/
    while(OpcaoDeSaida !=1){
        cout << "Menu CRUD\n";
        cout << "1- Criar registro de cliente\n";
        cout << "2- Ler registro de cliente \n";
        cout << "3- Atualizar registro de cliente \n";
        cout << "4- Apagar registro de cliente \n";
        cout << "0- Retornar ao menu inicial";
        cin >> OpcaoMenu;
    }
    /*Fim da impressão do menu no console e coleta de opção de menu*/

    /*Switch case do menu CRUD*/
    switch(OpcaoMenu){
        case 0:
            OpcaoDeSaida=1;
            break;
        case 1:

            char CPF[14]; //formato XXX.XXX.XXX-XX
            char nome[50];
            int CPFvalido=1;

            system("cls");
            cout << "***** Criacao de novo registro de cliente *****\n";
            cout << "Informe o CPF do cliente no formato XXX.XXX.XXX-XX";
            cin >> CPF;
            if((CPF[3] != '.' || CPF[7] != '.') || CPF[11] != '-'){{
                system("cls");
                cout << "CPF inserido tem formato invalido, formato esperado: XXX.XXX.XXX-XX";
                CPFvalido=0;
            }
            if( (CPF[0] < '0') || (CPF[0] > '9') ||
                (CPF[1] < '0') || (CPF[1] > '9') ||
                (CPF[2] < '0') || (CPF[2] > '9') ||
                (CPF[4] < '0') || (CPF[4] > '9') ||
                (CPF[5] < '0') || (CPF[5] > '9') ||
                (CPF[6] < '0') || (CPF[6] > '9') ||
                (CPF[8] < '0') || (CPF[8] > '9') ||
                (CPF[9] < '0') || (CPF[9] > '9') ||
                (CPF[10] < '0') || (CPF[10] > '9') ||
                (CPF[12] < '0') || (CPF[12] > '9') ||
                (CPF[13] < '0') || (CPF[13] > '9') ){
                system("cls");
                cout << "CPF inserido tem formato invalido, formato esperado: XXX.XXX.XXX-XX onde X devem ser numeros";
                CPFvalido=0;
            }


            if(CPFvalido == 1){
                system("cls");
            }


    }
    /*Fim do switch case do menu CRUD*/

}

void RegistrarEntrada(char Placa[7]){

}

void RegistrarSaida(char Placa[7]){

}

void imprimirNoArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo, std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Código: " << Codigo << std::endl;
        arquivo << "Placa: " << Placa << std::endl;
        arquivo << "Modelo: " << Modelo << std::endl;
        arquivo << "Entrada: " << Entrada << std::endl;
        arquivo << "Saída: " << Saida << std::endl;
        arquivo << "Valor Pago: " << ValorPago << std::endl;
        arquivo << "Cliente: " << Cliente << std::endl;
        arquivo << "------------------" << std::endl;
        arquivo.close();
        std::cout << "Objeto impresso com sucesso no arquivo " << nomeArquivo << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
    }
}

int main()
{
    int OpcaoDeSaida=0,OpcaoMenu;
    char PlacaInserida[7];

    ofstream outdata;

    while(OpcaoDeSaida != 1){

        /*Impressão do menu no console e coleta de opção de menu*/
        system("cls");
        cout << "Menu: \n";
        cout << "1- Sistema CRUD para clientes. \n";
        cout << "2- Registro de entrada de veiculo.\n";
        cout << "3- Registro de saida de veiculo.\n";
        cout << "4- Arquivo de veiculos estacionados.\n";
        cout << "5- Arquivo com valor total recebido durante um mes\n";
        cout << "0- Sair.\n";
        cout << "Opcao: ";
        cin >> OpcaoMenu;
        /*Fim de impressão do menu no console e coleta de opção de menu*/

        /*Switch case do menu principal*/
        switch(OpcaoMenu){
            case 0:
                system("cls");
                cout << "Finalizando console, os arquivos gerados ainda estao salvos.\n";
                OpcaoDeSaida=1;
                system("pause");
                break;
            case 1:
                system("cls");
                SistemaCRUD();
                break;
            case 2:
                system("cls");
                cout << "Informe a placa do veiculo entrando: ";
                cin >> PlacaInserida;
                RegistrarEntrada(PlacaInserida);
                break;
            case 3:
                system("cls");
                cout << "Informe a placa do veiculo entrando: ";
                cin >> PlacaInserida;
                RegistrarSaida(PlacaInserida);
                break;
            case 4:
                system("cls");
                outdata.open("C:veiculos_estacionados.txt");
                for(int i)
                cout << "Arquivo 'veiculos_estacionados.txt' gerado em 'PENSAR COMO IMPRIMIR ENDEREÇO NO DESKTOP'";
                break;
            case 5:
                system("cls");
                cout << "Arquivo 'NOME DO ARQUIVO' gerado em 'PENSAR COMO IMPRIMIR ENDEREÇO NO DESKTOP'";
                break;
        }
        /*Fim switch case do menu principal*/

    }
}
