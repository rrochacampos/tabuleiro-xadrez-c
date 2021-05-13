
/*TABULEIRO DE XADREZ
Esse programa imita um tabuleiro de xadrez e suas pe�as, sem seguir as regras corretamente. Para escolher e movimentar uma pe�a
voc� deve: escolher o n�mero de uma linha, apertar espa�o, escolher o n�mero de uma coluna e apertar enter. As pe�as com letra min�scula
s�o do jogador 1 e de letra mai�scula do jogador 2. Voc� pode movimentar para um espa�o vazio (os que possuem um ponto) ou para uma pe�a
do outro jogador. O programa finaliza quando o jogador coloca uma pe�a no lugar do rei do outro jogador.

    P (pe�o)  T (torre)  C (cavalo)  B (bispo)  K (rei)  Q (rainha)*/

#include <stdio.h>
#include <windows.h>
#include <locale.h>



void exibirTabuleiro(char tabuleiro[9][9], char jogadorUm[], char jogadorDois[])
{
    system("cls");
    printf("  %c   %c   %c   %c   %c   %c   %c   %c   %c", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4], tabuleiro[0][5], tabuleiro[0][6], tabuleiro[0][7], tabuleiro[0][8]);
    printf("\n   ___________________________________");
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Jogador 1: pe�as min�sculas.", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4], tabuleiro[1][5], tabuleiro[1][6],
           tabuleiro[1][7], tabuleiro[1][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Jogador 2: pe�as mai�sculas.", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4], tabuleiro[2][5], tabuleiro[2][6],
           tabuleiro[2][7], tabuleiro[2][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  COMO SELECIONAR E MOVIMENTAR: Aperte o", tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5],
           tabuleiro[3][6], tabuleiro[3][7], tabuleiro[3][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  n�mero de uma linha, aperte espa�o, aperte", tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4], tabuleiro[4][5],
           tabuleiro[4][6], tabuleiro[4][7], tabuleiro[4][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  o n�mero de uma coluna e aperte enter.", tabuleiro[5][0], tabuleiro[5][1], tabuleiro[5][2], tabuleiro[5][3], tabuleiro[5][4], tabuleiro[5][5],
           tabuleiro[5][6], tabuleiro[5][7], tabuleiro[5][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |", tabuleiro[6][0], tabuleiro[6][1], tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4], tabuleiro[6][5], tabuleiro[6][6], tabuleiro[6][7],
           tabuleiro[6][8]);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Pe�as capturadas pelo jogador 1: %s", tabuleiro[7][0], tabuleiro[7][1], tabuleiro[7][2], tabuleiro[7][3], tabuleiro[7][4], tabuleiro[7][5],
           tabuleiro[7][6], tabuleiro[7][7], tabuleiro[7][8], jogadorUm);
    printf("\n\n%c  |  %c   %c   %c   %c   %c   %c   %c   %c  |  Pe�as capturadas pelo jogador 2: %s", tabuleiro[8][0], tabuleiro[8][1], tabuleiro[8][2], tabuleiro[8][3], tabuleiro[8][4], tabuleiro[8][5],
           tabuleiro[8][6], tabuleiro[8][7], tabuleiro[8][8], jogadorDois);
    printf("\n   ___________________________________\n");
}

void exibirMensagemDeErro()
{
    puts("\nMovimento inv�lido! Pressione qualquer tecla para continuar...\n");
            fflush(stdin);
            getchar();
}

int verificarMovimento (int x, int y, char peca, int jogador)
{
    int valor = 1;
    if (jogador == 1)
    {
        if(isalpha(x) || isalpha(y) || x <= 0 || y <= 0 || x > 8 || y > 8 || islower(peca))
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    else
    {
        if (isalpha(x) || isalpha(y) || x <= 0 || y <= 0 || x > 8 || y > 8 || isupper(peca))
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    return valor;
}

void realizarMovimento (char jogador[17], int *indice, int *qualJogador, char tabuleiro[9][9], int x, int y, int linha, int coluna)
{
    if (tabuleiro[x][y] == '.') //verifica se vai mover para um espa�o "vazio".
    {
        tabuleiro[x][y] = tabuleiro[linha][coluna];
        tabuleiro[linha][coluna]='.';

        if (*qualJogador == 1)
        {
            (*qualJogador)++;
        }
        else
        {
            (*qualJogador)--;
        }
    }
    else //vai mover para uma pe�a do jogador advers�rio
    {
        if (*qualJogador == 1) //move para uma pe�a do jogador 2
        {
            jogador[*indice] = tabuleiro[x][y];
            tabuleiro[x][y] = tabuleiro[linha][coluna];
            tabuleiro[linha][coluna]='.';
            (*indice)++;
            (*qualJogador)++;
        }
        else //move para uma pe�a do jogador 1
        {
            jogador[*indice] = tabuleiro[x][y];
            tabuleiro[x][y] = tabuleiro[linha][coluna];
            tabuleiro[linha][coluna]='.';
            (*indice)++;
            (*qualJogador)--;
        }
    }
}

/*Primeiro verifica qual jogador est� na vez. Depois verifica se linha e colunas s�o do tipo alfab�tico, se s�o menores ou iguais
a zero, se o char peca � igual a '.' e se o char peca � mai�sculo (no caso do jogador 1 e min�sculo no jogador 2).
Caso confirme, � informada uma mensagem de erro. Caso a pe�a seja v�lida, o valor retornado � 0.*/
int verificarPeca (char peca, int linha, int coluna, int qualJogador)
{
    int valor = 1;
    if (qualJogador == 1)
    {
        if (isalpha(linha) || isalpha(coluna) || linha <= 0 || coluna <= 0 || linha > 8 || coluna > 8 || isupper(peca) || peca == '.')
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    else
    {
        if (isalpha(linha) || isalpha(coluna) || linha <= 0 || coluna <= 0 || linha > 8 || coluna > 8 || islower(peca) || peca == '.')
        {
            exibirMensagemDeErro();
        }
        else
        {
            valor = 0;
        }
    }
    return valor;
}

void exibirVitoria (char jogador[])
{
    printf("\n\nXeque mate! %s capturou o rei e venceu!\n\n", jogador);
    Beep(660,100);
    Sleep(50);
    Beep(660,100);
    Sleep(200);
    Beep(660,100);
    Sleep(200);
    Beep(510,100);
    Sleep(25);
    Beep(660,100);
    Sleep(200);
    Beep(770,100);
    Sleep(450);
    Beep(380,100);
    Sleep(475);
}

main ()
{
    /*qualJogador indica o jogador do momento.
    indiceUm e indiceDois indicam o indice atual de cada jogador em que a pe�a capturada ser� colocada.
    jogadorUm[17] e jogadorDois[17] s�o arrays do tipo char que armazenam as pe�as capturadas por cada jogador
    tabuleiro[9][9] � um array bidimensional do tipo char que armazena o tabuleiro*/
    setlocale(LC_ALL,"");
    int qualJogador=1, indiceUm=0, indiceDois=0, continua=1, linha=0, coluna=0, x=0, y=0; //x e y s�o linha e coluna para onde a pe�a ir�
    char jogadorUm[17]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char jogadorDois[17]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char tabuleiro[9][9] = {' ','1','2','3','4','5','6','7','8',
                            '1','t','c','b','q','k','b','c','t',
                            '2','p','p','p','p','p','p','p','p',
                            '3','.','.','.','.','.','.','.','.',
                            '4','.','.','.','.','.','.','.','.',
                            '5','.','.','.','.','.','.','.','.',
                            '6','.','.','.','.','.','.','.','.',
                            '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
                            '8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T'
                           };


    while (continua == 1) //repeti��o do jogo inteiro
    {

        exibirTabuleiro(tabuleiro, jogadorUm, jogadorDois);

        if (jogadorUm[indiceUm-1]=='K')//verifica se o jogador 1 venceu
        {
            exibirVitoria("Jogador 1");
            return(0);
        }
        else if (jogadorDois[indiceDois-1]=='k')//verifica se o jogador 2 venceu
        {
            exibirVitoria("Jogador 2");
            return(0);
        }

        do //ir� repetir caso o jogador escolha um pe�a inv�lida
        {
            exibirTabuleiro(tabuleiro, jogadorUm, jogadorDois);
            printf("\n\nJogador %i - digite qual pe�a deseja mover: ", qualJogador);
            fflush(stdin);
            scanf("%i%i", &linha, &coluna);

        }
        while(verificarPeca(tabuleiro[linha][coluna], linha, coluna, qualJogador));


        do //ir� repetir enquanto for um movimento inv�lido
        {
            exibirTabuleiro(tabuleiro, jogadorUm, jogadorDois);
            printf("\nJogador %i - digite para onde deseja mover a peca da linha %i e coluna %i: ", qualJogador, linha, coluna);
            fflush(stdin);
            scanf("%i%i", &x, &y);

        }
        while(verificarMovimento(x, y, tabuleiro[x][y], qualJogador));


        if (qualJogador == 1)
        {
            realizarMovimento(jogadorUm, &indiceUm, &qualJogador, tabuleiro, x, y, linha, coluna);
        }
        else
        {
            realizarMovimento(jogadorDois, &indiceDois, &qualJogador, tabuleiro, x, y, linha, coluna);
        }
    }
}
