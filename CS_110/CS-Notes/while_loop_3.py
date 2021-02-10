def main():
    i=0
    while (i>0):
        if vault.tryCode(i):
            return i
        i+=1
    return -1

def foo():
    count = 0
    i = 0
    j = 0 #need to implement third variable to change to while loop
    while (i < 100):
        j = i
        count = i+10
        i = count +1
        i = j + 1
    return i 
