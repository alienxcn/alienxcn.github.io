#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<pair<int, int> > a;
    pair<int, int> p1(1, 2);
    pair<int, int> p2(1, 3);
    pair<int, int> p3(2, 5);
    a.push(p1);
    a.push(p2);
    a.push(p3);
    while(!a.empty()){
        cout << a.top().first << " " << a.top().second << endl;
        a.pop();
    }
    return 0;
}