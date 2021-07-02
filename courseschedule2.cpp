https://leetcode.com/problems/course-schedule-ii/
//topological sort using kahns algorithm

class Solution {
public:
    bool kahnsalgo(vector<int> g[],vector<int> in,vector<int>& ans,int n){
        queue<int> q;
        int c=0;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                cout<<i<<" ";
                ans.push_back(i);
                c++;
            }     
        }
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto e:g[i]){
                in[e]--;
                if(in[e]==0){
                    cout<<e<<" ";
                    q.push(e);
                    c++;
                    ans.push_back(e);
                }
            }
        }
        return c==n;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> g[n];
        vector<int> in(n,0),ans;
        for(int i=0;i<p.size();i++){
            g[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        if(kahnsalgo(g,in,ans,n))
            return ans;
        return {};
    }
};
