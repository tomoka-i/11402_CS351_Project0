# Project Plan

## Overview
This document outlines the development plan for the "Two Sum" project. The project is divided into structured phases covering algorithm implementation, rigorous testing, DevOps automation, and documentation.

## Phases and Milestones

### Phase 1: Project Initialization
- [x] Create Git repository and basic directory structure.
- [x] Define project scope and intended use.
- [x] Initialize documentation scaffolding.

### Phase 2: Algorithm Implementation
- [x] Define C++ function signatures for the "Two Sum" problem.
- [x] Implement **Approach 1 (Brute Force)**: Nested loops, O(n²) time complexity.
- [x] Implement **Approach 2 (Optimized)**: Hash table, O(n) time complexity.

### Phase 3: Testing Implementation
- [x] Set up unit testing structure in `TwoSum.cpp`.
- [x] Write tests for **Normal Cases**: Standard varying sizes.
- [x] Write tests for **Edge Cases**: Duplicates, negative numbers, and zeros.
- [x] Write tests for **Boundary Conditions**: Empty arrays, single-element arrays, no solution scenarios.

### Phase 4: CI/CD and Containerization
- [x] **GitHub Actions**: Create `.github/workflows/cpp_test.yml` to compile (`g++ -std=c++11`) and run tests on push/PR to `main`.
- [x] **Docker**: Create `Dockerfile` using the official `gcc` image to containerize the application and run tests on startup.

### Phase 5: Complete Documentation
- [ ] Draft Software Requirements Specification (`02_SRS.md`).
- [ ] Draft Software Design Specification (`03_SDS.md`).
- [ ] Complete remaining SDLC documentation (Test Plan, Acceptance Tests, Traceability, etc.).

### Phase 6: Future Enhancements (Post-MVP)
These tasks are slated for future iterations to improve code robustness and pipeline efficiency:
- [ ] Integrate memory leak analysis using tools like Valgrind.
- [ ] Generate and publish test coverage reports.
- [ ] Implement dependency caching in GitHub Actions to reduce workflow execution time.