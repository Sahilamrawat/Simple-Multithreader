# Simple Multithreader C++ Assignment

## Overview

This assignment focuses on abstracting Pthread-based parallelism in C++ using a header-only library called `SimpleMultithreader`. By leveraging C++11 lambda expressions, this library simplifies multi-threading usage in C++ programs. The main objective is to reduce the complexity traditionally associated with parallelizing algorithms using Pthreads.

## Files Included

1. **simple-multithreader.h** - Header file containing the `SimpleMultithreader` class implementation.
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
- `matrixSize`: Matrix size (e.g., 1024 for a 1024x1024 matrix).

### Vector Addition

To run the vector addition program:

```bash
./vector [numThreads] [vectorSize]
```

- `numThreads`: Number of threads to use for the addition.
- `vectorSize`: Size of the vectors.

## Implementation Details

`SimpleMultithreader` utilizes raw Pthreads and manages their lifecycle within each function call to `parallel_for`. It supports both single and two-dimensional loop parallelism. This implementation avoids using advanced C++ threading features to simplify the abstraction and focuses on demonstrating essential parallel execution.

## Students

- Sahil Amrawat (2023462)
- Vikas Meena (2023593)
