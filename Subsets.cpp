/*
This program is made by haoda he
https://dmoj.ca/problem/cco00p1
*/
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    bool chart_set[26][26] = {};
    bool chart_element[26][26] = {};
    bool sets[26] = {};
    bool finish = false;
    bool print;
    string input;
    char a, b;

    for(int i = 0; i < N; i ++){
        cin >> a >> input >> b;

        sets[(int) a - 65] = true;

        if(b >= 'a' && b <= 'z'){
            chart_element[(int) a - 65][(int) b - 97] = true;
        }
        else{
            sets[(int) b - 65] = true;
            chart_set[(int) a - 65][(int) b - 65] = true;
        }
    }

    while(1){
        finish = true;

        for(int i = 0; i < 26; i ++)
            for(int j = 0; j < 26; j ++)
                if(chart_set[i][j])
                    for(int k = 0; k < 26; k ++)
                        if(chart_element[j][k] && chart_element[i][k] == false){
                            finish = false;
                            chart_element[i][k] = true;
                        }

        if(finish)
            break;
    }

    for(int i = 0; i < 26; i ++){
        if(sets[i]){
            print = false;
            cout << (char) (i + 65) << " = {";
            for(int j = 0; j < 26; j ++)
                if(chart_element[i][j] && print == false){
                    cout << (char) (j + 97);
                    print = true;
                }
                else if(chart_element[i][j] && print)
                    cout << "," << (char) (j + 97);
            cout << "}\n";
        }
    }
}
