#CW: READING AND WRITING
infile = open("applic.txt",'r')
text = ''
for aline in infile:
	items = aline.split()
	text= (items[1]+','+items[0]+'\n')

infile.close()
file2 = open ("newtext.txt",'w')
file2.write(text)
file2.close()

