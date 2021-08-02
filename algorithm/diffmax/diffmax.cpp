#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

int N;
std::vector<int> R1, R2;
std::deque<int> q1, q2, tmp1, tmp2;


void input() {
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    
    int n;
    for (int i = 0; i < N; ++i) {
        std::cin >> n;
        q1.push_back(n);
        q2.push_back(n);
    }
    
    std::sort(q1.begin(), q1.end());
    std::sort(q2.begin(), q2.end());
}


void solve1() {
    
    tmp1.push_back(q1.back());
    q1.pop_back();
    
    while (!q1.empty()) {
        
        int front_diff = std::abs(tmp1.front() - q1.front());
        int back_diff = std::abs(tmp1.front() - q1.back());
        
        if (front_diff < back_diff) {
            tmp1.push_front(q1.back());
            q1.pop_back();
            
            if (q1.empty()) break;
            
            front_diff = std::abs(tmp1.back() - q1.front());
            back_diff = std::abs(tmp1.back() - q1.back());
            
            if (front_diff < back_diff) {
                tmp1.push_back(q1.back());
                q1.pop_back();
            }
            else {
                tmp1.push_back(q1.front());
                q1.pop_front();
            }
        }
        else {
            front_diff = std::abs(tmp1.front() - q1.front());
            back_diff = std::abs(tmp1.front() - q1.back());
            
            tmp1.push_front(q1.front());
            q1.pop_front();
            
            if (q1.empty()) break;
            
            front_diff = std::abs(tmp1.back() - q1.front());
            back_diff = std::abs(tmp1.back() - q1.back());
            
            if (front_diff < back_diff) {
                tmp1.push_back(q1.back());
                q1.pop_back();
            }
            else {
                tmp1.push_back(q1.front());
                q1.pop_front();
            }
        }
    }
}

void solve2() {
    
    tmp2.push_back(q2.front());
    q2.pop_front();
    
    while (!q2.empty()) {
        
        int front_diff = std::abs(tmp2.front() - q2.front());
        int back_diff = std::abs(tmp2.front() - q2.back());
        
        if (front_diff < back_diff) {
            tmp2.push_front(q2.back());
            q2.pop_back();
            
            if (q2.empty()) break;
            
            front_diff = std::abs(tmp2.back() - q2.front());
            back_diff = std::abs(tmp2.back() - q2.back());
            
            if (front_diff < back_diff) {
                tmp2.push_back(q2.back());
                q2.pop_back();
            }
            else {
                tmp2.push_back(q2.front());
                q2.pop_front();
            }
        }
        else {
            front_diff = std::abs(tmp2.front() - q2.front());
            back_diff = std::abs(tmp2.front() - q2.back());
            
            tmp2.push_front(q2.front());
            q2.pop_front();
            
            if (q2.empty()) break;
            
            front_diff = std::abs(tmp2.back() - q2.front());
            back_diff = std::abs(tmp2.back() - q2.back());
            
            if (front_diff < back_diff) {
                tmp2.push_back(q2.back());
                q2.pop_back();
            }
            else {
                tmp2.push_back(q2.front());
                q2.pop_front();
            }
        }
    }

}


void output() {
    
    int ans1 = 0;
    int ans2 = 0;
    
    while (!tmp1.empty()) {
        R1.push_back(tmp1.front());
        tmp1.pop_front();
    }
    
    for (int i = 1; i < N; ++i)
        ans1 += std::abs(R1[i] - R1[i - 1]);
    
    
    while (!tmp2.empty()) {
        R2.push_back(tmp2.front());
        tmp2.pop_front();
    }
    
    for (int i = 1; i < N; ++i)
        ans2 += std::abs(R2[i] - R2[i - 1]);
    
    std::cout << std::max(ans1, ans2);
}


int main (int argc, const char * argv []) {
    
    input();
    solve1();
    solve2();
    output();
    
    return 0;
}
