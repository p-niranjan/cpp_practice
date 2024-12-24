// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    long long hoursTaken(vector<int>& piles, int rate) 
    {
        long long hours = 0;
        for(int pile : piles) 
        {
            hours += ceil((double)pile / (double)rate);
        }
        return hours;
    }

    int maxElement(vector<int>& piles)
    {
        int mx = piles[0];
        for(int pile : piles) mx = max(pile, mx);
        return mx;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = maxElement(piles);
        while(l <= r)
        {
            int mid = (l+r)/2;
            long long hours = hoursTaken(piles, mid);

            if (hours <= h) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};