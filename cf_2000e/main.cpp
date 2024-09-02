#include <cassert>
#include <functional>
#include <iostream>
#include <queue>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int w;
    std::cin >> w;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long> > pq;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long> > h;

    int r_weight = 1;
    int c_weight = 1;

    for (int i = 0; i < n; ++i) {
        r_weight = std::min(std::min(i + 1, n - i), std::min(n - k + 1, k));

        for (int j = 0; j < m; ++j) {
            c_weight = std::min(std::min(j + 1, m - j), std::min(m - k + 1, k));

            pq.push(r_weight * c_weight);
            if (pq.size() > w) {
                pq.pop();
            }
        }
    }

    long long tmp;
    for (int i = 0; i < w; ++i) {
        std::cin >> tmp;
        h.push(tmp);
    }

    long long res = 0;
    assert(pq.size() == h.size());
    // std::cout << '\n';

    while (pq.size()) {
        // std::cout << h.top() << ' ' << pq.top() << '\n';
        // std::cout << '|' << res << '\n';
        res += h.top() * pq.top();
        h.pop();
        pq.pop();
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

