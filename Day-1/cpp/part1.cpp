#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

int main() {
    std::ifstream file("../data.txt");
    std::vector<int> data_first, data_second, indexes;
    int x, y, n;
    n = 0;
    while (file >> x >> y) {
        data_first.push_back(x);
        data_second.push_back(y);
        indexes.push_back(n);
        n++;
    }
    std::sort(data_first.begin(), data_first.end());
    std::sort(data_second.begin(), data_second.end());
    int total = 0;
    for(const int& n : indexes) {
        total += std::abs(data_first[n] - data_second[n]);
    }
    std::cout << total << std::endl;
}