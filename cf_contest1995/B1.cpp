#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

void solve()
{
    long long n, m;
    std::cin >> n >> m;

    std::unordered_map<long long, long long> flowers;
    std::vector<long long> flower_types;
    flowers.reserve(n);
    flower_types.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long tmp;
        std::cin >> tmp;

        if (flowers.find(tmp) != flowers.end()) {
            flowers[tmp]++;
        } else {
            flowers[tmp] = 1;
            flower_types.push_back(tmp);
        }
    }

    std::sort(flower_types.begin(), flower_types.end(), std::greater<long long>());

    long long res = 0;
    if (flower_types.size() == 1) {
        res = std::min(m / flower_types[0], flowers[flower_types[0]]) * flower_types[0];
        std::cout << res << '\n';
        return;
    }

    for (int i = 0; i < flower_types.size() - 1; ++i) {
        long long k1 = m;
        long long k2 = m;
        long long foo = 0;
        long long bar = 0;
        foo += std::min(k1 / flower_types[i], flowers[flower_types[i]]) * flower_types[i];
        long long curr1 = std::min(k2 / flower_types[i + 1], flowers[flower_types[i + 1]]);
        bar += curr1 * flower_types[i + 1];

        if (flower_types[i] == flower_types[i + 1] + 1) {
            if (foo < k1) {
                k1 -= foo;
                foo += std::min(k1 / flower_types[i + 1], flowers[flower_types[i + 1]]) * flower_types[i + 1];
            }
            if (bar < k2) {
                k2 -= bar;
                long long curr2 = std::min(k2 / flower_types[i], flowers[flower_types[i]]);
                bar += curr2 * flower_types[i];
                while (curr1 && flowers[flower_types[i]] - curr2 && bar < m) {
                    bar++;
                    curr1--;
                    curr2++;
                }
            }
        }
        res = std::max(std::max(foo, bar), res);
        if (res == m) {
            break;
        }
    }

    std::cout << res << '\n';
}

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
