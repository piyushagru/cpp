class Solution {
public:
    bool dfs(vector<vector<int> > &adj, vector<int> &visited, int v){
        if(visited[v] == 1) return false;
        if(visited[v] == 2) return true;
        visited[v] = 1;
        for(auto x:adj[v]){
            if(!dfs(adj,visited,x))
                return false;
        }
        visited[v] = 2;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& A) {
        vector<vector<int> > adj(n,vector<int>());
        for(auto x:A){
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0 and !dfs(adj,visited,i)){
                return false;
            }
        }
        return true;
    }
};