recursionFn :: Int -> Int -> Int
recursionFn empty rate
    | empty >= rate = recursionFn (drinks + bottle_remain) rate + drinks
    | otherwise = 0
    where drinks = empty `div` rate
          bottle_remain = empty `mod` rate

threeArg :: Int -> Int -> Int -> Int
threeArg holding today rate = recursionFn (holding + today) rate
