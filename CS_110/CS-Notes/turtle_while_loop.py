def outofbounds(w,t):
    lbound = -(w.window_width()/2)
    rbound = (w.window_width()/2)
    tbound = (w.window_height()/2)
    bbound = -(w.window_height)/2

    xcoor = t.xcor()
    ycoor = t.ycor()

    if(lbound <= xcoor<=rbound) and 
        return False
    elif(bbound<=ycoor<=tbound):
        return False
    else:
        return True
def main():
    donatello = turtle.Turtle()
    donatello.shape('turtle')
    donatello.speed(0)
    window = turtle.Screen()
    while(not outofbounds(donatello)):
        coin = random.randrange(2)
        if(coin==1):
            donatello.left(90)
        else:
            donatello.right(90)
    window.exitonclick()
main()

    
