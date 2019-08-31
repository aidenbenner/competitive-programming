#include <iostream>
#include <queue>
#include <cassert>
#include <vector>
#include <map>
using namespace std;


struct Dep {
    char a;
    char b;

    Dep(char a, char b) : a(a), b(b) { }
};


typedef map<char, vector<char>> AdjList;
queue<char> getBuildOrder(vector<Dep> deps, vector<char> projects) {

    queue<char> order;
    map<char, int> inbound;
    AdjList adj;
    for (auto a : projects) {
         inbound[a] = 0;   
         adj[a] = vector<char>{};
    }

    for (auto d : deps) {
        adj[d.a].push_back(d.b);
        inbound[d.b]++;
    }

    // (1, 2) (2, 3), (3,4)
    queue<char> processNext;
    for (auto a : projects) {
        if (inbound[a] == 0) {
            order.push(a);
            for (auto b : adj[a]) {
                inbound[b]--;
                if (inbound[b] == 0)
                    processNext.push(b);
            }
        }
    }

    while (processNext.size() != 0) {
        char front = processNext.front();
        processNext.pop();
        order.push(front);
        for (auto b : adj[front]) {
            inbound[b]--;
            if (inbound[b] == 0)
                processNext.push(b);
        }
    }
    if (order.size() != projects.size())
        assert(false);
    return order;
}

int main() {
    vector<Dep> deps = {Dep{'a','d'}, Dep{'f', 'b'}, Dep{'b','d'}, Dep{'f', 'a'}, Dep{'d','c'}};
    vector<char> projects = {'a','b','c','d','e','f'};
    auto order = getBuildOrder(deps, projects);

    while (order.size() != 0) {
        char p = order.front();
        order.pop();
        cout << p << endl;
    }
}
