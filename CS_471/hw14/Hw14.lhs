> module HW14
>   where

Part A:

1. What is the type of  (\x -> x)?
    (\x->x) :: p -> p
2. What is the value of (verify in ghci).
    a. (\x -> x) 3 ?
        3
    b. (\x -> x) (+) 5 3 ?
        8
    c. (\x -> x) (+)?
        In ghci there is no way to print the return value but essentially it returns the original function (+)
    d. What would be a descriptive name for the abstractions in 2.b?
        return original

3. What is the value of (verify in ghci).
    a. (\x -> x +x ) 3
        6
    b. What is the expression ? (E)
        x+x

4. What is the value of (verify in ghci).
    a. (\x -> 3) 6 ?
        3   
    b. What would be a descriptive name for this abstractions?
        return 3

Part B:

> hLen::(Num u, Eq t) => ([t]->u)->[t]->u
> hLen = (\f x -> if x == [] then 0 else 1 + (f(tail x)))
> myLength ls = if ls == [] then 0 else 1 + myLength (tail ls)

1. Look at hLen --
    1. Is hLen recursive?  Why or why not?
        No hLen is not recursive because it does not call itself within the function body.
    2. Is hLen a HOF (higher order function)? Why or why not?
        Yes because hLen takes a function as an argument and also returns a function as long as x is not an empty list
    3. What is the value of
        a. hLen sum [4,5,6] ?
            12
        b. hLen head [4,5,6] ?
            6

Does hLen have anything to do with sum or head?
    hLen applies sum and head to the tail of the incoming list and returns `1 + <return value>`. As long as the return type of sum and head can be incremented by 1 then there's no problem. I'm not sure what you mean by 'have anything to do with sum and head'. 

2. What is the value of
    hLen myLength [4,5,6] ?
       3
       
3. What is the relationship between hLen and myLength?
    hLen uses myLength in order to use recursion on the tail of the list.  

Part C:

> factorial :: Integral a => a -> a
> factorial n = if n ==0 then 1 else n * (factorial (n - 1))

1. Define hFact to be a lambda abstraction such that it takes a function as an argument, and returns another function, similar to hLen.  Write this so that hFact factorial = factorial. What is the type of hFact?  (Follow the model of hLen)

> hFact = (\f n -> if n == 0 then 1 else n*(f(n-1))) 

2. Apply hFact to ( ^ 2) -- What is the value of hFact (^ 2) 5?
    80

3. What is the value of hFact factorial 5? Is it the same value as factorial 5?
    They both return the value 120

Part D:

> factorial' = hFact factorial'

1. What is the type of factorial' ?
    factorial' :: Integer -> Integer

> fix f = f (fix f )

2.
a. What is the type of fix?
    fix :: (t -> t) -> t

b. What is the difference between the code below?
    > fix f = f (fix f )
        and
    > fix f = f fix f ?

    The first line takes (fix f) as the argument to f whereas the second line just takes fix as the argument for f and then uses f as the argument for (f fix). Essentially the second line is fix f = (f fix) f.

3.Combining all we have done -- What is the value of
    a. factorial 4   (definition given in part C)
        24
    b. hFact factorial 4 ( you defined in part C #2 )
        24
    c. factorial' 4 (definition given in part D #1)
        24
    d. fix hFact 4 (definition given in part D)
        24
