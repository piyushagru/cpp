//30 june
class Trie {
    Trie *children[26];
    bool isEndOfWord = true;
    
    //that completes the insertion of the word;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEndOfWord = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(char x : word){ 
            if(!(curr->children[x - 'a']))//if this node does not exit create it
                curr->children[x - 'a'] = new Trie;
            //increment the curr pointer to point to last letter of word
            curr = curr->children[x - 'a'];
        }
        //now when loop is executed whole word will be entered and
        //curr will be at the endof the word
        curr->isEndOfWord = true;
        
        //that completes the insertion of the word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        //mostly like the insertion part
        //return true if word is present
        //return false if word is not present
        Trie* curr = this;
        for(char x:word){//checking character of each word
            curr = curr->children[x - 'a']; 
            if(!curr)//if this node does not exit return false
                return false;
        }
        //if it does exit return true
        //but first check if its the end of the word or not
        
        if(curr -> isEndOfWord)
            return true;
        else return false;
        
        
        //return curr -> isEndOfWord;//i.e we check for full word
}
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //we do this if we need to check if a particular prefix
        //is present or not
        Trie* curr = this;
        for(char x:prefix){//checking character of each word
             curr = curr->children[x - 'a']; 
            if(!curr)//if this node does not exit return false
                return false;
        }
        //if it does exit return true
                
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */