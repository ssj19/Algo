//problem statement is reduced to checking cycle present or not in a directed graph
//https://leetcode.com/problems/course-schedule-i/

class Solution {
public:
    bool iscycle(vector<int> p[],vector<bool>& vis,int src,vector<bool> rev){
        vis[src]=true;
        rev[src]=true;
        
        for(auto i:p[src]){
            if(!vis[i] && iscycle(p,vis,i,rev)){
                return true;
            }
            else if(rev[i])
                return true;
        }
        rev[src]=false;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> g[n];

        for (int i = 0; i < p.size(); i++)
        {
            g[p[i][1]].push_back(p[i][0]);
        }
        vector<bool> vis(n,0);
        vector<bool> rev(n,0);
        for(int i=0;i<n;i++){
            // cout<<vis[i]<<" "<<i<<" ";
            if(!vis[i] && iscycle(g,vis,i,rev)){
                return false;
            }
        }
        return true;
    }
};
