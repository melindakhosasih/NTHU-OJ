#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    list<long long int> cards;
    list<long long int> most;
    long long int ans = 0;
    long long int cnt = 0;
    while(n--) {
        long long int num;
        cin >> num;
        auto itr = cards.begin();
        auto itr2 = most.begin();
        for(;itr != cards.end(); itr++, itr2++) {
            if((*itr) == num) break;
        }
        if(itr == cards.end()) {
            if(cnt == 0) {
                cnt = 1;
                ans = num;
            }
            else if(cnt == 1 && ans < num) {
                ans = num;
            }
            cards.push_back(num);
            most.push_back(1);
        }
        else {
            long long int check = *itr2;
            check++;
            *itr2 = check;
            if(check == cnt && ans < *itr) {
                ans = *itr;
                cnt = check;
            }
            else if(check > cnt) {
                ans = *itr;
                cnt = check;
            }
        }
        cout << ans << endl;
    }
}
