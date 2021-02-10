def calcEaster(year):
    a = year%19
    b = year // 100
    c = year % 100
    d = (((19*a)+b)-(b//4)-((b-((b+8)//25)+1)//3)+15)%30
    e = (32+2(b%4)+2(c//4)-d-(c%4))%7
    f = d+e-7((a+11*d+22*e)//451)+114
    month = f//31
    day = f%31 + 1
    print(month)
    print (day)


def main():
    year = int(input("Enter year when you want to know when easter is"))
    if 3000>year>1999:
        calcEaster(year)
    else:
        print "error, invalid year"
main()
    

