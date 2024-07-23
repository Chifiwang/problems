#include <iostream>
#include <string>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int x = 0;
    int n;

    std::cin >> n;

    while(n--) {
        std::string tmp;
        std::cin >> tmp;

        if (tmp[0] == '+' || tmp[2] == '+') {
            ++x;
        }
        else {
            --x;
        }
    }

    std::cout << x;

    return 0;
}
