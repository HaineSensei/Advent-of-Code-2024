import System.File
import Data.String

parseLine : String -> List Integer
parseLine str = let str_words = words str in -- Split on whitespace
    mapMaybe parseInteger str_words 

checkPairs : (a -> a -> Bool) -> List a -> Bool
checkPairs p xs = case xs of
    [] => True
    [_] => True
    a::b::tail => p a b && checkPairs p (b::tail)

increasing : List Integer -> Bool
increasing = checkPairs (<)

decreasing : List Integer -> Bool
decreasing = checkPairs (>)

mono : List Integer -> Bool
mono xs = increasing xs || decreasing xs

noBigJump : List Integer -> Bool
noBigJump = checkPairs (\x, y => abs (x - y) <= 3)

safe : List Integer -> Bool
safe xs = mono xs && noBigJump xs

removals : List a -> List (List a)
removals [] = [[]]
removals (x::xs) = (xs) :: map (\ys => x::ys) (removals xs)

dampened : (List a -> Bool) -> List a -> Bool
dampened f xs = any f (removals xs)

dampened_safe : List Integer -> Bool
dampened_safe = dampened safe


count : (Integer -> Bool) -> List Integer -> Nat
count f xs = length (filter f xs)

main : IO ()
main = do
    Right contents <- readFile "../data.txt"
        | Left err => putStrLn "Error reading file"
    let lines = lines contents
    let logs = map parseLine lines
    printLn $ count dampened_safe logs