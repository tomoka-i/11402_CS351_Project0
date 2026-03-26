# Traceability Matrix

## 1. Introduction
This document provides a traceability matrix mapping the software requirements defined in the SRS to the corresponding design components, test cases, and implementation artifacts.

## 2. Requirements Traceability

| Requirement ID | Description | Design Component (SDS) | Test Cases (Test Plan) | Implementation File |
| :--- | :--- | :--- | :--- | :--- |
| **FR1** | Input Processing | 3.1 Core Algorithms | All Test Cases | `TwoSum.cpp` |
| **FR2** | Brute Force Solution | 3.1 Core Algorithms | All Test Cases | `TwoSum.cpp` (Approach 1) |
| **FR3** | Optimized Solution | 3.1 Core Algorithms | All Test Cases | `TwoSum.cpp` (Approach 2) |
| **FR4** | Output format | 3.1 Core Algorithms | All Test Cases | `TwoSum.cpp` |
| **FR5** | No Solution Handling | 3.1 Core Algorithms | TC_BOUND_01, 02, 03 | `TwoSum.cpp` |
| **NFR1** | Perf: O(n²) / O(1) | 3.1 Core Algorithms | N/A (Code Review) | `TwoSum.cpp` (Approach 1) |
| **NFR2** | Perf: O(n) / O(n) | 3.1 Core Algorithms | N/A (Code Review) | `TwoSum.cpp` (Approach 2) |
| **NFR3** | C++11 Standard | 4.1 CI/CD Workflow | N/A (Build Step) | `TwoSum.cpp`, `.github/workflows/cpp_test.yml` |
| **NFR4** | Docker Portability | 4.2 Containerization | Container Execution | `Dockerfile` |
| **TR1** | Comprehensive Unit Tests | 3.2 Testing Suite | All Test Cases | `TwoSum.cpp` |
| **TR2** | Automated Execution | 3.2 Testing Suite | All Test Cases | `TwoSum.cpp` |
| **AR1** | CI/CD Trigger | 4.1 CI/CD Workflow | Scenario 2 (Acceptance) | `.github/workflows/cpp_test.yml` |
| **AR2** | Compile & Execute | 4.1 CI/CD Workflow | Scenario 2 (Acceptance) | `.github/workflows/cpp_test.yml` |
| **AR3** | Fail on Regression | 4.1 CI/CD Workflow | Scenario 3 (Acceptance) | `.github/workflows/cpp_test.yml` |