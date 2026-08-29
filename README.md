<h1 align="center">Push_swap</h1>

<div align="center">
<img src="https://github.com/debsalbornoz/push_swap/assets/119970138/9f579a43-3c59-4020-b57e-e464e80880fd">
</div>

<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
<img alt="Static Badge" src="https://img.shields.io/badge/42-Project-blue">
<img alt="Static Badge" src="https://img.shields.io/badge/Language-C-lightgrey">
</div>

## Demo

[pshhh.webm](https://github.com/user-attachments/assets/dff23ac6-0189-4d67-a216-4fcf791724ec)

## Description

**Push_swap** is a project focused on sorting a stack of integers using two stacks and a limited set of basic operations. The goal is to sort the original stack using the smallest possible number of operations.

The project implements an efficient approach to solving the problem, taking into account the complexity of the operations and the need for optimization.

## Table of Contents

- [How It Works](#how-it-works)
  - [Sorting Small Stacks](#sorting-small-stacks)
- [Rules](#rules)
- [Installation & Build](#installation--build)

## How It Works

The program starts with two stacks, `a` and `b`. Stack `a` receives the program's arguments in the order they were passed, while `b` starts empty. The sorting algorithm is split into several interdependent steps, described below:

1. **Position setup**

    Each node in the stack is assigned a current position and a flag indicating whether it's above or below the stack's median. This helps determine which nodes are the "highest priority" to move first.

2. **Target node definition**

    For each node in stack `b`, the algorithm determines the best node in stack `a` to be its "target." The target is the smallest value in `a` that's still larger than the node in `b`. If no such value exists, the target is the smallest node in `a`.

3. **Move cost calculation**

    Each node in stack `b` is assigned a "cost" representing the total number of operations needed to move it into stack `a`. This cost is based on the node's current position in `b` and its target's position in `a`, taking into account whether the node is above or below the median — which affects the cheapest way to move it.

4. **Cheapest node selection**

    Among all nodes in stack `b`, the one with the lowest move cost is identified. That node is marked as the cheapest and is the next one to be moved.

This process repeats until every node has been sorted into stack `a`.

### Sorting Small Stacks

For small stacks, a dedicated function performs the sort using a basic set of operations:

- **Rotate** — rotates the stack upward, moving the first element to the bottom.
- **Reverse Rotate** — rotates the stack downward, moving the last element to the top.
- **Swap** — swaps the top two elements of the stack.

These operations are used to nudge the stack progressively closer to the desired order.

## Rules

- Only the basic operations may be used: `push`, `swap`, `rotate`, and `reverse rotate`.
- The sort must be efficient, minimizing the total number of operations.

## Installation & Build

1. Clone the repository:

    ```bash
    git clone https://github.com/debsalbornoz/push_swap.git
    ```

2. Move into the project directory:

    ```bash
    cd push_swap
    ```

3. Make sure a C compiler and the other required tools are installed on your system, then build the project:

    ```bash
    make
    ```

    This compiles the source code and generates the project's executable.

---

<p align="center">Built as part of the 42 curriculum 🖥️</p>
