class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        int count, bestPrefixLength;
        bool isEndOfWord;
        TrieNode() : count(0), bestPrefixLength(-1), isEndOfWord(false) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int totalWords = words.size();
        vector<int> result(totalWords, 0);
        if (totalWords - 1 < k) return result;
        root = new TrieNode();
        for (const string &word : words) {
            //insert the word with increasing the count by 1 (prefix count)
            updateTrie(word, 1, k);
        }
        for (int i = 0; i < totalWords; i++){
            //temp deletion of the word with count decreased by 1
            updateTrie(words[i], -1, k);
            result[i] = root->bestPrefixLength;
            //re-insertion of the word
            updateTrie(words[i], 1, k);
        }
        return result;
    }
    
private:
    void updateTrie(const string &word, int delta, int k) {
        int wordLength = word.size();
        //used to store the path used during trie travesal to update the count and use the count
        vector<TrieNode*> nodePath(wordLength + 1, nullptr);
        vector<int> depths(wordLength + 1, 0);
        nodePath[0] = root;
        depths[0] = 0;
        //trie insertion
        for (int i = 0; i < wordLength; i++) {
            int letterIndex = word[i] - 'a';
            if (nodePath[i]->children[letterIndex] == nullptr) {
                nodePath[i]->children[letterIndex] = new TrieNode();
            }
            nodePath[i + 1] = nodePath[i]->children[letterIndex];
            depths[i + 1] = depths[i] + 1;
        }
        //increase the count of each prefix 
        for (TrieNode* node : nodePath) {
            node->count += delta;
        }
        //find the best prefix
        for (int i = wordLength; i >= 0; i--) {
            TrieNode* currentNode = nodePath[i];
            int candidate = (currentNode->count >= k ? depths[i] : -1);
            for (int j = 0; j < 26; j++) {
                TrieNode* childNode = currentNode->children[j];
                if (childNode != nullptr) {
                    candidate = max(candidate, childNode->bestPrefixLength);
                }
            }
            currentNode->bestPrefixLength = candidate;
        }
    }
};
