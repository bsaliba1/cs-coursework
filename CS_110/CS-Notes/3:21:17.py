def main():
    kilometers=[20,10,5,30]
    miles_list=[]
    for i in kilometers:
        if (i*0.621371>5):
            miles_list.append(i*0.621371)

    miles_list = [i*0.621371 for i in kilometers]
    #miles_list=[expression for item in sequence (optional) if condition]
main()




def optimized():
sentence = "the quick brown fox jumps over the lazy dog"
words = sentence.split()
word_lengths=[]
word_lengths = [len(word)for word in words if word !="the"]

numbers = [34.6,-203.4,44.9,68.3,-12.2,44.6,12.7]
newlist[]
for x in numbers:
    if x>0:
        newlist.append(int(x))
newlist[int(x) for x in numbers if x>0]




def original():
sentence = "the quick brown fox jumps over the lazy dog"
words = sentence.split()
word_lengths=[]
#some other stuff was here as well

numbers = [34.6,-203.4,44.9,68.3,-12.2,44.6,12.7]
newlist[]
for x in numbers:
    if x>0:
        newlist.append(int(x))



def newmain():
    matrix = [ list(range(5) for i in range(5)]
    matrix [2][1]=5
    for i in range(n):
        for j in range(m):
            print (matrix[i][j]=list range(5)))

newmain()
               
def position():
    X
    X--> F[-X]+[X]
    F--> FF

### Assignment_Two():
    
    import turtle

def applyRules(char):
    return_str = ""
    if(char == "X"):
        return_str = "X+YF"
    elif(char == "Y"):
        return_str = "FX-Y"
    else:
        return_str = char
    return return_str

def process(old_string):
    new_str = ''
    for c in old_string:
        new_str += applyRules(c)
    return new_str

def createLSystem(iterations, axiom):
    start_string = axiom
    end_string = ""
    for i in range(iterations):
        end_string = process(start_string)
        start_string = end_string
    return end_string

def drawLSystem(string, dist, deg):
    snappy = turtle.Turtle()
    snappy.speed(0)
    sn = turtle.Screen()

    for instruction in string:
        if (instruction == 'F'):
            snappy.forward(dist)
        elif (instruction == '-'):
            snappy.right(deg)
        elif (instruction == '+'):
            snappy.left(deg)

    sn.exitonclick()

def main():
    iters = int(input("Number of iterations: "))
    final_str = createLSystem(iters, "FX")
    distance = int(input("How far forward?: "))
    degree = int(input("How much to turn?: "))
    drawLSystem(final_str, distance, degree)
main()
    

