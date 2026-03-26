# Test Plan

## 1. Introduction
This document describes the testing strategy and specific test cases for the "Two Sum" project. The goal is to ensure the correctness, robustness, and reliability of both the Brute Force and Optimized solution approaches.

## 2. Test Environment
- **Compiler:** `g++` with `-std=c++11` flag.
- **Local Execution:** Manual execution via command line.
- **CI/CD Environment:** GitHub Actions (`ubuntu-latest` runner).
- **Containerized Environment:** Docker container based on the official `gcc` image.

## 3. Test Cases (Unit Tests)
The following categories of tests will be implemented in `TwoSum.cpp`. Both Approach 1 and Approach 2 must pass all these cases.

### 3.1 Normal Cases
- **TC_NORM_01:** Standard array with a solution in the middle. (e.g., `nums=[2, 7, 11, 15]`, `target=9` -> `[0, 1]`)
- **TC_NORM_02:** Solution at the beginning and end of the array.
- **TC_NORM_03:** Array with unsorted elements.

### 3.2 Edge Cases
- **TC_EDGE_01 (Duplicates):** Array containing duplicate values that form the target. (e.g., `nums=[3, 3]`, `target=6` -> `[0, 1]`)
- **TC_EDGE_02 (Negative Numbers):** Array containing negative values. (e.g., `nums=[-1, -2, -3, -4, -5]`, `target=-8` -> `[2, 4]`)
- **TC_EDGE_03 (Zeros):** Array containing zeros. (e.g., `nums=[0, 4, 3, 0]`, `target=0` -> `[0, 3]`)

### 3.3 Boundary Conditions
- **TC_BOUND_01 (Empty Array):** Handling of an empty input array (`nums=[]`). Should return an empty result or gracefully indicate no solution.
- **TC_BOUND_02 (Single Element):** Handling of an array with only one element (`nums=[5]`). Cannot form a pair, should return no solution.
- **TC_BOUND_03 (No Solution):** Array where no two numbers add up to the target. (e.g., `nums=[1, 2, 3]`, `target=7`).

## 4. Test Execution Strategy
1. **Local Development:** Developers run the compiled executable locally to verify changes before committing.
2. **Automated CI (GitHub Actions):** On every push or pull request to the `main` branch, the test suite is compiled and executed automatically. Any test failure will result in a failed pipeline.
3. **Docker Verification:** The Dockerfile is configured to compile and run the tests on container startup. This ensures the code works in an isolated, standard Linux environment.

## 5. Future Enhancements
- Integration of **Valgrind** to check for memory leaks during test execution.
- Implementation of code coverage tools to verify that 100% of the core logic is tested.