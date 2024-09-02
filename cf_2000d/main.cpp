#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<long long> strip(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> strip[i + 1];
        strip[i + 1] += strip[i];
    }

    std::string s;
    std::cin >> s;
    long long res = 0;

    int mx = n + 1;
    int mn = 0;

    while (mn < mx) {
        int l = mn + 1;
        int r = mx - 1;

        while (l < r && (s[l - 1] != 'L' || s[r - 1] != 'R')) {
        // std::cerr << '\n' << r << ' ' << l << '\n';
            if (s[l - 1] != 'L') {
                l++;
            }

            if (s[r - 1] != 'R') {
                r--;
            }
        }

        // std::cerr << '\n' << r << ' ' << l << '\n';

        if (l >= r) {
            res += 0;
        } else {
            res += strip[r] - strip[l - 1];
        }

        mx = r;
        mn = l;
    }

    std::cout << res << '\n';
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

