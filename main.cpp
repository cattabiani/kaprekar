#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& v) {
    for (auto i : v) {
        os << i << ", ";
    }
    return os << endl;
}

ostream& operator<<(ostream& os, unordered_set<int>& v) {
    for (auto i : v) {
        os << i << ", ";
    }
    return os << endl;
}

ostream& operator<<(ostream& os, unordered_map<int, int>& v) {
    for (auto i : v) {
        os << i.first << ' ' << i.second << endl;
    }
    return os << endl;
}

uint advance(uint a) {
    if (a == 0) {
        return 0;
    }
        

    vector<int> v;
    while (a) {
        v.push_back(a%10);
        a /= 10;
    }
    sort(v.begin(), v.end());
    size_t k = 1;
    for (auto i : v) {
        a += k*i;
        k *= 10;
    }

    uint b = 0;
    k = 1;
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        b += (*i) * k;
        k *= 10;
    }


    return a-b;

}



vector<int> run(int a) {

    unordered_set<int> s;
    int b = -1;
    vector<int> ans;
    
    for (int i = 0; i < 1000; ++i) {

        s.emplace(a);
        ans.push_back(a);
        // cout << a << endl;
        b = a;
        a = advance(a);

        auto p  = s.find(a);

        if (p != s.end()) {
            break;

        }
            

    }

    auto p = find(ans.rbegin(), ans.rend(), a);

    ans.erase(ans.begin(), ans.end() - distance(ans.rbegin(), p)-1);

    return ans;
}




int main() {
    auto a = run(1234);
    cout << a << endl;
    return 0;
}
