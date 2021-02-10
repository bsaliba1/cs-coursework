> module Test
> where

> mysB :: a -> b -> a
> uncurry :: (a -> b -> c) -> (a, b) -> c
> mysB a b = a
> uncurry f (a,b) =  f a b

> data Tree a = Leaf | Branch a (Tree a) (Tree a)

> instance (Eq a) => Eq (Tree a) where 
>   Leaf         == Leaf          =  True
>   (Branch a l1 r1) == (Branch b l2 r2)  =  a == b && (l1==l2) && (r1==r2)
>   _              == _               =  False

> instance Functor Tree where
>    fmap f (Branch x left right) = Branch (f x) (fmap f left) (fmap f right)

> mapTree f Leaf = Leaf
> mapTree f (Branch v left right) = (Branch (f v) (mapTree f left) (mapTree f right))


> collatz n
>   |even n = div n 2
>   |otherwise = (3*n +1)

> collatzSeqM n = seq
>   where
>     seq = n: map collatz seq

> collatzSeqL n = seq
>   where
>     seq = n:[collatz x| x <- seq] 

> reverse::(Foldable f, Num a) => f a -> [a]
> reverse = foldr op []
>   where
>       op el acc = acc ++ [el] 

> mymap f lst = foldr (\ el acc -> f el:acc) [] lst

> big c [] = []
> big c (x:xs) = if x>c then x:(big c xs) else (big c xs)

> bigHOF c lst = foldr op [] lst
>   where
>       op el acc = if el>c then el:acc else acc

> bigF c lst = filter (\x -> x>c) lst

> mys f lst 
>     | null lst = f 3
>     | otherwise = mys (\x -> f (x - 5)) (init lst)

> hStep f b e
>      | (e==0) = 1
>      | otherwise = b * (f b (e-1))

> pow b e
>    | (e==0) = 1
>    | otherwise = b * (pow b (e-1))

> fix f = f (fix f)

> gtwo :: Num a => (a -> a) -> a
> gtwo f = f 7

> iterateC :: (a -> a) -> a -> [a] 
> iterateC f x = iterateSeq
>   where
>       iterateSeq = x: iterateC f (f x)

> maxL :: Ord a => [a] ->  a
> maxL (x:xs)  = maxHelper x (x:xs)
> maxHelper curr lst 
>   | null lst = curr
>   | otherwise = if head lst > curr then maxHelper (head lst) (tail lst) else maxHelper curr (tail lst)

> maxHOF :: Ord a => [a] ->  a
> maxHOF lst = foldr1 max lst
