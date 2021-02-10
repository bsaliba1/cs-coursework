#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void genDMatrix(int size, string fileName){
    ofstream testFile;
    testFile.open(fileName);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(j<size-1){
                if(j==i){
                    testFile<<0<<',';
                }else{
                    testFile<<rand()%1000<<',';
                }
            }else{
                if(j==i){
                    testFile<<0;
                }else{
                    testFile<<rand()%1000;
                }
            }
        }
        testFile<<endl;
    }
    testFile.close();
}
void genUDMatrix(int size, string fileName){
    ofstream testFile;
    testFile.open(fileName);
    int matrix[size][size];
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            if(j==i){
                matrix[i][j] = 0;
            }else{
                int x = rand()%1000;
                matrix[i][j] = x;
                matrix[j][i] = x;
            }

        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(j<size-1){
                testFile<<matrix[i][j]<<',';
            }else{
                testFile<<matrix[i][j];
            }
        }
        testFile<<endl;
    }
    testFile.close();
}
int main(){
    string Dgraph = "DgraphRand1000/test";
    string UDgraph = "UDgraphRand1000/test";
    for(int i=2; i<=30; i++){
        for(int j=1; j<=5;j++){
            string fileName = Dgraph+ to_string(i)+"v"+to_string(j)+".txt";
            string fileName2 = UDgraph+ to_string(i)+"v"+to_string(j)+".txt";
            genDMatrix(i,fileName);
            genUDMatrix(i, fileName2);
        }
    }
}
