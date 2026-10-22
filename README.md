# CPE010-CPE21S1

A portfolio repository for all **Hands-on Activities** completed in **CPE010** (Section **CPE21S1**). It documents a semester-long progression from basic C++ programming through core data structures, classic algorithms, and algorithm analysis.

| | |
|---|---|
| **Course** | CPE010 |
| **Section** | CPE21S1 |
| **Student** | _Your Name Here_ |
| **Instructor** | _Instructor Name Here_ |
| **Primary Language** | C++ |

---

## Table of Contents

- [About](#about)
- [Repository Structure](#repository-structure)
- [Topics Covered](#topics-covered)
- [Getting Started](#getting-started)
- [Using the Activities](#using-the-activities)
- [Academic Integrity Note](#academic-integrity-note)
- [Author](#author)

---

## About

This repository serves as a personal portfolio of hands-on laboratory work. Each activity lives in its own folder, numbered in the order it was taken in class, so the full learning path from fundamentals to advanced algorithmic topics can be followed from top to bottom.

---

## Repository Structure

```
CPE010-CPE21S1/
├── Hands-on Activity 1.1 Basic C++ Programming/
├── Hands-on Activity 2.1 Arrays, Pointers and Dynamic Memory Allocation/
├── Hands-on Activity 3.1 Linked Lists/
├── Hands-on Activity 4.1 Stacks/
├── Hands-on Activity 5.1 Queues/
├── Hands-on Activity 6.1 Searching Techniques/
├── Hands-on Activity 7.1 Sorting Algorithms Pt1/
├── Hands-on Activity 8.1 Sorting Algorithms Pt2/
├── Hands-on Activity 9.1 Tree ADT/
├── Hands-on Activity 10.1 Graphs/
├── Hands-on Activity 11.1 Basic Algorithm Analysis/
├── Hands-on Activity 12.1 Algorithmic Strategies/
├── Hands-on Activity 13.1 Parallel Algorithms and Multithreading Copy/
├── Hands-on Activity 14.1 Algorithm Complexity/
└── README.md
```

---

## Topics Covered

| # | Activity | Focus |
|---|----------|-------|
| 1.1 | [Basic C++ Programming](./Hands-on%20Activity%201.1%20Basic%20C%2B%2B%20Programming) | Syntax, input/output, control flow, functions |
| 2.1 | [Arrays, Pointers and Dynamic Memory Allocation](./Hands-on%20Activity%202.1%20Arrays%2C%20Pointers%20and%20Dynamic%20Memory%20Allocation) | Memory management, pointer operations, `new`/`delete` |
| 3.1 | [Linked Lists](./Hands-on%20Activity%203.1%20Linked%20Lists) | Node-based dynamic data structures |
| 4.1 | [Stacks](./Hands-on%20Activity%204.1%20Stacks) | LIFO data structure and its applications |
| 5.1 | [Queues](./Hands-on%20Activity%205.1%20Queues) | FIFO data structure and its applications |
| 6.1 | [Searching Techniques](./Hands-on%20Activity%206.1%20Searching%20Techniques) | Linear and binary search |
| 7.1 | [Sorting Algorithms Pt1](./Hands-on%20Activity%207.1%20Sorting%20Algorithms%20Pt1) | Introductory sorting algorithms |
| 8.1 | [Sorting Algorithms Pt2](./Hands-on%20Activity%208.1%20Sorting%20Algorithms%20Pt2) | More advanced sorting algorithms |
| 9.1 | [Tree ADT](./Hands-on%20Activity%209.1%20Tree%20ADT) | Tree structures and traversal |
| 10.1 | [Graphs](./Hands-on%20Activity%2010.1%20Graphs) | Graph representation and traversal |
| 11.1 | [Basic Algorithm Analysis](./Hands-on%20Activity%2011.1%20Basic%20Algorithm%20Analysis) | Measuring and comparing algorithm performance |
| 12.1 | [Algorithmic Strategies](./Hands-on%20Activity%2012.1%20Algorithmic%20Strategies) | Common problem-solving paradigms |
| 13.1 | [Parallel Algorithms and Multithreading](./Hands-on%20Activity%2013.1%20Parallel%20Algorithms%20and%20Multithreading%20Copy) | Concurrent and parallel execution |
| 14.1 | [Algorithm Complexity](./Hands-on%20Activity%2014.1%20Algorithm%20Complexity) | Time and space complexity, Big-O notation |

---

## Getting Started

### Prerequisites

- A C++ compiler such as **g++** (GCC), **clang++**, or **MSVC**
- Git
- Optionally, an IDE or editor such as Visual Studio Code, Code::Blocks, CLion, or an online compiler like OnlineGDB

### Clone the repository

```bash
git clone https://github.com/Pasioncpe/CPE010-CPE21S1.git
cd CPE010-CPE21S1
```

---

## Using the Activities

Open the folder of the activity you want to explore, then compile and run its source file. For example, with `g++`:

```bash
cd "Hands-on Activity 3.1 Linked Lists"
g++ -std=c++17 -Wall -o activity main.cpp
./activity          # On Windows: activity.exe
```

> Replace `main.cpp` with the actual source file name inside each folder. Folder names contain spaces, so wrap paths in quotes.

Some activities (for example, 13.1 on multithreading) may need extra compiler flags such as `-pthread`:

```bash
g++ -std=c++17 -pthread -o activity main.cpp
```

---

## Academic Integrity Note

This repository is a record of my own coursework and is shared for portfolio and reference purposes. If you are currently taking this course, please use it only as a study aid and complete your own activities in accordance with your school's academic integrity policies.

---

## Author

**_Your Name Here_**
GitHub: [@Pasioncpe](https://github.com/Pasioncpe)
