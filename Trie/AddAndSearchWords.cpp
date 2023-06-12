// LC 211
// Design a data structure that supports adding new words and finding if a string 
// matches any previously added string.

// Implement the WordDictionary class:
// WordDictionary() 
// Initializes the object.
// void addWord(word) 
// Adds word to the data structure, it can be matched later.
// bool search(word) 
// Returns true if there is any string in the data structure that matches word or false otherwise. 
// word may contain dots '.' where dots can be matched with any letter.

#include <string>
#include <vector>

struct TrieNode {
    std::vector<TrieNode *> children = std::vector<TrieNode *> (26, nullptr);
    bool isTerminal = false;
};

class WordDictionary {
public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(std::string word) {
        auto node = root;
        for (auto letter : word) {
            int idx = letter - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }

        node->isTerminal = true;
    }

    bool search(std::string word) {
        auto node = root;
        return searchInWord(0, word, node);
    }

private:
    TrieNode* root;

    bool searchInWord(int idx, std::string& word, TrieNode* node) {
        // Base Case
        if (nullptr == node) {
            return false;
        }

        if (idx == word.size()) {
            return true;
        }

        // Recursive Case
        if (auto letter = word[idx]; letter != '.') {
            node = node->children[letter - 'a'];
            return searchInWord(idx + 1, word, node);
        }

        for (int i = 0; i < 26; ++i) {
            if (searchInWord(idx + 1, word, node->children[i])) {
                return true;
            }
        }

        return false;
    }
};