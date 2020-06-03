class Solution {
public:
    static bool comp(const vector<int> a, const vector<int> b){
        return (a[1]-a[0])>(b[1]-b[0]);       
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int res = 0;

        sort(costs.begin(),costs.end(),comp);

        for(int i=0;i<n;i++){
            res += costs[i][0];   
        }
        for(int i=n;i<2*n;i++){
            res += costs[i][1];
            cout<<costs[i][0]<<" ";
        }
    return res;
    }
};