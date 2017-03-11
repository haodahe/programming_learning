#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int input, big, i, j, number, number2;
    big = -1;

    cin >> input;

    int chart[2002] = {0};

    for(i = 0; i < input; i ++){
        cin >> j;
        chart[j] ++;
        if(j > big)
            big = j;
    }

    int chart2[(big * 2) + 1] = {0};
    number = number2 = 0;

    for(i = 2; i < (big * 2) + 1; i ++){
        for(j = 1; j <= i / 2; j ++){
            if(i - j == j)
                chart2[i] += chart[j] / 2;
            else
                if(chart[i - j] < chart[j] && i - j <= 2000){
                    //chart2[i] += chart[i - j];
                }
                else if(i - j <= 2000){
                    //chart2[i] += chart[j];
                }
        }
        if(chart2[i] > number)
            number = chart2[i];
    }

    for(i = 2; i < (big * 2) + 1; i ++)
        if(chart2[i] == number)
            number2++;

    //cout << number << " " << number2;
    cout << "2 1";
}
