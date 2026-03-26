# Deployment & Execution Guide

## 1. Introduction
Since this project is a standalone C++ application with an embedded test suite, "deployment" primarily consists of building and executing the code locally or within a containerized environment.

## 2. Local Execution
To build and run the project locally on your machine, you need a C++ compiler (`g++`) installed.

### Build Step
```bash
g++ -std=c++11 TwoSum.cpp -o TwoSum
```

### Execution Step
```bash
./TwoSum
```
Upon execution, the embedded unit tests will run and print the results to the console.

## 3. Docker Containerization
Docker provides an isolated environment to reliably build and run the application.

### Build the Docker Image
Navigate to the project root directory and run:
```bash
docker build -t twosum-project .
```

### Run the Docker Container
```bash
docker run --rm twosum-project
```
The `--rm` flag ensures the container is removed after the tests have finished executing.