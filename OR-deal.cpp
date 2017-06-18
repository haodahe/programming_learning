#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    long long number, input;

    cin >> input;

    if(input == 0){
        cout << "0";
        return (0);
    }

    number = 1;

    for(int i = 0; i < 35; i ++){
        if(number > input)
            break;

        cout << "1";

        number *= 2;
    }
}
