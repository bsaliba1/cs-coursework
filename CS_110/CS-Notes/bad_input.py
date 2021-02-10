import json


def badinput():
	num = 0
	while num==0:
		num = int(input("Please enter a number:"))
	if num != 0:
		1/num
badinput()

def exception_handeling():
	try:
		fptr = open('data.txt','r')
		x= 1/0
	except FileNotFoundError:
		fptr = open ('data.txt','w')#creates file
		print("file not found")
	except ZeroDivisionError:
		print('bad number')
	except:
		print('something else went wrong')

exception_handeling()
