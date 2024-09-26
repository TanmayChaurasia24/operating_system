# Bélády’s Anomaly in Page Replacement Algorithms

In an Operating System, process data is loaded in fixed-sized chunks, with each chunk referred to as a **page**. The processor loads these pages into fixed-sized chunks of memory called **frames**. Typically, the size of each page is equal to the frame size.

A **page fault** occurs when a page is not found in memory and needs to be loaded from the disk.

When a page fault occurs and all memory frames have been already allocated, a replacement of a page in memory is required to load the new page. This process is known as **demand-paging**.

Page replacement algorithms determine which page to replace when memory is full. Common page replacement algorithms include:
- **FIFO (First-In-First-Out)**
- **LRU (Least Recently Used)**
- **Optimal page replacement**

---

## What is a Page Fault?

A **page fault** is a type of interrupt or exception that occurs when a program tries to access a page of memory that is not currently loaded into physical RAM (Random Access Memory). Instead, the page resides on disk in a storage space called the **page file** or **swap space**.

---

## What is Bélády’s Anomaly?

**Bélády’s Anomaly** refers to the phenomenon where increasing the number of page frames can result in an increase in the number of page faults for a given memory access pattern.

This anomaly is typically observed in the following page replacement algorithms:
- **First-In-First-Out (FIFO)**
- **Second Chance Algorithm**
- **Random Page Replacement Algorithm**

---

## Reason for Bélády’s Anomaly

1. The **Optimal** and **LRU (Least Recently Used)** algorithms do not experience Bélády’s Anomaly. These algorithms belong to a class of **stack-based page replacement algorithms**.

2. A **stack-based algorithm** ensures that the set of pages in memory with N frames is always a subset of the pages that would be in memory with N+1 frames.

3. In **LRU replacement**, the set of pages in memory represents the N most recently referenced pages. As the number of frames increases, these N pages will remain the most recently referenced and thus stay in memory, preventing Bélády’s Anomaly.

4. In contrast, **FIFO** (First-In-First-Out) does not follow a stack-based page replacement policy. For example, if a page `b` was loaded into physical memory before a page `a`, the priority for replacing `b` is higher, regardless of the number of page frames. This non-stack behavior is why **FIFO** can experience Bélády’s Anomaly.
