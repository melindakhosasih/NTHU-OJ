#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100000 + 5
#define L 105
#define P 10

// struct for the information of each user
typedef struct {
    int time[P]; // how many time that he submit to the i-th problem until he get Accepted
    int verdict[P]; // When do he get Accepted on i-th problem
} Info;

// struct for the score of each user
typedef struct {
    int id, acnum, penalty;
} Score;

Info sub[N];
Score score[N];
char in[L]; // the memory space to store the input
int attend[N]; // store whether the i-th user has submisstion

// compare function for qsort
int cmp(const void* a, const void* b) {
    Score sa = *(Score*)a, sb = *(Score*)b;
    if(sa.acnum < sb.acnum) return 1;
    else if(sa.acnum > sb.acnum) return -1;
    else {
        if(sa.penalty > sb.penalty) return 1;
        else if(sa.penalty < sb.penalty) return -1;
        else {
            if(sa.id > sb.id) return 1;
            else if(sa.id < sb.id) return -1;
            else return 0;
        }
    }
}
// return the time of the input char array in minutes.
// c is the position of ':'
// c[-2] is valid since c[-2] is actaully *(c - 2)
// Accoding to the same concept, -2[c] is also valid.
int getTime(char* c) {
    return (c[-2] - '0') * 600 + (c[-1] - '0') * 60 + (c[1] - '0') * 10 + (c[2] - '0');
}
// get the id according to the input char arary.
int getID(char* c) {
    int i = 0, ret = 0;
    while(c[i] >= '0' && c[i] <= '9') {
        ret = 10 * ret + (c[i] - '0');
        i++;
    }
    return ret;
}
// init the sub[i].verdict[j] to -1, since sub[i].verdict[j] is possible to be zero
// And we want to use this variable to detect whether the user has get Accepted on this problem (not -1)
void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            sub[i].verdict[j] = -1;
        }
    }
}
int main() {
    init();
    int T = 10;
    while(T--) fgets(in, L, stdin); // Ignore first ten lines
    while(fgets(in, L, stdin) != NULL) {
        int time, userid, pid, verdict, len;
        time = userid = pid = verdict = -1;
        len = strlen(in);
        for(int i = 0; i < len; i++) {
            if(in[i] == '/') break; // check whether it contains </tbody>
        }
        fgets(in, L, stdin); // time
        len = strlen(in);
        for(int i = 0; i < len; i++) {
            if(in[i] == ':') {
                time = getTime(in + i);
                break;
            }
        }
        fgets(in, L, stdin); // User
        len = strlen(in);
        for(int i = 0; i < len; i++) {
            if(in[i] >= '0' && in[i] <= '9') {
                userid = getID(in + i);
                break;
            }
        }
        fgets(in, L, stdin); // pid
        len = strlen(in);
        for(int i = 0; i < len; i++) {
            if(in[i] >= 'A' && in[i] <= 'Z') {
                pid = in[i] - 'A';
                break;
            }
        }
        fgets(in, L, stdin); // verdict
        len = strlen(in);
        for(int i = 0; i < len; i++) {
            if(in[i] == 'A') {
                verdict = 1;
                break;
            } else if(in[i] == 'W') {
                verdict = 0;
                break;
            }
        }
        fgets(in, L, stdin); // </tr>
        attend[userid] = 1; // set attend [userid] to 1 since userid has submission
        if(sub[userid].verdict[pid] == -1) { // ignore the submission that the user has already get Accepted
            sub[userid].time[pid]++;
            if(verdict == 1) sub[userid].verdict[pid] = time;
        }
    }
    fgets(in, L, stdin); // get </table>
    // set everyone's score
    int num = 0;
    for(int i = 0; i < N; i++) {
        if(attend[i]) {
            score[num].id = i;
            for(int j = 0; j < P; j++) {
                if(sub[i].verdict[j] != -1)
                    score[num].acnum += 1, score[num].penalty += sub[i].verdict[j] + 20 * sub[i].time[j] - 20;
            }
            num++;
        }
    }
    qsort(score, num, sizeof(Score), cmp);
    for(int i = 0; i < num; i++) {
        printf("%d", score[i].id);
        for(int j = 0; j < P; j++) {
            if(sub[score[i].id].verdict[j] == -1) {
                if(sub[score[i].id].time[j] > 0) printf(" %d/-", sub[score[i].id].time[j]);
                else printf(" -/-");
            } else {
                printf(" %d/%d", sub[score[i].id].time[j], sub[score[i].id].time[j] * 20 + sub[score[i].id].verdict[j] - 20);
            }
        }
        printf(" %d %d\n", score[i].acnum, score[i].penalty);
    }
}
