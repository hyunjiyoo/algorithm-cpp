#include <iostream>

const int tot_height = 100;
int dwarf[9];
bool realdwarf[9];
int sortdwarf[7];


void sort() {
    
    int j = 0;
    for (int i = 0; i < 9; ++i) {
        if (realdwarf[i]) {
            sortdwarf[j] = dwarf[i];
            j += 1;
        }
    }
    
    int tmp = 0;
    for (int i = 0; i < 7; ++i) {
        
        for (int j = 0; j < 6 - i; ++j) {
            
            if (sortdwarf[j + 1] < sortdwarf[j]) {
                tmp = sortdwarf[j];
                sortdwarf[j] = sortdwarf[j + 1];
                sortdwarf[j + 1] = tmp;
            }
            
        }
    }
    
    for (int i = 0; i < 7; ++i) {
        std::cout << sortdwarf[i] << std::endl;
    }
}


int count = 0;
bool findDwarf(int idx = 0, int sum = 0) {
    
    if (sum == tot_height && count == 7) {
        sort();
        return true;
    }
    
    for (int i = idx; i < 9; ++i) {
        
        sum += dwarf[i];
        realdwarf[i] = true;
        count += 1;
        
        if (findDwarf(i + 1, sum))
            return true;
            
        sum -= dwarf[i];
        realdwarf[i] = false;
        count -= 1;
    }

    return false;
}


int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 9; ++i) {
        std::cin >> dwarf[i];
        realdwarf[i] = false;
    }
    
    findDwarf();
    
    return 0;
}
