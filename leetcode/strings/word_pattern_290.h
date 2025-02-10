// https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWordMap;
        unordered_map<string, char> wordToCharMap;
        int i = 0;
        string word;
        stringstream ss(s);
        while(getline(ss, word, ' ')) {
            // if(i >= pattern.size()) return false;
            char ch = pattern[i];
            if(charToWordMap.count(ch) && charToWordMap[ch] != word)
                return false;
            if(wordToCharMap.count(word) && wordToCharMap[word] != ch)
                return false;

            wordToCharMap[word] = ch;
            charToWordMap[ch] = word;
            i++;
        }
        return i == pattern.size();
    }
};