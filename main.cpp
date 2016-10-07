#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class solution {
  public:
    vector<vector<int>> largestDivisibleSubset(const vector<int> & nums) {
        auto sorted(nums);
        std::sort(sorted.begin(),sorted.end());
        vector<vector<int>> subsets;
        for (auto n : sorted) {
            vector<int> path{n};
            auto paths = addOne(sorted, path);
            for (auto p : paths) {
                subsets.push_back(p);
                std::for_each(p.begin(), p.end(), [](auto & i){std::cout << i << " ";});
                std::cout << std::endl;
            }
        }

        return subsets;
    }

  private:
    vector<vector<int>> addOne(const vector<int> & nums, const vector<int> & path)
    {
        vector<vector<int>> result;
        auto it = std::upper_bound(nums.begin(), nums.end(), path.back());
        if (it == nums.end()) {
            result.push_back(path);
        }
        else {
            while (it != nums.end() && *it % path.back() != 0) {
                ++it;
            }
            if (it != nums.end()) {
                auto cpy = path;
                cpy.push_back(*it);
                auto temp = addOne(nums, cpy);
                for (auto tmp : temp)
                    result.push_back(tmp);
            }
            else {
                result.push_back(path);
            }
        }
        return result;
    }
};

int main() {
    // vector<int> nums{1,2,3};
    vector<int> nums{2,1,4,8};
    
    solution soln;
    auto subsets = soln.largestDivisibleSubset(nums);
}
