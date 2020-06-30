//TLE solution
class Solution {
public:
    unordered_map<int,int> mp;
    int numSquares(int n) {
     if(n<4)
         return n;
        if(mp.count(n)>0)// != mp.end())
            return mp[n];
        int count = n;
        for(int i = 1;i*i<=n;i++){
            count = min(count, numSquares(n- i*i)+1);
        }
        mp[n] = count;
    return count;
    }
};


