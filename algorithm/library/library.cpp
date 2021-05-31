#include <iostream>
#include <algorithm>
#include <vector>

int N, M, R;
std::vector<int> b1, b2;

void input() {
    std::scanf("%d %d", &N, &M);
    
    int book = 0;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &book);
        if (book > 0)
            b1.push_back(book);
        else
            b2.push_back(-book);
    }
}


void solve() {
    
    std::sort(b1.begin(), b1.end(), std::greater<int>());
    std::sort(b2.begin(), b2.end(), std::greater<int>());
        
    R = 0;
    
    for (int i = 0; i < b1.size(); ++i) {
        std::cout << b1[i] << ' ';
    }
    
    
    for (int i = 0; i < b2.size(); ++i) {
        std::cout << b2[i] << ' ';
    }
    std::cout <<  std::endl;
    
    if (b1[0] > b2[0]) {
        R = b1[0];
        
        int R1, R2;
        R1 = 0;
        for (int i = 0; i < b2.size(); i += M) {
            R1 += (b2[i] * M);
        }
        
        R2 = b2[0];
        for (int i = M; i < b2.size(); i += M) {
            R2 += (b2[i] * M);
        }
        R += std::min(R1, R2);
        
        
        int R3, R4;
        R3 = R4 = 0;
        for (int i = 1; i < b1.size(); i += M) {
            R3 += (b1[i] * M);
        }
        
        for (int i = 2; i < b1.size(); i += M) {
            R4 += (b1[i] * M);
        }
        
        R += std::min(R3, R4);
        
    }
    else {
        R = b2[0];
        
        int R1, R2;
        R1 = 0;
        for (int i = 0; i < b1.size(); i += M) {
            R1 += (b1[i] * M);
        }
        
        R2 = b1[0];
        for (int i = 1; i < b1.size(); i += M) {
            R2 += (b1[i] * M);
        }
        R += std::min(R1, R2);
        
        
        int R3, R4;
        R3 = R4 = 0;
        for (int i = 1; i < b2.size(); i += M) {
            R3 += (b2[i] * M);
        }
        
        for (int i = M; i < b2.size(); i += M) {
            R4 += (b2[i] * M);
        }
        
        R += std::min(R3, R4);
    }
}


int main (int argc, const char * argv []) {
    input();
    solve();
    
    std::printf("%d", R);
    
    return 0;
}
