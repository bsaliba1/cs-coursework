#include "List.hpp"
#include <iostream>

int main(){
    List<int> list;
    list.push_front(1);
    list.insert(list.begin(), 3);
    list.insert(list.end(), 4);
    list.push_front(2);
    list.push_back(5);
    list.displayList();
}