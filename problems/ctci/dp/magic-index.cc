#include <vector>
#include <cassert>
using namespace std;

int getmagind(vector<int> arr, int bot, int top) {
    if (top < bot) return -1;
    int mid = bot + (top - bot) / 2;
    if (arr[mid] == mid) return mid;
    // 1 2 3 4 5 6 7
    if (arr[mid] > mid) {
        return getmagind(arr, bot, mid - 1);
    }
    return getmagind(arr, mid + 1, top);
}
int getmagind(vector<int> arr) {
    return getmagind(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> x = {1,2,3,4,5,6};
    assert(getmagind(x) == -1);
    x = {0,2,3,4,5,6};
    assert(getmagind(x) == 0);
    x = {-1,0,1,2,3,5};
    assert(getmagind(x) == 5);
}
