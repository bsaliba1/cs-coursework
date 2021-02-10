using namespace std;

typedef struct instr{
    char ls;
    string addr;
}instr;

int power(int base, int exponent){
    int retVal= base;
    for(int i=1;i<exponent;i++){
        retVal= retVal*base;
    }
    return retVal;
}
int log(int num){
    int count=0;
    while(num!=1){
        num= num/2;
        count++;
    }
    return count;
}

class DirectMapped{
    public:
        vector<int> cache;
        int num_sets;
        DirectMapped(int sizeInKB){
            num_sets = sizeInKB*1024/32;
            //cout<<"Num Sets: "<<num_sets<<endl;
            for(int i=0; i<num_sets; i++){
                cache.push_back(-1);
            }
        }

        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            //cout<<"Set: "<<set<<", Offset: "<<offset<<", Tag: "<<tag<<endl;

            if(cache[set]==-1){
                cache[set] = tag;
                return 0;
            }else{
                if(cache[set]!=tag){
                    cache[set] = tag;
                    return 0;
                }else{
                    return 1;
                }
            } 
            return 1;
        }
};

class SetAssociative{
    public:
        vector<deque<int> > cache;
        int num_sets;
        SetAssociative(int ways){
            num_sets = 16*1024/(32*ways);
            for(int i=0; i<num_sets; i++){
                deque<int> temp;
                for(int i=0; i<ways;i++){
                    temp.push_back(-1);
                }
                cache.push_back(temp);
            }   
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            for(int i=0;i<cache[set].size();i++){
                if(cache[set][i] == tag){
                    cache[set].erase(cache[set].begin()+i);
                    cache[set].push_back(tag);
                    return 1;
                }        
            }
            cache[set].pop_front();
            cache[set].push_back(tag);

            return 0;
        }
};
class FullyAssociativeLRU{
    public:
        deque<int> cache;
        FullyAssociativeLRU(){
            int ways = 16*1024/32;
            for(int i=0;i<ways;i++){
                cache.push_back(-1);
            }
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int offset = i_addr%32;
            int tag = i_addr/32;

            for(int i=0;i<cache.size();i++){
                if(cache[i] == tag){
                    cache.erase(cache.begin()+i);//remove tag from queue
                    cache.push_back(tag);//add to back
                    return 1;
                }        
            }
            cache.pop_front();
            cache.push_back(tag);

            return 0;       

        }
};
class FullyAssociativeHC{
    public:
        vector<int> cache;
        vector<int> HC;
        int ways; 
        FullyAssociativeHC(){
            ways =16*1024/32;
            for(int i=0;i<ways;i++){
                cache.push_back(-1);
                HC.push_back(0);
            }
        }
        void set(int index){
            int pivot = 0;
            for(int j=0; j<log(ways); j++){
                int temp = (index/(ways/(2<<j)))%2;
                if(temp==1){
                    HC[pivot] = 0;
                    pivot = 2*(pivot+1);
                }else{
                    HC[pivot] = 1;
                    pivot = (2*pivot)+1;
                }
            }
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int offset = i_addr%32;
            int tag = i_addr/32;

            for(int i=0;i<cache.size();i++){
                if(cache[i] == tag){ 
                    set(i);
                    return 1;      
                }   
            }
            int pivot = 0;

            for(int i =0; i<log(ways);i++){
                if(HC[pivot]==1){
                    HC[pivot]=0;
                    pivot = 2*(pivot+1);
                }else{
                    HC[pivot] = 1;
                    pivot = (2*pivot)+1;
                }
            }
            pivot = pivot+1 - ways;
            cache[pivot] = tag;
            return 0;       
        }
};
class SetAssociativeNA{
    public:
        vector<deque<int> > cache;
        int num_sets;
        SetAssociativeNA(int ways){
            num_sets = 16*1024/(32*ways);
            for(int i=0; i<num_sets; i++){
                deque<int> temp;
                for(int i=0; i<ways;i++){
                    temp.push_back(-1);
                }
                cache.push_back(temp);
            }   
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            for(int i=0;i<cache[set].size();i++){
                if(cache[set][i] == tag){
                    cache[set].erase(cache[set].begin()+i);
                    cache[set].push_back(tag);
                    return 1;
                }        
            }
            if(i->ls == 'L'){
                cache[set].pop_front();
                cache[set].push_back(tag);
            }
            return 0;
        }
};
class SetAssociativePF{
    public:
        vector<deque<int> > cache;
        int num_sets;
        SetAssociativePF(int ways){
            num_sets = 16*1024/(32*ways);
            for(int i=0; i<num_sets; i++){
                deque<int> temp;
                for(int i=0; i<ways;i++){
                    temp.push_back(-1);
                }
                cache.push_back(temp);
            }   
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            int ni_addr = stoi(i->addr, 0, 16)+32;//get next line
            int next_set = (ni_addr/32)%num_sets; 
            int noffset = ni_addr%32;
            int ntag = ni_addr/power(2,5+log(num_sets));

            for(int i=0;i<cache[set].size();i++){
                if(cache[set][i] == tag){
                    cache[set].erase(cache[set].begin()+i);
                    cache[set].push_back(tag);
                    //prefetch on hit
                    bool found = false;
                    for(int j=0; j<cache[next_set].size();j++){
                        if(cache[next_set][j] == ntag){
                            cache[next_set].erase(cache[next_set].begin()+j);
                            cache[next_set].push_back(ntag);
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cache[next_set].pop_front();
                        cache[next_set].push_back(ntag);

                    }
                    return 1;
                }        
            }
            cache[set].pop_front();
            cache[set].push_back(tag);
            //prefetch on miss
            bool found = false;
            for(int i=0; i<cache[next_set].size(); i++){
                if(cache[next_set][i] == ntag){
                    cache[next_set].erase(cache[next_set].begin()+i);
                    cache[next_set].push_back(ntag);
                    found = true;
                    break;
                }
            }
            if(!found){
                cache[next_set].pop_front();
                cache[next_set].push_back(ntag);
            }
            return 0;
        }
};
class SetAssociativePFonMiss{
    public:
        vector<deque<int> > cache;
        int num_sets;
        SetAssociativePFonMiss(int ways){
            num_sets = 16*1024/(32*ways);
            for(int i=0; i<num_sets; i++){
                deque<int> temp;
                for(int i=0; i<ways;i++){
                    temp.push_back(-1);
                }
                cache.push_back(temp);
            }   
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            int ni_addr = stoi(i->addr, 0, 16)+32;
            int next_set = (ni_addr/32)%num_sets; 
            int noffset = ni_addr%32;
            int ntag = ni_addr/power(2,5+log(num_sets));

            for(int i=0;i<cache[set].size();i++){
                if(cache[set][i] == tag){
                    cache[set].erase(cache[set].begin()+i);
                    cache[set].push_back(tag);

                    return 1;
                }        
            }
            cache[set].pop_front();
            cache[set].push_back(tag);
            //prefetch on miss
            bool found = false;
            for(int i=0; i<cache[next_set].size(); i++){
                if(cache[next_set][i] == ntag){
                    cache[next_set].erase(cache[next_set].begin()+i);
                    cache[next_set].push_back(ntag);
                    found = true;
                    break;
                }
            }
            if(!found){
                cache[next_set].pop_front();
                cache[next_set].push_back(ntag);
            }
            return 0;
        }
};
class SetAssociativePF2{
    public:
        vector<deque<int> > cache;
        int num_sets;
        SetAssociativePF2(int ways){
            num_sets = 16*1024/(32*ways);
            for(int i=0; i<num_sets; i++){
                deque<int> temp;
                for(int i=0; i<ways;i++){
                    temp.push_back(-1);
                }
                cache.push_back(temp);
            }   
        }
        int access(instr* i){
            int i_addr = stoi(i->addr, 0, 16);
            int set = (i_addr/32)%num_sets; 
            int offset = i_addr%32;
            int tag = i_addr/power(2,5+log(num_sets));

            int ni_addr = stoi(i->addr, 0, 16)+32;//get next line
            int next_set = (ni_addr/32)%num_sets; 
            int noffset = ni_addr%32;
            int ntag = ni_addr/power(2,5+log(num_sets));

            int ni_addr2 = stoi(i->addr, 0, 16)+64;//get next line
            int next_set2 = (ni_addr2/32)%num_sets; 
            int noffset2 = ni_addr2%32;
            int ntag2 = ni_addr2/power(2,5+log(num_sets));

            bool found2 = false;
            for(int i=0;i<cache[next_set2].size();i++){
                if(cache[next_set2][i] == tag){
                    cache[next_set2].erase(cache[next_set2].begin()+i);
                    cache[next_set2].push_back(tag);
                    found2 = true;
                    break;
                }        
            }
            if(!found2){
                cache[next_set2].pop_front();
                cache[next_set2].push_back(ntag2);
            }

            for(int i=0;i<cache[set].size();i++){
                if(cache[set][i] == tag){
                    cache[set].erase(cache[set].begin()+i);
                    cache[set].push_back(tag);
                    //prefetch on hit
                    bool found = false;
                    for(int j=0; j<cache[next_set].size();j++){
                        if(cache[next_set][j] == ntag){
                            cache[next_set].erase(cache[next_set].begin()+j);
                            cache[next_set].push_back(ntag);
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        cache[next_set].pop_front();
                        cache[next_set].push_back(ntag);

                    }
                    return 1;
                }        
            }
            cache[set].pop_front();
            cache[set].push_back(tag);
            //prefetch on miss
            bool found = false;
            for(int i=0; i<cache[next_set].size(); i++){
                if(cache[next_set][i] == ntag){
                    cache[next_set].erase(cache[next_set].begin()+i);
                    cache[next_set].push_back(ntag);
                    found = true;
                    break;
                }
            }
            if(!found){
                cache[next_set].pop_front();
                cache[next_set].push_back(ntag);
            }
            return 0;
        }
};
