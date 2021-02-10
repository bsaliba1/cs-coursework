#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void genDMatrix(int size, string fileName){
    ofstream testFile;
    int x = rand()%100;
    testFile.open(fileName);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(j<size-1){
                if(j==i){
                    testFile<<0<<',';
                }else{
                    //testFile<<rand()%100<<',';
                    testFile<<x<<',';
                }
            }else{
                if(j==i){
                    testFile<<0;
                }else{
//                    testFile<<rand()%100;
                    testFile<<x;
                }
            }
        }
        testFile<<endl;
    }
    testFile.close();
}
void genUDMatrix(int size, string fileName){
    ofstream testFile;
    int y = rand()%100;
    testFile.open(fileName);
    int matrix[size][size];
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            if(j==i){
                matrix[i][j] = 0;
            }else{
              //  int x = rand()%100;
              //  matrix[i][j] = x;
              //  matrix[j][i] = x;
              matrix[i][j]=y;
              matrix[j][i]=y;
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
    //string Dgraph = "DgraphRand100/test";
    //string UDgraph = "UDgraphRand100/test";
    string AllSame = "AllSame/test";
    for(int i=2; i<=12; i++){
        for(int j=1; j<=5;j++){
<<<<<<< HEAD
            //string fileName = Dgraph+ to_string(i)+"v"+to_string(j)+".txt";
            //string fileName2 = UDgraph+ to_string(i)+"v"+to_string(j)+".txt";
            string allName = AllSame + to_string(i)+"v"+to_string(j)+".txt";
            genDMatrix(i,allName);
            //genDMatrix(i,fileName);
            //genUDMatrix(i, fileName2);
=======
            string fileName = Dgraph+ to_string(i)+"-"+to_string(j)+".txt";
            string fileName2 = UDgraph+ to_string(i)+"-"+to_string(j)+".txt";
            genDMatrix(i,fileName);
            genUDMatrix(i, fileName2);
>>>>>>> b8a441d5476622df68e42795ffd318fa6abaf94f
        }
    }
}
