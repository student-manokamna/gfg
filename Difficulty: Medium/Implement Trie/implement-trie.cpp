// User function template for C++
class Trie {
  public:
  Trie *child[26];
  bool isleaf;

    Trie() {
        // implement Trie
        isleaf=false;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }

    void insert(string &word) {
        // insert word into Trie
        Trie *node =this;
        for(auto c:word){
            int in=c-'a';
            if(!node->child[in]){
                Trie *newnd=new Trie();
                node->child[in]=newnd;
            }
            node=node->child[in];
        }
        node->isleaf=true;
        
    }

    bool search(string &word) {
        // search word in the Trie
        Trie *node=this;
        for(auto c:word){
            int i=c-'a';
           
                if(!node->child[i]) return false;
                node=node->child[i];
            }
        return node->isleaf;
        
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
         Trie *node=this;
        for(auto c:word){
            int i=c-'a';
           
                if(!node->child[i]) return false;
                node=node->child[i];
            }
        return true;
    }
};
