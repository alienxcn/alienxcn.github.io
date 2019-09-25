#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout << s.size() << endl;
    cout << s.max_size() << endl;
    cout << *s.begin() << endl;
    cout << *s.end() << endl;

    for(set<int>::iterator i = s.begin(); i!=s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    s.clear();
    return 0;
}