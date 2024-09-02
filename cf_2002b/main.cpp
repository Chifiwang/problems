#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }


    std::vector<bool> at(n + 1, true);
    std::vector<bool> bt(n + 1, true);

    int ai = 0;
    int aj = n - 1;
    int bi = 0;
    int bj = n - 1;

    for (int i = 0; i < n - 1; ++i) {
        if (bt[a[ai]] && bt[a[aj]]) {
            if (b[bi] == a[ai] || b[bj] == a[ai]) {
                at[a[aj]] = false;
                aj--;
            } else {
                at[a[ai]] = false;
                ai++;
            }
        } else if (bt[a[aj]]) {
            at[a[aj]] = false;
            aj--;
        } else {
            at[a[ai]] = false;
            ai++;
        }

        if (!at[b[bj]] || !at[b[bi]]) {
            if (a[ai] == b[bi] || a[aj] == b[bi]) {
                bt[b[bj]] = false;
                bj--;
            } else {
                bt[b[bi]] = false;
                bi++;
            }
        } else if (!at[b[bj]]) {
            bt[b[bj]] = false;
            bj--;
        } else {
            bt[b[bi]] = false;
            bi++;
        }
    }

    if (a[ai] == b[bi]) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Alice\n";
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
