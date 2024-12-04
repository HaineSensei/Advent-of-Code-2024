# Day 1 details
I started out with my most familiar language — Python — and tried to implement similar things in other languages. The Python files I wrote on my own, the other implementations I had help from claude.ai details to follow.

## C++
**COMPLETE**

These files are to be compiled with `clang++ partx.cpp -o partx` or `g++ -std=c++17 partx.cpp -o partx` (I set up an alias for clang as mentioned later in this section), and then run with `.partx` all run from in the cpp folder

I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me
```
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
```
This uses specifically more modern syntax, so I had to include `alias clang++='clang++ -std=c++17'` in my shell config file. In the end, my final version did not feature these same syntax features, however it does use a C++11 extension for a loop.

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

## Haskell
This project is to be run with `ghc haskell/partx.hs` for part x followed by `./haskell/partx`.

I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me
```
main :: IO ()
main = do
    contents <- readFile "../data.txt"
    let pairs = map ((\[x, y] -> (read x :: Int, read y :: Int)) . words) 
                   (lines contents)
    -- For testing, let's print the pairs
    print pairs
```

## OCaml
This project should be run with `dune exec bin/main.exe` after running `dune build` both from within the `ocaml` directory. I needed to install dune via `opam install core dune` after having run `eval $(opam env)`. 

This took ages to set up to work... The basic files main.ml and lib.ml were entirely produced by Claude. Claude also helped me set up the dune environment to use the Core library for it, which was a lot of trouble considering that the final files part1.ml and part2.ml will likely not use that library at all. 

## Idris
This project should be compiled with `idris2 part1.idr -o part1` from in the idris folder, and then run with `./build/exec/part1` again from in the idris folder.

I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me
```
import System.File
import Data.String

parseLine : String -> Maybe (Integer, Integer)
parseLine str = do
    let words = words str  -- Split on whitespace
    case words of
        [x, y] => do
            numX <- parseInteger x
            numY <- parseInteger y
            Just (numX, numY)
        _ => Nothing

main : IO ()
main = do
    Right contents <- readFile "../data.txt"
        | Left err => putStrLn "Error reading file"
    let lines = lines contents
    let pairs = mapMaybe parseLine lines  -- mapMaybe filters out the Nothings
    printLn pairs  -- To verify what we got
```

## TypeScript
**COMPLETE**

To run here, first run `npx tsc` to compile the TypeScript to JavaScript, then run `node src/part1.js` both from inside the typescript directory.

I started out by asking Claude for a way to import the file and split it in the same manner as the Python file, which quickly got me
```
import * as fs from 'fs';

const data: [number, number][] = fs.readFileSync('../data.txt', 'utf8')
    .trim()
    .split('\n')
    .map(line => {
        const nums = line.split('   ').filter(s => s.length > 0).map(Number);
        return [nums[0], nums[1]] as [number, number];
    });

console.log(data);
```