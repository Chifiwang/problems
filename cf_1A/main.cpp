#include <cmath>
#include <iostream>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int n, m, a;
    n = 0;
    m = 1;
    a = 2;

    std::cin >> n >> m >> a;

    long long res = 0;

    res = std::ceil(n / (double) a) * std::ceil(m / (double) a);
    std::cout << res;
    return 0;
}
