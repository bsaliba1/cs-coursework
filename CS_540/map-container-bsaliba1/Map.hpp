#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <bits/stdc++.h>
#include <vector>

//Map Containing skip list
namespace cs540{
    template <typename Key_T, typename Mapped_T>
        class Map{
            /*  LINK CLASS
                Two types of links:
                1. Links at all levels > 0. These have the:
                - next pointer
                - prev pointer
                - base pointer, which refers to the base NODE at level 0, you can obtain key value pair from base node
                2. Links at level 0. These have the:
                - next pointer
                - prev pointer
                - all_levels pointer to all links in higher levels 
                */
            class Link{
                public:
                    Link* next;
                    Link* prev;
                    Link* base;
                    std::vector<Link*> all_levels;
                    Link(): prev(this), next(this), base(nullptr){};
                    Link(const Link* copy): prev(this), next(this), base(this){
                        for(int i=0; i<copy->all_levels.size(); i++){
                            Link* link = copy->all_levels[i];
                            if(i == 0){
                                all_levels.push_back(this);
                            }else{
                                Link* temp = new Link(link);
                                temp->base = this;
                                all_levels.push_back(temp);
                            }
                        }
                    }
                    Link(Link* base, int): prev(this), next(this), base(base){}; //to create level above
                    Link(int level): prev(this), next(this), base(this){
                        all_levels.push_back(this);
                        for(int i=0; i<level; i++){
                            Link* temp = new Link(this, 1);
                            all_levels.push_back(temp);
                        }
                    }
                    const Key_T& get_key(){
                        Node* base_node = (Node*) base;
                        return base_node->key();
                    }
                    Mapped_T& get_value(){
                        Node* base_node = (Node*) base;
                        return base_node->value();
                    }
                    ~Link(){
                        size_t s = all_levels.size();
                        //std::cout<<this<<" | "<<all_levels.size()<<std::endl;
                        for(int i=1; i<s ; i++){
                            Link* l = all_levels[s-i];
                            delete l;
                        }
                    }
            };
            //NODE CLASS
            class Node: public Link{
                public:
                    std::pair<const Key_T,Mapped_T> element;

                    //Constructor
                    Node(const std::pair<const Key_T,Mapped_T>& elm, int level):Link(level), element(elm){};
                    Node(const Node* copy): Link((Link*) copy), element(copy->element){};
                    ~Node(){};
                    const Key_T& key(){
                        return element.first;
                    }
                    Mapped_T& value(){
                        return element.second;
                    }
            };

            public:
            class Iterator{
                public:
                    Node* current;
                    Link* next;
                    Link* prev;
                    Link* start;
                    Iterator():current(nullptr),next(nullptr),prev(nullptr),start(nullptr){};
                    Iterator(Node* position, Link* sent): current(position), next(position->next), prev(position->prev), start(sent){};
                    Iterator(Link* sent):current(nullptr),next(sent->next),start(sent),prev(sent->prev){};
                    Iterator& operator++(){
                        if(next != start && next != nullptr){
                            current = (Node*) next;
                            next = next->next;
                            prev = current;
                        }else{
                            current = nullptr;
                            next = nullptr;
                            prev= start->prev;
                        }
                        return *this;
                    }
                    Iterator operator++(int){
                        if(next != start && next != nullptr){
                            current = (Node*) next;
                            next = next->next;
                            prev = current;
                        }else{
                            current = nullptr;
                            next = nullptr;
                            prev= start->prev;
                        }
                        return *this;
                    }
                    Iterator& operator--(){
                        if(prev != start && prev != nullptr){
                            current = (Node*) prev;
                            prev = prev->prev;
                            next = current;
                        }
                        else{
                            current = nullptr;
                            next = start->next;
                            prev = nullptr;
                        }
                        return *this;
                    }
                    Iterator operator--(int){
                        if(prev != start && prev != nullptr){
                            current = (Node*) prev;
                            prev = prev->prev;
                            next = current;
                        }
                        else{
                            current = nullptr;
                            next = start->next;
                            prev = nullptr;
                        }
                        return *this;
                    }
                    inline bool operator==(const Iterator it){
                        if(current == it.current){
                            return true;
                        }
                        return false;
                    }
                    inline bool operator!=(const Iterator it){
                        if(current == it.current){
                            return false;
                        }
                        return true;
                    }
                    std::pair<const Key_T, Mapped_T>& operator*() const{
                        return current->element;
                    }
                    std::pair<const Key_T, Mapped_T> *operator->() const{
                        return &current->element;
                    }
            };
            class ConstIterator: public Iterator{
                public:
                    ConstIterator(){};
                    ConstIterator(const Iterator &it){};	
                    ConstIterator(Node* position, Link* sent): Iterator(position, sent){};
                    ConstIterator(Link* sent): Iterator(sent){};
                    inline bool operator==(const ConstIterator it){
                        if(this->current == it.current){
                            return true;
                        }
                        return false;
                    }
                    inline bool operator!=(const ConstIterator it){
                        if(this->current == it.current){
                            return false;
                        }
                        return true;
                    }
                    inline const std::pair<const Key_T,Mapped_T>& operator*() const {
                        return this->current->element;
                    }
                    const std::pair<const Key_T, Mapped_T> *operator->() const{
                        return &this->current->element; 
                    }
            };

            class ReverseIterator: public Iterator{
                public:
                    ReverseIterator(){};
                    ReverseIterator(Node* position, Link* sent): Iterator(position, sent){};
                    ReverseIterator(Link* sent): Iterator(sent){};
                    ReverseIterator &operator++(){
                        if(this->prev != this->start && this->prev != nullptr){
                            this->current = (Node*) this->prev;
                            this->next = this->current;
                            this->prev = this->prev->prev;
                        }else{
                            this->current = nullptr;
                            this->next = this->start->next;
                            this->prev = nullptr;
                        }
                        return *this;
                    };	
                    ReverseIterator operator++(int){
                        if(this->prev != this->start && this->prev != nullptr){
                            this->current = (Node*) this->prev;
                            this->next = this->current;
                            this->prev = this->prev->prev;
                        }else{
                            this->current = nullptr;
                            this->next = this->start->next;
                            this->prev = nullptr;
                        }
                        return *this;
                    }
                    ReverseIterator &operator--(){
                        if(this->next != this->start && this->next != nullptr){
                            this->current = (Node*) this->next;
                            this->next = this->next->next;
                            this->prev = this->current;
                        }else{
                            this->current = nullptr;
                            this->next = nullptr;
                            this->prev = this->start->prev;
                        }
                        return *this;
                    }
                    ReverseIterator operator--(int){
                        if(this->next != this->start && this->next != nullptr){
                            this->current = (Node*) this->next;
                            this->next = this->next->next;
                            this->prev = this->current;
                        }else{
                            this->current = nullptr;
                            this->next = nullptr;
                            this->prev= this->start->prev;
                        }
                        return *this;
                    }
                    inline bool operator==(const ReverseIterator it){
                        if(this->current == it.current){
                            return true;
                        }
                        return false;
                    }
                    inline bool operator!=(const ReverseIterator it){
                        if(this->current == it.current){
                            return false;
                        }
                        return true;
                    }
            };


            //Data Members
            Link* sentinel;
            int top_level;
            size_t map_size;


            public:
            //Constructor
            Map():top_level(0),map_size(0){
                sentinel = new Link();
                sentinel->all_levels.push_back(sentinel);
            }
            ~Map(){
                Link* head = sentinel->next;
                while(head!=sentinel){
                    Node* node = (Node*) head;
                    head = head->next;
                    delete node;
                }
                delete sentinel;
            }

            Map(const Map &copy): top_level(copy.top_level), map_size(copy.map_size){
                sentinel = new Link(copy.sentinel);
                Link* head = copy.sentinel->next;
                while(head != copy.sentinel){
                    Node* to_append = new Node((Node*) head);
                    append(to_append);
                    head = head->next;
                }
            }
            Map &operator=(const Map &copy){
                if(&copy != this){
                    clear();
                    delete sentinel;
                    sentinel = new Link(copy.sentinel);
                    Link* head = copy.sentinel->next;
                    while(head != copy.sentinel){
                        Node* to_append = new Node((Node*) head);
                        append(to_append);
                        head = head->next;
                    }
                    map_size = copy.map_size;
                    top_level = copy.top_level;
                }
                return *this;
            }	
            Map(std::initializer_list<std::pair<const Key_T, Mapped_T>> i_list):top_level(0),map_size(0){
                sentinel = new Link();
                sentinel->all_levels.push_back(sentinel);
                for(std::pair<const Key_T, Mapped_T> element: i_list){
                    insert(element);
                }
            }	
            template <typename IT_T>
                void insert(IT_T range_beg, IT_T range_end){
                    for (auto it = range_beg; it != range_end; ++it) {
                        try{
                            insert(*it);
                        }catch(...){
                            std::cout<<"Incompatible iterator type"<<std::endl;
                        }
                    }
                }

            //Function prototypes
            std::pair<Iterator, bool> insert(const std::pair<const Key_T, Mapped_T>& element){
                Iterator retIterator;
                bool retBool = true;

                //Obtain random height for new node
                int rlevel = rand_level();
                if(rlevel >= top_level){
                    adjust_sentinel(rlevel-top_level);
                }

                //Check if key already in the list
                Iterator b_added = find(element.first);
                if(b_added != this->end()){
                    retIterator = b_added;
                    retBool = false;
                    return std::make_pair(retIterator,retBool);
                }

                //Create new Node
                Node* to_insert = new Node(element, rlevel);

                //Search where to place new node
                Link* head = sentinel->all_levels[top_level];
                int current_level = top_level;
                while(current_level >= 0){
                    Link* start = sentinel->all_levels[current_level];
                    while(head->next != start && head->next->get_key() < element.first){
                        head = head->next;
                    }
                    if(rlevel>= current_level){
                        place_node(head, to_insert, current_level);
                    }
                    if(current_level > 0){
                        head = (Node*) head->base->all_levels[current_level-1]; 
                    }
                    current_level--;
                }

                //Make return pair
                retIterator = Iterator(to_insert, sentinel);
                map_size++;
                return std::make_pair(retIterator,retBool);
            }

            void erase(Iterator it){
                if( it != end()){
                    for(Link* link: it.current->all_levels){
                        link->prev->next = link->next;
                        link->next->prev = link->prev;
                    }
                    delete it.current;
                    map_size--;
                }
            }
            void erase(const Key_T &key){
                Iterator it = find(key);
                if(it == end()){
                    throw std::out_of_range ("Key not found");
                }else{
                    erase(it);
                }
            }

            size_t size() const{
                return map_size;
            }

            bool empty() const{
                if(map_size == 0){
                    return true;
                }
                return false;
            }

            void clear(){
                Link* head = sentinel->next;
                while(head != sentinel){
                    Node* temp = (Node*) head;
                    head = head->next;
                    delete temp;
                }
                delete sentinel;
                sentinel = new Link();
                sentinel->all_levels.push_back(sentinel);
                top_level = 0;
                map_size = 0;
            }

            Iterator begin(){
                if(sentinel->next != sentinel){
                    return Iterator((Node*)sentinel->next, sentinel);
                }
                return Iterator(sentinel);
            }
            Iterator end(){
                return Iterator(sentinel);
            }
            ConstIterator begin() const{
                if(sentinel->next != sentinel){
                    return ConstIterator((Node*)sentinel->next, sentinel);
                }
                return ConstIterator(sentinel);
            }
            ConstIterator end() const{
                return ConstIterator(sentinel);
            }
            ReverseIterator rbegin(){
                if(sentinel->prev != sentinel){
                    return ReverseIterator((Node*)sentinel->prev, sentinel);
                }
                return ReverseIterator(sentinel);
            }
            ReverseIterator rend(){
                return ReverseIterator(sentinel);

            }

            //Returns node pointer to node with same key if found
            //if no same key found nullptr is returned
            Iterator find(const Key_T &key){
                Link* head = sentinel->all_levels[top_level];
                int current_level = top_level;
                while(current_level >= 0){
                    Link* start = sentinel->all_levels[current_level];
                    while(head->next != start && (head->next->get_key() < key|| keys_equal(head->next->get_key(), key))) {
                        if(keys_equal(head->next->get_key(), key)){
                            return Iterator((Node*)head->next->base, sentinel);
                        }
                        head = head->next;
                    }
                    if(current_level > 0){
                        head = (Node*) head->base->all_levels[current_level-1]; 
                    }
                    current_level--;
                }
                return Iterator(sentinel);
            }
            //Returns node pointer to node with same key if found
            //if no same key found nullptr is returned
            ConstIterator find(const Key_T &key) const{
                Link* head = sentinel->all_levels[top_level];
                int current_level = top_level;
                while(current_level >= 0){
                    Link* start = sentinel->all_levels[current_level];
                    while(head->next != start && (head->next->get_key() < key|| keys_equal(head->next->get_key(), key))) {
                        if(keys_equal(head->next->get_key(), key)){
                            return ConstIterator((Node*)head->next->base, sentinel);
                        }
                        head = head->next;
                    }
                    if(current_level > 0){
                        head = (Node*) head->base->all_levels[current_level-1]; 
                    }
                    current_level--;
                }
                return ConstIterator(sentinel);
            }
            Mapped_T &at(const Key_T &key){
                Iterator it = find(key);
                if(it == end()){
                    throw std::out_of_range ("Key not found");
                }
                return it.current->get_value(); 

            }
            const Mapped_T &at(const Key_T &key) const{
                ConstIterator it = find(key);
                if(it == end()){
                    throw std::out_of_range ("Key not found");
                }
                return it.current->get_value();
            }

            //Comparitors
            bool operator==(const Map &y){
                Link* head1 = sentinel->next;
                Link* head2 = y.sentinel->next;

                if(map_size != y.map_size) return false;
                while(head1 != sentinel){
                    Node* h1 = (Node*) head1;
                    Node* h2 = (Node*) head2;
                    if(!(keys_equal(h1->get_key(), h2->get_key()) && mapped_equal(h1->get_value(), h2->get_value()))){
                        return false;
                    }
                    head1 = head1->next;
                    head2 = head2->next; 
                }
                return true;
            }
            bool operator!=(const Map &y){
                return !(*this == y);
            }

            bool operator<(const Map &y){
                Link* head1 = sentinel->next;
                Link* head2 = y.sentinel->next;
                bool retBool;
                Link* s;
                if(size() < y.size()){
                    s = sentinel;
                    while(head1 != s){
                        Node* h1 = (Node*) head1;
                        Node* h2 = (Node*) head2;
                        if(h1->get_key() < h2->get_key()){
                            return true;
                        }else if(h2->get_key()<h1->get_key()){
                            return false;
                        }
                        head1 = head1->next;
                        head2 = head2->next; 
                    }            
                    return true;
                }else{
                    s = y.sentinel;
                    while(head2 != s){
                        Node* h1 = (Node*) head1;
                        Node* h2 = (Node*) head2;
                        if(h1->get_key() < h2->get_key()){
                            return true;
                        }else if(h2->get_key()<h1->get_key()){
                            return false;
                        }
                        head1 = head1->next;
                        head2 = head2->next; 
                    }            
                    return false;
                }
                return true;
            }

            //find is O(logn)
            //insert is O(logn)
            //Meaning operator[] is O(2logn) == O(logn)
            Mapped_T &operator[](const Key_T &key){
                Iterator it = find(key);
                if(it == end()){
                    Mapped_T def;
                    it = insert(std::make_pair(key, def)).first;
                    return (*it).second;
                }else{
                    return (*it).second;
                }
            }

            //-----------------------------------------------------------------
            //UTILITY FUNCTIONS
            private:
            void adjust_sentinel(int height_increase){
                for(int i=0; i<height_increase; i++){
                    Link* new_sentinel = new Link(sentinel, 1);
                    sentinel->all_levels.push_back(new_sentinel);
                    top_level++;
                }
            }
            int rand_level(){
                int ret_level=0;
                int x = (rand()%2)+1;
                while(x != 1){
                    ret_level++;
                    x = (rand()%2)+1;
                }
                return ret_level;
            }
            void place_node(Link* head, Node* to_insert, int level){
                if(level == 0){
                    to_insert->next = head->next;
                    to_insert->prev = head;
                    head->next->prev = to_insert;
                    head->next = to_insert; 
                }else{
                    Link* level_node = to_insert->all_levels[level];
                    level_node->next = head->next;
                    level_node->prev = head;
                    head->next->prev = level_node;
                    head->next = level_node;
                }   
            }
            bool keys_equal(const Key_T x, const Key_T y) const{
                if(!(x < y) && !(y<x)){
                    return true;
                }
                return false;
            }
            bool mapped_equal(Mapped_T x, Mapped_T y){
                if(x==y){
                    return true;
                }
                return false;
            }
            void append_level(Link* link, int level){
                Link* sentinel_level = sentinel->all_levels[level];
                Link* link_level = link->all_levels[level];
                link_level->prev = sentinel_level->prev;
                link_level->next = sentinel_level; 
                sentinel_level->prev->next = link_level;
                sentinel_level->prev = link_level;
            }
            void append(Link* link){
                for(int i=0; i<link->all_levels.size();i++){
                    append_level(link, i);
                }
            }
        };
}
