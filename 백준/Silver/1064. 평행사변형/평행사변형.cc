#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bool sameLine = (((ax - bx) * (ay - cy)) == ((ay - by) * (ax - cx)));

    if (sameLine)
    {
        cout << -1;
        return 0;
    }

    // ab
    double ab = sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
    
    // ac
    double ac = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));

    // bc
    double bc = sqrt(pow((bx - cx), 2) + pow((by - cy), 2));

    double mx = max(ab, max(ac, bc));
    double mn = min(ab, min(ac, bc));

    cout.precision(11);
    cout << fixed;
    cout << (mx - mn) * 2.0;
}

