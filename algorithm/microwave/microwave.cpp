#include <iostream>

using namespace std;

int T;

void input() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
}

void solve() {
    
    int one = T / 300;
    T -= (300 * one);
    
    int two = T / 60;
    T -= (60 * two);
    
    int three = T / 10;
    T -= (10 * three);
    
    if (T == 0)
        cout << one << ' ' << two << ' ' << three;
    else
        cout << "-1";
}


int main (int argc, const char * argv []) {
    
    input();
    solve();
    
    return 0;
}
