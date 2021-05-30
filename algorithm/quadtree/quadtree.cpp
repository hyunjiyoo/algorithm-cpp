#include <iostream>
#include <string>
using namespace std;

int N;
char VISION[64][64];
string R;

void init() {
    cin >> N;
    char stmp[N];
    for (int i = 0; i < N; ++i) {
        cin >> stmp;
        for (int j = 0; j < N; ++j)
            VISION[i][j] = stmp[j];
    }
    
    R = "";
}

char solve(int s1, int s2, int n) {
    
    char lt = VISION[s1][s2];
    char rt = VISION[s1][s2 + (n - 1)];
    char lb = VISION[s1 + (n - 1)][s2];
    char rb = VISION[s1 +(n - 1)][s2 + (n - 1)];
    
    
    if (n == 2) {
        
        if (lt == rt && rt == lb && lb == rb) {
            return lt;
            
        } else {
            
            R += '(';
            R += lt;
            R += rt;
            R += lb;
            R += rb;
            R += ')';
            
            return '\0';
        }
        
    } else {
        
        for (int i = s1; i < s1 + n; ++i) {
            for (int j = s2; j < s2 + n; ++j) {
                
                if (VISION[s1][s2] != VISION[i][j]) {
                    R += '(';
                    
                    char ret;
                    ret = solve(s1, s2, n/2);
                    if (ret != '\0')
                        R += ret;
                    ret = solve(s1, s2 + n/2, n/2);
                    if (ret != '\0')
                        R += ret;
                    ret = solve(s1 + n/2, s2, n/2);
                    if (ret != '\0')
                        R += ret;
                    ret = solve(s1 + n/2, s2 + n/2, n/2);
                    if (ret != '\0')
                        R += ret;
                    R += ')';
                    
                    return '\0';
                }
            }
        }
        
        return lt;
    }
    
    return '\0';
}


void prevsolve() {
    
    bool flag = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (VISION[0][0] != VISION[i][j])
                flag = false;
        }
    }

    if (flag)
        R = VISION[0][0];
    else
        solve(0, 0, N);
    
    return;
}


int main (int argc, const char * argv []) {
    
    init();
    prevsolve();
    cout << R;
    
    return 0;
}
