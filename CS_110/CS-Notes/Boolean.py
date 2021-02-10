def main():
    num  =int(input("Please enter a number   "))
    if(num!=0):
        if (num>0):
            result = 20/num
            print(result)
        else:
            if (num<0):
                result = -20/num
                print(result)
    else:
        print("I told you not to enter 0")
              
main()
