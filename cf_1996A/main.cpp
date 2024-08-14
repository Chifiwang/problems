#include <iostream>
#include <cassert>

void solve() {
    int N;
    std::cin >> N;

    assert(N % 2 == 0);
    if (N % 4 == 0) {
        std::cout << N / 4 << '\n';
    } else {
        std::cout << N / 4 + 1 << '\n';
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
