#include "order.h"
#include "bench.h"
#include <stdio.h>

void addList(int binNum,int list[]);
void placeBin(int binNum);
int canPlace();
void replaceBin(int binNum,int list[]);
int binOnDesk(int binNum);

/* 1) Get order
 * 2) Get part #
 * 3) Get bin #
 * 4) Check if you already have the bin
 * 5) If not then place the bin
 * 6) Replace the oldest bin
 *
*/
int main(int argc, char **argv) {
	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}    
    int list[5] = {-1,-1,-1,-1,-1};
	
    do {
		int pn=nextPartNumber();
        int bin=pn/10;
        

      if(binOnDesk(bin)==0){
            if(canPlace()==1){   
                  placeBin(bin);
             }else{
                  replaceBin(bin,list);
             }
        }
        addList(bin,list);
    } while(fetchNextPart());
    closeOrder();
    return 0;
}
//takes in a list and binum and adds binum to list if there is an open slot
//if not then it removes the last element and then adds one to all the other elements
//then it places the binum add the beginning of the list where there is now an empty slot
//(INCOMPLETE)
void addList(int binNum,int list[]){
    //ensures that bin is not already in list
    for(int i=0; i<5;i++){
        if(list[i]==binNum && i==0){
            return;
        }
        if(list[i]==binNum && i!=0){
            int temp=0;
            for(int j=0;i<=j;j++){
                if(j==0){
                    temp = list[j];
                    list[j]=list[i];
                }else{
                    int temp2 = list[j];
                    list[j] = temp;
                    temp = temp2;
                }
            }   
            return;
        }
    }
    //determines if list is full or not. If not add binNum to list
    int full = 0;
    for(int i=4; i>=0;i--){
        if(list[i]==-1){
            list[i]=binNum;
            return;
        }else{
            full++;
        }
    }
    //if list is full then then get rid of list[4], add 1 to the indexes of all the values, and place bin at list[0]
    if(full == 5){
        int temp=0;
        for(int i=0;i<=4;i++){
            if(i==0){
                temp = list[i];
                list[i]=binNum;
            }else{
                int temp2 = list[i];
                list[i]= temp;
                temp = temp2;
            }
        }
    }
}

//places bin in an empty spot
void placeBin(int binNum){
    for(int i=0; i<5; i++){
        if(binInSlot(i)==-1){
            fetchBin(binNum,i);
            break;
        }
    }
}
//returns -1 if there are no slots open and 1 if there are slots open
int canPlace(){
    for(int i=0;i<5;i++){
        if(binInSlot(i)!=-1);
        else return 1;
    }
    return -1;
}

//replaces least needed bin
void replaceBin(int binNum, int list[]){
   int oldest =list[4];
   int oldest_bin;
   for(int i=0;i<5;i++){
       if(binInSlot(i)==oldest){
           oldest_bin=i;
       }
   }
   fetchBin(binNum,oldest_bin);    
}
//returns 1 if bin is already in a slot and 0 if not 
int binOnDesk(int binNum){
    int retVal=0;
    for(int i=0;i<5;i++){
        if(binInSlot(i)==binNum)retVal=1;
    }
    return retVal;
}
