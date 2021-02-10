#include <string.h>
#include <stdio.h>
int main(int argc, char* argv[]){
    double num = 11.0111111111;
    char arr[200]; 
    sprintf(arr, "%2.13f", num);
    int end=1;
    int i=0;
    while(end!=0x00){
        printf("%c\n and size of arr %lu",arr[i],sizeof(arr));
        i++;
        end=arr[i];
    }
}

