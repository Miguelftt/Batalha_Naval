#ifndef ARTES_H
#define ARTES_H

#include "gconio.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <ctype.h>

#define Max_col 140
#define Max_lin 40

using namespace std;
void animacao_inicio();
void Cor_Moldura();
void Tela_Inicial();
void Nome_Do_Jogo();
int Menu_Desenho();
int Escolhido(); // Antigo int Seta_Menu();
int Escolhido(int escolha);

void Cor_Moldura() // Moldura Da tela utilizando caracteres
{
    textbackground(LIGHTBLUE);
    textcolor(RED);
    clrscr();

    gotoxy(0, 0);
    printf("%c", 201);
    for (int linha = 1; linha < Max_lin - 1; linha++) // colunas
    {
        gotoxy(0, linha);
        printf("%c", 186);
        gotoxy(Max_col - 1, linha);
        printf("%c", 186);
    }
    gotoxy(0, Max_lin);
    printf("\n%c", 200);

    for (int coluna = 1; coluna < Max_col - 1; coluna++) // linha em cima
    {
        gotoxy(coluna, 0);
        printf("%c", 205);
    }
    printf("%c", 187);

    for (int coluna = 1; coluna < Max_col - 1; coluna++) // linha em baixo
    {
        gotoxy(coluna, Max_lin - 1);
        printf("%c", 205);
    }
    printf("%c", 188);
}

void Nome_Do_Jogo()
{
    int y = 7, x = 40;

    gotoxy(x, y++);
    cout << (" ____        _        _ _             _   _                  _  ");
    gotoxy(x, y++);

    cout << "|  _ \\      | |      | | |           | \\ | |                | | ";
    gotoxy(x, y++);

    cout << "| |_) | __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| | ";
    gotoxy(x, y++);

    cout << "|  _ < / _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | | ";
    gotoxy(x, y++);

    cout << "| |_) | (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | | ";
    gotoxy(x, y++);

    cout << "|____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| |_| \\_|\\__,_| \\_/ \\__,_|_| ";
}

void Tela_Inicial()
{
    Cor_Moldura();
    Nome_Do_Jogo();
    int y = 13, x = 35;
    y = y + 5;

    gotoxy(x, y++);
    cout << ("                           |\\                        ");
    gotoxy(x, y++);
    cout << ("                           |_\\                        ");
    gotoxy(x, y++);
    cout << ("                           |__\\                      ");
    gotoxy(x, y++);
    cout << ("                           |___\\                     ");
    gotoxy(x, y++);
    cout << ("                           |____\\                    ");
    gotoxy(x, y++);
    cout << ("                           |_____\\                  ");
    gotoxy(x, y++);
    cout << ("                           |______\\                ");
    gotoxy(x, y++);
    cout << ("                        ______|_______________        ");
    gotoxy(x, y++);
    cout << ("~~~~~~~~~~~~~~~~~~~~~~~~\\____________________/~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(x, y++);
    cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    gotoxy(x, y++);
    cout << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    cout << ("");

    gotoxy(x + 18, y + 5);
    cout << "Clique qualquer tecla para continuar!!\n\n\n";
    getch();
}

int Menu_Desenho()
{
    Cor_Moldura();
    Nome_Do_Jogo();

    int x = 50, y = 20;

    gotoxy(x, y);
    printf("%c", 201);

    for (int linha = y; linha < 28; linha += 2)
    {
        gotoxy(x, linha + 2);
        printf("%c", 204);
        gotoxy(x, linha + 1);
        printf("%c", 186);
        if (linha == 26) // fechamento dos cantos
        {
            gotoxy(x, linha + 2);
            printf("%c", 200);
            gotoxy(x + 40, linha + 2);
            printf("%c", 188);
            gotoxy(x + 40, y);
            printf("%c", 187);
        }
    }

    for (int coluna = x + 1; coluna < 90; coluna++) // linhas entre as opções
    {
        gotoxy(coluna, y);
        printf("%c", 205);
        gotoxy(coluna, y + 2);
        printf("%c", 205);
        gotoxy(coluna, y + 4);
        printf("%c", 205);
        gotoxy(coluna, y + 6);
        printf("%c", 205);
        gotoxy(coluna, y + 8);
        printf("%c", 205);
    }

    for (int linha = y; linha < 26; linha += 2)
    {
        gotoxy(x + 40, linha + 2);
        printf("%c", 185);
        gotoxy(x + 40, linha + 1);
        printf("%c", 186);
        if (linha == 24)
        {
            gotoxy(x + 40, linha + 3);
            printf("%c", 186);
        }
    }

    gotoxy(x + 18, y += 1); // resto dos quadrado
    printf("JOGAR");

    gotoxy(x + 16, y += 2);
    cout << "COMO JOGAR";

    gotoxy(x + 15, y += 2);
    cout << "OPCOES(BETA)";

    gotoxy(x + 19, y += 2);
    cout << "SAIR";
    return Escolhido(Escolhido()); // Antigo int Seta_Menu(); menu estava dentro do Escolhido
}

int Escolhido(int escolha)
{
    int x = 60, y = 30;
    if (escolha == 1)
    {
        gotoxy(x, y);
        cout << "Voce escolheu: JOGAR!!!";
        animacao_inicio();
        Cor_Moldura();
        return escolha;
    }
    else if (escolha == 2)
    {
        gotoxy(x, y);
        cout << "Voce escolheu: COMO JOGAR!!!";
        return escolha;
    }
    else if (escolha == 3)
    {
        gotoxy(x, y);
        cout << "Voce escolheu: OPCAO!!!";
        return escolha;
    }
    else if (escolha == 4)
    {
        gotoxy(x, y);
        cout << " tchau ;-; :'( ";
        return escolha;
    }
}

int Escolhido() // Antigo int Seta_Menu();
{
    int coluna = 91, linha = 21, escolha = 1;
    char letra;

    gotoxy(115, 2);
    textcolor(BLACK);
    cout << "MOVA-SE COM 'W' E 'S'";
    gotoxy(115, 3);
    cout << "OU UTILIZE AS SETAS";
    textcolor(RED);

    gotoxy(coluna, linha);
    cout << "<========";
    do
    {
        gotoxy(140, 40);
        letra = getch();

        if (linha != 21)
        {
            if (letra == 72 || toupper(letra) == 87) // subir seta
            {

                gotoxy(coluna, linha -= 2);
                cout << "<========";
                escolha -= 1;
            }
            if (linha != 29) // apagar setas
            {
                gotoxy(coluna, linha + 2);
                cout << "         ";
            }
        }
        if (linha != 27)
        {
            if (letra == 80 || toupper(letra) == 83) // descer seta
            {
                gotoxy(coluna, linha += 2);
                cout << "<========";
                escolha += 1;
            }
            if (linha != 29) // apagar setas
            {
                gotoxy(coluna, linha - 2);
                cout << "         ";
            }
        }
        gotoxy(139, 39);

    } while (letra != 13 && letra != ' ');
    return escolha;
}

void tela_gameover()
{
    textbackground(BLACK);
    textcolor(RED);
    clrscr();
    gotoxy(0, 0);
    printf("%c", 201);
    for (int linha = 1; linha < Max_lin - 1; linha++) // colunas
    {
        gotoxy(0, linha);
        printf("%c", 186);
        gotoxy(Max_col - 1, linha);
        printf("%c", 186);
    }
    gotoxy(0, Max_lin);
    printf("\n%c", 200);

    for (int coluna = 1; coluna < Max_col - 1; coluna++) // linha em cima
    {
        gotoxy(coluna, 0);
        printf("%c", 205);
    }
    printf("%c", 187);

    for (int coluna = 1; coluna < Max_col - 1; coluna++) // linha em baixo
    {
        gotoxy(coluna, Max_lin - 1);
        printf("%c", 205);
    }
    printf("%c", 188);

    int y = 14, x = 20;

    gotoxy(x, y++);
    cout << "   .::::         .:       .::       .::. ::::::::     .::::     .::         .::.::::::::.:::::::    ";

    gotoxy(x, y++);
    cout << " .:    .::      .: ::     .: .::   .:::. ::         .::    .::   .::       .:: .::      .::    .::  ";

    gotoxy(x, y++);
    cout << ".::            .:  .::    .:: .:: . .::. ::       .::        .::  .::     .::  .::      .::    .::  ";

    gotoxy(x, y++);
    cout << ".::           .::   .::   .::  .::  .::. ::::::   .::        .::   .::   .::   .::::::  .: .::      ";

    gotoxy(x, y++);
    cout << ".::   .::::  .::::::::::. .::   .:  .::. ::       .::        .::    .:: .::    .::      .::  .::    ";

    gotoxy(x, y++);
    cout << " .::    .:  .::       .:: .::       .::. ::         .::     .::      .::::     .::      .::    .::  ";

    gotoxy(x, y++);
    cout << "  .:::::   .::         .::.::       .::. ::::::::     .::::           .::      .::::::::.::      .::";
}

void animacao_inicio()
{
    int i;
    int j;
    int clear_color1 = BLACK;
    int clear_color2 = BLACK;
    for (i = 1; i <= Max_lin / 2; ++i)
    {
        for (j = 1; j <= Max_col; ++j)
        {
            textbackground(WHITE);
            gotoxy(j, i);
            printf(" ");

            gotoxy(j, Max_lin - (i - 1));
            printf(" ");

            if (i > 1)
            {
                textbackground(clear_color1);
                textcolor(clear_color1);
                gotoxy(j, i - 1);
                printf(" ");

                if (i <= Max_lin * 0.2)
                    textbackground(clear_color2);

                gotoxy(j, Max_lin - (i - 2));
                printf(" ");
            }
        }

        gotoxy(Max_col / 2, Max_lin / 2);
        Sleep(20);
    }

    textbackground(clear_color1);
    for (j = Max_col / 2; j > 0; --j)
    {
        for (i = 0; i < 2; ++i)
        {
            gotoxy(j, Max_lin / 2 + i);
            printf(" ");

            gotoxy(Max_col - (j - 1), Max_lin / 2 + i);
            printf(" ");
        }

        gotoxy(Max_col / 2, Max_lin);
        Sleep(15);
    }
}

#endif /* ARTES.H */
