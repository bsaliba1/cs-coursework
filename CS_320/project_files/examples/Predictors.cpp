#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class alwaysTaken{
    public:
        int num_correct;
        int total_branches;
        alwaysTaken(){
            num_correct =0;
            total_branches=0;
        }
        void check(string behavior){
            total_branches++;
            if(behavior=="T"){
                num_correct++;
            }
        }
};

class alwaysNotTaken{ 
    public:
        int num_correct;
        int total_branches;
        alwaysNotTaken(){
            num_correct =0;
            total_branches=0;
        }
        void check(string behavior){
            total_branches++;
            if(behavior =="NT"){
                num_correct++;
            }
        }
};

class bimodial2{
    public:
        int one[16] = {0};
        int two[32] = {0};
        int three[128] = {0};
        int four[256] = {0};
        int five[512] = {0};
        int six[1024] = {0};
        int seven[2048] = {0};

        int num_correct1;
        int num_correct2;
        int num_correct3;
        int num_correct4;
        int num_correct5;
        int num_correct6;
        int num_correct7;

        bimodial2(){
            num_correct1=0;
            num_correct2=0;
            num_correct3=0;
            num_correct4=0;
            num_correct5=0;
            num_correct6=0;
            num_correct7=0;
            for(int i=0;i<16;i++){
                one[i]=1;
            }
            for(int i=0;i<32;i++){
                two[i]=1;
            }
            for(int i=0;i<128;i++){
                three[i]=1;
            }
            for(int i=0;i<256;i++){
                four[i]=1;
            }
            for(int i=0;i<512;i++){
                five[i]=1;
            }
            for(int i=0;i<1024;i++){
                six[i]=1;
            }
            for(int i=0;i<2048;i++){
                seven[i]=1;
            }
        }
        void increment(int arr[], string behavior, int index, int* num_correct){
            if(arr[index]<2 and behavior == "NT"){
                *num_correct= (*num_correct)+1;
            }else if (arr[index]>=2 and behavior == "T"){
                *num_correct= (*num_correct)+1;
            }else{

            }

            if(arr[index]>0 and behavior == "NT"){
                arr[index] = arr[index]-1;
            }else if(arr[index]<3 and behavior == "T"){
                arr[index] = arr[index]+1;
            }else{

            }

        }    
        void check(int option, unsigned long long addr, string behavior){
            int index;
            switch(option){
                case 1:                
                    index = addr%16;//possible problems here
                    increment(one, behavior, index,&num_correct1);
                    break;            
                case 2:
                    index = addr%32;//possible problems here
                    increment(two, behavior, index, &num_correct2);
                    break;
                case 3:
                    index = addr%128;//possible problems here
                    increment(three, behavior, index,&num_correct3);
                    break;
                case 4:
                    index = addr%256;//possible problems here
                    increment(four, behavior, index,&num_correct4);
                    break;
                case 5:
                    index = addr%512;//possible problems here
                    increment(five, behavior, index,&num_correct5);
                    break;
                case 6:
                    index = addr%1024;//possible problems here
                    increment(six, behavior, index,&num_correct6);
                    break;
                case 7:
                    index = addr%2048;//possible problems here
                    increment(seven, behavior, index,&num_correct7);
                    break;
            }
        }
};

class bimodial1{
    public:
        int one[16] = {0};
        int two[32] = {0};
        int three[128] = {0};
        int four[256] = {0};
        int five[512] = {0};
        int six[1024] = {0};
        int seven[2048] = {0};

        int num_correct1;
        int num_correct2;
        int num_correct3;
        int num_correct4;
        int num_correct5;
        int num_correct6;
        int num_correct7;

        bimodial1(){
            num_correct1=0;
            num_correct2=0;
            num_correct3=0;
            num_correct4=0;
            num_correct5=0;
            num_correct6=0;
            num_correct7=0;
        }
        void increment(int *arr, string behavior, int index, int* num_correct){
            if(arr[index]== 0 and behavior == "NT"){
                *num_correct = *num_correct+1;
            }else if (arr[index]==1 and behavior == "T"){
                *num_correct= *num_correct+1;
            }
            if(arr[index]==1 and behavior == "NT"){
                arr[index] = arr[index]-1;
            }else if(arr[index]==0 and behavior == "T"){
                arr[index] = arr[index]+1;
            }
        }
        void check(int option, unsigned long long addr, string behavior){
            int index;
            switch(option){
                case 1:                
                    index = addr%16;//possible problems here
                    increment(one, behavior, index,&num_correct1);
                    break;            
                case 2:
                    index = addr%32;//possible problems here
                    increment(two, behavior, index, &num_correct2);
                    break;
                case 3:
                    index = addr%128;//possible problems here
                    increment(three, behavior, index,&num_correct3);
                    break;
                case 4:
                    index = addr%256;//possible problems here
                    increment(four, behavior, index,&num_correct4);
                    break;
                case 5:
                    index = addr%512;//possible problems here
                    increment(five, behavior, index,&num_correct5);
                    break;
                case 6:
                    index = addr%1024;//possible problems here
                    increment(six, behavior, index,&num_correct6);
                    break;
                case 7:
                    index = addr%2048;//possible problems here
                    increment(seven, behavior, index,&num_correct7);
                    break;
            }
        }
};
class Gshare {
    public:
        int num_correct;
        int arr[2048] = {0};
        int GHR;
        int history_b;
        int history_s;
        int index;

        Gshare(){

        }

        Gshare(int history_size){
            num_correct = 0;
            history_b = history_size;
            history_s = 1;
            GHR = 0;
            for(int i=0;i<history_b;i++){
                history_s = 2*history_s;
            }
            for(int i=0;i<2048;i++){
                arr[i]=1;
            }
        }
        void increment(string behavior, int index){
            if(arr[index]<2 and behavior == "NT"){
                num_correct++;
            }else if (arr[index]>=2 and behavior == "T"){
                num_correct++;
            }
            if(arr[index]>0 and behavior == "NT"){
                arr[index]--;
            }else if(arr[index]<3 and behavior == "T"){
                arr[index]++;
            }
        }
        void shift(string behavior){
            GHR= GHR<<1;
            if(behavior == "T"){
                GHR++;
            }
            GHR= GHR%history_s;
        }
        void check(unsigned long long addr, string behavior){
            index = (addr % 2048)^GHR;
            increment(behavior, index);
            shift(behavior);
        }
};
class Tournament{
    public:
        int num_correct;
        int selector[2048];
        Gshare x;
        bimodial2 y;

        Tournament(){
            num_correct = 0;
            x = Gshare(11);
            y = bimodial2();
            for(int i = 0; i<2048; i++){
                selector[i] = 2;
            } 
        }
        int increment(int arr[], string behavior, int index){
            int retVal = 0;
            if(arr[index]< 2  and behavior == "NT"){
                num_correct++;
                retVal = 1;
            }else if (arr[index]>=2 and behavior == "T"){
                num_correct++;
                retVal = 1;
            }
            if(arr[index]>0 and behavior == "NT"){
                arr[index]--;
            }else if(arr[index]<3 and behavior == "T"){
                arr[index]++;
            }
            return retVal;
        }
        void check(unsigned long long addr, string behavior){
            int index = addr % 2048;
            int g_index = index ^ x.GHR;
            int right1 = 0;
            int right2 = 0;
            if(selector[index] >= 2){//bimodial chosen
                right1 = increment(y.seven, behavior, index);
                //check if gshare is right
                if(x.arr[g_index] < 2 and behavior == "NT"){
                    right2 = 1;
                }else if(x.arr[g_index]>=2 and behavior=="T"){
                    right2 = 1;
                }
                //change gshare index
                if(x.arr[g_index] > 0 and behavior == "NT"){
                    x.arr[g_index]--;
                }else if(x.arr[g_index] < 3 and behavior == "T"){
                    x.arr[g_index]++;
                }
                //change selector
                if(right1 == 1 and right2 == 0 and selector[index] < 3){
                    selector[index]++;
                }else if (right1 == 0 and right2 == 1 and selector[index] > 0 ){
                    selector[index]--;
                }
            }else{//gshare chosen
                right1 = increment(x.arr, behavior, g_index); 
                //check if bimodial is right
                if(y.seven[index] <2 and behavior == "NT"){
                    right2 = 1;
                }else if( y.seven[index]>=2 and behavior == "T"){
                    right2 = 1;
                }
                //change bimodal index
                if(y.seven[index] > 0 and behavior == "NT"){
                    y.seven[index]--;
                }else if(y.seven[index] < 3 and behavior == "T"){
                    y.seven[index]++;
                }
                //change selector
                if(right1 == 1 and right2 == 0 and  selector[index] > 0){
                    selector[index]--;
                }else if (right1 == 0 and right2 == 1 and selector[index] < 3){
                    selector[index]++;
                }
            }
            x.shift(behavior);    
        }
};

