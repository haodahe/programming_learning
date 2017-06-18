#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int N;
    long long sum;

    cin >> N;

    long long A[N + 1];
    long long B[N + 1];

    for(int i = 1; i <= N; i ++)
        cin >> A[i];

    B[1] = sum = A[1];
    cout << B[1] << " ";

    for(int i = 2; i <= N; i ++){
        B[i] = A[i] * i;
        B[i] -= sum;
        cout << B[i] << " ";
        sum += B[i];
    }
}
