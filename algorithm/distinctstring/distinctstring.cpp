#include <iostream>
#include <string>

int n;
std::string s;
std::string str[101];
bool flag[102];

void input() {
    std::cin >> s >> n;
    
    for (int i = 0; i < n; ++i)
        std::cin >> str[i];
    
    flag[0] = true;
}


void solve() {
    
    std::string tmp = "";
    
    for (int i = 0; i < s.length(); ++i) {
        
        for (int j = 0; j <= i; ++j) {
            
            if (flag[j]) {
                
                // flag가 true 인것부터 비교 문자인덱스까지 문자열 만들어주기
                for (int k = j; k <= i; ++k)
                    tmp += s[k];
                
                for (int k = 0; k < n; ++k) {
                    // 비교해서 찾으면 flag 값 갱신
                    if (tmp == str[k]) {
                        flag[i + 1] = true;
                        break;
                    }
                }

                tmp = "";
            }
        }
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    std::cout << flag[s.length()];
    
    return 0;
}
