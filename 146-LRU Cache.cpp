class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity){
    }
    
    int get(int key) {
        if(m_map.find(key) != m_map.end()) {
            auto iter = m_map.find(key)->second;
            int val = iter->second;
            m_list.splice(m_list.begin(), m_list, iter);
            return val;
        } else
            return -1;
    }
    
    void put(int key, int value) {
        if(m_map.find(key) != m_map.end()) {
            auto iter = m_map.find(key)->second;
            iter->second = value;
            m_list.splice(m_list.begin(), m_list, iter);
            return;
        }
        if(m_map.size() == m_capacity) {
            int lru_key = m_list.back().first;
            m_map.erase(lru_key);
            m_list.pop_back();
        }
        m_list.push_front({key, value});
        m_map[key] = m_list.begin();
    }
    
private:
    list<pair<int,int>> m_list; // first is key, second is value
    unordered_map<int, list<pair<int,int>>::iterator> m_map;
        // first is key, second is iterator to m_list
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
