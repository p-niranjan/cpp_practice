//https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
private:
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }    
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            if(!stk.empty()) {
                char last = stk.top();
                char cur = c;
                if(isPair(last, cur)) {
                    stk.pop();
                    continue;
                }                
            }
            stk.push(c);
        }
        return stk.empty();
    }
};