// The solution for Picture
// https://dmoj.ca/problem/ioi98p4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, input1, input2, input3, input4, pointer;
    long long answer;

    cin >> N;

    bool chart_X[20001] = {};
    bool chart_Y[20001] = {};

    multiset<pair<int, pair<int, pair<int, int> > > > line_X;
    multiset<pair<int, pair<int, pair<int, int> > > > line_Y;

    for(int i = 0; i < N; i ++){
        cin >> input1 >> input2 >> input3 >> input4;
        //if(i >= 45)
        //    cout << input1 << " " << input2 << " " << input3 << " " << input4 << "\n";

        pointer = input1;
        for(int j = input1 + 1; j < input3; j ++){
            if(chart_X[j + 10000]){
                line_X.insert(make_pair(input2, make_pair(0, make_pair(pointer, j))));
                line_X.insert(make_pair(input4, make_pair(1, make_pair(pointer, j))));
                pointer = j + 1;
            }
        }

        if(pointer != input3){
            line_X.insert(make_pair(input2, make_pair(0, make_pair(pointer, input3 - 1))));
            line_X.insert(make_pair(input4, make_pair(1, make_pair(pointer, input3 - 1))));
        }

        pointer = input2;
        for(int j = input2 + 1; j < input4; j ++){
            if(chart_Y[j + 10000]){
                line_Y.insert(make_pair(input1, make_pair(0, make_pair(pointer, j))));
                line_Y.insert(make_pair(input3, make_pair(1, make_pair(pointer, j))));
                pointer = j + 1;
            }
        }

        if(pointer != input4){
            line_Y.insert(make_pair(input1, make_pair(0, make_pair(pointer, input4 - 1))));
            line_Y.insert(make_pair(input3, make_pair(1, make_pair(pointer, input4 - 1))));
        }

        //chart_X[input2 + 10000] = chart_X[input4 + 10000] = true;
        //chart_Y[input1 + 10000] = chart_Y[input3 + 10000] = true;
    }

    set<pair<int, pair<int, pair<int, int> > > >::iterator it;
/*
    cout << '\n';
    for(it = line_X.begin(); it != line_X.end(); ++ it)
        cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second.first << " " << (*it).second.second.second << "\n";
    cout << '\n';

    for(it = line_Y.begin(); it != line_Y.end(); ++ it)
        cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second.first << " " << (*it).second.second.second << "\n";
    cout << '\n';
*/
    int count_X[20001] = {};
    int count_Y[20001] = {};

    answer = 0;

    for(it = line_X.begin(); it != line_X.end(); ++ it){
        if((*it).second.first == 0){
            for(int i = (*it).second.second.first; i <= (*it).second.second.second; i ++){
                if(count_X[i + 10000] == 0)
                    answer ++;
                count_X[i + 10000] ++;
            }
        }
        else{
            for(int i = (*it).second.second.first; i <= (*it).second.second.second; i ++){
                if(count_X[i + 10000] == 1)
                    answer ++;
                count_X[i + 10000] --;
            }
        }
    }

    for(it = line_Y.begin(); it != line_Y.end(); ++ it){
        if((*it).second.first == 0){
            for(int i = (*it).second.second.first; i <= (*it).second.second.second; i ++){
                if(count_Y[i + 10000] == 0)
                    answer ++;
                count_Y[i + 10000] ++;
            }
        }
        else{
            for(int i = (*it).second.second.first; i <= (*it).second.second.second; i ++){
                if(count_Y[i + 10000] == 1)
                    answer ++;
                count_Y[i + 10000] --;
            }
        }
    }

    cout << answer;
}
