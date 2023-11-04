#include<iostream>
#include<vector>

using namespace std;

void ssp(vector<pair<int,int>> g, int v){
    vector<int> dist(v,INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < v-1; i++)
    {
        for(int j = 0 ; j < v ; j++){
            for (auto x : g)
            {
                int u,v,w;
                u = j;
                v = x.first;
                w = x.second;
                if (dist[u] != INT_MAX && dist[u]+w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
                

            }
            
        }
    }
    
}

int main( )
  {
    vector<pair<int,int>> g [6];
    for (int i = 0; i < 6; i++)
    {
        int u,v,w;
        cout<<"enter uvw\n";
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
    }
    
return 0 ;
}