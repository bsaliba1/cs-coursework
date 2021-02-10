all:	makeFiles.exe main.exe 

main.exe:	main.cpp
	g++ -o main.exe main.cpp

makeFiles.exe:	makeFiles.cpp
	g++ -o makeFiles.exe makeFiles.cpp

files:
	mkdir DRIVE
	touch DRIVE/FILE_NAME_MAPPER
	./makeFiles.exe

clean:
	rm makeFiles.exe main.exe
	rm -rf DRIVE
