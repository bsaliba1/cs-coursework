def grade():
    perc = int(input("please enter your exam percentage  "))
    if (perc>=90):
       return 'A'


    elif (perc>=80):
        return 'B'

               
    elif (perc>=70):
       return 'C'

    elif (perc>=60):
        return 'D'
    

    else:
        return 'F'
       
def isPassing():
    if (grade)== 'A' or 'B' or 'C':
        return 'You are passing'
    else:
        return "That's a failing grade"
    
def main():
    p = grade()
    q = isPassing()
    print "Your letter grade is an", p
    print (q)
main()
