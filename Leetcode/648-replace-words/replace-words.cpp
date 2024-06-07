
struct Node {
    map<char, Node*> next;
    bool has;
};
class Trie {
    Node* head;

public:
    Trie() { head = new Node(); }

    void add(string word) {
        Node* nd = head;
        for (auto& i : word) {
            if (!nd->next.count(i)) {
                Node* newNode = new Node();
                nd->next[i] = newNode;
            }
            nd = nd->next[i];
        }
        nd->has = true;
    }

    int search(string word) {
        Node* nd = head;
        int j = 0;
        for (auto& i : word) {
            if (nd->has)
                return j;
            j++;
            if (!nd->next.count(i)) {
                return word.size();
            }
            nd = nd->next[i];
        }
        return j;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        Trie x;
        for (auto i : d)
            x.add(i);
        string ret, cur;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                cur = cur.substr(0, x.search(cur));
                ret += cur + ' ';
                cur = "";
            } else
                cur += s[i];
        }
        if (cur != "") {
            cur = cur.substr(0, x.search(cur));
            ret += cur + ' ';
        }
        if (ret.back() == ' ')
            ret.pop_back();
        return ret;
    }
};