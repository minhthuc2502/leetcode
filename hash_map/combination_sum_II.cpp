// https://leetcode.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//     std::sort(candidates.begin(), candidates.end());
//     unordered_map<int, vector<vector<int>>> hash_map;
//     set<vector<int>> result_set;
//     for (auto &i : candidates) {
//         if (i == target) {
//             result_set.insert({target});
//             continue;
//         }
//         if (hash_map.find(i) == hash_map.end()) {
//             for (auto &mem : hash_map) {
//                 if (i < mem.first)
//                 {
//                     for (auto &child : mem.second) {
//                         vector<int> mvector = child;
//                         mvector.push_back(i);
//                         hash_map[mem.first - i].push_back(mvector);
//                     }
//                 }
//             }
//             hash_map[target - i].push_back({i});
//         }
//         else {
//             for (auto &mvector : hash_map[i]) {
//                 vector<int> element = mvector;
//                 element.push_back(i);
//                 result_set.insert(element);
//             }
//         }
//     }
//     vector<vector<int>> result;
//     copy(result_set.begin(), result_set.end(), std::back_inserter(result));
//     return result;
// }

void backtracking(vector<int>& candidates, int index, int sum, vector<vector<int>>& result, vector<int> ds) {
    if (sum == 0) {
        result.push_back(ds);
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        if (index < i && candidates[i - 1] == candidates[i]) continue;
        if (candidates[i] > sum) break;

        ds.push_back(candidates[i]);
        backtracking(candidates, i + 1, sum - candidates[i], result, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    backtracking(candidates, 0, target, result, {});

    return result;
}

int main() {
    vector<int> candidates = {3,1,3,5,1,1};
    int target = 8;
    auto result = combinationSum2(candidates, target);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}