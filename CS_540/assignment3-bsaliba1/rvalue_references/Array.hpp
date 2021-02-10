#include <vector>

namespace cs540{
    class Array{
        std::vector<MyInt> container;
        Array(std::intializer_list<int> list){
            for(int i = 0; i<list.length(); i++){
                container.push_back(MyInt(list[i]));
            }
        }
    };
}