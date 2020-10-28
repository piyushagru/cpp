class LRUCache {
    int size;
    list<int> keys;
    unordered_map<int,pair<int,list<int>::iterator> > cache;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key].second = keys.begin();
            return cache[key].first;
        }
        return -1;
    }
   
        
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            keys.erase(cache[key].second);
            keys.push_front(key);
            // cache[key].second = keys.begin();
            cache[key] = {value,keys.begin()};
        }
        else{
            //key ni mili 
            if(keys.size() == size){
                cache.erase(keys.back());
                keys.pop_back();
            }
            
                keys.push_front(key);
                cache[key] = {value,keys.begin()};
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */