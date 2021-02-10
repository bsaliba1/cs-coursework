#ifndef CS540_LIST_HPP
#define CS540_LIST_HPP



#include <assert.h>
#include <iostream>

/*
Hints: 
1) Doubly linked is easier to implement. 
2) Delegate logic to helper classes if possible
*/

template <typename T>
class List {
    private:
    class Link
    {
      public:
      Link* next;
      Link* prev;
      Link():next(this),prev(this){};
    };
    class Node: public Link
    {
      public:
      T element;
      Node(const T& el):Link(), element(el){};
    };

    public:
        class Iterator {
          public:
          Link* current;
          Link* l_node;
          Iterator(Link* cur, Link* last):current(cur),l_node(last){};
          Iterator& operator++(int){
            if(current->next != l_node){
              current = current->next;
            }
            return *this;
          }
          Iterator& operator--(int){
            if(current->prev != l_node){
              current = current->prev;
            }
          }

          bool operator!=(Iterator& it){
            if(it.current != current){
              return false;
            }
            return true;
          }
        };

    public:
        Link* sentinel;
        List(){
          sentinel = new Link();
        }
        Iterator& begin() { 
          Iterator* it = new Iterator(sentinel,sentinel);
          return *it;
        }
        Iterator& end() { 
           Iterator* it = new Iterator(sentinel->prev, sentinel); 
           return *it;
        }
        Iterator& insert(const Iterator &it, const T &val) {
          Node* to_insert = new Node(val);
          it.current->next->prev = to_insert;
          to_insert->next = it.current->next;
          to_insert->prev = it.current;
          it.current->next = to_insert;
          Iterator* retIt = new Iterator(to_insert,sentinel);
          return *retIt;
        }
        Iterator& push_front(const T &val) {
          Node* to_insert = new Node(val);
          to_insert->next = sentinel->next;
          to_insert->prev = sentinel;
          sentinel->next->prev = to_insert;
          sentinel->next = to_insert;
          Iterator* it = new Iterator(to_insert,sentinel);
          return *it;
        }
        Iterator& push_back(const T &val) {
          Node* to_insert = new Node(val);
          to_insert->next = sentinel;
          to_insert->prev = sentinel->prev;
          sentinel->prev->next = to_insert;
          sentinel->prev = to_insert;
          Iterator* it = new Iterator(to_insert,sentinel);
          return *it;
          //Implement this
        }
        void erase(const Iterator &it) {
            assert(it.current != &sentinel);
            it.current->prev->next = it.current->next;
            it.current->next->prev = it.current->prev;
            delete it;
        }
        void displayList(){
          Link* head = sentinel->next;
          while(head != sentinel){
            Node* casted = (Node*) head;
            std::cout<<casted->element<<std::endl;
            head = head->next;
          }
        }
};

#endif