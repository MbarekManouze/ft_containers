# FT_CONTAINERS

This project focuses on creating custom C++ containers from scratch, including vector, stack, and map (implemented as a binary search tree AVL). The goal is to gain a deep understanding of data structures and algorithms while implementing these fundamental container types in C++.

## Overview

The project aims to replicate the functionality of standard C++ containers like vector, stack, and map, using custom implementations. Each container is designed to provide efficient storage and retrieval of data, utilizing advanced techniques and algorithms for optimal performance.

## Features

**Vector**: The custom vector implementation provides dynamic array-like behavior, allowing for efficient insertion, deletion, and access to elements. It utilizes the substitution failure is not an error (SFINAE) method for improved error handling and introduces custom allocator support for memory management. Additionally, it includes a custom iterator class for traversing elements in its underlying structure.

**Stack**: The custom stack implementation follows the last-in, first-out (LIFO) principle, supporting push, pop, and top operations. It leverages the SFINAE technique and custom allocator to ensure robust error handling and efficient memory management. It also includes a custom iterator class for traversing elements in its underlying structure.

**Map (Binary Search Tree AVL)**: The custom map implementation is based on a binary search tree AVL (Adelson-Velsky and Landis) for efficient key-value pair storage and retrieval. It employs advanced balancing techniques to maintain the tree's height balance and ensure optimal performance. It also includes a custom iterator class for traversing elements in its underlying structure.

## Techniques Used

**Substitution Failure Is Not An Error (SFINAE)**: The SFINAE technique is employed to enable elegant error handling and enable or disable certain template instantiations based on compile-time conditions.

**Custom Namespaces**: Custom namespaces are utilized to organize the container implementations and prevent naming conflicts with standard library containers.

**Custom Allocator**: Custom allocators, inspired by those used in the standard vector container, are implemented to manage memory allocation and deallocation. These allocators include methods such as construct and destroy for object construction and destruction.

**Custom Iterator**: Each container includes a custom iterator class for traversing elements in its underlying structure. These iterators provide support for operations like dereferencing, incrementing, and comparing elements.

