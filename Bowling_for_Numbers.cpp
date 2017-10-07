/*
This program is made by Haoda He
CCC '07 S5 - Bowling for Numbers
https://dmoj.ca/problem/ccc07s5
*/
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int t, n, k, w, max_number;

    cin >> t;

    for(int l = 0; l < t; l ++){
        cin >> n >> k >> w;

        int input[n];
        int chart1[n] = {};
        int chart2[n] = {};

        for(int i = 0; i < n; i ++)
            cin >> input[i];

        chart1[0] = input[0];
        for(int i = 1; i < w; i ++)
            chart1[i] = input[i] + chart1[i - 1];

        for(int i = w; i < n; i ++){
            max_number = 0;

            for(int j = 0; j < w; j ++)
                max_number += input[i - j];

            chart1[i] = max(max_number, chart1[i - 1]);
        }

        //for(int i = 0; i < n; i ++)
        //    cout << chart1[i] << " ";

        for(int i = 2; i <= k; i ++){
            chart2[0] = input[0];
            for(int j = 1; j < w * i; j ++)
                chart2[j] = input[j] + chart2[j - 1];

            for(int j = w * i; j < n; j ++){
                max_number = 0;

                for(int l = 0; l < w; l ++)
                    max_number += input[j - l];

                max_number += chart1[j - w];

                chart2[j] = max(max_number, chart2[j - 1]);
            }

            for(int j = 0; j < n; j ++)
                chart1[j] = chart2[j];
        }

        cout << chart1[n - 1] << "\n";

        /*
        for(int j = 0; j < n; j ++)
            cout << chart2[j] << " ";
        */
    }
}
