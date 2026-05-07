#include <iostream>
#include <vector>
// --- Function Declarations ---
// Declare the functions defined in twosum.cpp so that this example main can use them.
extern std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target);
extern std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target);

static void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    std::cout << "]";
}

int main() {
    std::cout << "Two Sum example run:\n";
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto res = twoSumOptimized(nums, target);
    std::cout << "Input: ";
    printVector(nums);
    std::cout << ", target=" << target << "\nResult: ";
    printVector(res);
    std::cout << "\n";
    return 0;
}