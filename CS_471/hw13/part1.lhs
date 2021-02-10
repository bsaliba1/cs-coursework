> module HW13_p1
> where

> setG lst
>   | (length lst) == 0 = []
>   | otherwise = head lst * head lst : setG (tail lst)

> setP [] = []
> setP (h:t) = h*h : setP t

> setM [] = []
> setM (h:t) = (^ 2) h : map (^ 2) t

> prodPRLHOF :: (Num t1, Foldable t) => t t1 -> [t1]
> prodPRLHOF = foldr f []
>   where
>   f y [] = [y]
>   f y (x:xs) = [y*x]++(f y xs) 
