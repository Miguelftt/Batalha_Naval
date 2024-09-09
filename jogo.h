#ifndef jogo_h
#define jogo_h

#include <iostream>
#include <time.h>
#include <Windows.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <fstream>

#include "ARTES.h"
#include "jogo.h"

#define lin 3 // RECOMENDADO NO MAXIMO 10
#define col 3 // RECOMENDADO NO MAXIMO 10
#define Max_col 140
#define Max_lin 40

using namespace std;

void Sair_Ou_Continuar(char &letra)
{
    gotoxy(55, 35);
    cout << "DESEJA CONTINUAR? Digite 'S' ou 'N'" << endl;
    getchar(); // NECESSÁRIO POIS AINDA RECEBE O CHAR DA FUNÇÃO GANHADOR

    while (toupper(letra) != 'S' && toupper(letra) != 'N')
    {
        gotoxy(70, 37);
        letra = getchar();
        if (toupper(letra) != 'S' && toupper(letra) != 'N')
        {
            gotoxy(55, 38);
            cout << "Digite apenas 's' ou 'n'";
        }
    }
}

void inicializar(int tabela[lin][col])
// faz com que a tabela inicialize com -1
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            tabela[i][j] = -1;
        }
    }
}

void verificacaoTabela(int tabela[lin][col])
// se retornar 1 (verdadeiro) printa * se retornar 0(falso) printa N  e -1 para printar vazio a cartela
{
    int x = 50, y = 5;
    int aux = 53;

    gotoxy(53, 5);
    for (int n = 0; n < col; n++) // numeros da coluna
    {
        gotoxy(aux, y);
        cout << n;
        aux += 4;
    }

    for (int i = 0; i < lin; i++)
    {

        y += 2;
        gotoxy(x - 2, y);

        printf("%d  ", i); // numeros da linha
        for (int j = 0; j < col; j++)
        {
            if (tabela[i][j] == 1)
                printf(" [N]");         // acertou tem navio ali
            else if (tabela[i][j] == 0) // depois fazer com que o usuario nao possa jogar 2 veze sno mesmo lugar//
                printf(" [%c]", 158);   // errou nao tem navio
            else if (tabela[i][j] == -1)
                printf("  %c ", 254);
        }
        printf("\n");
    }
}

void criacaoNavio(int navio[3][2])
// vai gerar numeros aleatorios para os navios tanto nas linhas quanto nas colunas
{
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        navio[i][0] = rand() % lin; // gera os navios aleatorios na linha
        navio[i][1] = rand() % col; // gera os navios aleatorios na coluna
        for (int j = 0; j < i; j++)
        {
            if ((navio[i][0] == navio[j][0]) && (navio[i][1] == navio[j][1]))        // se os numeros forem iguais a anterior gera novos por isso o 0 e 1
            {                                                                        // para nao gerarem 2 navios no mesmo lugar
                while ((navio[i][0] == navio[j][0]) && (navio[i][1] == navio[j][1])) // gera ate serem diferentes
                {
                    navio[i][0] = rand() % lin;
                    navio[i][1] = rand() % col;
                }
            }
        }
    }
}

// void selecionar(){
// 0 é a linha e 1 é a coluna de onde o usuario quer selecionar
// printf("\nSelecione as casas\n");
// printf("Linha: ");
// printf("%s",aux);
// printf("algumacoisa");
// scanf("%d",&tiro[0]);
// printf("algumacoisa");
// printf("Coluna: ");
// scanf("%d",&tiro[1]);
// }

int selecionarTiro(int tiro[2], int navio[3][2]) // ver se tem navio na posição
{
    //
    for (int i = 0; i < 3; i++)
    {
        if ((tiro[0] == navio[i][0]) && (tiro[1] == navio[i][1]))
        {
            return 1;
        }
    }
    return 0;
}

void ganhadores(string &g)
{
    Cor_Moldura();
    gotoxy(45, 2);
    cout << "DIGITE O SEU NOME PARA GRAVAR NAS LISTA DE VENCEDORES";

    gotoxy(60, 5);
    cin >> g;

    int y = 5, x = 43;
    gotoxy(x, y++);
    cout << "__          _______ _   _ _   _ ______ _____   _____ ";
    gotoxy(x, y++);
    cout << "\\ \\        / /_   _| \\ | | \\ | |  ____|  __ \\ / ____|";
    gotoxy(x, y++);
    cout << " \\ \\  /\\  / /  | | |  \\| |  \\| | |__  | |__) | (___  ";
    gotoxy(x, y++);
    cout << "  \\ \\/  \\/ /   | | | . ` | . ` |  __| |  _  / \\___ \\ ";
    gotoxy(x, y++);
    cout << "   \\  /\\  /   _| |_| |\\  | |\\  | |____| | \\ \\ ____) |";
    gotoxy(x, y++);
    cout << "    \\/  \\/   |_____|_| \\_|_| \\_|______|_|  \\_\\_____/ ";

    ifstream entrada;
    fstream saida;
    entrada.open("infile.txt");
    saida.open("ganhadores.txt", ios::app);
    entrada >> g;
    saida << g << endl;
    string h;
    ifstream ent("ganhadores.txt");
    x = 60;
    y = 13;
    int n = 1;
    while (getline(ent, h))
    {
        gotoxy(x, y++);
        printf("%i%c ", n, 167);
        cout << h << endl;
        n++;
        if (n > 20)
        {
            break;
        }
    }
    ent.close();
    entrada.close();
    saida.close();
}

void como_jogar()
{
    Cor_Moldura();

    int x = 52, y = 4;
    gotoxy(x, y++);
    cout << "              _ _    _ _____          ";

    gotoxy(x, y++);
    cout << "    /\\       | | |  | |  __ \\   /\\    ";

    gotoxy(x, y++);
    cout << "   /  \\      | | |  | | |  | | /  \\   ";

    gotoxy(x, y++);
    cout << "  / /\\ \\ _   | | |  | | |  | |/ /\\ \\  ";

    gotoxy(x, y++);
    cout << " / ____ \\ |__| | |__| | |__| / ____ \\ ";

    gotoxy(x, y++);
    cout << "/_/    \\_\\____/ \\____/|_____/_/    \\_\\";

    x = 10;
    y = 15;
    gotoxy(x, y += 2);
    printf("%c%c O JOGO EH CONSTITUIDO POR ESPACOS COM BARCO E ESPACOS VAZIOS", 175, 175);
    gotoxy(x, y += 2);
    printf("%c%c O USUARIO PRECISA ACERTAR 3 BARCOS PARA GANHAR O JOGO", 175, 175);
    gotoxy(x, y += 2);
    printf("%c%c A QUANTIDADE DE CHANCES VAI VARIAR COM O TAMANHO DO TABULEIRO CONFIGURADO (POR ENQUANTO APENAS POSSIVEL NO CODIGO)", 175, 175);
    gotoxy(x, y += 2);
    printf("%c%c ACERTE A POSICAO DE TODOS OS BARCOS ANTES QUE SUAS TENTATIVAS ACABEM :'( ", 175, 175);
    gotoxy(x, y += 2);
    printf("%c%c TENHA UM BOM JOGO!!", 175, 175);
    y = y + 5;
    x = 60;
    gotoxy(x, y);
    printf("%c%c CLIQUE PARA VOLTAR %c%c", 175, 175, 174, 174);

    getch();
    return;
}

#endif /* jogo_h */
