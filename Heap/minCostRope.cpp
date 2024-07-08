#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long int minCost(vector<long long int>& a, long long int n) {
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

    for (long long int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    long long int cost = 0;

    while (pq.size() > 1) {
        long long int min1 = pq.top();
        pq.pop();

        long long int min2 = pq.top();
        pq.pop();

        long long int sum = min1 + min2;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main() {
    // Example usage
    vector<long long int> ropeLengths = {4, 3, 2, 6};
    long long int result = minCost(ropeLengths, ropeLengths.size());
    cout << result;
    // Output or further use of the result...
    return 0;
}
