#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int>vis;

void func(int s,vector<int>&dist,vector<int>&par){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        auto temp=q.top();
        q.pop();
        int d=temp.first;
        int node = temp.second;
        for(auto child:adj[node]){
            if(d+child.second<dist[child.first]){
                dist[child.first]=d+child.second;
                par[child.first]=node;
                q.push({dist[child.first],child.first});
            }   
        }
    }
}


int main() {
    
    int n,m,s;
    cin >> n >> m >> s;
    adj.resize(n);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vis.resize(n);
    vector<int>dist(n,INT_MAX);
    vector<int>par(n,-1);
    func(s,dist,par);
    for(int i=0;i<n;++i){
        if(dist[i]==INT_MAX){
            cout << "INFINITY" << " ";
        }
        else{
            cout << dist[i] << " ";
        }
    }
    cout << "\n";
    for(int i=0;i<n;++i){
        if(dist[i]==INT_MAX){
            continue;
        }
        vector<int>path;
        int p=i;
        while(p!=-1){
            path.push_back(p);
            p=par[p];
        }
        cout << s << "-" << i << ": ";
        for(int i=path.size()-1;i>=0;--i){
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
