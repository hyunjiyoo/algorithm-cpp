#include <iostream>
#include <vector>

std::vector<int> temp;

void merge_sort(std::vector<int>& data, int l, int r) {
    if (temp.size() < r + 1) // temp resizing
        temp.resize(r + 1);
    
    if (l == r) // base case
        return;
    
    int m = (l + r) / 2; // range calc
    int lidx = l, lend = m + 1;
    int ridx = m + 1, rend = r + 1;
    
    merge_sort(data, lidx, lend - 1); // divide
    merge_sort(data, ridx, rend - 1); // divide
    
    for (int i = l; i <= r; ++i) // copy to temp
        temp[i] = data[i];
    
    for (int i = l; i <= r; ++i) { // merge
        if (ridx == rend) {
            data[i] = temp[lidx++];
        } else if (lidx == lend) {
            data[i] = temp[ridx++];
        } else {
            if (temp[lidx] < temp[ridx])
                data[i] = temp[lidx++];
            else
                data[i] = temp[ridx++];
        }
    }
}

int main(int argc, const char* argv[]) {
    std::vector<int> test = { 5, 2, 7, 4, 10, -11, 9, 4 };
    
    merge_sort(test, 0, (int)test.size() - 1);
    
    for (auto v : test)
        std::cout << v << " ";
    return 0;
}
