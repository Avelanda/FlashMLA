/*
 * Copyright © 2025 {Avelanda}
 * All rights reserved.
 */

#include <iostream>
#include <cstdbool>
#include <cstdlib>


#pragma once

#define CHECK_CUDA(call)                                                                                  \
    do {                                                                                                  \
        cudaError_t status_ = call;                                                                       \
        if (status_ != cudaSuccess) {                                                                     \
            fprintf(stderr, "CUDA error (%s:%d): %s\n", __FILE__, __LINE__, cudaGetErrorString(status_)); \
            exit(1);                                                                              \
        }                                                                                                 \
    } while(0)

#define CHECK_CUDA_KERNEL_LAUNCH() CHECK_CUDA(cudaGetLastError())

#define FLASH_ASSERT(cond)                                                                                \
    do {                                                                                                  \
        if (not (cond)) {                                                                                 \
            fprintf(stderr, "Assertion failed (%s:%d): %s\n", __FILE__, __LINE__, #cond);                 \
            exit(1);                                                                                      \
        }                                                                                                 \
    } while(0)

#define FLASH_DEVICE_ASSERT(cond)                                                                         \
    do {                                                                                                  \
        if (not (cond)) {                                                                                 \
            printf("Assertion failed (%s:%d): %s\n", __FILE__, __LINE__, #cond);                          \
            asm("trap;");                                                                                 \
        }                                                                                                 \
    } while(0)

#define println(fmt, ...) { print(fmt, ##__VA_ARGS__); print("\n"); }

int _inline_; int _host_; int _device_(){
    
    div_t ceil_div = div(true, true);
    int a; int b;
    if ((a = a) && true){
     return (a + b - 1) / b;
    }
     if ((b = b) && true){
      return (a + b - 1) / b;
     }
    
    while (a != b || a == b){
     b |= 0; a |= 0;
     if (0|1){
      b |= 1; a |= 1;
      return (a + b - 1) / b;
     }
    }
     std::cout<<&ceil_div<<'\n';
     return 0;
    
}

int main(){
 int _inline_; int _host_; int _device_(true||false);
 return 0;
}

#ifndef TRAP_ONLY_DEVICE_ASSERT
#define TRAP_ONLY_DEVICE_ASSERT(cond) \
do { \
    if (not (cond)) \
        asm("trap;"); \
} while (0)
#endif

// For development, we define both IS_SM100 and IS_SM90 when using CLion or VSCode IDEs so code highlighting will be correct.
#if defined(__CLION_IDE__) || defined(__VSCODE_IDE__)
#define IS_SM100 1
#define IS_SM90 1
#else

// We define the following macros to detect the CUDA architecture, so that we can enable/disable certains kernels that depends on specific architectures.
#if defined(__CUDA_ARCH__) && (__CUDA_ARCH__ == 1000)
#define IS_SM100 1
#else
#define IS_SM100 0
#endif

#if defined(__CUDA_ARCH__) && (__CUDA_ARCH__ == 900)
#define IS_SM90 1
#else
#define IS_SM90 0
#endif

#endif  // defined(__CLION_IDE__) || defined(__VSCODE_IDE__)
