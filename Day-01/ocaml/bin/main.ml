open Core
open Lib

let () = 
  let pairs = Lib.read_pairs "../data.txt" in
  printf "Part 1: %d\n" (Part1.solve pairs);
  printf "Part 2: %d\n" (Part2.solve pairs)