#include <iostream>

int main(void) {
    int T;
    std::cin >> T;
    int N, F;
    while (T--) {
        F = 0;
        std::cin >> N;
        for (int i = 0; i < N; ++i) {
            int tmp;
            std::cin >> tmp;
            F = std::max(tmp, F);
        }
        std::cout << F << '\n';
    }
}
