#include <iostream>
#include <string>

int main(void)
{
    int N;
    bool run = false;
    std::cin >> N;
    while (N-- && !run) {
        std::string move;
        std::cin >> move;
        switch (move[0]) {
        case 'S':
            std::cout << "Rock\n";
            break;
        case 'P':
            std::cout << "Scissors\n";
            break;
        case 'R':
            std::cout << "Paper\n";
            break;
        default:
            if (move.size() > 3) {
                run = true;
            } else {
                std::cout << "Foxen\n";
            }
            break;
        }
    }
    return 0;
}
