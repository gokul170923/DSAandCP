class TrieNode{
public:
    TrieNode * arr[2];
    int end ,prefix;
    TrieNode(){
        arr[0] = arr[1] = nullptr;
        end = 0;
        prefix = 0;
    }
};

class Trie{
public:
    TrieNode * root, *itr ;
    Trie(){
        root = new TrieNode();
    }
    void insert(int n){
        itr = root;
        for(int i=31;i>=0;i--){
            int in = (n>>i)&1;
            if(!itr->arr[in]) itr->arr[in] = new TrieNode(); 
            itr = itr->arr[in];
            itr->prefix++;
        }
        itr->end++;
    }
    int findmaxi(int x){
        itr = root;
        int ans =0;
        for(int i=31;i>=0;i--){
            int in = (x>>i)&1;
            if(!itr->arr[!in]){
                itr = itr->arr[in];
            }
            else{
                ans = ans | (1<<i);
                itr = itr->arr[!in];
            }
        }
        return ans;
    }
    
    TrieNode * delrecc(int n,int bit,TrieNode * node){
        if(!node) return nullptr;
        node->arr[(n>>bit)&1] = delrecc(n,bit-1,node->arr[(n>>bit)&1]);
        node->prefix--;
        if(bit==-1) node->end--;
        if(node->prefix==0){
                delete node;
                return nullptr;
        }
        else return node;
    }

    void erase(int n){
        root->arr[(n>>31)&1] = delrecc(n,30,root->arr[(n>>31)&1]);
    }
};