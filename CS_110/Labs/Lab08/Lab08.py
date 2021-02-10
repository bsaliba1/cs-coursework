import random


def createRandomString(q):
    x = 0
    string = ""
    for i in range(q):
        x=33
        while (x >32 and x<65)or (x>90 and x<97):
            x =random.randrange(32,122)
        z = chr(x)
        string += z
    return string

def countCharacters(string):
    mat = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    lower=string.lower()
    for i in range(len(lower)):
        x = lower[i]
        y = ord(x)
        if y>96 and y<123:
            y= y-97
            mat[y]+=1
    return mat
    
def main():
    q = int(input("Please state how many characters long your random string should be   "))
    randst = createRandomString(q)
    string = input("Please input a string    ")
    mat = countCharacters(string)

