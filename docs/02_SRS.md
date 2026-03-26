# Software Requirements Specification (SRS)

## 1. Introduction
This document details the software requirements for the "Two Sum" project. It defines the functional and non-functional requirements, testing requirements, and deployment environment constraints.

## 2. Functional Requirements
- **FR1 (Input Processing):** The system shall accept an array of integers (`nums`) and a single integer (`target`).
- **FR2 (Brute Force Solution):** The system shall provide a function that finds two distinct indices whose values sum to the target using a brute-force approach.
- **FR3 (Optimized Solution):** The system shall provide a function that finds two distinct indices whose values sum to the target using a hash table-based optimized approach.
- **FR4 (Output):** The system shall return a collection (e.g., array or pair) containing the two distinct indices.
- **FR5 (No Solution Handling):** The system shall gracefully handle scenarios where no valid solution exists in the array.

## 3. Non-Functional Requirements
- **NFR1 (Performance - Approach 1):** The brute-force approach shall operate with a time complexity of O(n²) and a space complexity of O(1).
- **NFR2 (Performance - Approach 2):** The optimized approach shall operate with a time complexity of O(n) and a space complexity of O(n).
- **NFR3 (Language Standard):** The application shall be written in C++ and conform to the C++11 standard.
- **NFR4 (Portability):** The application shall be capable of being compiled and executed within a Linux-based Docker container.

## 4. Testing Requirements
- **TR1:** The system shall include a comprehensive unit test suite covering normal cases, edge cases (duplicates, negatives, zeros), and boundary conditions (empty arrays, single elements, no valid solutions).
- **TR2:** The test suite must execute automatically and report failures based on standard assertion mechanisms.

## 5. Automation and CI/CD Requirements
- **AR1:** A CI/CD pipeline shall be triggered automatically on every push and pull request to the `main` branch.
- **AR2:** The pipeline shall compile the code using `g++` and execute the test suite.
- **AR3:** The workflow shall fail if any test case does not pass, preventing regressions.