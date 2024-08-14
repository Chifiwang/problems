#include <array>
#include <iostream>
#include <cmath>

std::array<int, 200002> mem;

void solve() {
    int l, r;
    std::cin >> l >> r;

    int res = mem[l] - 2 * mem[l - 1] + mem[r];

    std::cout << res << '\n';
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;

    mem[0] = 0;
    double log_3 = std::log2(3);

    for (int i = 1; i <= 200000; ++i) {
        mem[i] = mem[i - 1] + std::log2(i) / log_3 + 1;
    }

    while (t--) {
        solve();
    }

    return 0;
}
