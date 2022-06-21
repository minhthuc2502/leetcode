#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.empty())
        return {};

    vector<vector<string>> result;
    if (strs.size() == 1) {
        result.push_back(strs);
        return result;
    }
    unordered_map<string, vector<int>> mmap_base;
    for (int i = 0; i < strs.size(); ++i) {
        auto tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        mmap_base[tmp].push_back(i);
    }
    for (auto &it : mmap_base) {
        vector<string> mset;
        for (auto &e : it.second) {
            mset.push_back(strs[e]);
        }
        result.push_back(mset);
    }
    return result;
}
int main(void) {
    return 0;
}