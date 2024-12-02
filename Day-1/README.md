## Day 1 details
I started out with my most familiar language — Python — and tried to implement similar things in other languages. The Python files I wrote on my own, the other implementations I had help from claude.ai details to follow.

# C++
I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me
```
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
    return 0;
}
```