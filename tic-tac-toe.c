#include <stdio.h>
#include <ctype.h>

#define P1 'X'
#define P2 'O'
#define DOT '.'
#define DOTS {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT}

int calc(char p[], int move);
char change_player(char player);

int main (void)
{
    char p[9] = DOTS, player;
    bool win = false;
    int move = 0, buff;

    printf("Which player goes first? [%c/%c]\n", P2, P1);
    printf("> ");
    scanf("%1c", &player);
    getchar();
    printf("\n");

    player = toupper(player);

    if (player != P1 && player != P2)
    {
        printf("Invalid player.\n\n");
        return 1;
    }

    while (true)
    {
        printf("  ╔═══╤═══╤═══╗\n");
        printf("  ║ %c │ %c │ %c ║  1   2   3\n", p[0], p[1], p[2]);
        printf("  ╟───┼───┼───╢\n");
        printf("  ║ %c │ %c │ %c ║  4   5   6\n", p[3], p[4], p[5]);
        printf("  ╟───┼───┼───╢\n");
        printf("  ║ %c │ %c │ %c ║  7   8   9\n", p[6], p[7], p[8]);
        printf("  ╚═══╧═══╧═══╝\n");

        if (!(move == 9) && !win)
        {
            printf("[%c] player\n", player);
        }
        else if (win)
        {
            player = change_player(player);

            printf("[%c] won!", player);
            printf("\n\n");
            break;
        }
        else if (move == 9)
        {
            printf("It's a draw!");
            printf("\n\n");
            break;
        }

        printf("> ");
        scanf("%1i", &buff);
        getchar();
        printf("\n");

        int pos = buff - 1;
        if (buff >= 1 && buff <= 9 && p[pos] == '.')
        {
            p[pos] = player;
            win = calc(p, move);
            player = change_player(player);
            move++;
        }
        else
        {
            printf("\n");
            printf("Invalid play.");
            printf("\n\n");
        }
    }
    return 0;
}

int calc(char p[], int move)
{
    if (move >= 4)
    {
        if ((p[0] != DOT && p[0] == p[1] && p[1] == p[2]) ||
            (p[3] != DOT && p[3] == p[4] && p[4] == p[5]) ||
            (p[6] != DOT && p[6] == p[7] && p[7] == p[8]) ||

            (p[0] != DOT && p[0] == p[3] && p[3] == p[6]) ||
            (p[1] != DOT && p[1] == p[4] && p[4] == p[7]) ||
            (p[2] != DOT && p[2] == p[5] && p[5] == p[8]) ||

            (p[0] != DOT && p[0] == p[4] && p[4] == p[8]) ||
            (p[6] != DOT && p[6] == p[4] && p[4] == p[2]))
            {
                return 1;
            }
    }
    return 0;
}

char change_player(char player)
{
    return (player == P1) ? P2 : P1;
}
