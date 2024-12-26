#include <iostream>
#include <string>

using namespace std;

void checkVPS(const string& str);

int main(void)
{
    int tc; cin >> tc;

    while (tc--)
    {
        string str; cin >> str;
        checkVPS(str);
    }
}

void checkVPS(const string& str)
{
    int cnt = 0;
    bool isVps = true;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;

        if (cnt < 0)
        {
            isVps = false;
            break;
        }
    }

    if (isVps && cnt == 0) cout << "YES\n";
    else cout << "NO\n";

}