#include <cassert>
#include <iostream>
#include <vector>

const unsigned int p = 998244353;

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int N;
    unsigned long long T;

    std::cin >> N >> T;

    long long v_max = 0;
    long long v_min = 1;

    std::vector<long long> a;
    std::vector<long long> b;
    a.reserve(N);
    b.reserve(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> a[i] >> b[i];
        v_max = std::max(a[i], v_max);
    }

    long long v;
    unsigned long long vi;
    unsigned long long ti;

    assert(v_min <= v_max);
    while (v_min <= v_max) {
        v = ((v_max + v_min) >> 1) % p;
        vi = 0;
        ti = 0;

        for (int i = 0; i < N; ++i) {
            long long ai = a[i] % p;
            long long bi = b[i] % p;
            // while (ai >= v) {
            //     vi += ai;
            //     ai -= bi;
            //     ti++;
            //     if (vi > p) {
            //         vi %= p;
            //     }
            // }
            if (ai < v) {
                continue;
            }
            unsigned long long tmp = ai - v;
            unsigned long long k = tmp / bi + 1;
            vi += ((k * (ai + ai - (k - 1) * bi)) >> 1) % p;
            vi %= p;
            ti += k;
            if (ti > T) {
                break;
            }
        }

        if (ti == T) {
            break;
        } else if (ti < T) {
            v_max = v - 1;
        } else {
            v_min = v + 1;
        }
    }

    std::cout << vi << std::endl;
    return 0;
}
