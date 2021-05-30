#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int N;
vector<string> guitar;
int64_t len[1'000];
int64_t sum[1'000];

void input() {
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        guitar.push_back(str);
    }
}


void solve() {
    int v;
    string serial;
    for (int i = 0; i < N; ++i) {
        v = 0;
        serial = guitar.at(i);
        
        for (int j = 0; j < serial.size(); ++j) {
            if ('0' <= serial[j] && serial[j] <= '9')
                v += (serial[j] - '0');
        }
        
        len[i] = serial.size();
        sum[i] = v;
    }
}


void sort() {
    string str;
    int64_t ltmp, stmp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (len[i] < len[j]) {
                str = guitar[i];
                guitar[i] = guitar[j];
                guitar[j] = str;
                
                ltmp = len[i];
                len[i] = len[j];
                len[j] = ltmp;
                
                stmp = sum[i];
                sum[i] = sum[j];
                sum[j] = stmp;
                
            }
        }
    }
    
    int j;
    for (int i = 1; i < N; ++i) {
        
        if (len[i - 1] != len[i]) {
            
            for (j = i; len[j] == len[i]; ++j) {

                for (int k = i; len[k] == len[i]; ++k) {
                    if (sum[j] < sum[k]) {
                        str = guitar[j];
                        guitar[j] = guitar[k];
                        guitar[k] = str;
                        
                        ltmp = len[j];
                        len[j] = len[k];
                        len[k] = ltmp;
                        
                        stmp = sum[j];
                        sum[j] = sum[k];
                        sum[k] = stmp;
                    }
                }
            }
            
            i = j;
        }
    }
    
    j = 0;
    int ch1, ch2;
    int idx = 0;
    for (int i = 1; i < N; ++i) {
        if (len[i - 1] == len[i] && sum[i - 1] == sum[i]) {
            idx = i - 1;
            for(j = idx; j < N; ++j) {
                bool flag = false;
                
                for (int k = idx; k < N; ++k) {
                    if (flag) break;
                    
                    for (int m = 0; m < len[k]; ++m) {
                        
                        ch1 = guitar[j][m] - '0';
                        ch2 = guitar[k][m] - '0';

                        if (ch1 == ch2) continue;
                        if (ch1 > ch2) break;

                        if (ch1 < ch2) {
                            str = guitar[j];
                            guitar[j] = guitar[k];
                            guitar[k] = str;

                            ltmp = len[j];
                            len[j] = len[k];
                            len[k] = ltmp;

                            stmp = sum[j];
                            sum[j] = sum[k];
                            sum[k] = stmp;
                            
                            flag = true;
                            break;
                        }
                    }
                }
            }
            
            i = j;
        }
    }
    
    
    for (int i = 0; i < N; ++i)
        cout << guitar[i] << endl;
}


int main (int argc, const char * argv []) {
    input();
    solve();
    sort();
    
    return 0;
}
