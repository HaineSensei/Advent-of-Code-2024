# Day 1 details
I started out with my most familiar language — Python — and tried to implement similar things in other languages. The Python files I wrote on my own, the other implementations I had help from claude.ai details to follow.

## Overview
Each file is designed to be run from the Day-1 directory unless otherwise specified (eg. Rust — see below).

## C++
These files are to be run with `clang++ cpp/part-x.cpp -o cpp/out-x` or `g++ -std=c++17 cpp/part-x.cpp -o cpp/out-x` (I set up an alias for clang as mentioned later in this section).

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
This uses specifically more modern syntax, so I had to include `alias clang++='clang++ -std=c++17'` in my shell config file.

## Rust
This project is to be run with `cargo run` from the `rust` directory.

I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me a `part1.rs` and `part2.rs` with
```
pub fn solve(input_path: &str) -> Result<i32, Box<dyn std::error::Error>> {
    let data_pairs: Vec<(i32, i32)> = std::fs::read_to_string(input_path)?
        .lines()
        .map(|line| {
            let mut nums = line.split("   ");
            (nums.next().unwrap().parse().unwrap(), 
             nums.next().unwrap().parse().unwrap())
        })
        .collect();
    
    // Rest of solution here
    Ok(0) // Replace with actual result
}
```
and a `main.rs` with
```
mod part1;
mod part2;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Run part 1
    let part1_result = part1::solve("../data.txt")?;
    println!("Part 1: {}", part1_result);

    // Run part 2
    let part2_result = part2::solve("../data.txt")?;
    println!("Part 2: {}", part2_result);

    Ok(())
}
```
