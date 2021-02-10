#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    ofstream checkpoint;
    checkpoint.open("DRIVE/CHECKPOINT_REGION");
    char check[224];
    char zero = '0';
    for(int i=0; i<64; i++){
	    memcpy(&check[i],&zero, 1);
    }
    char null_char = '\0';
    for(int i=64; i<224; i++){
    	memcpy(&check[i], &null_char, 1);
    }
    checkpoint.write(check,224);
    checkpoint.close();

    for(int i = 0; i < 64; i++)
    {
        string fileName = "DRIVE/SEGMENT";

        fileName = fileName + to_string(i);

        ofstream outputFile;
        outputFile.open(fileName);

        for(int j = 0; j < 1024*1024; j++)
        {
            outputFile << '\0';
        }

        outputFile.close();
    }

    return 0;
}
