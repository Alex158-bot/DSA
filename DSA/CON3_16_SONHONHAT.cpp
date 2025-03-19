#include <bits/stdc++.h>
using namespace std;

//D la so chu so
//S phai la so nho nhat sao cho tong nhat

string findSmallestNumber(int S, int D) {
    
    if (S > 9 * D) return "-1";// moi chu so toi da 9 chu so neu qua thi invalid
    
    vector<int> digits(D, 0); 
    	S--; 
    for (int i = D - 1; i > 0; i--) {
        if (S > 9) {
            digits[i] = 9;
            S -= 9;
        } else {
            digits[i] = S;
            S = 0;
        }
    }
    digits[0] = S + 1; 
    string result = "";
    for(int i = 0;i < digits.size(); i++){
    	result+=(char)(digits[i]+'0');
	}
    return result;
}          

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, D;
        cin >> S >> D;
        cout << findSmallestNumber(S, D) << endl;
    }
    return 0;
}

