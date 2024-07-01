#include <iomanip>
#include <iostream>

void solve();
int main(void)
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        solve();
    }
}

struct Quaternion {
    double x;
    double y;
    double z;
    double w;
};

void print(Quaternion q)
{
    std::cout << std::fixed << std::setprecision(6)
              << q.x << ' '
              << q.y << ' '
              << q.z << '\n';
}

void normalize(Quaternion& q)
{
    double inv_len = 1 / sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    q.x *= inv_len;
    q.y *= inv_len;
    q.z *= inv_len;
    q.w *= inv_len;
}

Quaternion prod(Quaternion a, Quaternion b)
{
    return {
        a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w,
        a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z
    };
}

void solve()
{
    Quaternion point;
    std::cin >> point.x >> point.y >> point.z;
    point.w = 0;

    Quaternion axis;
    std::cin >> axis.x >> axis.y >> axis.z;
    axis.w = 0;

    double angle;
    std::cin >> angle;
    angle /= 2;

    normalize(axis);

    Quaternion rotator;
    rotator.w = cos(angle);
    double sin_t = sin(angle);

    rotator.x = axis.x * sin_t;
    rotator.y = axis.y * sin_t;
    rotator.z = axis.z * sin_t;

    Quaternion rotator_conj;
    rotator_conj.w = rotator.w;
    rotator_conj.x = -rotator.x;
    rotator_conj.y = -rotator.y;
    rotator_conj.z = -rotator.z;

    Quaternion res = prod(prod(rotator, point), rotator_conj);

    // print(axis);
    print(res);
}
