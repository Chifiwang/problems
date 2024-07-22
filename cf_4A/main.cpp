#include <iostream>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int w;
    std::cin >> w;

    if (w % 2 == 0 && w > 2) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
