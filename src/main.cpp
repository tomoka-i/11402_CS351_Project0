#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

// --- Function Declarations ---
// Declare the functions defined in twosum.cpp so that main.cpp can use them.
// This avoids the need for a header file in this simple project structure.
extern std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target);
extern std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target);

// --- Embedded Unit Testing Suite ---

// Global counter for failed tests
int failed_tests = 0;

/**
 * @brief Helper function to print a vector for clear test output.
 */
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << "]";
}

/**
 * @brief Generic test runner function.
 * @param test_name The name of the test case.
 * @param func The Two Sum function to test (passed as a function pointer/lambda).
 * @param nums The input vector.
 * @param target The target sum.
 * @param expected The expected result vector.
 */
void runTest(
    const std::string& test_name,
    const std::function<std::vector<int>(const std::vector<int>&, int)>& func,
    const std::vector<int>& nums,
    int target,
    std::vector<int> expected)
{
    std::vector<int> result = func(nums, target);
    // Sort results to handle different order of indices
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());

    if (result == expected) {
        std::cout << "[PASS] " << test_name << std::endl;
    } else {
        std::cout << "[FAIL] " << test_name << " - Expected: ";
        printVector(expected);
        std::cout << ", Got: ";
        printVector(result);
        std::cout << std::endl;
        failed_tests++;
    }
}

int main() {
    // Wrapper to test both implementations with the same test case
    auto testBoth = [&](const std::string& name, const std::vector<int>& nums, int target, const std::vector<int>& expected) {
        runTest(name + " (Brute Force)", twoSumBruteForce, nums, target, expected);
        runTest(name + " (Optimized)", twoSumOptimized, nums, target, expected);
    };

    // Test cases based on 04_test_plan.md
    testBoth("TC_NORM_01: Standard Case", {2, 7, 11, 15}, 9, {0, 1});
    testBoth("TC_NORM_02: Solution at ends", {10, 2, 7, 5}, 15, {0, 3});
    testBoth("TC_NORM_03: Unsorted array", {15, 7, 2, 11}, 9, {1, 2});
    testBoth("TC_EDGE_01: Duplicates in input", {3, 3}, 6, {0, 1});
    testBoth("TC_EDGE_02: Negative numbers", {-1, -2, -3, -4, -5}, -8, {2, 4});
    testBoth("TC_EDGE_03: Zero values", {0, 4, 3, 0}, 0, {0, 3});
    testBoth("TC_BOUND_01: Empty array", {}, 10, {});
    testBoth("TC_BOUND_02: Single element array", {5}, 5, {});
    testBoth("TC_BOUND_03: No solution", {1, 2, 3}, 7, {});

    std::cout << "\n--- Test Summary ---\n";
    if (failed_tests == 0) {
        std::cout << "All tests passed!" << std::endl;
        return 0; // Success exit code
    } else {
        std::cout << failed_tests << " test(s) failed." << std::endl;
        return 1; // Failure exit code for CI/CD
    }
}