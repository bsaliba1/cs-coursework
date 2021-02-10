In order to compile this file simply use the command:
	make
To run program:
	./BestFirstSeach <inputfile.txt> <output.txt>

Note: I have left the two sets of test files that I used i1.txt and i2.txt with there corresponding output file o1.txt and o2.txt. You may use those if you want.

This program utilizes 3 main data structures:
1. Item Structure: This is used to store the information about the items that we parsed from the input. It has two data members which are the weight and price of the items.
2. Vector of Items: This is where we store all of the items that we parsed from input. We sort this list using the function "pwratio", which compares two items and returns true if item one has a lower price/weight ratio and false otherwise. This allows us to sort the list in descending ratio order. 
3. Node Structure: This structure stores various bits of data; the value at that node, weight used, estimate according to remaining items, level in the tree, and lastly a vector of all included items. This last vector is used to decide the optimal solution at the end.
