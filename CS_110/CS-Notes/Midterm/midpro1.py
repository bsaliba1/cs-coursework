def maxval(a,b,c):
    max = a
    if a>b and a<c:
            max=c
    else:
        if b>c:
            max=b
        else:
            max=c
    return max
def main():
    x = maxval(1,2,3)
    y = maxval(-9,-8,-7)
    z = maxval(5,5,5)
    print(maxval(x,y,z))
main()
