#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, R;

int main()

{
 cin >> N >> M >> R;
 vector<int> E(N);

 for (int i = 0; i < N; i++)
 {
   cin >> E[i];
 }

 E.push_back(M + R); // Dummy final emitter which must be reached.

 sort(E.begin(), E.end()); // Sort by increasing distance.

 int prev = R, ans = 0;

 for (int i = 0; i < (int)E.size(); i++) {
     int dist = E[i] - R - prev; // Distance from prev to current.
     if (dist > 0) {
         ans += (dist - 1)/(2 * R) + 1; // Cover intervening distance.
      }
      prev = E[i] + R;
 }
 cout << ans << endl;
 return 0; }
