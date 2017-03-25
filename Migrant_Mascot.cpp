//https://dmoj.ca/problem/dmopc16c4p5

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int sz = 200001;
vector<pair<int,int> > a[sz];
int dis[sz];

void Dijkstra(int source, int n){
    dis[source] = 1e9;

    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second < p2.second;}};
    priority_queue<pair<int, int> ,vector<pair<int, int> >, prioritize> pq;
    int cv, cw, number;

    pq.push(make_pair(source,dis[source]));
    while(!pq.empty()){
        pair<int, int> curr = pq.top();
        cv = curr.first;
        cw = curr.second;

        pq.pop();

        for(int i = 0; i < a[cv].size(); i ++){
            number = min(a[cv][i].second, cw);
            if(number > dis[a[cv][i].first])
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first] = number)));
        }
    }
    dis[source] = 0;
}

int main()
{
    int n, m, x, y, w;

    cin >> n >> m;

    for(int i = 0; i < m; i ++){
        scan(x);
        scan(y);
        scan(w);
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
    }

    int source;
    source = 1;
    Dijkstra(source, n);

    for(int i = 1; i < n + 1; i ++)
        cout << dis[i] << "\n";
}
