#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {}

    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
            int key_to_del = m_list.back().first; 
            m_list.pop_back();            //remove node in list;
            m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cout << "cache.get(1) = " << cache.get(1) << endl;
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cout << "cache.get(2) = " << cache.get(2) << endl;
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cout << "cache.get(1) = " << cache.get(1) << endl;
    cache.get(3);       // returns 3
    cout << "cache.get(3) = " << cache.get(3) << endl;
    cache.get(4);       // returns 4
    cout << "cache.get(4) = " << cache.get(4) << endl;

    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}