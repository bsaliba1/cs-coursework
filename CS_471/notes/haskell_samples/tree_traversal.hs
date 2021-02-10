module ClassS20 where

data Tree a = Leaf a| Branch (Tree a) (Tree a)
treeSize::Tree a -> Integer
treeSize (Leaf x) = 1
treeSize (Branch lt rt) = treeSize lt + treeSize rt

tree = Branch (Leaf 3) (Branch (Leaf 6) (Leaf 9))
