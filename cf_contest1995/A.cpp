#include <iostream>

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int res = 0;

        if (k <= n) {
            std::cout << !!k << '\n';
            continue;
        } else {
            res += 1;
            k -= n;
        }

        for (int i = 1; i < n; ++i) {
            if (k <= 0) {
                break;
            }

            k -= n - i;
            res++;

            if (k > 0) {
                k -= n - i;
                res++;
            }
        }

        std::cout << res << '\n';
    }

    return 0;
}
