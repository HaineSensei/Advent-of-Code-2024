#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::ifstream file("../data.txt");
    std::vector<int> data_first, data_second;
    int x, y;
    while (file >> x >> y) {
        data_first.push_back(x);
        data_second.push_back(y);
    }
    int sim_score = 0;
    for(const int& x : data_first) {
        sim_score += x*std::count(data_second.begin(), data_second.end(), x);
    }
    std::cout << sim_score << std::endl;
}