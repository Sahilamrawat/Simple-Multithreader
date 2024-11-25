#include <iostream>
#include <functional>
#include <vector>
#include <pthread.h>
#include <chrono>
#include <cassert>

int user_main(int argc, char **argv);

/* Demonstration on how to pass lambda as a parameter. */
void demonstration(std::function<void()> &&lambda) {
    lambda();
}

// Thread argument structure for single-loop parallel_for
struct ThreadArgs {
    int low;
    int high;
    std::function<void(int)> lambda;
};

// Thread argument structure for nested-loop parallel_for
struct ThreadArgsDouble {
    int low1;
    int high1;
    int low2;
    int high2;
    std::function<void(int, int)> lambda;
};

void* thread_function_single(void* args) {
    ThreadArgs* arg = static_cast<ThreadArgs*>(args);
    for (int i = arg->low; i < arg->high; ++i) {
        arg->lambda(i);
    }
    return nullptr;
}

void* thread_function_double(void* args) {
    ThreadArgsDouble* arg = static_cast<ThreadArgsDouble*>(args);
    for (int i = arg->low1; i < arg->high1; ++i) {
        for (int j = arg->low2; j < arg->high2; ++j) {
            arg->lambda(i, j);
        }
    }
    return nullptr;
}

// Single-loop parallel_for
void parallel_for(int low, int high, std::function<void(int)> &&lambda, int numThreads) {
    if (numThreads <= 0) {
        std::cerr << "Error: Number of threads must be greater than zero.\n";
        exit(EXIT_FAILURE);
    }

    pthread_t threads[numThreads];
    std::vector<ThreadArgs> args(numThreads);

    int range = (high - low + numThreads - 1) / numThreads; // Divide work evenly
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; ++i) {
        int thread_low = low + i * range;
        int thread_high = std::min(high, thread_low + range);

        args[i] = {thread_low, thread_high, lambda};

        if (pthread_create(&threads[i], nullptr, thread_function_single, &args[i]) != 0) {
            std::cerr << "Error creating thread " << i << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Execution time: " << duration.count() << " microseconds\n";
}

// Nested-loop parallel_for
void parallel_for(int low1, int high1, int low2, int high2, std::function<void(int, int)> &&lambda, int numThreads) {
    if (numThreads <= 0) {
        std::cerr << "Error: Number of threads must be greater than zero.\n";
        exit(EXIT_FAILURE);
    }

    pthread_t threads[numThreads];
    std::vector<ThreadArgsDouble> args(numThreads);

    int range1 = (high1 - low1 + numThreads - 1) / numThreads; // Divide outer loop work evenly
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; ++i) {
        int thread_low1 = low1 + i * range1;
        int thread_high1 = std::min(high1, thread_low1 + range1);

        args[i] = {thread_low1, thread_high1, low2, high2, lambda};

        if (pthread_create(&threads[i], nullptr, thread_function_double, &args[i]) != 0) {
            std::cerr << "Error creating thread " << i << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Execution time: " << duration.count() << " microseconds\n";
}

int main(int argc, char **argv) {
    /* 
   * Declaration of a sample C++ lambda function
   * that captures variable 'x' by value and 'y'
   * by reference. Global variables are by default
   * captured by reference and are not to be supplied
   * in the capture list. Only local variables must be 
   * explicity captured if they are used inside lambda.
   */
    int x=5,y=1;
  // Declaring a lambda expression that accepts void type parameter
    auto /*name*/ lambda1 = /*capture list*/[/*by value*/ x, /*by reference*/ &y](void) {
    /* Any changes to 'x' will throw compilation error as x is captured by value */
    y = 5;
    std::cout<<"====== Welcome to Assignment-"<<y<<" of the CSE231(A) ======\n";
    /* you can have any number of statements inside this lambda body */
    };
    // Executing the lambda function
    demonstration(lambda1); // the value of x is still 5, but the value of y is now 5

    int rc = user_main(argc, argv);
    
    auto /*name*/ lambda2 = [/*nothing captured*/]() {
        std::cout<<"====== Hope you enjoyed CSE231(A) ======\n";
        /* you can have any number of statements inside this lambda body */
    };
    demonstration(lambda2);
    return rc;
}

#define main user_main
