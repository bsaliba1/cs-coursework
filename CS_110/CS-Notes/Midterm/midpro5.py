def maxVal(a,b,c):
    Max = a
    if c>a and c>b:
        Max = c
    elif a>b and a>c:
        Max = a
    else:
        Max = b
    return Max

def main():
    x = maxVal(1,2,3)
    y = maxVal(-9,-8,-7)
    z = maxVal(5,5,5)
    print(maxVal(x,y,z))

    
main()
