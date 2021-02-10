def main():
	file_pointer = open("/Users/bsaliba1/Desktop/files.py",'w')#'w' = write mode & 'r'=read mode
	file_pointer.write('This is a test')
	file_pointer.write('This is another test')
	file_pointer.close()#this ensures that the file is saved
main()
