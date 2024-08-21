#include <cstdio>
#include <iostream>

void solve() {
    int mn = 2;
    int mx = 1000;
    int i, j;
    int res;
    do {
        i = mn + (mx - mn) / 3;
        j = mn + 2 * (mx - mn) / 3;
        printf("? %d %d\n", i, j);
        fflush(stdout);

        std::cin >> res;
        if (res == i * j) {
            mn = j;
            // printf("a\n");
        } else if (res == i * (j + 1)) {
            mx = j + 1;
            mn = i;
            // printf("b\n");
        } else {
            mx = i + 1;
            // printf("c\n");
        }
    } while (j - i > 1);

    if (res == i * (j + 1)) {
        printf("! %d\n", j);
        fflush(stdout);
    } else {
        printf("! %d\n", i);
        fflush(stdout);
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
