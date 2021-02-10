#include<iostream>
#include<fstream>
#include<string>
#include "Predictors.cpp"

using namespace std;

int main(int argc, char *argv[]) {
  
  alwaysNotTaken ANT = alwaysNotTaken();
  
  alwaysTaken AT = alwaysTaken();
  
  bimodial1 B1 = bimodial1();
  bimodial2 B2 = bimodial2();

  Gshare G3 = Gshare(3);
  Gshare G4 = Gshare(4);
  Gshare G5 = Gshare(5);
  Gshare G6 = Gshare(6);
  Gshare G7 = Gshare(7);
  Gshare G8 = Gshare(8);
  Gshare G9 = Gshare(9);
  Gshare G10 = Gshare(10);
  Gshare G11 = Gshare(11);

  Tournament T1 = Tournament();

  unsigned long long addr;
  string behavior;
  string input_file = "test_input.txt";
  char* output_file;
  FILE* myfile = stdout;
  int total_branches;
  if(argc==3){
      input_file = argv[1];
      output_file = argv[2];
      myfile = fopen(output_file, "w");

  }

  // Open file for reading
  ifstream infile(input_file);

  // The following loop will read a hexadecimal number and
  // a string each time and then output them
  while(infile >> hex >> addr >> behavior) {
    ANT.check(behavior);
    AT.check(behavior);
    for(int i=1; i<8; i++){
        B1.check(i, addr, behavior);    
        B2.check(i, addr, behavior);
    }
    G3.check(addr,behavior);
    G4.check(addr,behavior);
    G5.check(addr,behavior);
    G6.check(addr,behavior);
    G7.check(addr,behavior);
    G8.check(addr,behavior);
    G9.check(addr,behavior);
    G10.check(addr,behavior);
    G11.check(addr,behavior);
    
    T1.check(addr,behavior);
  }
  total_branches = AT.total_branches;
  
  fprintf(myfile,"%d,%d\n", AT.num_correct, total_branches); 
  
  fprintf(myfile,"%d,%d\n", ANT.num_correct, total_branches); 
  
  fprintf(myfile,"%d,%d; ", B1.num_correct1, total_branches);
  fprintf(myfile,"%d,%d; ", B1.num_correct2, total_branches);
  fprintf(myfile,"%d,%d; ", B1.num_correct3, total_branches);
  fprintf(myfile,"%d,%d; ", B1.num_correct4, total_branches);
  fprintf(myfile,"%d,%d; ", B1.num_correct5, total_branches);
  fprintf(myfile,"%d,%d; ", B1.num_correct6, total_branches);
  fprintf(myfile,"%d,%d; \n", B1.num_correct7, total_branches);
  
  fprintf(myfile,"%d,%d; ", B2.num_correct1, total_branches);
  fprintf(myfile,"%d,%d; ", B2.num_correct2, total_branches);
  fprintf(myfile,"%d,%d; ", B2.num_correct3, total_branches);
  fprintf(myfile,"%d,%d; ", B2.num_correct4, total_branches);
  fprintf(myfile,"%d,%d; ", B2.num_correct5, total_branches);
  fprintf(myfile,"%d,%d; ", B2.num_correct6, total_branches);
  fprintf(myfile,"%d,%d; \n", B2.num_correct7, total_branches);
  
  fprintf(myfile,"%d,%d; ", G3.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G4.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G5.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G6.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G7.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G8.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G9.num_correct, total_branches);
  fprintf(myfile,"%d,%d; ", G10.num_correct, total_branches);
  fprintf(myfile,"%d,%d; \n", G11.num_correct, total_branches);

  fprintf(myfile,"%d , %d; \n", T1.num_correct, total_branches);


  return 0;
}
