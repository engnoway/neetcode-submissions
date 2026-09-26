class TriNode{
    public:
unordered_map<char,TriNode*>child;
bool endword=false;
};
class PrefixTree {
public:
 TriNode *root;
    PrefixTree() {
         root = new TriNode();
    }
    
    void insert(string word) {
        TriNode *curr=root;
        for(auto ch:word){
            if(curr->child.count(ch)==0){
                curr->child[ch]=new TriNode();
            }
            curr=curr->child[ch];
        }
        curr->endword=true;
    }
    
    bool search(string word) {
        TriNode *curr=root;
        for(auto ch:word){
            if(curr->child.count(ch)==0){
                return false;
            }
            curr=curr->child[ch];
        }
        return curr->endword;
    }
    
    bool startsWith(string prefix) {
        TriNode *curr=root;
        for(auto ch:prefix){
            if(curr->child.count(ch)==0){
                return false;
            }
            curr=curr->child[ch];
        }
        return true;
    }
};
