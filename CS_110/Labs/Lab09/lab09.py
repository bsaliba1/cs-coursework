import random

   
def submatrix():
    alph = [chr(i) for i in range(32,127)]
    dicti= {}
    for i in range(32,127):
        y = random.choice(alph)
        alph.remove(y)
        dicti[chr(i)]= y

    return dicti

def encrypt(text, dicti):
    xx= ""
    for i in text:
        if ord(i) in range(32,127):
            y = dicti[i] 
            xx += y
    return xx    
      

def main():
    dicti = submatrix()
    print (dicti)
    text = input( "Please input a string to be encrypted: ")
    q = encrypt(text,dicti)
    print(q)
    while True:
        ans = input("would you like to continue encrypting? Enter any key besides q if yes.\n")
        if ans == "q":
            print("Thanks for using this encryptor")
            break
        else:
            q = encrypt(ans,dicti)
            print(q)
main()
