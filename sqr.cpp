#include <iostream>
#include <vector>
#include <map>

template <typename T>
T Sqr(T &n)
{
    return n * n;
}

template <typename T>
std::vector<T> Sqr(std::vector<T> &v)
{
    for (auto& i : v) {
       i = Sqr(i);
    }
    return v;
};

template <typename T1, typename T2>
std::pair<T1, T2> Sqr(std::pair<T1, T2> &p)
{
    p.first *= p.first;
    p.second *= p.second;
    return p;
}

template <typename K, typename V>
std::map<K, V> Sqr(std::map<K, V> &m)
{
    for (auto &i : m) {
        i.second = Sqr(i.second);
    }
    return m;
};

int main() {
    int a = 6;
    std::cout << "number: " << Sqr(a) << std::endl;
    std::cout << std::endl;


    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x : Sqr(v)) {
       std::cout << ' ' << x;
    }
    std::cout << std::endl << std::endl;


    std::map<std::string, double> m = {
        {"one", 11},
        {"two", 22}
    };
    std::cout << "map:" << std::endl;
    for (const auto& x : Sqr(m)) {
        std::cout << x.first << ' ' << x.second << std::endl;
    }
    std::cout << std::endl;


    std::pair<int, double> p = {8, 5.2};
    p = Sqr(p);
    std::cout << "pair: " << p.first << ", " << p.second << std::endl << std::endl;


    std::map<int, std::pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }

    return 0;
}
