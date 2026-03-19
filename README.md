# Two Sum

## Description

Given an array of integers and a target sum, find two distinct elements that add up to the target and return their indices.

**Example:**
- Input: `nums = [2, 7, 11, 15]`, `target = 9`
- Output: `[0, 1]` (because `nums[0] + nums[1] = 2 + 7 = 9`)

## Solution Approaches

### Approach 1: Brute Force
- **Algorithm:** Use nested loops to compare each element with every other element.
- Time Complexity: O(n²)
- Space Complexity: O(1)

### Approach 2: Optimized (Hash Table)
- **Algorithm:** Use a hash table to store visited numbers and their indices, allowing for O(1) lookups.
- Time Complexity: O(n)
- Space Complexity: O(n)

## Testing and Automation

This project includes a comprehensive testing strategy and is configured for automated builds and validation using CI/CD and containerization.

### Testing Strategy
A suite of unit tests is implemented in `TwoSum.cpp` to ensure correctness and robustness for both solution approaches. The strategy covers:
- **Normal Cases:** Standard inputs with varying sizes.
- **Edge Cases:** Inputs containing duplicates, negative numbers, and zero values.
- **Boundary Conditions:** Scenarios with empty arrays, single-element arrays, and inputs with no valid solution pair.

### CI/CD Pipeline (GitHub Actions)
An automated CI/CD pipeline is configured in `.github/workflows/cpp_test.yml` to ensure code quality on every push and pull request to the `main` branch.
- **Workflow:** The pipeline triggers automatically, using an `ubuntu-latest` runner.
- **Build Process:**
    1. The source code is checked out.
    2. The C++ code is compiled using `g++` with the `-std=c++11` flag.
- **Test Execution:**
    1. The compiled executable, which contains the test suite, is run.
    2. The workflow will fail if any test case does not pass, preventing regressions from being merged.
- **Future Enhancements:**
    - Integrate memory leak analysis using tools like Valgrind.
    - Generate and publish test coverage reports.
    - Cache dependencies to speed up workflow execution time.

### Containerization (Docker)
The application is containerized using Docker for consistent, portable deployments and testing.
- **Dockerfile:** A `Dockerfile` is provided to create an image based on the official `gcc` base image.
- **Build Process:** The Docker build process compiles the C++ application.
- **Execution:** The container is configured to run the test suite automatically upon startup, validating the code within a clean, isolated environment.