#will print out 11

def main():
    mystri='1'+'1"
    print(mystri)
main()

#will print "This Sunday Sunday Sunday"

def foo():
    mystr='This' + 'Sunday'*3
    print(mystr)

#can replace Sunday with monday
    
def foo():
    mystr='This' + 'Sunday'*3
    print(mystr.replace('Su','Mo')

#should print jello

def Jello():
    mystr='Hello'
    otherstr = 'J'+mystr[1:5]#slices string after 'H', [:4] would slice the 'o' off
    print(otherstr)

#QUICK NOTE:
#In a boolean a string is considered greater than another if the first letter
#in the first word is later in the alphabet

#CW#1
          
#parta
def CW1():
    nums - ""
    for i in range (1,101):
          if (i==100):
              nums += str(i)
          else:
              nums+=str(i)+","
    print(nums)
          
#partb
    bing = 'Binghamton'
    print(bing[:3])
    print(bing[4:6])+bing[7])
    print9bing[0]+bing[-2]+bing[5]+bing[-3])
    
#partc
    results='average: 0.8745'
    i = results.find(':')
    val = float(result[i+1:].strip())
    print(val)
main()


#Accumulator with Strings
def acc():
    axiom='A'
    rule= 'ZA'

    newAxiom = ""
    for c in axiom:
        if (c=='A'):
            newAxiom+='ZA'
        elif(c=='Z'):
            newAxiom+='ZAY'
        else:
            newAxiom+=c
        axiom = newAxiom
        return axiom
          
