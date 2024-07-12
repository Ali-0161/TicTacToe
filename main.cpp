#include <iostream>
#include <random>

void render(char grid[9]);

int main() {
    system("clear");

    char grid[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    render(grid);

    while (true)
    {
        int human_move = 0;

        while (human_move > 9 || human_move < 1)
        {
            std::cout << "What is your next move? (1-9): ";
            std::cin >> human_move;
        }

        grid[human_move-1] = 'X';
        system("clear");
        render(grid);

        if (
            (grid[0] == 'X' && grid[1] == 'X' && grid[2] == 'X') ||
            (grid[3] == 'X' && grid[4] == 'X' && grid[5] == 'X') ||
            (grid[6] == 'X' && grid[7] == 'X' && grid[8] == 'X') ||

            (grid[0] == 'X' && grid[3] == 'X' && grid[6] == 'X') ||
            (grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X') ||
            (grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X') ||

            (grid[0] == 'X' && grid[4] == 'X' && grid[8] == 'X') ||
            (grid[2] == 'X' && grid[4] == 'X' && grid[6] == 'X')
        )
        {
            std::cout << "YOU WON!! CONGRATS!" << '\n';
            break;
        }

        int bot_move;

        while (bot_move > 9 || bot_move < 1 || grid[bot_move-1] != ' ')
        {
            bot_move = rand() % 9 + 1;
        }

        grid[bot_move-1] = 'O';
        system("clear");
        render(grid);

        if (
            (grid[0] == 'O' && grid[1] == 'O' && grid[2] == 'O') ||
            (grid[3] == 'O' && grid[4] == 'O' && grid[5] == 'O') ||
            (grid[6] == 'O' && grid[7] == 'O' && grid[8] == 'O') ||

            (grid[0] == 'O' && grid[3] == 'O' && grid[6] == 'O') ||
            (grid[1] == 'O' && grid[4] == 'O' && grid[7] == 'O') ||
            (grid[2] == 'O' && grid[5] == 'O' && grid[8] == 'O') ||

            (grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O') ||
            (grid[2] == 'O' && grid[4] == 'O' && grid[6] == 'O')
        )
        {
            std::cout << "YOU LOST! THE BOT WON" << '\n';
            break;
        }
        
    }

    return 0;
}

void render(char grid[9]) {
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << grid[3] << "  |  " << grid[4] << "  |  " << grid[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << grid[6] << "  |  " << grid[7] << "  |  " << grid[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
}