/*
https://leetcode.com/problems/longest-duplicate-substring/discuss/694873/c%2B%2B-video-explanation-binary-search-rabin-carp-algorithm

https://www.youtube.com/watch?v=-N8uBVdSyf4

length = binary search
substring = hashing 
comparison = rabin karp method
*/

class Solution {
    vector<int> pow_er;
    string ret;
    int prime=19260817;
public:
    string algo(string &s,int &k){
        if(k==0) return "";
        long long int hashing=0;
        unordered_map<int,vector<int> > map_pair;
        for(int i=k-1;i>=0;i--){
            hashing=(hashing+(pow_er[k-1-i]*(s[i]-'a'+1))%prime)%prime;
        }
        int i=0,j=k-1;
        map_pair[hashing]=vector<int>(1,0);
        bool flag=0;
        while(j<s.size()-1){
            hashing=(hashing-((pow_er[k-1]*(s[i]-'a'+1))%prime)+prime)%prime;
            hashing=(hashing*101)%prime;
            i++;
            j++;
            hashing=(hashing%prime+((pow_er[0]*(s[j]-'a'+1))%prime))%prime;
            if(map_pair.find(hashing)!=map_pair.end()){
                int e = 0;
                for(auto idx:map_pair[hashing]){
                    if (strcmp((s.substr(idx,k)).data(), s.substr(i, k).data()) == 0) {
                    return s.substr(idx,k);
                    }
                    e = idx;
                }
                map_pair[hashing].push_back(i);
            }
            else{
                map_pair[hashing]=vector<int>(1,i);
            }
            
        }
        return "";
}
    string longestDupSubstring(string S) {
        pow_er.resize(S.size()+1);
        pow_er[0]=1;
        for(int i=1;i<=S.size();i++){
            pow_er[i]=(101*pow_er[i-1])%prime;
        }
        int s = 0; 
        int e = S.size();
        string ans="";
        while (s<=e){
            int mid = (s+e)/2;
            string val_id = algo(S,mid);
            if(val_id.size()>0){
                if(val_id.size()>ans.size()){
                    ans = val_id;
                }
                s = mid+1;
            }
            else
                e = mid-1;   
        }
        return ans;
    }
};
