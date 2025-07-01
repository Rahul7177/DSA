#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int l = 0;
    int r = arr.size() - 1;
    
    while (l <= r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverseArray(arr);

    cout << "Reversed array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
