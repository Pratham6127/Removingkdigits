#include<bits/stdc++.h>
using namespace std;

vector<int> removek(vector<int>& array, int k) {
    stack<int> stk;
    vector<int> result;

    for (int num : array) {
        while (!stk.empty() && k > 0 && stk.top() > num) {
            stk.pop();
            k--;
        }
        stk.push(num);
    }

    while (!stk.empty() && k > 0) {
        stk.pop();
        k--;
    }

    while (!stk.empty()) {
        int top = stk.top();
        stk.pop();
        result.push_back(top);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int k;
    cout << "Enter the number of digits to be removed: ";
    cin >> k;

    vector<int> array(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }

    vector<int> result = removek(array, k);

    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}