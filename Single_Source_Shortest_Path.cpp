#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

const int sz = 10001;
vector<pair<int,int> > a[sz];
int dis[sz];
bool vis[sz] = {0};

void Dijkstra(int source, int n) {
    for(int i = 0; i < sz; i ++)
        dis[i] = INF;

    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,int> ,vector<pair<int,int>>, prioritize> pq;
    pq.push(make_pair(source,dis[source]=0));
    while(!pq.empty()){
        pair<int, int> curr = pq.top();
        pq.pop();
        int cv = curr.first, cw = curr.second;
        if(vis[cv])
            continue;
        vis[cv] = true;
        for(int i = 0; i < a[cv].size(); i ++)
            if(!vis[a[cv][i].first] && a[cv][i].second + cw < dis[a[cv][i].first])
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw)));
    }
}

int main()
{
    int n, m, x, y, w;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
    }

    int source;
    source = 1;
    Dijkstra(source, n);
    for(int i = 1; i <= n; i ++){
        dis[i]!=INF? cout << dis[i] << "\n" : cout << "-1\n";
    }
    return 0;
}
