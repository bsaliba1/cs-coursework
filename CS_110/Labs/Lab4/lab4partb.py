# -*- coding: utf-8 -*-
import math
import turtle

fred = turtle.Turtle()
wn = turtle.Screen()
pi = 3.141592653589793238462

def drawsine(fred):
    for i in range(0,361):
        y = sin(i)
        fred.goto(radians(i),y)

def drawCosineCurve(fred):
    fred.up()
    for i in range(0,90):
        y = sin(i)
        fred.goto(radians(i)-(pi/2),y)
    fred.down()
    for i in range(90,410):
        y = sin(i)
        fred.goto(radians(i)-(pi/2),y)

def radians(x):
    q = int(pi)
    return((x*q/180))

def sin(x):
    y = (radians(x)) - ((radians(x)**3)/factorial(3)) + ((radians(x)**5)/factorial(5)) - ((radians(x)**7)/factorial(7)) + ((radians(x)**9)/factorial(9)) - ((radians(x)**11)/factorial(11)) + ((radians(x)**13)/factorial(13)) - ((radians(x)**15)/factorial(15)) + ((radians(x)**17)/factorial(17)) + ((radians(x)**19)/factorial(19)) - ((radians(x)**21)/factorial(21))+((radians(x)**23)/factorial(23)) - ((radians(x)**25)/factorial(25)) + ((radians(x)**27)/factorial(27)) - ((radians(x)**29)/factorial(29)) + ((radians(x)**31)/factorial(31)) - ((radians(x)**33)/factorial(33)) + ((radians(x)**35)/factorial(35)) - ((radians(x)**37)/factorial(37)) + ((radians(x)**39)/factorial(39))
    return(y)
           
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
                

def setUpWindow():
    wn.setworldcoordinates(-(2*math.pi),-1,(2*math.pi),1)

def setUpTurtle():
    fred.shape("turtle")
    fred.color('blue')
    fred.goto(2*math.pi,0)
    fred.goto(-(2*math.pi),0)
    fred.goto(0,0)
    fred.goto(0,1)
    fred.goto(0,-1)
    fred.goto(0,0)
    
def main():
    setUpWindow()
    setUpTurtle()
    drawsine(fred)
    fred.up()
    fred.goto(-pi/2,0)
    fred.down()
    drawCosineCurve(fred)
    wn.exitonclick()
main()
