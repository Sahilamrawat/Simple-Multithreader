# Simple Multithreader C++ Assignment

## Overview

This assignment focuses on abstracting Pthread-based parallelism in C++ using a header-only library called `SimpleMultithreader`. By leveraging C++11 lambda expressions, this library simplifies the usage of multi-threading in C++ programs. The main objective is to reduce the complexity traditionally associated with parallelizing algorithms using Pthreads.

## Files Included

1. **simple-multithreader.h** - Header file containing the implementation of the `SimpleMultithreader` class.
2. **matrix.cpp** - Demonstrates the use of `SimpleMultithreader` for matrix multiplication.
3. **vector.cpp** - Demonstrates the use of `SimpleMultithreader` for vector addition.
4. **Makefile** - Provides the necessary commands to compile the programs with proper linking.

## Requirements

- C++ compiler supporting C++11 standard.
- Linux environment for Pthread compatibility.
- Basic understanding of C++ and lambda expressions.

## Setup and Compilation

To compile the programs, use the provided Makefile:

```bash
make all
```

This command will compile both `matrix.cpp` and `vector.cpp` using the settings defined in the Makefile.

## Usage

### Matrix Multiplication

To run the matrix multiplication program:

```bash
./matrix [numThreads] [matrixSize]
```

- `numThreads`: Number of threads to use for the calculation.
- `matrixSize`: Size of the matrix (e.g., 1024 for a 1024x1024 matrix).

### Vector Addition

To run the vector addition program:

```bash
./vector [numThreads] [vectorSize]
```

- `numThreads`: Number of threads to use for the addition.
- `vectorSize`: Size of the vectors.

## Implementation Details

`SimpleMultithreader` utilizes raw Pthreads and manages their lifecycle within each function call to `parallel_for`. It supports both single and two-dimensional loop parallelism. This implementation avoids the use of advanced C++ threading features to keep the abstraction simple and focused on demonstrating basic parallel execution.

## Evaluation

Your implementation will be tested using the provided example programs (`matrix.cpp` and `vector.cpp`). Ensure not to modify these examples as the evaluation will use identical copies to verify the correctness and performance of your implementation.

## Students

- Sahil Amrawat (2023462)
- Vikas Meena (2023593)
