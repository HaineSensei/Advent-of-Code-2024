open Core

module Part1 = Part1
module Part2 = Part2

let read_pairs filename =
  In_channel.read_lines filename
    |> List.map ~f:(fun line ->
        match String.split line ~on:' ' |> List.filter ~f:(String.( <> ) "") with
        | [x; y] -> (int_of_string x, int_of_string y)
        | _ -> failwith "Invalid input")