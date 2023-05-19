// LC 127
// A transformation sequence from word beginWord to word endWord using a dictionary wordList 
// is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of 
// words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        using WordSet = std::unordered_set<std::string>;
        WordSet dictionary(wordList.begin(), wordList.end());
        if (dictionary.count(endWord) == 0) {
            return false;
        }

        WordSet startSet, endSet;
        startSet.emplace(beginWord);
        endSet.emplace(endWord);

        int ladder = 0;
        while (!startSet.empty() && !endSet.empty()) {
            ++ladder;

            if (startSet.size() > endSet.size()) {
                std::swap(startSet, endSet);
            }

            WordSet tmp;
            for (auto word : startSet) {
                for (auto i = 0; i < word.size(); ++i) {
                    auto curr = word[i];
                    for (int c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;

                        if (endSet.find(word) != endSet.end()) {
                            return ++ladder;
                        }

                        if (dictionary.find(word) == dictionary.end()) {
                            continue;
                        }

                        tmp.emplace(word);
                        dictionary.erase(word);
                    }

                    word[i] = curr;
                }
            }

            startSet = tmp;
        }

        return ladder;
    }
};