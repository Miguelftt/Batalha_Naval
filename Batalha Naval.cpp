#include "jogo.h"

using namespace std;

void ganhadores(string &g);
void inicializar(int tabela[lin][col]);
void verificacaoTabela(int tabela[lin][col]);
void criacaoNavio(int navio[3][2]);
void selecionar(int tiro[2]);
int selecionarTiro(int tiro[2], int navio[3][2]);
void printarNavioAleatorio(int navio[3][2]) // HACK Mostrar onde os navios foram escondidos
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("[%d] ", navio[i][j]);
        }
        printf("\n");
    }
}
void tela_gameover();
void Cor_Moldura();
void Tela_Inicial();
void Nome_Do_Jogo();
int Menu_Desenho();
int Escolhido(); // Antigo int Seta_Menu();
int Escolhido(int escolha);
void Sair_Ou_Continuar(char &letra);

void como_jogar();

int main()
{
    system("mode con:cols=140 lines=40"); // Controlar tamanho do cmd
    Tela_Inicial();

    char sair;
    do
    {
        // int clear_color1, clear_color2;
        sair = '.';
        int jogo = 0;
        jogo = Menu_Desenho();

        if (jogo == 1)
        {

            int tabela1[lin][col];
            int navios[3][2];
            int tiros[2];
            int tentativa = (lin + col) / 2 + 2, ganhou = 0;

            inicializar(tabela1);
            verificacaoTabela(tabela1);
            criacaoNavio(navios);
            do
            {
                tiros[0] = 100;
                tiros[1] = 100;
                // printarNavioAleatorio(navios);
                gotoxy(115, 3);
                printf("PONTOS: %d", ganhou);

                gotoxy(60, 28);
                printf("SELECIONE A CASA\n");

                gotoxy(65, 3);
                printf("CHANCES: %d\n", tentativa);

                while (tiros[0] > lin - 1) // Controlar se o usuário escrever um número maior que a possibilidade
                {
                    gotoxy(60, 31);
                    printf("Linha: ");
                    scanf("%d", &tiros[0]);
                    if (tiros[0] > lin - 1)
                    {
                        gotoxy(60, 31);
                        cout << "Valor invalido";

                        gotoxy(60, 31);
                        Sleep(1000);
                        cout << "                          "; // apagar o que o usuário errou
                    }
                }
                while (tiros[1] > col - 1) // Controlar se o usuário escrever um número maior que a possibilidade
                {
                    gotoxy(60, 32);
                    printf("Coluna: ");
                    scanf("%d", &tiros[1]);
                    if (tiros[1] > lin - 1)
                    {
                        gotoxy(60, 32);
                        cout << "Valor invalido";

                        gotoxy(60, 32);
                        Sleep(1000);
                        cout << "                               "; // apagar o que o usuário errou
                    }
                }
                // printf("[%d] [%d]\n",tiros[0],tiros[1]);

                gotoxy(60, 33);
                if (tabela1[tiros[0]][tiros[1]] == -1) // Não permitir que o usuário digite a mesma linha e coluna
                {
                    if (selecionarTiro(tiros, navios) == 1)
                    {
                        printf("Em cheio\n");
                        tabela1[tiros[0]][tiros[1]] = 1;
                        ganhou++;
                    }
                    else
                    {
                        printf("Tente outra vez\n");
                        tentativa--;
                        tabela1[tiros[0]][tiros[1]] = 0;
                    }
                }
                else
                {
                    cout << "CASA JA SELECIONADA";
                }
                gotoxy(60, 34);

                printf("Pressione alguma tecla");
                getch();
                system("cls");
                Cor_Moldura();
                verificacaoTabela(tabela1);

            } while (tentativa > 0 && ganhou != 3);
            gotoxy(60, 36);
            string s;
            if (ganhou == 3)
            {
                cout << "parabens tu ganhaste" << endl;
                getch();
                printf("Digite o seu nome campeão :");
                ganhadores(s);
                Sair_Ou_Continuar(sair);
            }
            else
            {
                printf("putz, tente de novo");
                getch();
                tela_gameover();
                Sair_Ou_Continuar(sair);
            }
        }
        else if (jogo == 2)
        {
            como_jogar();
        }
        else if (jogo == 3)
        {
            system("cls");
            char comando[9] = {"color "};
            char cores[3];
            char p;
            // scanf("%c",&p);
            do
            {
                Cor_Moldura;
                int x = 48, y = 4;
                gotoxy(x, y++);
                cout << " _______       ____  ______ _               ";

                gotoxy(x, y++);
                cout << "|__   __|/\\   |  _ \\|  ____| |        /\\    ";

                gotoxy(x, y++);
                cout << "   | |  /  \\  | |_) | |__  | |       /  \\   ";

                gotoxy(x, y++);
                cout << "   | | / /\\ \\ |  _ <|  __| | |      / /\\ \\  ";

                gotoxy(x, y++);
                cout << "   | |/ ____ \\| |_) | |____| |____ / ____ \\ ";

                gotoxy(x, y++);
                cout << "   |_/_/    \\_\\____/|______|______/_/    \\_\\";

                y = 15;
                gotoxy(x, y++);
                printf("0 - Preto                1 - Azul");
                gotoxy(x, y++);
                printf("2 - Verde                3 - Verde Água");
                gotoxy(x, y++);
                printf("4 - Vermelho             5 - Roxo");
                gotoxy(x, y++);
                printf("6 - Amarelo              7 - Branco");
                gotoxy(x, y++);
                printf("8 - Cinza                9 - Azul Claro");
                gotoxy(x, y++);
                printf("A - Verde claro          B - Verde Água Claro");
                gotoxy(x, y++);
                printf("C - Vermelho Claro       D - Lilás");
                gotoxy(x, y++);
                printf("F - Branco Brilhante     99 - Sair");

                y = 27;

                gotoxy(x, y++);
                printf("Cor de Fundo: ");
                scanf("%c", &cores[0]);
                getchar();
                gotoxy(x, y++);

                printf("Cor do Texto: ");
                scanf("%c", &cores[1]);
                cores[2] = '\0';

                strcat(comando, cores);

                system(comando);

                getch();
                getchar();

                break;
            } while (p != 99);
        }

        else if (jogo == 4)
        {
            gotoxy(60, 35);
            cout << "VOCE SAIU DO JOGO";
            break;
        }

    } while (toupper(sair) != 'N');
    return 0;
}
