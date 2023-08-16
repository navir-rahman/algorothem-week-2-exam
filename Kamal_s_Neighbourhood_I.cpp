#include <bits/stdc++.h>
using namespace std;
const int E=1e3+5;
vector<int> adj[E];
bool visited[E];
int level[E];
// void dfs(int u)
// {
//     visited[u]=true;
//     for(int v:adj[u])
//     {
//         if(visited[v]) continue;
//         dfs(v);
//     }
// }

int componentCount[E];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root]=true;

    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!visited[v]){
                q.push(v);
                level[v]=level[u]+1;
                // cout<<"parent "<<u<<" child "<<v<<endl;
                componentCount[u]++;
                visited[v]=true;
            }
        }
    }
    
}

int main(){

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }


    int x;
    cin>>x;
    bfs(x);
    cout<<componentCount[x];
    // for (int i = 1; i <=n; i++)
    // {
    //     if(visited[i]) continue;
    //     bfs(i);

    // }
    // for (size_t i = 0; i < E; i++)
    // {
    //     if(!visited[i]) continue;
    //     cout<<"level of "<<i<< " "<< level[i]<<endl;
    // }
    // cout<<level[x];
       
    
    return 0;
}