#include <fstream>
#include <vector>
#include <utility>
#include <iostream>

int main() {
    std::ifstream file("../data.txt");
    std::vector<std::pair<int, int>> data_pairs;
    int x, y;
    while (file >> x >> y) {
        data_pairs.push_back({x, y});
    }

    std::cout << data_pairs[0].first << std::endl;
    return 0;
}