//https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    int nextNumber(int n) {
        int num = 0;
        while(n) {
            int lastDigit = n%10;
            num += lastDigit*lastDigit;
            n = n/10;
        }
        return num;
    }    
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1 && !s.count(n)) {
            s.insert(n);
            n = nextNumber(n);
        }
        return n == 1;
    }
};

