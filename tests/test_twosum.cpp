#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

// production implementation functions
extern std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target);
extern std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target);

static int failed_tests = 0;

static void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    std::cout << "]";
}

static bool equalUnordered(const std::vector<int>& a, const std::vector<int>& b) {
    auto aa = a; auto bb = b;
    std::sort(aa.begin(), aa.end());
    std::sort(bb.begin(), bb.end());
    return aa == bb;
}

static void runTestImpl(const std::string& test_name,
                        const std::function<std::vector<int>(const std::vector<int>&, int)>& func,
                        const std::vector<int>& nums,
                        int target,
                        const std::vector<int>& expected)
{
    std::vector<int> result = func(nums, target);
    if (equalUnordered(result, expected)) {
        std::cout << "[PASS] " << test_name << std::endl;
    } else {
        std::cout << "[FAIL] " << test_name << " - Expected: ";
        printVector(expected);
        std::cout << ", Got: ";
        printVector(result);
        std::cout << std::endl;
        ++failed_tests;
    }
}

static void testBoth(const std::string& name, const std::vector<int>& nums, int target, const std::vector<int>& expected) {
    runTestImpl(name + " (BruteForce)", twoSumBruteForce, nums, target, expected);
    runTestImpl(name + " (Optimized)", twoSumOptimized, nums, target, expected);
}

static bool isValidPairResult(const std::vector<int>& res, const std::vector<int>& nums, int target) {
    if (res.size() != 2) return false;
    int a = res[0];
    int b = res[1];
    if (a < 0 || b < 0) return false;
    if ((size_t)a >= nums.size() || (size_t)b >= nums.size()) return false;
    if (a == b) return false;
    return nums[a] + nums[b] == target;
}

static void runTestValidImpl(const std::string& test_name,
                             const std::function<std::vector<int>(const std::vector<int>&, int)>& func,
                             const std::vector<int>& nums,
                             int target)
{
    std::vector<int> result = func(nums, target);
    if (isValidPairResult(result, nums, target)) {
        std::cout << "[PASS] " << test_name << std::endl;
    } else {
        std::cout << "[FAIL] " << test_name << " - Result invalid or does not sum to target. Got: ";
        printVector(result);
        std::cout << std::endl;
        ++failed_tests;
    }
}

static void testBothValid(const std::string& name, const std::vector<int>& nums, int target) {
    runTestValidImpl(name + " (BruteForce)", twoSumBruteForce, nums, target);
    runTestValidImpl(name + " (Optimized)", twoSumOptimized, nums, target);
}

int main() {
    // Core cases
    testBoth("TC_NORM_01: Standard Case", {2, 7, 11, 15}, 9, {0, 1});
    testBoth("TC_NORM_02: Solution at ends", {10, 2, 7, 5}, 15, {0, 3});
    testBoth("TC_NORM_03: Unsorted array", {15, 7, 2, 11}, 9, {1, 2});

    // Edge cases
    testBoth("TC_EDGE_01: Duplicates in input", {3, 3}, 6, {0, 1});
    testBoth("TC_EDGE_02: Negative numbers", {-1, -2, -3, -4, -5}, -8, {2, 4});
    testBoth("TC_EDGE_03: Zero values", {0, 4, 3, 0}, 0, {0, 3});

    // Additional cases
    // multiple valid pairs exist; accept any valid pair that sums to target
    testBothValid("TC_MULTI_01: Multiple possible pairs", {1,3,2,4,3}, 6);
    testBoth("TC_MULTI_02: Another multiple-pair", {3,2,4}, 6, {1,2});

    // Boundary cases
    testBoth("TC_BOUND_01: Empty array", {}, 10, {});
    testBoth("TC_BOUND_02: Single element array", {5}, 5, {});
    testBoth("TC_BOUND_03: No solution", {1, 2, 3}, 7, {});

    std::cout << "\n--- Test Summary ---\n";
    if (failed_tests == 0) {
        std::cout << "All tests passed!" << std::endl;
        return 0;
    } else {
        std::cout << failed_tests << " test(s) failed." << std::endl;
        return 1;
    }
}
