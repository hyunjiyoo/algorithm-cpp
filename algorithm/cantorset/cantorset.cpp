#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
int len;
vector<char> dash;

void solve(int s, int n) {
    if (n == 0)
        return;
    
    for (int i = s + pow(3, n - 1); i < s + (2*pow(3, n - 1)); ++i)
        dash[i] = ' ';
    
    solve(s, n - 1);
    solve(s + (2*pow(3, n - 1)), n - 1);
}


int main (int argc, const char * argv []) {
    
    dash.resize(pow(3, 12), '-');
    while (1) {
        
        cin >> N;
        if (cin.eof()) break;
        
        len = pow(3, N);
        for (int i = 0; i < len; ++i)
            dash[i] = '-';
        
        if (N != 0)
            solve(0, N);
        
        for (int i = 0; i < len; ++i)
            cout << dash[i];
        
        cout << endl;
    }
    
    return 0;
}
