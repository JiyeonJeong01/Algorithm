#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int two = 0, five = 0;
    for (int i = 2; i <= N; i++) {
        int num = i;
        while (num % 2 == 0){
            num /= 2;
            two++;
        }
        while (num % 5 == 0){
            num /= 5;
            five++;
        }
    }
    // cout << two << " " << five <<"\n";
    int mn = min(two, five);     
    cout << mn;        
}