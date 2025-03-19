#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit; // S?p x?p theo l?i nhu?n gi?m d?n
}

pair<int, int> maxProfit(Job jobs[], int n) {
    sort(jobs, jobs + n, cmp); // S?p x?p theo l?i nhu?n gi?m d?n
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    
    vector<bool> slot(maxDeadline + 1, false); // Ðánh d?u th?i gian dã s? d?ng
    int countJobs = 0, totalProfit = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    return {countJobs, totalProfit};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Job> jobs(N);
        for (int i = 0; i < N; i++) {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }
        pair<int, int> result = maxProfit(jobs.data(), N);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
