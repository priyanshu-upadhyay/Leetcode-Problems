class MyHashMap {
private:
    struct ListNode
    {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };
    
    int getHashValue(int key)
    {
        return key%size;
    }
    
    vector<ListNode*> hashTable;
    int size;
    
public:
    MyHashMap() {
        size = 5000;
        hashTable = vector<ListNode*> (size, NULL);
    }
        
    void put(int key, int value) {
        int hashValue = getHashValue(key);
        
        ListNode* curr = hashTable[hashValue];
        ListNode* pre = NULL; // Helpful in Insertion, if Not Found.
        while(curr != NULL)
        {
            if(curr->key == key)
            {
                curr->value = value;
                return;
            }
            pre = curr;
            curr = curr->next;
        }
        
        ListNode* newnode = new ListNode(key, value);
        if(pre == NULL)
        {
            hashTable[hashValue] = newnode;
        }
        else
        {
            pre->next = newnode;
            newnode->prev = pre;
        }
        
    }
    
    int get(int key) {
        int hashValue = getHashValue(key);
        ListNode* curr = hashTable[hashValue];
        while(curr != NULL)
        {
            if(curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = getHashValue(key);
        ListNode* curr = hashTable[hashValue];
        while(curr != NULL)
        {
            if(curr->key == key)
            {
               if(curr == hashTable[hashValue])  // First Element
               {
                   hashTable[hashValue] = curr->next;
                   if(curr->next != NULL)
                   {
                       curr->next->prev = NULL;
                   }
               }
                else //  Delete Middle or Last Element
                {
                    if(curr->next != NULL)
                    {
                        curr->next->prev = curr->prev;
                    }
                    curr->prev->next = curr->next;
                }
            }
            curr = curr->next;
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */