#include <stdio.h>
#include <stdlib.h>
#include "Map.hpp"

using namespace std;

template <template <typename, typename> class MAP_T>
void
traverse(const MAP_T<int, int> &m, int level) {
	for (auto it = m.begin(); it != m.end(); ++it) {
		//it->second = 1;
		if (level != 0) {
			traverse(m, level - 1);
		}
	}
}
//Display Functions

template < template <typename, typename> class MAP_T>
void display_list(const MAP_T<int,int>& map){
	cout<<"Map: ";
	for (auto it = map.begin(); it != map.end(); ++it) {
		cout<<"("<<(*it).first<<" , "<<(*it).second<<") ";
	}
	cout<<endl;
}

int main(){
	cs540::Map <int,int> map;
	auto p1_it = map.insert(std::make_pair(1, 1));
	map.insert(std::make_pair(2, 2));
	map.insert(std::make_pair(3, 3));
	map.insert(std::make_pair(4, 4));

	cout<<"----------------------"<<endl;
	cout<<"MAP INTIALIZATION TEST"<<endl;
	cout<<"Original Map| ";
	display_list(map);

	cout<<"----------------------"<<endl;
	cout<<"COPY CONSTRUCTOR TEST"<<endl;
	cs540::Map <int,int> copy(map);
	cout<<"Copied Map| ";
	display_list(copy);
	assert(map==copy);

	cout<<"----------------------"<<endl;
	cout<<"AT TEST"<<endl;
	cout<<"At index 1: "<<map.at(1)<<endl;
	assert(map.at(1) == 1);
	cout<<"At index 4: "<<map.at(4)<<endl;
	assert(map.at(4) == 4);

	cout<<"----------------------"<<endl;
	cout<<"BEGIN & END"<<endl;
	auto it = map.begin();
	cout<<"Key at begin: "<<it->first<<endl;
	cout<<"Value at begin: "<<it->second<<endl;
	auto it2 = map.end()--;
	cout<<"Key at end: "<<it2->first<<endl;
	cout<<"Value at end: "<<it2->second<<endl;

	cout<<"----------------------"<<endl;
	cout<<"EDIT VALUES"<<endl;
	cout<<"New first element: ("<<1<<","<<"9)"<<endl;
	it->second = 9;
	cout<<"New last element: ("<<4<<","<<"9)"<<endl;
	it2->second = 9;
	display_list(map);
	assert((*map.begin()).first == 1 && (*map.begin()).second == 9);
	assert(map.at(1) == 9);
	assert((*map.end()--).first == 4 && (*map.end()--).second == 9);
	assert(map.at(4) == 9);

	cout<<"----------------------"<<endl;
	cout<<"COPY CONSTRUCTOR"<<endl;
	cout<<"Before copy constructor: ";
	display_list(map);
	cs540::Map<int,int> z(map);
	cout<<"After copy constructor: ";
	display_list(z);
	assert(map == z);

	cout<<"----------------------"<<endl;
	cout<<"ASSIGNMENT"<<endl;
	cout<<"Original: ";
	display_list(map);
	cs540::Map<int, int> n_map;
	n_map = map;
	cout<<"Copy: ";
	display_list(n_map);
	assert(n_map == map);

	cout<<"Before self assignment: ";
	display_list(map);
	cs540::Map<int,int> temp;
	temp = map;
	map = map;
	cout<<"After self assignment: ";
	display_list(map);
	assert(temp == map);

	cout<<"----------------------"<<endl;
	cout<<"INITIALIZER LIST CONSTRUCTION"<<endl;
	cs540::Map<int,int> map2{{14,14}, {24,24}};
	display_list(map2);
	assert((*map2.begin()).first == 14);
	assert((*map2.end()--).first == 24);

	cout<<"----------------------"<<endl;
	cout<<"ITERATOR INSERT"<<endl;
	cs540::Map<int,int> map3;
	vector<pair<int,int>> vec = {{3,3},{4,4},{5,5},{6,6},{7,7},{8,8}};
	map3.insert(vec.begin(),vec.end());
	display_list(map3);
	assert((*map3.begin()).first == 3);
	assert((*map3.end()--).first == 8);
	cs540::Map<int, int> map3_cat{{1,1},{2,2}};
	map3_cat.insert(vec.begin(),vec.end());
	display_list(map3_cat);
	assert((*map3_cat.begin()).first == 1);
	assert((*map3_cat.end()--).first == 8);


	cout<<"----------------------"<<endl;
	cout<<"INDEXING"<<endl;
	cs540::Map<int,int> x;
	x[12] = 12;
	x[13] = 13;
	display_list(x);
	assert((*x.begin()).second == 12);
	assert((*x.begin()++).second == 13);
	x[12] = 99;
	x[13] = 99;
	assert((*x.begin()).second == 99);
	assert((*x.begin()++).second == 99);
	display_list(x);

	cout<<"----------------------"<<endl;
	cout<<"INCREMENTING"<<endl;
	cs540::Map<int,int> map4 = {{1,1},{2,2},{3,3},{4,4}};
	for (auto it = map4.begin(); it != map3.end(); ++it) {
		cout<<(*it).first<<" || "<<(*it).second<<endl;
	}
	cout<<"DECREMENTING"<<endl;
	for (auto it = map4.end()--; it != map4.begin()--; it--) {
		cout<<(*it).first<<" || "<<(*it).second<<endl;
	}

	cout<<"REVERSE_IT INCREMENTING"<<endl;
	for (auto it = map4.rbegin(); it != map4.rend(); it++) {
		cout<<(*it).first<<" || "<<(*it).second<<endl;
	}
	cout<<"REVERSE_IT DECREMENTING"<<endl;
	for (auto it = map4.rend()--; it != map4.rbegin()--; it--) {
		cout<<(*it).first<<" || "<<(*it).second<<endl;
	}
	map4 = map3;
	assert(map4 == map3);
	
	cout<<"----------------------"<<endl;
	cout<<"SIZE AND EMPTY TESTS"<<endl;
	cs540::Map<int,int> size_test;
	cout<<"Size of map: "<<size_test.size()<<endl;
	assert(size_test.size() == 0);
	cout<<"Is map empty: "<<size_test.empty()<<endl;
	assert(size_test.empty());
	size_test.insert(make_pair(33,33));
	cout<<"Size of map after insert: "<<size_test.size()<<endl;
	assert(size_test.size() == 1);
	cout<<"Is map empty after insert: "<<size_test.empty()<<endl;
	assert(!size_test.empty());

	cout<<"----------------------"<<endl;
	cout<<"ERASE TEST"<<endl;
	cs540::Map <int,int> erase_map;
	erase_map.insert(std::make_pair(1, 1));
	erase_map.insert(std::make_pair(2, 2));
	erase_map.insert(std::make_pair(3, 3));
	erase_map.insert(std::make_pair(4, 4));

	cout<<"Before erase: "<<endl;
	display_list(erase_map);

	cout<<"After erase for key 1 and key 2: "<<endl;
	erase_map.erase(1);
	erase_map.erase(2);
	display_list(erase_map);
	assert((*erase_map.begin()).first == 3);

	cout<<"After erase for beginning iterator: "<<endl;
	erase_map.erase(erase_map.begin());
	display_list(erase_map);
	assert((*erase_map.begin()).first == 4);

	cout<<"----------------------"<<endl;
	cout<<"CLEAR TEST"<<endl;
	cs540::Map<int,int> clear_map{{111,111},{222,222},{333,333},{444,444}};
	cout<<"Before Clear: ";
	display_list(clear_map);
	clear_map.clear();
	cout<<"After Clear: ";
	display_list(clear_map);
	assert(clear_map.empty());

	cout<<"----------------------"<<endl;
	cout<<"DEREFERENCING"<<endl;
	cs540::Map<int,int> deref_map{{100,100},{200,200},{300,300},{400,400}};
	auto it3 = deref_map.begin();
	it3++;
	it3++;
	cout<<"3rd element: ("<<(*it3).first<<","<<(*it3).second<<")"<<endl;
	auto it4 = deref_map.end();
	it4--;
	it4--;
	cout<<"3rd element: ("<<(*it4).first<<","<<(*it4).second<<")"<<endl;
	assert((*it3).first == 300);
	assert((*it4).first == 300);
	assert(it3 == it4);

	cout<<"----------------------"<<endl;
	cout<<"COMPARATORS"<<endl;
	cs540::Map<int,int> m1{{1,1},{2,2}};
	cs540::Map<int,int> m2{{2,2},{3,3}};
	cs540::Map<int,int> m3{{1,1}};
	cs540::Map<int,int> same{{1,1},{2,2}};

	assert(m1 != m2);
	assert(m1 < m2);
	assert(m3 != m2);
	assert(m3 < m2);
	assert(m1 == same);
}
