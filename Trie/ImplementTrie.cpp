// LC 208
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently 
// store and retrieve keys in a dataset of strings. There are various applications of this data structure, 
// such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() 
// Initializes the trie object.
// void insert(String word) 
// Inserts the string word into the trie.
// boolean search(String word)
// Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) 
// Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

#include <string>
#include <vector>

struct TrieNode {
    std::vector<TrieNode *> children = std::vector<TrieNode *> (26, nullptr);
    bool isTerminal = false;
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}

    void insert(std::string word) {
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
        for (auto letter : word) {
            int idx = letter - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }

        return node->isTerminal;
    }

    bool startsWith(std::string prefix) {
        auto node = root;
        for (auto letter : prefix) {
            int idx = letter - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }

        return true;
    }

private:
    TrieNode* root;
};