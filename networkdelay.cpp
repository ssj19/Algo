//Dijkstra algorithm to find shortest path to visit all the nodes
class Solution {
public:
    int c=0;
    unordered_map<string,int> u;
    void bfs(vector<vector<int>> g,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& q,int k,vector<bool>& vis){
        
        while(!q.empty()){
            pair<int,int> p=q.top();
            q.pop();
            if(vis[p.second])
                continue;
            vis[p.second]=true;
            // c=c+p.first;
            c=p.first;
            for(auto j:g[p.second]){
                
                q.push({p.first+u[to_string(p.second)+' '+to_string(j)],j});
                // cout<<j<<" "<<p.first+u[to_string(k)+' '+to_string(j)];
            }
            
        }
        return ;
    }
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool> vis(n+1,false);
        int h=t.size();
        vector<vector<int>> g(n+1);
        for(int i=0;i<h;i++){
            g[t[i][0]].push_back(t[i][1]);
            u.insert({to_string(t[i][0])+' '+to_string(t[i][1]),t[i][2]});
        }
        vis[k]=true;
        for(auto i:g[k]){
            q.push({u[to_string(k)+' '+to_string(i)],i});
        }
        // q.push()
        bfs(g,q,k,vis);
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                cout<<i<<" ";
                 return -1;
            }
               
        }
        return c;
    }
};
