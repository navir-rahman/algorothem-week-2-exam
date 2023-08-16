

#include <bits/stdc++.h>
using namespace std;

    const int BN=1000;
    vector<int> arr[BN];
    bool visited[BN];

int track[BN];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    track[s]++;

    while (!q.empty())
    {

        int u =q.front();
        q.pop();
        for(auto v:arr[u])
        {
            if(visited[v]== true) continue;
            q.push(v);
            visited[v]=true;
            
            track[s]++;
        }
    }
    
}

int main(){
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        arr[n1].push_back(n2);
        arr[n2].push_back(n1);
    }

    for (int i = 0; i <= BN; i++)
    {
        bfs(i);
        // cout<<i<<" "<<endl;
    }


   sort(track, track + BN);
    for (size_t i = 1; i < BN; i++)
    {
        if(track[i]>1)
        cout<<track[i]<<" ";
    }
    
    return 0;
}
