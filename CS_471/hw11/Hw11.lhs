Haskell Assignment 1:
Baptiste Saliba

> module Hw11
>   where

Part 1

Define factorial. Let Haskell infer the type of factorial.

2c. An if expression evaluates to a value whereas an if statement doesn't

> factorial n = if n == 0 then 1 else n * factorial (n - 1)

2f. factorial :: (Eq p, Num p) => p -> p   which means p is a Num which must be able to use the '==' operator

> fact1 :: Int -> Int
> fact1 n = if n == 0 then 1 else n * fact1 (n - 1)
> fact2 :: Integer -> Integer
> fact2 n = if n == 0 then 1 else n * fact2 (n - 1)

4.
factorial and fact2 work fine for all 3 tests; however fact1 returns 0 when it is given the param 500. This is because the result for fact1 is of type Int which has a restriction of 4 bytes, meaning the max size o the Int is maxBound::Int = 9,223,372,036,854,775,807 for a 64 bit machine
fact1 starts encountering issues after 20 and for 21 it goes negative because of overflow. Factorial and fact2 have no such constraint, because Int has an arbitrary precision type

5a.
*** Exception: stack overflow
This is because in the definition of factorial we take the param n and multiply it by the n-1 and then by n-2 and so on until n==0 however this never happens because n starts as negative and will continue to get more and more negative until stack overflows. If we changed the definition of factorial to be:
factorial n = if n <= 0 then 1 else n * factorial (n - 1) then we could fix this problems

5b.
This happens because the (-) function when given the parameter 2 has the type (-) 2 :: Num a => a -> a
However, when you call the function like this (-2) then it has the type (-2):: Num a => a
As you can see calling (-) 2 is a function that takes a num and returns a Num whereas (-2) is itself a Num. So when doing factorial -2 you are passing a function to factorial which is not allowed

> factP :: Integer -> Integer
> factP 0 = 1
> factP n = n * factP(n -1)

> factG x
>     | x < 0     = error "neg x"
>     | x == 0    = 1
>     | otherwise =
>       x * factG(x-1)

7.
factG can accept any type which is a Num and Ordered which means Floats, Doubles, Ints, and Integers. However, for Floats and Doubles if the decimal places have anything other than zero in them then the program will throw an error
When you type fact(-2) it is caught by the first case where x<0

> factI :: Integer -> Integer
> factI n
>     | n < 0     = error "neg n"
>     | n == 0    = 1
>     | otherwise = n * factI (n - 1)

> factE :: Integer -> Integer
> factE n
>     | n < 0     = error "neg n"
>     | n == 0    = 1
>     | otherwise = n * factE n - 1

8.
factorial runs until it overflows the stack this is because you are passing 5.1 as the param n and then multiplying it by n-1 until n == 0; however, n never gets to be 0 because n is not a whole number so the closest it gets to 0 is 0.1 then it goes to -0.9 and continues to get more and more negative until the stack overflows.
factG does the same thing as factorial except it throws an error as soon as n becomes negative so you don't get a stack overflow
factI on the other hand doesn't take a fractional (double, float) so an error is thrown saying 'No instance for (Fractional Integer)'
factE just keeps going until the stack overflows. My guess as to why this happens is because haskell interprets `n * factE n - 1` as `n * facE(n) - 1` which would never decrement n and thus n == 0 would never happen so it is just looping infinitely
Part 2

Tuple Data Type

> prodT (a,b,c) = a * b * c

1. The inferred type of prodT is prodT :: Num a => (a, a, a) -> a. This means that prodT expects a tuple of 3 Nums as it's single parameter and returns a Num. This prevents currying

Curried functions

> prodC a b c = a * b * c

2. The inferred type of prodC is prodC :: Num a => a -> a -> a -> a. This means that prodT is a function that takes 3 params of type Num and returns a Num

> prodCx :: Num a => a -> (a -> (a->a))
> prodCx a b c = a * b * c

3.
The value is 24
The type of prodCx and prodC is:
prodCx :: Num a => a -> a -> a -> a
prodC :: Num a => a -> a -> a -> a

Their types are exactly the same

> prodC1  = prodC 1
> prodC2  = prodC1 2
> prodC3  = prodC2 3
> prodC12 = prodC 1 2

4.
I believe this is legal because of the way that the functions are created in Haskell with currying. Essentially prodC1's definition is `prodC` 1 b c = 1 * b * c` where `a` defaults to 1.
After testing, prodC1 with params 2 3 results in 6 which is exactly as predicted `prodC1 2 3 = 1 * 2 * 3 = 6`. prodC2 is just `prodC 1 2 c = 1 * 2 * c` and prodC3 is just `prodC 1 2 3 = 1 * 2 * 3`
So after testing prodC2 with param 3 and prodC3 with no params they also resulted in 6 as expected.
prodC12 is the same as prodC2.

5.
No these definitions will not work because as we said when we looked at prodT's function definition, there is only one argument for prodT is a tuple of 3 Nums, so there is no way to partially evaluate a function with one argument.

6.
It is left associative as shown by the following example:

Prelude> 2/3/4
0.16666666666666666
Prelude> 2/(3/4)
2.6666666666666665
