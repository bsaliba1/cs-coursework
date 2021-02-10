#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    for(int i = 0; i < 50; i++)
    {
        string fileName = "xinput";

        fileName = fileName + to_string(i)+".txt";

        ofstream outputFile;
        outputFile.open(fileName);

        for(int j = 0; j < 64*1024; j++)
        {
            outputFile << 'a';
        }

        outputFile.close();
    }

    return 0;
}
