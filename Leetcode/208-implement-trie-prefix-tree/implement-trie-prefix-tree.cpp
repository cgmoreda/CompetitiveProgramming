
struct Node{
    map<char,Node*> next;
    bool has;
};
class Trie {
    Node* head;
public:
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* nd = head;
        for(auto &i:word)
        {
            if(!nd->next.count(i)){
                Node* newNode = new Node();
                nd->next[i] = newNode;
            }
            nd = nd->next[i];
        }
        nd->has = true;
    }
    
    bool search(string word) {
        Node* nd = head;
        for(auto &i:word)
        {
            if(!nd->next.count(i)){
                return false;
            }
            nd = nd->next[i];
        }
        return nd->has;
    }
    
    bool startsWith(string prefix) {
         Node* nd = head;
        for(auto &i:prefix)
        {
            if(!nd->next.count(i)){
                return false;
            }
            nd = nd->next[i];
        }
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