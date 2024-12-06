#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <regex>
#include <iostream>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int mulBlockEval(const std::string& str) {
    size_t comma_pos(str.find(',')), bracket_pos(str.find(')'));
    size_t first_num_length(comma_pos-4), second_num_length(bracket_pos-comma_pos-1);
    std::string str_num1(str.substr(4,first_num_length)), str_num2(str.substr(comma_pos+1,second_num_length));
    int num1(std::stoi(str_num1)),num2(std::stoi(str_num2));
    return num1 * num2;
}

const std::regex mulBlock(R"(^mul\((\d{1,3}),(\d{1,3})\))");

const std::array<std::string, 9> suffixes = {
    "mul(1,1)",
    "ul(1,1)",
    "l(1,1)",
    "(1,1)",
    "1,1)",
    ",1)",
    "1)",
    ")",
    ""
};

bool regex_prefix_match(const std::string& str, const std::regex& pattern) {
    for (const std::string& suffix : suffixes) {
        if (std::regex_match(str + suffix, pattern)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string data = readFile("../data.txt");
    int total = 0;
    std::string curr = "";
    for (char c : data) {
        curr.push_back(c);
        if (!regex_prefix_match(curr,mulBlock)){
            curr = "";
        } else if (std::regex_match(curr,mulBlock)){
            total += mulBlockEval(curr);
            curr = "";
        }
    }
    std::cout << total << std::endl;
    return 0;
}