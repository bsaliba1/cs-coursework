#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <deque>
#include "Caches.cpp"

using namespace std;

int line_size = 32;

int main(int argc, char* argv[]){
    ifstream infile;
	ofstream outfile;

    vector<instr*> addresses;

	if(argc != 3){
		fprintf(stderr, "Must be two command line arguments\n");
	    exit(0);
    }else{	
		infile.open(argv[1]);
		outfile.open(argv[2]);
	}

	string line;
	if (infile.is_open()){
        while ( getline (infile,line) ){//while still has lines
            instr* temp = new instr;
            temp->ls = line[0];
            temp->addr = line.substr(line.size()-10);          
            addresses.push_back(temp);
        }
    }
    DirectMapped D1(1);
    DirectMapped D2(4);
    DirectMapped D3(16);
    DirectMapped D4(32);

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    for(int i=0;i<addresses.size();i++){
        count1 += D1.access(addresses[i]);
        count2 += D2.access(addresses[i]); 
        count3 += D3.access(addresses[i]);
        count4 += D4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;

    SetAssociative A1(2);
    SetAssociative A2(4);
    SetAssociative A3(8);
    SetAssociative A4(16);

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += A1.access(addresses[i]);
        count2 += A2.access(addresses[i]);
        count3 += A3.access(addresses[i]);
        count4 += A4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;

    FullyAssociativeLRU FA1;
    FullyAssociativeHC FA2;

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += FA1.access(addresses[i]);
        count2 += FA2.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<";"<<endl;
    outfile<<count2<<","<<addresses.size()<<";"<<endl;

    SetAssociativeNA SA1(2);
    SetAssociativeNA SA2(4);
    SetAssociativeNA SA3(8);
    SetAssociativeNA SA4(16);

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += SA1.access(addresses[i]);
        count2 += SA2.access(addresses[i]);
        count3 += SA3.access(addresses[i]);
        count4 += SA4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;

    SetAssociativePF PF1(2);
    SetAssociativePF PF2(4);
    SetAssociativePF PF3(8);
    SetAssociativePF PF4(16);

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += PF1.access(addresses[i]);
        count2 += PF2.access(addresses[i]);
        count3 += PF3.access(addresses[i]);
        count4 += PF4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;

    SetAssociativePFonMiss PFM1(2);
    SetAssociativePFonMiss PFM2(4);
    SetAssociativePFonMiss PFM3(8);
    SetAssociativePFonMiss PFM4(16);

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += PFM1.access(addresses[i]);
        count2 += PFM2.access(addresses[i]);
        count3 += PFM3.access(addresses[i]);
        count4 += PFM4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;

    SetAssociativePF2 DF1(2);
    SetAssociativePF2 DF2(4);
    SetAssociativePF2 DF3(8);
    SetAssociativePF2 DF4(16);

    /* EXTRA CREDIT HERE, UNCOMMENT TO TEST
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;

    for(int i=0; i<addresses.size(); i++){
        count1 += DF1.access(addresses[i]);
        count2 += DF2.access(addresses[i]);
        count3 += DF3.access(addresses[i]);
        count4 += DF4.access(addresses[i]);
    }

    outfile<<count1<<","<<addresses.size()<<"; ";
    outfile<<count2<<","<<addresses.size()<<"; ";
    outfile<<count3<<","<<addresses.size()<<"; ";
    outfile<<count4<<","<<addresses.size()<<";"<<endl;
    */
    return 0;
}
