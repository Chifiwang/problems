#include <iostream>
#include <string>

int main(void)
{
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::string a, b;
        std::cin >> a >> b;

        for (int i = N - 1; i >= 0; --i) {
            std::cout << b[i] << a[i];
        }
        std::cout << '\n';
    }
}
