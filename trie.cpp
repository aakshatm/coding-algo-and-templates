class Trie {
    class Node{
        public: 
        vector<Node*> children; 
        bool isEnd; 

        Node(){
            children.resize(26, NULL);
            isEnd = false; 
        }
    };
    public:
    Node* root; 
    Trie() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* curr = root; 
        for (auto ch: word){
            // check if the child node exists or not
            // if not exists then create it
            if (curr->children[ch - 'a'] == NULL){
                curr -> children[ch - 'a'] = new Node();
            }
            curr = curr -> children[ch - 'a'];
        }
        curr->isEnd = true; 
    }
    
    bool search(string word) {
        Node* curr = root; 
        for (auto ch: word){
            // check if the child node exists or not
            // if not exists then create it
            if (curr->children[ch - 'a'] == NULL){
                return false; 
            }
            curr = curr -> children[ch - 'a'];
        }
        return curr -> isEnd; 
    }
    
    bool startsWith(string prefix) {
        Node* curr = root; 
        for (auto ch: prefix){
            // check if the child node exists or not
            // if not exists then create it
            if (curr->children[ch - 'a'] == NULL){
                return false; 
            }
            curr = curr -> children[ch - 'a'];
        }
        return true; 
    }
};
