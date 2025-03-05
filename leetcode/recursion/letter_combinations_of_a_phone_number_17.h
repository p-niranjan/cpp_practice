//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150

vector<string> chars(10, "");
class Solution {
    void populateStrings() {
        chars[2] = "abc";
        chars[3] = "def";
        chars[4] = "ghi";
        chars[5] = "jkl";
        chars[6] = "mno";
        chars[7] = "pqrs";
        chars[8] = "tuv";
        chars[9] = "wxyz";
    }

    void helper(int idx, const string& digits, string &aux, vector<string>& out) {
        const int n = digits.size();
        if(idx == n) {
            out.push_back(aux);
            return;
        }
        const int index = digits[idx] - '0';
        string letters = chars[index];
        for(char letter : letters) {            
            aux.push_back(letter);
            helper(idx+1, digits, aux, out);
            aux.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(0 == digits.size()) return {};
        vector<string> out;
        populateStrings();
        string aux;
        helper(0, digits, aux, out);
        return out;
    }
};
