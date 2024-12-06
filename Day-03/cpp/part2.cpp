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

const std::regex mulBlock(R"(mul\((\d{1,3}),(\d{1,3})\))"),
                 doBlock(R"(do\(\))"),
                 dontBlock(R"(don't\(\))");


const std::array<std::string, 9> mulBlockSuffixes = {
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
const std::array<std::string, 5> doBlockSuffixes = {
    "do()",
    "o()",
    "()",
    ")",
    ""
};
const std::array<std::string, 8> dontBlockSuffixes = {
    "don't()",
    "on't()",
    "n't()",
    "'t()",
    "t()",
    "()",
    ")",
    ""
};

bool regex_prefix_match_mul(const std::string& str) {
    for (const std::string& suffix : mulBlockSuffixes) {
        if (std::regex_match(str + suffix, mulBlock)) {
            return true;
        }
    }
    return false;
}

bool regex_prefix_match_do(const std::string& str) {
    for (const std::string& suffix : doBlockSuffixes) {
        if (std::regex_match(str + suffix, doBlock)) {
            return true;
        }
    }
    return false;
}

bool regex_prefix_match_dont(const std::string& str) {
    for (const std::string& suffix : dontBlockSuffixes) {
        if (std::regex_match(str + suffix, dontBlock)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string data = readFile("../data.txt");
    int total = 0;
    bool enabled = true;
    std::string curr = "";
    for (char c : data) {
        curr.push_back(c);
        if (!(regex_prefix_match_mul(curr)||regex_prefix_match_do(curr)||regex_prefix_match_dont(curr))){
            curr = "";
        } else if (std::regex_match(curr,mulBlock)){
            if (enabled) {
                total += mulBlockEval(curr);
            }
            curr = "";
        } else if (std::regex_match(curr,doBlock)){
            enabled = true;
            curr = "";
        } else if (std::regex_match(curr,dontBlock)){
            enabled = false;
            curr = "";
        }
    }
    std::cout << total << std::endl;
    return 0;
}