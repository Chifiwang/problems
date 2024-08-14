#include <iostream>

void solve() {
    int n, s, m;
    std::cin >> n >> s >> m;

    int i = 0;
    bool can_shower = false;
    while (n--) {
        int l, r;
        std::cin >> l >> r;

        if (l - i >= s) {
            can_shower = true;
        }

        i = r;
    }

    if (m - i >= s) {
        can_shower = true;
    }

    if (can_shower) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
