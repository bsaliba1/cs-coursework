> module HW12_Part1
>   where

> ordFunc:: Ord a => a-> Bool
> ordFunc a = True

> data Point a = Pt a a deriving (Show, Eq)
> inside r (Pt x y) = if x<r && y<r then True else False 

> test:: Ord a => a->Bool
> test a = True
