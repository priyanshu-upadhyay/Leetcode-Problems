class MyHashSet {
private:
    vector<int> hashmap;
public:
    MyHashSet() {
        hashmap.resize(10e6);
    }
    
    void add(int key) {
        hashmap[key] = 1;
    }
    
    void remove(int key) {
        hashmap[key] = 0;
    }
    
    bool contains(int key) {
        if(hashmap[key] == 1) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */