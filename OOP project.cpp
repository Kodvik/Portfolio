/*

1) Crie um programa em linguagem C++, usando orienta��o a objetos, para registro de ve�culos em
um estacionamento. Os registros dever�o implementados como Classe que dever� ter os seguintes
campos/atributos:

- C�digo (int) � Auto numer�vel
- Placa (char(7))
- Modelo (char(30))
- Entrada (>> Classe Data (dia, mes, ano, hora, minuto)
- Sa�da (>> Classe Data (dia, mes, ano, hora, minuto)
- Valor pago (float) - Preenchido automaticamente (R$1 por hora estacionada)
- Cliente.
    Caso o cliente e identifique e seja fidelizado/cadastrado, dever� ser aplicado um desconto de 10%).
    Caso o cliente n�o deseje ser identificado, ent�o n�o receber� desconto. Cliente tamb�m dever� ser uma classe com atributos (cpf, nome, data de cadastro)

O sistema dever� apresentar op��es para:
a) CRUD para cliente
b) Registro de entrada de ve�culo
c) Registro de sa�da de ve�culo (a partir da placa, pesquisa e atualizar a data de sa�da e valor pago)
d) Gera��o de um arquivo com os ve�culos que ainda est�o no estacionamento
e) Gera��o de um arquivo com o valor total pago pelos clientes durante um determinado m�s informado pelo usu�rio.
A Sigla CRUD significa (Create, Read, Update, Delete), ou seja, voc� ter� que oferecer op��es de Inser��o, Pesquisa por c�digo/nome, atualiza��o e exclus�o.

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

    /*Impress�o do menu no console e coleta de op��o de menu*/
    while(OpcaoDeSaida !=1){
        cout << "Menu CRUD\n";
        cout << "1- Criar registro de cliente\n";
        cout << "2- Ler registro de cliente \n";
        cout << "3- Atualizar registro de cliente \n";
        cout << "4- Apagar registro de cliente \n";
        cout << "0- Retornar ao menu inicial";
        cin >> OpcaoMenu;
    }
    /*Fim da impress�o do menu no console e coleta de op��o de menu*/

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
        arquivo << "C�digo: " << Codigo << std::endl;
        arquivo << "Placa: " << Placa << std::endl;
        arquivo << "Modelo: " << Modelo << std::endl;
        arquivo << "Entrada: " << Entrada << std::endl;
        arquivo << "Sa�da: " << Saida << std::endl;
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

        /*Impress�o do menu no console e coleta de op��o de menu*/
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
        /*Fim de impress�o do menu no console e coleta de op��o de menu*/

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
                cout << "Arquivo 'veiculos_estacionados.txt' gerado em 'PENSAR COMO IMPRIMIR ENDERE�O NO DESKTOP'";
                break;
            case 5:
                system("cls");
                cout << "Arquivo 'NOME DO ARQUIVO' gerado em 'PENSAR COMO IMPRIMIR ENDERE�O NO DESKTOP'";
                break;
        }
        /*Fim switch case do menu principal*/

    }
}
