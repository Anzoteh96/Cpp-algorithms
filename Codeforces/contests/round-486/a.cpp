#include <bits/stdc++.h>

using namespace std;

vector<int> team(vector<int>vec, int k) {
    int n = vec.size();
    vector<int>answer;
    map<int, vector<int> > ratings;
    for (int i = 0; i < n; ++i) {
        ratings[vec[i]].push_back(i + 1);
    }
    for (auto it = ratings.begin(); it != ratings.end() && answer.size() < k; ++it) {
        answer.push_back((it->second)[0]);
    }
    return answer;
}

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    vector<int> answer = team(vec, k);
    if (answer.size() < k) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < k; ++i) {
            cout << answer[i]<< " ";
        }
        cout << endl;
    }
}
