#include <iostream>

void solve() {
    int a[2];
    int b[2];

    std::cin >> a[0] >> a[1] >> b[0] >> b[1];

    int res = 0;

    int score = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (a[i] > b[j]) {
                score++;
            } else if (a[i] < b[j]) {
                score--;
            }

            if (a[1 - i] > b[1 - j]) {
                score++;
            } else if (a[1 - i] < b[1 - j]) {
                score--;
            }

            // std::cout << a[i] << ' ' << b[j] << ' ' << a[1-i] << ' ' << b[1-j] << ' ' << score << '\n';
            res += score > 0;
            score = 0;
        }
    }

    std::cout << res << '\n';
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
