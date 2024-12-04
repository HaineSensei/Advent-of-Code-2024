import System.IO
import Data.Maybe (mapMaybe)
import Text.Read (readMaybe)
import Control.Exception (catch, IOException)

parseLine :: String -> [Integer]
parseLine str = mapMaybe readMaybe (words str)

checkPairs :: (a -> a -> Bool) -> [a] -> Bool
checkPairs p [] = True
checkPairs p [_] = True
checkPairs p (a:b:tail) = p a b && checkPairs p (b:tail)

increasing :: [Integer] -> Bool
increasing = checkPairs (<)

decreasing :: [Integer] -> Bool
decreasing = checkPairs (>)

mono :: [Integer] -> Bool
mono xs = increasing xs || decreasing xs

noBigJump :: [Integer] -> Bool
noBigJump = checkPairs (\x y -> abs (x - y) <= 3)

safe :: [Integer] -> Bool
safe xs = mono xs && noBigJump xs

count :: (a -> Bool) -> [a] -> Int
count f = length . filter f

main :: IO ()
main = do
    contents <- readFile "../data.txt" `catch` \(e :: IOException) -> do
        putStrLn "Error reading file"
        return ""
    let ls = lines contents
        logs = map parseLine ls
    print $ count safe logs