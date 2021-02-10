class Point:
    num = 0
    def __init__(self):
        Point.num += 1
        print("Num Points:", self.num)

def main():
    p = Point()
    q = Point()
    p.num += 1
    print("p num:", p.num)
    print("q num:", q.num)
    Point.num +=1
    print("p num:", p.num)
    print("q num:", q.num)
main()