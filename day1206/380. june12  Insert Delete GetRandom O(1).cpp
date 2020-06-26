/*
https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/683165/Algorithm-Explained-or-O(1)-insert()-or-O(1)-delete-or-O(1)-getRandom()
https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/683138/ALGORITHM-EXPLAINED-video-clear-all-your-doubt-easy-solution
*/

class RandomizedSet {
    
public:
    unordered_map<int,int> map;
    vector<int> vlist;
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((int)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = map.find(val);
        if(it == map.end()){
            map.insert({val,vlist.size()});
                vlist.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = map.find(val);
        if(it == map.end()){
            return false; //not found returning false
        }
        int actual_idx = it->second;
        // take last index in  the list i.e. vlist.size()-1
        // and replace it with the actual_idx that we found
        vlist[actual_idx] = vlist[vlist.size()-1];
        //map mai bhi ye change kardo index value
        // matlab pehle dhunda ki ye value kaha hain map mai; then usko actual index se change kar diya
        map.find(vlist[actual_idx]) -> second = actual_idx;
        
        vlist.pop_back();
        map.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand()%vlist.size();
        return vlist[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */