import Lab08

def main():
    y = Lab08.countCharacters('Banana')
    print(y)
    yy = Lab08.countCharacters('I nip in; pin Pippin')
    print(yy)
    yyy = Lab08.countCharacters("Blowzy night-frumps vex'd Jack Q")
    print(yyy)
    q = input("Please state how many characters long your random string should be   ")
    x = Lab08.createRandomString(int(q))
    print(x)
    xx = Lab08.countCharacters(x)
    print(xx)

main()
