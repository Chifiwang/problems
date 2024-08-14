#include <iostream>
#include <string>
#include <unordered_map>

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::string a, b;
    std::cin >> a >> b;

    while (q--) {
        std::unordered_map<char, int> ai, bi;
        int l, r;
        std::cin >> l >> r;

        int res = 0;
        int rep = 0;
        for (int i = l - 1; i < r; ++i) {
            if (ai.find(a[i]) != ai.end()) {
                ai[a[i]]++;
            } else {
                ai[a[i]] = 1;
            }

            if (bi.find(b[i]) != bi.end()) {
                bi[b[i]]++;
            } else {
                bi[b[i]] = 1;
            }
        }

        for (auto it = ai.begin(); it != ai.end(); it++) {
            if (bi.find(it->first) != bi.end()) {
                rep += std::min(bi[it->first], it->second);
            }
        }
        res = r - l + 1 - rep;
        std::cout << res << '\n';
    }
}

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
