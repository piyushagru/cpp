// TLE SOLUTION
// class Solution {
// public:
//     static bool comp(vector<int> a,vector<int> b){
//              if(a[0] == b[0]) 
//                 return a[0] < b[0];  
//         else return a[1] < b[1];
//     }
//     int maxEvents(vector<vector<int>>& events) {
//         if(events.empty())return 0;
//         sort(events.begin(), events.end(), comp);{
//         vector<bool> dp(events.size()+1,false);
        
//         for(int event = 0; event<events.size(); event++){
//             for(int day = events[event][0]; day<=events[event][1]; day++){
//                 if(dp[day] == false)  
//                     dp[day] = true;    
//             }
//         }

//         int cnt = 0;
//         for(auto it : dp){
//             if(it == true)cnt++;
//         }
//         return cnt;
//     }
// };

//still need practice on this -> kafi dikkat aai thi samajhne main
class Solution {
public:
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
       priority_queue<int,vector<int>, greater<int> >event;
        int i = 0;//current_event
        int n = events.size();
        int res = 0;
        for(int d = 1; d<=100000;d++){
            while(!event.empty() and event.top() < d)
                event.pop();
            while(i<n and events[i][0] == d)
                event.push(events[i++][1]);
            if (event.size()) {
                event.pop();
                ++res;
            }
            
        }
    return res;
    }
};