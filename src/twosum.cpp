#include <vector>
#include <unordered_map>

// --- Core Algorithm Implementations ---

/**
 * @brief Finds two indices that sum to the target using brute force. (Approach 1)
 * @param nums The input vector of integers.
 * @param target The target sum.
 * @return A vector containing the two indices, or an empty vector if no solution is found.
 */
std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target) {
    for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return std::vector<int>{(int)i, (int)j};
            }
        }
    }
    return {}; // No solution found
}

/**
 * @brief Finds two indices that sum to the target using a hash map. (Approach 2)
 * @param nums The input vector of integers.
 * @param target The target sum.
 * @return A vector containing the two indices, or an empty vector if no solution is found.
 */
std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;
    for (std::size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.count(complement)) {
            return std::vector<int>{num_map[complement], (int)i};
        }
        num_map[nums[i]] = (int)i;
    }
    return {}; // No solution found
}
