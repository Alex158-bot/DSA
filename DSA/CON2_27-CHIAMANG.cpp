#include<bits/stdc++.h>

using namespace std;

// Function to find the largest number after at most k swaps
string findLargest(string s, int k) {
    string largest = s;
    int n = s.length();

    function<void(string, int)> solve =
        [&](string current_s, int current_k) {
        if (current_k == 0) {
            if (current_s > largest) {
                largest = current_s;
            }
            return;
        }

        if (current_s > largest) {
            largest = current_s;
        }

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (current_s[j] > current_s[i]) {
                    swap(current_s[i], current_s[j]);
                    solve(current_s, current_k - 1);
                    swap(current_s[i], current_s[j]); // Backtrack
                }
            }
        }
    };

    solve(s, k);
    return largest;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string s;
        cin >> k >> s;
        cout << findLargest(s, k) << endl;
    }
    return 0;
}
