-- part1.hs

main :: IO ()
main = do
    contents <- readFile "data.txt"
    let pairs = map ((\[x, y] -> (read x :: Int, read y :: Int)) . words) 
                   (lines contents)
    -- For testing, let's print the pairs
    print pairs