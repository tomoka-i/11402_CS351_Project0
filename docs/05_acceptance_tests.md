# Acceptance Tests

## 1. Introduction
This document defines the acceptance criteria and high-level testing scenarios required to consider the "Two Sum" project complete and successful.

## 2. Acceptance Criteria
- **AC1 (Functional Correctness):** Both the Brute Force and Optimized approaches must yield the correct indices for all defined unit test cases.
- **AC2 (Robustness):** The application must not crash when provided with invalid input sizes (empty or single-element arrays) or arrays with no valid solutions.
- **AC3 (CI/CD Automation):** The GitHub Actions pipeline must successfully compile the code and execute the test suite on every commit to the `main` branch.
- **AC4 (Regression Prevention):** Intentionally introducing a bug into the algorithm must cause the GitHub Actions pipeline to fail.
- **AC5 (Containerization):** Building and running the provided `Dockerfile` must execute the test suite successfully within the container without manual intervention.

## 3. Acceptance Test Scenarios

### Scenario 1: Verify Algorithmic Correctness
- **Action:** Compile and run `TwoSum.cpp` locally.
- **Expected Result:** The executable runs to completion and outputs success messages indicating that all unit tests for both approaches have passed. The exit code is `0`.

### Scenario 2: Verify CI/CD Pipeline Execution
- **Action:** Push a valid code commit to the repository on GitHub.
- **Expected Result:** The GitHub Actions workflow is triggered. The workflow completes with a "Success" status (green checkmark), confirming successful build and test execution.

### Scenario 3: Verify CI/CD Failure on Bad Code
- **Action:** Modify `TwoSum.cpp` to introduce a logical error (e.g., return incorrect indices) and push the change to a test branch.
- **Expected Result:** The GitHub Actions workflow is triggered and fails (red cross). The logs clearly show which unit test failed.

### Scenario 4: Verify Docker Containerization
- **Action:** Execute `docker build -t twosum-test .` followed by `docker run --rm twosum-test`.
- **Expected Result:** The image builds successfully. Upon running, the container outputs the test results showing all tests passed and then exits cleanly.