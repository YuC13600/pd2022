recursionFn :: Int -> Int -> Int
recursionFn empty rate = if empty >= rate
                        then recursionFn (empty `mod` rate + empty `div` rate) rate + empty `div` rate
                        else 0

threeArg :: Int -> Int -> Int -> Int
threeArg holding today rate = recursionFn (holding + today) rate
