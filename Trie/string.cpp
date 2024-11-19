
/************************************               CLASS base implementation  */

class TrieNode{
public:                    // node
    TrieNode * arr[26];
    int end , prefix = 0;
    TrieNode(){
        end = 0;
        prefix = 0;
        for(int i=0;i<26;i++) arr[i] = nullptr;
    }
};

class Trie{
public:
    TrieNode * root , *itr;
    Trie(){
        root = new TrieNode();
    }
                                // insert
    void insert(string &word){
        itr = root;
        for(char &i:word){
            if( !itr->arr[i-'a']) itr->arr[i-'a'] = new TrieNode();
            itr = itr->arr[i-'a'];
            itr->prefix++;
        }
        itr->end++;
    }
                                // find
    int find(string &word,bool pre = false){
        itr = root;
        for(char &i:word){
            if( !itr->arr[i-'a']) return 0;
            itr = itr->arr[i-'a'];
        }
        if(pre) return true; 
        return itr->end;   
    }
                                // prefix
    bool startsWith(string &prefix) {
        return find(prefix,true);
    }
                                // count prefix
    int countprefix(string &word){
        itr = root;
        for(char &i:word){
            if( !itr->arr[i-'a']) return 0;
            itr = itr->arr[i-'a'];
        } 
        return itr->prefix;
    }
                                // erase
    void erase(string &word){
        if(!find(word)) return;
        itr = root;
        for(char &i:word){
            itr = itr->arr[i-'a'];
            itr->prefix--;
        } 
        itr->end--;
    }
};
