using P = pair<string, int>;
struct compare
{
    bool operator()(P p1, P p2)
    {
        if(p1.second == p2.second)
            return p1.first > p2.first;

        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word : words) mp[word]++;
        priority_queue<P, vector<P>, compare> minHeap(mp.begin(), mp.end());
        vector<string> out;
        for(int i = 0; i < k; i++) {
            printf("top word: %s, freq: %d\n", minHeap.top().first.c_str(), minHeap.top().second);
            out.push_back(minHeap.top().first);
            minHeap.pop();
        }
        //reverse(out.begin(), out.end());
        return out;
    }
};