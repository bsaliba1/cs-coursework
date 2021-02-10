#include <stdio.h>
#include <stdlib.h>

int powI(int pow, int base) {
  int acc, p;
  for (acc=1,p=0; p < pow; p++) {
    acc = acc * base;
  }
  return acc;
} 
int powF(int pow, int base) {
    if (pow <= 0){
        return 1;
    }else{
        return base*powF(pow-1, base);
    }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("%s usage: [BASE] [POWER]\n", argv[0]);
    return 1;
  }
  int base = atoi(argv[1]);
  int pow = atoi(argv[2]);
  int r = powI(pow,base);
  printf("%d\n", r);
  int r2 = powF(pow,base);
  printf("%d\n", r2);
  return 0;
}
