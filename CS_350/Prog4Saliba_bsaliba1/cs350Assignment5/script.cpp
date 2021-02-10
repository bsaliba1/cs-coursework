#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    ofstream outputFile;
    outputFile.open("AutoRun.txt");

    for(int i = 0; i < 129; i++)
    {
        outputFile << "import test_files/hinput0.txt output" << i << ".txt" << endl;
        outputFile << "import test_files/xinput0.txt EdCarryTiste" << i << ".txt" << endl; 
        outputFile << "import test_files/input0.txt TisteNoCN" << i << ".txt" << endl; 
    }

    outputFile << "shutdown" << endl;
    outputFile.close();
}
