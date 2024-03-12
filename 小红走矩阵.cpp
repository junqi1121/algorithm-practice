#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
#include<string>
using namespace std;
const int N  = 1010,M = 1010;
typedef pair<int,int> PII;
int n,m;
int a[N][M];
int ans = -1;
int h[2*N*M],ne[2*N*M],e[2*N*M],idx;
int dist[N*M];
bool st[N*M];
void add(int x,int y,int pp,int qq)
{
    int p1 = (x-1)*n+y, p2 = (pp-1)*n+qq;
    e[idx] = p2;
    ne[idx] = h[p1];
    h[p1] = idx++;
    e[idx] = p1;
    ne[idx] = h[p2];
    h[p2] = idx++;
}
int dijkstra()
{
    memset(dist ,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second,distance = t.first;
        
        if(st[ver]) continue;
        
        st[ver] = true;
        
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j= e[i];
            if(dist[j]>distance+1)
            {
                dist[j] = distance+1;
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[6]==0x3f3f3f3f) return -1;
    return dist[6];
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i <= n; i++)
    {
        string s;
        cin>>s;
        for(int j = 1;j <= m;j++)
            a[i][j] = s[j-1];
    }
        
    memset(h,-1,sizeof h);
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
        	 
            if(j+1 <= m && a[i][j+1] != a[i][j])
            {
                add(i,j,i,j+1);
            }
            if(i+1 <= n && a[i+1][j] != a[i][j])
            {
                add(i,j,i+1,j);
            }
        }
    }
    
    cout<<dijkstra();;
    return 0;
}
