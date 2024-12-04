// part1.rs

pub fn solve(input_path: &str) -> Result<i32, Box<dyn std::error::Error>> {
    let data_pairs: Vec<(i32, i32)> = std::fs::read_to_string(input_path)?
        .lines()
        .map(|line| {
            let mut nums = line.split("   ");
            (nums.next().unwrap().parse().unwrap(), 
             nums.next().unwrap().parse().unwrap())
        })
        .collect();
    let mut data_first: Vec<i32> = data_pairs.iter()
        .map(|(x,_)| *x)
        .collect::<Vec<_>>();
    let mut data_second: Vec<i32> = data_pairs.iter()
        .map(|(_,y)| *y)
        .collect::<Vec<_>>();
    
    data_first.sort();
    data_second.sort();
    let total: i32 = (0..data_first.len())
        .map(|i: usize| data_first[i] - data_second[i])
        .map(i32::abs)
        .sum();
    // Rest of solution here
    Ok(total) // Replace with actual result
}