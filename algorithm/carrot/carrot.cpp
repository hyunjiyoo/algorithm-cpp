#include <iostream>

int main (int argc, const char * argv []) {
    int X, Y;
    std::scanf("%d %d", &X, &Y);
    
    if (X > Y)
        std::printf("%d", X + Y + (Y/10));
    else
        std::printf("%d", X + Y + (X/10));
    
    return 0;
}
