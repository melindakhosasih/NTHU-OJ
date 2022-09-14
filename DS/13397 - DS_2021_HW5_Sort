#include <iostream>
using namespace std;
int main() {
    int n, idx_left, idx_right;
    int *data;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    data = new int [1000005];
    while(cin >> n) {
        idx_left = -2;
        idx_right = -2;
        for(int i = 0; i < n; i++) {
            cin >> data[i];
            if(data[i] >= 0 && idx_left == -2) {
                idx_right = i;
                idx_left = i-1;
            }
        }
        if(idx_left == -2) {
            while(n--) {
                if(n > 0) cout << data[n] << " ";
                else cout << data[n] << endl;
            }
        } else {
            while (idx_left >= 0 && idx_right != n) {
                if(data[idx_left]*-1 <= data[idx_right]) {
                    cout << data[idx_left] << " ";
                    idx_left--;
                } else {
                    if(idx_right != n-1 || idx_left >= 0) cout << data[idx_right] << " ";
                    else cout << data[idx_right] << endl;
                    idx_right++;
                }
            }
            while(idx_left >= 0) {
                if(idx_left != 0) cout << data[idx_left] << " ";
                else cout << data[idx_left] << endl;
                idx_left--;
            }
            while(idx_right != n) {
                if(idx_right != n-1) cout << data[idx_right] << " ";
                else cout << data[idx_right] << endl;
                idx_right++;
            }
        }
    }
}
