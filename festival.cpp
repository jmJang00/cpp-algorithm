#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

double solve(int day, int team, vector<int>& price) {
    double ret = 99999.;
    int sum = 0;

    for (int count = team; count <= day; ++count) {
        for (int i = 0; i + count <= day; ++i) {
            sum = 0;
            for (int j = 0; j < count; ++j) {
                sum += price[i + j];
            }
            ret = min(ret, (double) sum / count);
        }
    }

    return ret;
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; ++i) {
        int numDay;
        cin >> numDay;
        int numTeam;
        cin >> numTeam;

        vector<int> price(numDay);
        for (int j = 0; j < numDay; ++j) {
            cin >> price[j];
        }
        
        printf("%.8lf\n", solve(numDay, numTeam, price));
    }
    
    return 0;
}