all:	test1 test2 minimal

test1:	test1.cpp Map.hpp
	g++ -o test1 test1.cpp
	
test2:	Map.hpp test2.cpp
	g++ -o test2 test2.cpp

minimal:	Map.hpp minimal.cpp
	g++ -o minimal minimal.cpp

clean:
	rm test1 test2 minimal my_test
