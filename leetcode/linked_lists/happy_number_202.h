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
        int slow = n, fast = nextNumber(n);
        while(fast != 1 && slow != fast) {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return fast == 1;
    }
};

