#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> mapping;
    mapping["Wa"] = "Waninoko";
    mapping["Mi"] = "Milotic";
    mapping["Ma"] = "Magikarp";
    mapping["Va"] = "Vaporeon";
    mapping["Sh"] = "Sharpedo";
    mapping["Tapu"] = "Tapu Fini";
    mapping["Em"] = "Empoleon";
    mapping["La"] = "Lapras";
    mapping["Pi"] = "Pikachu";
    mapping["Pe"] = "Pikachu";
    mapping["Me"] = "Mega Gyarados";

    while(n--) {
        string name, uni;
        cin >> name >> uni;
        bool flag = true;
        for(auto &m : mapping) {
            if(name.substr(0, m.first.size()) == m.first) {
                flag = false;
                cout << name << " the " << uni << " " << m.second << endl;
                break;
            }
        }
        if(flag) cout << name << " is looking for a Chinese tutor, too!\n";
    }
}
