def multiply(x,y):
   accum = 0
   for i in range (y):
       accum = accum + x
   return(accum)

def main():
    num1 = int(input("What is the first number you want to multiply"))
    num2 = int(input("What is the second number you want to multiply"))
    result = multiply(num1,num2)
    print(result)
main()
