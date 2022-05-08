class LRUCache {
private:
    list<int> linkedlist;
    unordered_map<int, list<int> :: iterator> address;
    unordered_map<int, int> key_value;
    int capacity;
    int curr_size = 0;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(address.find(key) == address.end()) return -1;
        linkedlist.erase(address[key]);
        linkedlist.push_front(key);
        address[key] = linkedlist.begin();
        return key_value[key];
    }
    
    void put(int key, int value) {
        /*
            1. Wo present ho pahle se
            2. Uska size bhar gya ho, to delete hoga
                nhi to simple dal jaayega usme
        */
        if(address.find(key) != address.end())
        {
            linkedlist.erase(address[key]);
            linkedlist.push_front(key);
            address[key] = linkedlist.begin();
            key_value[key] = value;
        }
        else
        {
            if(curr_size == capacity)
            {
                int last_element = linkedlist.back();
                linkedlist.erase(address[last_element]);
                address.erase(last_element);
                key_value.erase(last_element);
                curr_size--;
            }
            curr_size++;
            linkedlist.push_front(key);
            address[key] = linkedlist.begin();
            key_value[key] = value;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */