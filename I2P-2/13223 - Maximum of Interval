#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    deque<int> seq;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int data;
        cin >> data;
        seq.push_back(data);
        if(data > ans) ans = data;
        if(i >= l) {
            cout << ans << " ";
            if(ans == seq.front()) ans = *max_element(seq.begin()+1, seq.end());
            seq.pop_front();
        }
    }
    cout << "\n";
}
