#include <iostream>
#include <string>

int w1, w2, h1, h2;
int a1, a2, b1, b2;
std::string ret;

std::string comp(int x1, int x2, int z1, int z2) {
    bool flag, point;
    std::string status;
    flag = point = false;
    
    if ((x1 >= z1 && x2 <= z2) || (x1 <= z1 && x2 >= z2)) {
        flag = true;
    }
    
    if (x1 <= z1 && x2 <= z2) {
        if (x2 >= z1) flag = true;
        if (x2 == z1) point = true;
    }
    
    if (x1 >= z1 && x2 >= z2) {
        if (x1 <= z2) flag = true;
        if (x1 == z2) point = true;
    }
    
    if (!flag) {
        status = "NULL";
    }
    else {
        if (point)
            status = "POINT";
        else
            status = "FACE";
    }
    
    return status;
}


void solve() {
    std::string x, y;
    x = comp(w1, w2, a1, a2);
    y = comp(h1, h2, b1, b2);
    
    if (x == "NULL" || y == "NULL") {
        ret = "NULL";
    }
    else {
        if (x == "POINT" && y == "POINT")
            ret = "POINT";
        
        else if (x == "FACE" && y == "FACE")
            ret = "FACE";

        else if (x == "FACE" && y == "POINT")
            ret = "LINE";
        
        else if (x == "POINT" && y == "FACE")
            ret = "LINE";
    }
}

int main (int argc, const char* argv []) {
    
    std::cin >> w1 >> h1 >> w2 >> h2;
    std::cin >> a1 >> b1 >> a2 >> b2;
    
    solve();
    
    std::cout << ret;
    
    return 0;
}
