#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<bool> buf(n + 2, false);
    std::vector<int> ord(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> ord[i];
    }

    buf[ord[0]] = true;
    for (int i = 1; i < n; ++i) {
        if (buf[ord[i] - 1] || buf[ord[i] + 1]) {
            buf[ord[i]] = true;
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
