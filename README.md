# Algorithm

My problem-solving log for algorithms and data structures, written in C++.
Every accepted solution on [Baekjoon Online Judge](https://www.acmicpc.net/) is committed here automatically through [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub), so the history of this repository is a record of what I actually solved and when.

[![Solved.ac Profile](http://mazassumnida.wtf/api/v2/generate_badge?boj=rlaghkstn511)](https://solved.ac/profile/rlaghkstn511)

## Why this repository exists

The goal is to build algorithmic fundamentals that hold up under time pressure, for technical coding assessments in 2027 and for the implementation work that research in autonomous driving requires.

Current level: **Gold III** on [solved.ac](https://solved.ac/profile/rlaghkstn511).

## Plan (December 2026 – April 2027)

The roadmap covers every topic in solved.ac CLASS 1–5, about 130 problems in total.

| Period | Stage | Focus |
| --- | --- | --- |
| Dec 17 – Jan 3 | Review (Silver IV – I) | Re-solve problems I solved before, from a blank file and under a time limit: stacks, queues, greedy, two pointers, BFS/DFS, trees, heaps, basic DP, binary search |
| Jan 4 – Jan 24 | New Silver problems | Divide and conquer, backtracking, graph search, prefix sums, sets and maps, bitmasking, coordinate compression, combinatorics |
| Jan 25 – Feb 7 | Entering Gold | Multi-dimensional BFS, simulation, knapsack DP, two pointers |
| Feb 8 – Feb 28 | Advanced algorithms (CLASS 4–5) | Dijkstra, Bellman-Ford, Floyd-Warshall, 0-1 BFS, matrix exponentiation, LCS, union-find, topological sort, MST, tree DP, geometry (CCW) |
| Mar 1 – Apr 11 | Exam practice (Gold IV – II) | Implementation-heavy simulation problems in the style of Korean industry coding tests |

## How I work

- **Time limit:** each problem gets 30 minutes. If I am stuck, I read a solution, write down exactly where I got stuck, and solve it again a few days later without looking.
- **Weekly mock test:** every weekend, two unseen problems in 60 minutes, one easier and one harder, with the result and the mistakes logged.
- **Re-solving:** earlier solutions are re-solved from scratch rather than reread, so that this repository reflects what I can do now, not what I once did.

## Structure

```
백준/
├── Bronze/
├── Silver/
├── Gold/
└── Platinum/
    └── <problem number>. <title>/
        ├── <solution>.cc
        └── README.md   # problem statement, category, time and memory
```

Folder names are in Korean (백준 = Baekjoon) because BaekjoonHub generates them automatically.

## Language

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)
