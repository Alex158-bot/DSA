#include <iostream>
#include <vector>
using namespace std;

void generateTriangle(vector<int> &A) {
    int n = A.size();
    vector<int> temp = A; 
    vector<vector<int>> result; 


    for (int len = n; len > 0; len--) {
        result.push_back(vector<int>(temp.begin(), temp.begin() + len));
        for (int i = 0; i < len - 1; i++) {
            temp[i] += temp[i + 1]; 
        }
    }

    
    for (int i = 0; i <=result.size() - 1;i++ ) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;
        generateTriangle(A);
    }
    return 0;
}

