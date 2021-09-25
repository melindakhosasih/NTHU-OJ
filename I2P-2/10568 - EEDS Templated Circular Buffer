#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class circular_buffer {
public:
    circular_buffer (int capacity) {
        if(capacity == 0) return;
        this->capacity = capacity;
    }
    ~circular_buffer () {
        data.clear();
    }
    T &operator[](int idx) {
        return data[idx];
    }
    void push_back(int num) {
        if(capacity == size()) pop_front();
        data.push_back(num);
    }
    void pop_front() {
        if(!data.empty()) data.pop_front();
    }
    int size() const {
        return data.size();
    }
private:
    deque<T> data;
    int capacity;
};

int main()
{
    int capacity;
    cin >> capacity;
    circular_buffer<int> cbi(capacity);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        if(cmd=="push_back"){
            int data;
            cin >> data;
            cbi.push_back(data);
        }else if(cmd=="pop_front"){
            cbi.pop_front();
        }else if(cmd=="print"){
            for(int j=0; j<cbi.size(); j++){
                cout << cbi[j] << endl;
            }
            cout << "----" << endl;
        }
    }
    return 0;
}
