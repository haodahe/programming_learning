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

    cin >> N;

    long long input[N] = {};
    long long sum = 0;
    long long answer = 0;

    for(int i = 0; i < N; i ++){
        cin >> input[i];
        sum += input[i];
    }

    if(sum % N!= 0)
        cout << "Impossible";
    else{
        sum = sum / N;
        for(int i = 0; i < N; i ++){
            if(input[i] > sum)
                answer += input[i] - sum;
        }
        cout << answer;
    }

}
