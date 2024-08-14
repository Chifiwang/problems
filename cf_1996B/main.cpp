#include <iostream>
#include <vector>

void solve()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> buff;
    buff.reserve(N * N);

    char c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> c;
            if (i % K == 0 && j % K == 0) {
                buff.push_back(c - '0');
            }
        }
    }

    N /= K; // output width
    for (int i = 0; i < buff.size(); ++i) {
        std::cout << buff[i];
        if ((i + 1) % N == 0) {
            std::cout << '\n';
        }
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
