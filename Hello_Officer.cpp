#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

const int sz = 2001;
vector<pair<int,int> > a[sz];
int dis[sz];

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
        for(int i = 0; i < a[cv].size(); i ++)
            if(a[cv][i].second + cw < dis[a[cv][i].first])
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw)));
    }
}

int main()
{
    int n, m, b, q, x, y, w;
    cin >> n >> m >> b >> q;
    for(int i = 0; i < m; i ++){
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
    }

    int source;
    source = b;

    for(int i = 0; i < q; i ++){
        cin >> w;
        Dijkstra(source, w);
        if(dis[w] != INF)
            cout << dis[w] << "\n";
        else
            cout << "-1\n";
    }
}
