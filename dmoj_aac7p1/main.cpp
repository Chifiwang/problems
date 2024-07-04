#include <iostream>

int main(void)
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int w, h;
        std::cin >> w >> h;

        if ((w < 7 && h == 1)
            || (w < 4 && h < 4)
            || (w == 1))
            std::cout << "bad\n";
        else
            std::cout << "good\n";
    }

    return 0;
}
