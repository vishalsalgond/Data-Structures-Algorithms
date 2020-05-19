//https://leetcode.com/problems/lru-cache/submissions/

class LRUCache {
public:
    unordered_map <int,int> m1; //to store key value pairs
    unordered_map <int,list<int>::iterator> m2; //to store address of nodes
    int cap;
    list <int> l; //doubly linked-list
    
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        //if not found return -1
        if(m1.find(key)==m1.end()) return -1;
        
        //if found, delete the node containing that key
        //now push the same key to the front of list
        l.erase(m2[key]);
        l.push_front(key);
        
        //update the address of key in m2
        m2[key] = l.begin();
        
        return m1[key];
        
    }
    
    void put(int key, int value) {
        
        //if the key is not already present in list
        //then create space to add new key in list
        if(m1.find(key) == m1.end()){
            if(m1.size() == cap){
                int back = l.back();
                //remove least recently used node
                l.pop_back();
                //also erase it from the hashmap
                m1.erase(back);
            }
        }
        //if the key is already present in list
        //then first delete the node containing that node
        else{
            l.erase(m2[key]);   
        }
        
        //push the key to front of the node
        l.push_front(key);
        //add the value of key
        m1[key] = value;
        //add or update the address of key in m2
        m2[key] = l.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
