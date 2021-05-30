#include <iostream>
#include <string>
using namespace std;

int N;
int len[27];
int idx;
string S[27] = {"moo", "mooo", "moooo", };
string moo;
string R;

void makeMoo() {
    for (int i = 3; i < 27; ++i)
        S[i] = S[i - 1] + "o";
}

void findSindex() {
    len[0] = 3;
    for (int i = 1; i <= 27; ++i) {
        len[i] = (len[i - 1] * 2) + (i + 3);
        if (len[i] > N) {
            idx = i;
            break;
        }
    }
}


void solve(int i = idx) {
    
    int moostart = len[i - 1];
    int mooend = len[i - 1] + (3 + i);
    
    if (0 < N && N <= moostart) {
        solve(i - 1);
    }
    else if (moostart < N && N <= mooend) {
        R = S[i][(N - len[i - 1]) - 1];
        return;
    }
    else {
        N -= mooend;
        findSindex();
        solve();
    }
}


int main (int argc, const char * argv []) {
    cin >> N;
    makeMoo();
    findSindex();
    solve();
    cout << R;
    
    return 0;
}
