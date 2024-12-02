// main.rs
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