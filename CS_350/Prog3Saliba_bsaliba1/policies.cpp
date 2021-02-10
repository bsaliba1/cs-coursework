#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int optimal(int memsize, int requests[]){
    if(memsize == 0)
    {
        return 10000;
    }

    int size = 10000;
    int misses = 0;
    int arr[100]={0};
    int page;
    int counter = 0;
    for(int i=0;i<size;i++){
        page = requests[i];
        if(counter<memsize){
            if(arr[page]==0){
                misses++;
                arr[page]=1;
                counter++;
            }
        }
        else{
            if(arr[page]==0){
                /*change all 1's in bit vector to distance from next page request
                 * Done by: iterating through arr and checking all 1's and then 
                 * checking distance from next page request in requests.
                 * Next we go through all the indexes with value>1 and then
                 * we see which one is the greatest value and then we replace that index
                 */
                misses++;
                for(int j=0;j<100;j++){
                    if(arr[j] ==1){
                        for(int k=i+1;k<size;k++){
                            if(requests[k]==j){
                                arr[j]=k;
                                break;
                            }
                            else if(k==size-1){
                                arr[j] = size;
                                break;
                            }
                        }
                    }
                }
                int greatest=1;
                int greatest_index=0;
                for(int j=0;j<100;j++){		
                    if(arr[j]>=1){
                        if(arr[j]>=greatest){
                            greatest = arr[j];
                            greatest_index = j;
                        }
                        arr[j]=1;
                    }
                }
                arr[greatest_index]=0;
                arr[page]=1;
            }
        }	
    }
    return misses;     
}
int LRU(int memsize, int requests[]){

    if(memsize == 0)
    {
        return 10000;
    }
    int arr[100] = {0};
    vector<int> de;
    int page;
    int misses=0;
    for(int i=0; i<10000;i++){
        page = requests[i]; 
        if(de.size()<memsize){
            if(arr[page]==0){
                misses++;
                arr[page]=1;
                de.push_back(page);
            }
        }else{
            if(arr[page]==0){
                misses++;
                de.push_back(page);
                arr[page]=1;
                arr[de[0]]=0;
                de.erase(de.begin());
            }else{
                int index;
                for(int x = 0; x<de.size();x++){
                    if(de[x]==page){
                        index=x;
                    }
                }
                de.push_back(page);
                de.erase(de.begin()+index);
            }
        }
    } 
    return misses;
}
int FIFO(int memSize, int requests[]){

    if(memSize == 0)
    {
        return 10000;
    }
    int misses = 0;
    int page;
    queue<int> cache;
    int pageVector[100] = {0};

    for(int i = 0; i < 10000; i++)
    {
        page = requests[i];
        /*Check the size of the cache, if the cache is not full, add the page to it, otherwise pop off queue and adjust pageVector.*/
        if(cache.size() < memSize)
        {
            /*Check if the page is not in the cache*/
            if(pageVector[page] != 1)
            {
                cache.push(page);
                pageVector[page] = 1;
                misses++;
            }

            /*Page is in the cache already*/
            else
            {
                /*Do nothing*/
            }
        }

        /*Cache is full, do FIFO page replacement*/
        else
        {
            /*Check if the page is not in the cache.*/
            if(pageVector[page] != 1)
            {
                misses++;

                /*Remove the front element of the queue from the pageVector and the queue.
                 *Insert the new page in the queue and set the page in the pageVector to be 1.*/

                pageVector[cache.front()] = 0;
                cache.pop();
                cache.push(page);
                pageVector[page] = 1;
            }
            /*This is a hit*/
            else
            {
                /*Do nothing*/
            }
        }
    }
    return misses;
}
int Rand(int memSize, int requests[]){

    /*To prevent floating point exception.*/
    if(memSize == 0)
    {
        return 10000;
    }

    int misses = 0;
    int page;
    int pageVector[100] = {0};
    int cache[memSize];
    int counter = 0;
    int randomPage;

    for(int i = 0; i < 10000; i++)
    {
        page = requests[i];

        /*Check if cache is not full and the element does not exist in cache already*/
        if(counter < memSize)
        {
            /*Check if page is not in cache, if it is not, add it.*/
            if(pageVector[page] != 1)
            {
                cache[counter] = page;
                misses++;
                pageVector[page] = 1;
                counter++;
            }

            /*Else page is in the cache already*/

            else
            {
                /*Do nothing*/
            }
        }
        /*Cache is full, perform Random replacement policy*/
        else
        {
            /*Check if page is not in the cache*/
            if(pageVector[page] != 1)
            {
                misses++;

                /*Generate random index into cache from 0 to memSize;*/
                randomPage = rand() % memSize;

                /*Take random page out of page vector.*/
                pageVector[cache[randomPage]] = 0;

                /*Overwrite the randomPage, which is in the cache, with the page we just read.*/
                cache[randomPage] = page;

                /*Update the page vector with the new page*/
                pageVector[page] = 1;
            }

            /*Else, this is a hit*/
            else
            {
                /*Do nothing*/
            }
        }
    }
    return misses;
}
int Clock(int memsize, int requests[]){

    if(memsize == 0)
    {
        return 10000;
    }

    int arr[100]={0};
    int counter=0;
    int misses=0;
    int cache[memsize];
    int page;
    int clock=0;
    for(int i=0;i<10000;i++){
        page = requests[i];
        if(counter<memsize){
            if(arr[page]==0){//Not in cache and mem not full
                misses++;
                arr[page]=2;//indicates recently used
                cache[counter]=page;//put page in cache
                counter++;
            }else{
                arr[page]=2;//probably redundant but whatever
            }
        }
        else{
            if(arr[page]==0){//Not in cache but mem full
                misses++; //problem after this line
                int j = clock;
                do{
                    if(arr[cache[j]]==2){
                        arr[cache[j]]=1;
                        j = (j+1)%memsize;
                    }else if(arr[cache[j]]==1){
                        arr[cache[j]]=0;
                        arr[page] = 2; 
                        cache[j] = page;
                        clock = j;
                        break;
                    }
                } while( j!= clock); 
            }else{
                arr[page]=2;
            }
        }
    }
    return misses;
}
void printUsage(){
    fprintf(stderr,"./policies <type> <input_filename>\n"); 
}
int main(int argc, char* argv[]){
    if(argc!=3){
        printUsage();
        exit(0);
    }
    string filename = argv[2];
    int graph = stoi(argv[1]);

    int requests[10000];
    ifstream file(filename);
    string line;

    int cache_misses;
    float percent;
    int i=0;
    while(getline(file,line)){
        requests[i]=stoi(line);
        i++;
    }

    if(graph == 1)
    {
        printf("#cache,OPT,LRU,FIFO,RAND,CLOCK\n");
    }
    else
    {

        printf("#cache,OPT,LRU,FIFO,RAND\n");

    }

    for(int i=0; i<105; i=i+5){
        printf("%d,", i);
        cache_misses  = optimal(i, requests);
        percent = (100.0 * ((10000 - cache_misses) / 10000.0));
        printf("%f,",percent);

        cache_misses  = LRU(i, requests);
        percent = (100.0 * ((10000 - cache_misses) / 10000.0));
        printf("%f,",percent);

        cache_misses  = FIFO(i, requests);
        percent = (100.0 * ((10000 - cache_misses) / 10000.0));
        printf("%f,",percent);


        cache_misses  = Rand(i, requests);
        percent = (100.0 * ((10000 - cache_misses) / 10000.0));
        if(graph == 0)
        {

            printf("%f\n",percent);

        }
        else if(graph == 1)
        {
            printf("%f,", percent);
        }

        if(graph == 1)
        { 
            cache_misses  = Clock(i, requests);
            percent = (100.0 * ((10000 - cache_misses) / 10000.0));
            printf("%f\n",percent);
        }
    }
}
