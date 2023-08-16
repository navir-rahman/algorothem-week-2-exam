

#include <bits/stdc++.h>
using namespace std;
const int E = 1e5 + 5;
vector<int> adj[E];
bool visited[E];

int height[E];
int depth[E];
int distence[E];
// void dfs(int root)
// {
//     visited[root] = true;
//     for (int v : adj[root])
//     {
//         if (!visited[v])
//         {
//             depth[v]=depth[root]+1;
//             dfs(v);
//             height[root]=max(height[v]+1,height[root]);
//         }
//     }
// }

void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root]=true;

    distence[root]=0;
    while (!q.empty())
    {
        int u =q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(visited[v]== true) continue;
            q.push(v);
                visited[v] = true;
                distence[v] = distence[u] + 1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // dfs(0);

    int x;
    cin >> x;


    for (int i = 0; i < x; i++)
    {
        memset(distence, -1, sizeof(distence));
        memset(visited, 0, sizeof(visited));
        int a,b;
        cin>>a>>b;
        bfs(a);
        cout<<distence[b]<<endl;
    }
    
    

    return 0;
}
