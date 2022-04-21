class MyHashSet {
private:
    int hashmap[1000001];
public:
    MyHashSet() {
        memset(hashmap, 0, sizeof(hashmap));
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