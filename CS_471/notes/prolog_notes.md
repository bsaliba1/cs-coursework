## Prolog Notes
### Usage:
1. Starting prolog: `$ swipl`
2. Loading Program: `$ swipl -s test.pro`
3. Load and get output: 
```
$ swipl
?- ['test.pro'].
```
### Language Details
- Clauses
    - Fact (unconditional)
        - ex) `?- woman(jody)`
        - ex2) `?- party.`
    - Rule (conditional)
        - ex) `?- hasLongHair(jody):- woman(jody)`
        - split up as head (left side of the if) and body (right side of the if)
        - head is deducted based on previous facts (**modus ponnens**)

- Iterate through list of arguments
    ```
    ?- predicate(F)
    F= x
    F= y
    F= z
    ```


