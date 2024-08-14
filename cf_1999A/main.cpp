#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int res = 0;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }

    std::cout << res << '\n';
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
