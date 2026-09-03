class WordDictionary {
private:
    struct TrieNode{
        TrieNode* characters[26];
        bool end;

        TrieNode(){
            end = false;
            for (int i = 0; i < 26; i++){
                characters[i] = nullptr;
            }
        }
    };

    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int idx = c-'a';
            if (!curr->characters[idx]){
                curr->characters[idx] = new TrieNode();
            }
            curr = curr->characters[idx];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return dfs(root, 0, word);
    }

    bool dfs(TrieNode* root, int i, string word){
        TrieNode* curr = root;

        for (int j = i; j < word.length(); j++){
            char c = word[j];

            if (c == '.'){
                for (TrieNode* t : curr->characters){
                    if (t && dfs(t, j+1, word)){
                        return true;
                    }
                }
                return false;
            }else{
                int idx = c - 'a';
                if (!curr->characters[idx]){
                    return false;
                }
                curr = curr->characters[idx];
            }
        }
        return curr->end;
    }
};
