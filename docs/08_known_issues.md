# Known Issues and Future Enhancements

## 1. Introduction
This document outlines currently known limitations of the project and tracks planned future enhancements.

## 2. Known Issues / Limitations
- **Brute Force Performance:** Approach 1 (Brute Force) has an O(n²) time complexity. While functional and correct, it will perform very poorly and potentially time out with extremely large input arrays (e.g., `n > 10^5`).
- **No Input Parser:** The application currently relies on hardcoded arrays within the embedded unit testing suite. There is no CLI or file parser to accept dynamic input from a user at runtime.

## 3. Future Enhancements
The following features are planned for future iterations (as noted in the project plan and README):
- **Memory Leak Detection:** Integrate `valgrind` into the GitHub Actions pipeline or Docker run process to verify there are no memory leaks, ensuring optimal memory management.
- **Code Coverage:** Implement a tool like `gcov` or `lcov` to automatically generate and publish code coverage reports, confirming that 100% of the logic branches are tested.
- **Dependency / Build Caching:** Update the GitHub Actions workflow (`.github/workflows/cpp_test.yml`) to cache dependencies and build artifacts to reduce workflow execution times.
- **Command Line Interface (CLI):** Allow the user to input arrays and target sums manually in the console (e.g., `./TwoSum "2 7 11 15" 9`).