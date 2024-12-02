#include <fstream>
#include <vector>
#include <utility>

int main() {
    std::ifstream file("part-1-data.txt");
    std::vector<std::pair<int, int>> data_pairs;
    int x, y;
    while (file >> x >> y) {
        data_pairs.push_back({x, y});
    }
    printf("Hi there.\n");
    return 0;
}