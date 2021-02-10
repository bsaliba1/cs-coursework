import turtle
import random
import os 

def main():
    window = turtle.Screen()
    window.bgcolor('lightblue')
    michelangelo = turtle.Turtle()
    leonardo = turtle.Turtle()
    michelangelo.color('orange')
    leonardo.color('blue')
    michelangelo.shape('turtle')
    leonardo.shape('turtle')
    michelangelo.up()        

    leonardo.up()
    michelangelo.goto(-100,20)
    leonardo.goto(-100,-20)

    #first race
    w = random.randrange(1,301)
    x = random.randrange(1,301)

    michelangelo.forward(w)
    leonardo.forward(x)

    michelangelo.goto(-100,20)
    leonardo.goto(-100,-20)

    #second race
    i = 0
    while i<10:
        y = random.randrange(1,31)
        z = random.randrange(1,31)

        michelangelo.forward(y)
        leonardo.forward(z)
        i = i+1
        
    leonardo.goto(-100,-20)

    #equilateral triangle
    leonardo.down()
    leonardo.left(120)
    leonardo.forward(100)
    leonardo.left(120)
    leonardo.forward(100)
    leonardo.left(120)
    leonardo.forward(100)

    #hexagon
    leonardo.left(60)
    leonardo.forward(100)
    leonardo.left(60)
    leonardo.forward(100)
    leonardo.left(60)
    leonardo.forward(100)
    leonardo.left(60)
    leonardo.forward(100)
    leonardo.left(60)
    leonardo.forward(100)
    leonardo.left(60)
    leonardo.forward(100)

    #square
    i=0
    while i<4:
        leonardo.left(90)
        leonardo.forward(100)
        i = i+1

    #octagon
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    leonardo.left(45)
    leonardo.forward(100)
    
    #print out man page
    os.system('man man')
    os.system("man ls")
    os.system('man pwd')
    os.system("man rm")
    os.system('man cd')
    os.system("man mv")
    os.system('man cp')
    os.system("man python3")

    window.exitonclick()
main()


