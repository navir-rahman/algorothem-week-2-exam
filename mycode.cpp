// //dsf code
// #include <bits/stdc++.h>
// using namespace std;
//     const int BN=1005;
//     vector<int> arr[BN];
    
//     bool visited[BN];



//     void dfs(int root)
//     {
//         // cout<<root<<" " << endl; // will show all the node
//         visited[root]=true;
//         for(int v:arr[root])
//         {

//             if(!visited[v])
//             dfs(v);
//             cout<< root<< " and child node "<<v<<" "<<endl; // will show child not the root
//         }
//     }

// int main(){
//     int n,e;
//     cin>>n>>e;
//     for (int i = 0; i < e; i++)
//     {
//         int n1,n2;
//         cin>>n1>>n2;
//         arr[n1].push_back(n2);
//     }
    
//     int cc=0;
//     for (int i = 1; i <= BN; i++)
//     {
//         if(visited[i]) continue;
//         dfs(i);
//         cc++;
//         cout<<endl;
        
//     }
//     cout<<endl<<cc;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

    const int BN=1005;
    vector<int> arr[BN];
    bool visited[BN];

int track[BN];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while (!q.empty())
    {

        int u =q.front();
        q.pop();
        // section 1
        for(auto v:arr[u])
        {
            // section 2
            if(visited[v]== true) continue;
            q.push(v);
            visited[v]=true;
            
        cout<<"root "<<s<<" "  ;
            cout<<" child "<<v<<endl;
            track[s]++;
            // section 3
        }
        // section 4
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
    }

    for (int i = 0; i <= n; i++)
    {
        bfs(i);


    }



//     int arr2[5]={0};
//    for (size_t i = 0; i < 5; i++)
//    {
//     arr2[i]++;
//     /* code */
//    }
   
    for (size_t i = 0; i < BN; i++)
    {
        if(track[i]!=0)
        cout<<track[i]<<" ";
    }
    
    return 0;
}