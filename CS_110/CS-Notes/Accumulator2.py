def square(num):
    accum = 0
    for i in range(num):
        accum = accum +num
    return accum

def main():
    toSquare = 10
    result = square(toSquare)
    print(result)

main()
    
