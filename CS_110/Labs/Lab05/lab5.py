import turtle
import math
import random
import time



def drawPolygon(turt1, sz, num_sides):
    for i in range(num_sides):
        turt1.forward(sz)
        turt1.left(360/num_sides)

def drawCircle(turt1,radius):
   num_sides = 360
   sz = (2*math.pi*radius)/360
   drawPolygon(turt1,sz,num_sides)

def setUpWindow(wn): #Adjust wn size
    wn.setworldcoordinates(-2,-2,2,2)

def setUpAxis(turt1): #Set up the axis
    turt1.goto(0,-1)
    turt1.goto(0,1)
    turt1.up()
    turt1.goto(-1,1)
    turt1.goto(-1,0)
    turt1.down()
    turt1.goto(1,0)
    turt1.up()
    turt1.goto(0,-1)
    turt1.down()

def throwDarts(turt2, num_darts):
    a=0
    for i in range(num_darts):
        x = random.uniform(-1,1)
        y = random.uniform(-1,1)
        turt2.up()
        turt2.goto(x,y)
        dist = turt2.distance(0,0)
        if (dist<=1):
            turt2.pencolor("Green")
            a = a+1
        else:
            turt2.pencolor("Red")
        turt2.dot()
    return a

def piapproximation(a):
    ratio= a/5000 #find ratio of darts in circle vs. darts out
    print("ratio is",ratio)#should have same ratio as pi/4
    pi = ratio*4
    return pi
def percenterror(pi):
    actual_pi= math.pi
    percerr= abs(100* ((actual_pi - pi) /actual_pi))
    return percerr
    
def main():
    wn = turtle.Screen()
    turt1 = turtle.Turtle()
    turt2 = turtle.Turtle()
    wn.tracer(20,0)
    start_time = time.time()
    setUpWindow(wn)
    turt2.hideturtle()
    setUpAxis(turt1)
    drawCircle(turt1, 1)#Set up circle of board
    turt1.back(1)
    drawPolygon(turt1,2,4)#Set up square
    turt1.hideturtle()
    num_darts=5000
    wn.tracer(300,0)
    a=throwDarts(turt2,num_darts)#throw darts
    pi = piapproximation(a)
    print('estimation of pi is', pi)

    #percent error calculation
    
    percerr= percenterror(pi)
    print("The percent error is ", percerr, "%")
    
    #This elapsed time is not representative of the codes performance because
    #the timing is not really what we are trying to measure but rather how close
    #our estimated value of pi is to the actual value of pi
    #above I have included the percent error, as I believe that is truly
    #indicative of the codes performance
    
    elapsed_time = time.time() - start_time
    print('time elapsed is', elapsed_time, 'seconds')

    wn.exitonclick()   
main()
