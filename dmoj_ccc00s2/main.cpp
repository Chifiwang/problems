#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::vector<double> mountain;

    int N;
    std::cin >> N;
    mountain.reserve(N);

    int curr = 0;

    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        mountain.emplace_back(temp);
    }

    int code = 0;
    while (true) {
        std::cin >> code;
        if (code == 77) {
            break;
        }

        int idx;
        std::cin >> idx;

        if (code == 99) {
            double percent;
            std::cin >> percent;
            percent /= 100;

            double tmp = (1 - percent) * mountain[idx - 1];
            mountain[idx - 1] *= percent;

            mountain.insert(mountain.begin() + idx, tmp);

        } else if (code == 88) {
            mountain[idx - 1] += mountain[idx];
            mountain.erase(mountain.begin() + idx);
        }
    }

    for (int i = 0; i < mountain.size() - 1; ++i) {
        std::cout << mountain[i] << ' ';
    }
    std::cout << mountain[mountain.size() - 1];
    return 0;
}
