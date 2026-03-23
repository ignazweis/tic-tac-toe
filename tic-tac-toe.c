#include <stdio.h>

int calc(char p[], char player, int move);
char change_player(char player);

int main (void)
{
    char p[9], player;
    bool win = false, invalid_move;
    int move = 0, buff;
    
    for (int i = 0; i < 9; i++)
    {
        p[i] = '.';
    }

    printf("Which player goes first? [O/X]\n");
    printf("> ");
    scanf("%1c", &player);
    getchar();
    printf("\n");

    if (player == 111 || player == 120)
    {
        player = player - 32;
    }

    if (player != 'X' && player != 'O')
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

        if (win == true)
        {
            player = change_player(player);

            printf("[%c] won!", player);
            printf("\n\n");
            return 0;
        }
        else if (move == 9)
        {
            printf("It's a draw!");
            printf("\n\n");
            return 0;
        }

        printf("> ");

        scanf("%1i", &buff);
        getchar();
        printf("\n");

        int pos = buff - 1;
        if (buff >= 1 && buff <= 9 && p[pos] == '.')
        {
            p[pos] = player;
            invalid_move = false;
        }
        else
        {
            invalid_move = true;
        }

        if (invalid_move == true)
        {
            printf("\n");
            printf("Jogada inválida.");
            printf("\n\n");
        }

        win = calc(p, player, move);

        player = change_player(player);

        if (invalid_move == false)
        {
            move++;
        }
    }
    return 0;
}

int calc(char p[], char player, int move)
{
    if (move >= 4)
    {
        if ((p[0] == player && p[1] == player && p[2] == player) ||
            (p[3] == player && p[4] == player && p[5] == player) ||
            (p[6] == player && p[7] == player && p[8] == player) ||

            (p[0] == player && p[3] == player && p[6] == player) ||
            (p[1] == player && p[4] == player && p[7] == player) ||
            (p[2] == player && p[5] == player && p[8] == player) ||

            (p[0] == player && p[4] == player && p[8] == player) ||
            (p[6] == player && p[4] == player && p[2] == player))
            {
                return 1;
            }
    }
    return 0;
}

char change_player(char player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
    return player;
}
