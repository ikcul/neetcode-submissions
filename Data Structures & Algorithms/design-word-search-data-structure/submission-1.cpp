class WordDictionary {
private:
    struct TrieNode{
        bool endOfWord;
        TrieNode* characters[26];

        TrieNode(){
            endOfWord = false;
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
            int idx = c - 'a';
            if (!curr->characters[idx]){
                curr->characters[idx] = new TrieNode();
            }
            curr = curr->characters[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        //ts needs a dfs in order to be solved as when we encounter a . we must iteratete through all possible branches that form from the .->children
        return dfs(root, 0, word);
    }
    bool dfs(TrieNode* root, int i, string word){
        TrieNode* curr = root;
        for (int j = i; j < word.length(); j++){
            if (word[j] == '.'){
                for (TrieNode* node : curr->characters){
                    if (node != nullptr && dfs(node, j + 1, word)){
                        return true;
                    }
                }
                return false;
            }else{
                int idx = word[j] - 'a';
                if (!curr->characters[idx]){
                    return false;
                }
                curr = curr->characters[idx];
            }
        }
        return curr->endOfWord;
    }
};
