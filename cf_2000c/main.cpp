#include <iostream>
#include <unordered_map>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    std::string s;

    bool failed;
    while (m--) {
        // std::cout << '\n';
        std::unordered_map<int, char> a2s;
        std::unordered_map<char, int> s2a;
        failed = false;
        std::cin >> s;

        if (s.size() != a.size()) {
            std::cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            // std::cout << a[i] << ' ' << s[i] << '\n';
            bool found_a2s = a2s.find(a[i]) != a2s.end();
            bool found_s2a = s2a.find(s[i]) != s2a.end();

            if (found_a2s && !found_s2a) {
                // std::cerr << "1";
                std::cout << "NO\n";
                failed = true;
                break;
            }

            if (!found_a2s && found_s2a) {
                // std::cerr << "2";
                std::cout << "NO\n";
                failed = true;
                break;
            }

            if (!found_a2s && !found_s2a) {
                a2s[a[i]] = s[i];
                s2a[s[i]] = a[i];
                continue;
            }

            if (a2s[a[i]] != s[i] || s2a[s[i]] != a[i]) {
                // std::cerr << "3";
                std::cout << "NO\n";
                failed = true;
                break;
            }
        }

        if (failed) {
            continue;
        }

        std::cout << "YES\n";
    }
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

