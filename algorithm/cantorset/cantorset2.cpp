#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int len;
int mypow[13];
vector<char> dash;

void solve(int s, int n) {
    if (n == 0)
        return;
    
    for (int i = s + mypow[n - 1]; i < s + (2*mypow[n - 1]); ++i)
        dash[i] = ' ';
    
    solve(s, n - 1);
    solve(s + (2*mypow[n - 1]), n - 1);
}


int main (int argc, const char * argv []) {
    mypow[0] = 1;
    for(int i = 1; i <= 12; ++i)
        mypow[i] = mypow[i - 1] * 3;
    
    dash.resize(mypow[12], '-');
    
    solve(0, 12);
    
    while (1) {
        cin >> N;
        if (cin.eof()) break;
        
        len = mypow[N];
        
        for (int i = 0; i < len; ++i)
            cout << dash[i];
        
        cout << endl;
    }
    
    return 0;
}
