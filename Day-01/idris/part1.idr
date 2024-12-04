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