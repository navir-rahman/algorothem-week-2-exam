#include <bits/stdc++.h>
using namespace std;
const int E = 1e5+5;
vector<int> adj[E];
bool visited[E];
int level[E] = {-1};

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    level[s] = 0;
    while (!q.empty())
    {

        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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

    bfs(0);
    int L;
    cin >> L;
    if (L == 0)
    {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < E; i++)
    {
        if (level[i] == L)
        {
            cout << i << " ";
        }
        else if (L >= n)
        {
            cout << "-1";
            break;
        }
    }

    return 0;
}
