import random
def main():
    b = random.randrange(1,10)
    for i in range(3):
        a = int(input("Please guess the number I'm thinking of between 1 and 10  "))
        if a > b:
            print("your guess is too high")

        if a<b:
            print("Your guess is too low")

        if(a==b):
            print("You got it!!!")
            break
    
main()
