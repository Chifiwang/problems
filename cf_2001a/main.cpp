#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> freq(n + 1);
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;

        freq[tmp]++;
        max = std::max(max, freq[tmp]);
    }

    std::cout << n - max << '\n';
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::cout.tie(NULL);
    std::cout.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
