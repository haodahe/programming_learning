#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    int N, j;

    cin >> N;

    int number = N - 1;
    number *= 2;

    int chart[number][2];

    for(int i = 0; i < number; i += 2){
        cin >> chart[i][0];
        cin >> chart[i][1];
        chart[i + 1][0] = chart[i][1];
        chart[i + 1][1] = chart[i][0];
    }

    queue<int> chart2;
    int distance[N + 1];

    for(int i = 2; i < N + 1; i ++)
        distance[i] = 99999999;

    chart2.push(1);

    int i;

    while(!chart2.empty()){
        i = chart2.front();
        chart2.pop();

        for(j = 0; j < number; j ++){
            if(chart[j][0] == i && distance[i] + 1 < distance[chart[j][1]]){
                chart2.push(chart[j][1]);
                distance[chart[j][1]] = distance[i] + 1;
            }
        }
    }

    int max_number = -1;
    int index;

    for(i = 1; i < N + 1; i ++){
        if(max_number < distance[i]){
            max_number = distance[i];
            index = i;
        }
    }

    chart2.push(index);

    for(int i = 0; i < N + 1; i ++)
        distance[i] = 99999999;

    distance[index] = 0;

    while(!chart2.empty()){
        i = chart2.front();
        chart2.pop();

        for(j = 0; j < number; j ++){
            if(chart[j][0] == i && distance[i] + 1 < distance[chart[j][1]]){
                chart2.push(chart[j][1]);
                distance[chart[j][1]] = distance[i] + 1;
            }
        }
    }

    max_number = -1;

    for(i = 1; i < N + 1; i ++)
        if(max_number < distance[i])
            max_number = distance[i];

    cout << max_number;

}
