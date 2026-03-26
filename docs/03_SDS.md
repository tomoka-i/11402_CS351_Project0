# Software Design Specification (SDS)

## 1. Introduction
This document outlines the architectural and component-level design of the "Two Sum" project. It describes the algorithms, data structures, and the CI/CD and containerization deployment models.

## 2. System Architecture
The application is designed as a standalone C++ application. It combines the core algorithmic logic for solving the "Two Sum" problem with an embedded unit testing suite to validate its correctness.

## 3. Component Design

### 3.1 Core Algorithms
Two distinct functions will be implemented to satisfy the requirements:

**Approach 1: Brute Force**
- **Algorithm:** Utilizes nested loops. The outer loop iterates through each element (index `i`), and the inner loop iterates through all subsequent elements (index `j`). It checks if `nums[i] + nums[j] == target`.
- **Data Structures:** Standard sequential array/vector traversal. No auxiliary data structures are used.

**Approach 2: Optimized (Hash Table)**
- **Algorithm:** Utilizes a single pass through the array. For each element `nums[i]`, it calculates the `complement = target - nums[i]`. It checks if this complement exists in a hash table. If found, the current index and the complement's index are returned. If not, `nums[i]` and its index `i` are stored in the hash table for future lookups.
- **Data Structures:** `std::unordered_map<int, int>` (Hash Table) to store the mapping of elements to their indices, allowing O(1) average-time lookups.

### 3.2 Testing Suite
- **Structure:** Implemented within `TwoSum.cpp`. A test runner executes a series of assertion checks against both algorithm approaches using predefined test vectors (normal, edge, and boundary cases).
- **Execution:** The executable will return a non-zero exit code if any assertion fails, which is essential for CI pipeline integration.

## 4. Environment and Automation Design

### 4.1 CI/CD Workflow (GitHub Actions)
- **Configuration:** Defined in `.github/workflows/cpp_test.yml`.
- **Environment:** Uses the `ubuntu-latest` runner.
- **Build Step:** Compiles the source code using `g++ -std=c++11 TwoSum.cpp`.
- **Test Step:** Executes the compiled binary.

### 4.2 Containerization (Docker)
- **Base Image:** Built upon the official `gcc` Docker image.
- **Build Process:** The `Dockerfile` copies the local source code into the container image and compiles it during the `docker build` phase.
- **Execution:** Configured via `CMD` or `ENTRYPOINT` to automatically execute the compiled test binary upon container startup, providing an isolated validation environment.