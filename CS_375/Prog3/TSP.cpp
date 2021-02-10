#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "TSPBruteForce.cpp"
#include "TSPBestFirstSearch.cpp"

/*
 * 2d matrix representation of graph 
 */
class Graph {
    public:
        vector< vector<int> > matrix; // [i, j] is the distance between node[i] and node[j]

        Graph(int V) {
            matrix.resize(V, vector<int>(V, -1)); // initialize every entry -1
        }
};
//Run tests
void test(ifstream &infile,ofstream &outfile){    

    int V=0;
    vector<string> lines;

    string line;
    if (infile.is_open()){
        while ( getline (infile,line) ){ 
            V++;
            lines.push_back(line);
        }
        infile.close();
    }

    Graph graph(V); // create graph 

    for(int i=0; i<lines.size(); i++){
        string line = lines[i];
        stringstream ss(line);

        int j = 0;
        int v;
        while(ss >> v) {
            graph.matrix[i][j] = v;
            if (ss.peek() == ',') ss.ignore();
            j++;
        }
    }

    // ===================================================
    // Test Brute Force Algorithm
    // ===================================================
    cout << "Starting Brute Force Algorithm..." << endl;
    //    clock_t start, end;
    //    start = clock(); 
    //
    cout << "   Minimum Cost: " << tspBruteForce(graph.matrix, graph.matrix.size())<<endl;
    //    end = clock(); 
    //    double runtime1 = (double) (end - start) / (double) (CLOCKS_PER_SEC);
    //    //outfile << "   Runtime:  " << runtime1 << "s" << endl;
    //    outfile<<","<<runtime1;

    // ===================================================
    // Test Best-First Search Branch and Bound Algorithm
    // ===================================================
    cout << "Starting Best-First Search Branch and Bound Algorithm..." << endl;
    //clock_t start2, end2;
    //start2 = clock();
    cout  << "   Minimum Cost: " << tspBestFirstSearch(graph.matrix, graph.matrix.size())<<endl;
    //end2 = clock();
    //double runtime2 = (double) (end2 - start2) / (double) (CLOCKS_PER_SEC);
    //outfile << "   Runtime:  " << runtime2 << "s" << endl;
    //outfile<<","<<runtime2<<endl;
}

int main(int argc, char* argv[]){
    string inClassTest = "inClassTest.txt";
    ifstream input;
    input.open(inClassTest);
    ofstream dummy("output.txt");
    test(input,dummy);
    //string randTestOut = "test_cases/DgraphRand1000out/test"; 
    //ofstream outfile;
    //outfile.open(randTestOut);
    //for(int i=2; i<16; i++){
    //    for(int j=1; j<5; j++){
    //        string randTestIn = "test_cases/DgraphRand1000/test"+to_string(i)+"v"+to_string(j)+".txt";
    //        ifstream infile;
    //        infile.open(randTestIn);
    //        test(infile,outfile);
    //        infile.close();
    //    }
    //}
    // outfile.close();
    // randTestOut = "test_cases/UDgraphRand10out/test"; 
    // outfile.open(randTestOut);
    // for(int i=2; i<16; i++){
    //     for(int j=1; j<5; j++){
    //         string randTestIn = "test_cases/UDgraphRand10/test"+to_string(i)+"v"+to_string(j)+".txt";
    //         ifstream infile;
    //         infile.open(randTestIn);
    //         test(infile,outfile);
    //         infile.close();
    //     }
    // }
    // outfile.close();
    // randTestOut = "test_cases/DgraphRand10out/test"; 
    // outfile.open(randTestOut);
    // for(int i=2; i<16; i++){
    //     for(int j=1; j<5; j++){
    //         string randTestIn = "test_cases/DgraphRand10/test"+to_string(i)+"v"+to_string(j)+".txt";
    //         ifstream infile;
    //         infile.open(randTestIn);
    //         test(infile,outfile);
    //         infile.close();
    //     }
    // }
    // outfile.close();
    // randTestOut = "test_cases/DgraphRand100out/test"; 
    // outfile.open(randTestOut);
    // for(int i=2; i<16; i++){
    //     for(int j=1; j<5; j++){
    //         string randTestIn = "test_cases/DgraphRand100/test"+to_string(i)+"v"+to_string(j)+".txt";
    //         ifstream infile;
    //         infile.open(randTestIn);
    //         test(infile,outfile);
    //         infile.close();
    //     }
    // }
    // outfile.close();
    // randTestOut = "test_cases/AllSameout/test"; 
    // outfile.open(randTestOut);
    // for(int i=2; i<16; i++){
    //     for(int j=1; j<5; j++){
    //         string randTestIn = "test_cases/AllSame/test"+to_string(i)+"v"+to_string(j)+".txt";
    //         ifstream infile;
    //         infile.open(randTestIn);
    //         test(infile,outfile);
    //         infile.close();
    //     }
    // }
    return 0;
}
