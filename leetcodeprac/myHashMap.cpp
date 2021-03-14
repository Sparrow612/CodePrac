#include <vector>
#include <iostream> 
#include <utility>
#include <list>

using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int> > > items;
    static const int base = 1000;
    int hash(int key){
        return key%base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap(): items(base){

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        list<pair<int, int> >::iterator it = items[h].begin();
        while (it != items[h].end()){
            if (it->first == key){
                it->second = value;
                return;
            }
            it++;
        }
        pair<int, int> p;
        p.first = key;
        p.second = value;
        items[h].push_back(p);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        list<pair<int, int> >::iterator it = items[h].begin();
        while (it != items[h].end()){
            if (it->first == key){
                return it->second;
            }
            it++;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        list<pair<int, int> >::iterator it = items[h].begin();
        while (it != items[h].end()){
            if (it->first == key){
                items[h].erase(it);
                return;
            }
            it++;
        }
    }
};

