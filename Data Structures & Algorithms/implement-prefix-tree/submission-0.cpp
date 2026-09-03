class PrefixTree {
private:
    struct TrieNode{
        TrieNode* characters[26];
        bool endOfWord;

        TrieNode(){
            endOfWord = false;
            for (int i = 0; i < 26; i++){
                characters[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int idx = c - 'a';
            if (!curr->characters[idx]){
                curr->characters[idx] = new TrieNode();
            }
            curr = curr->characters[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word){
            int idx = c - 'a';
            if (!curr->characters[idx]){
                return false;
            }
            curr = curr->characters[idx];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix){
            int idx = c - 'a';
            if (!curr->characters[idx]){
                return false;
            }
            curr = curr->characters[idx];
        }
        return true;

    }
};
