#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

// #define DEBUG

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int n;
    std::cin >> n;

<<<<<<< HEAD
    std::vector<std::pair<int, int> > data;
=======
>>>>>>> 6c89c5a3e413e6ce1879315edc9ed55973bcc1ee
    data.reserve(n);

    long long tot = 0;

    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;

        data.emplace_back(tmp, i + 1);
        tot += tmp;
    }

    std::sort(data.begin(), data.begin() + n, [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first > b.first;
    });

#ifdef DEBUG
    std::cout << "HERE\n";
    for (int i = 0; i < n; ++i) {
        std::cout << data[i].first << ' ';
    }
    std::cout << '\n';
#endif

    std::vector<int> res;
    std::unordered_set<int> seen;
    std::unordered_set<int> rejected;
    bool is_nice;
    // int tmp;

    if (tot - data[0].first - data[1].first == data[1].first) {
        res.push_back(data[0].second);
    }

    for (int i = 1; i < n; ++i) {
        if (tot - data[i].first - data[0].first == data[0].first) {
            res.push_back(data[i].second);
#ifdef DEBUG
            std::cout << "inserted: " << data[i].first << ' ' << data[i].second << '\n';
#endif
        }
    }

    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }

    return 0;
}
