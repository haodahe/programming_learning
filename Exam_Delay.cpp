#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

const int sz = 1001;
vector<pair<int,double> > a[sz];
double dis[sz];

void Dijkstra(int source, int n, int level[]) {
    for(int i = 0; i < sz; i ++)
        dis[i] = INF;

    class prioritize{public: bool operator ()(pair<int, double>&p1 ,pair<int, double>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,double> ,vector<pair<int,double>>, prioritize> pq;
    pq.push(make_pair(source,dis[source] = 0.0));
    while(!pq.empty()){
        pair<int, double> curr = pq.top();
        pq.pop();
        int cv = curr.first;
        double cw = curr.second;
        for(int i = 0; i < a[cv].size(); i ++){
            if(a[cv][i].second + cw < dis[a[cv][i].first]){
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first] = a[cv][i].second + cw)));
                level[a[cv][i].first] = level[cv] + 1;
            }
            if(a[cv][i].second + cw == dis[a[cv][i].first] && level[a[cv][i].first] > level[cv] + 1){
                level[a[cv][i].first] = level[cv] + 1;
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    double aa, b, w;

    cin >> n >> m;

    int level[n + 1] = {};

    for(int i = 0; i < m; i ++){
        cin >> x >> y >> aa >> b;
        w = aa / b;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
    }

    int source;
    source = 1;
    Dijkstra(source, n, level);

    cout << level[n] << "\n";
    printf("%.0f", dis[n] * 20);

}
