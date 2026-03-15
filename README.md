# No More Traffic 🚦

![Language](https://img.shields.io/badge/Language-C-blue)
![Algorithm](https://img.shields.io/badge/Algorithm-Graph%20Scheduling-green)
![Complexity](https://img.shields.io/badge/Time%20Complexity-O(P×L)-orange)
![Project](https://img.shields.io/badge/Project-DAA-purple)

---


# Overview

**No More Traffic** is a project that implements a **Graph-Based Platoon Traffic Signal Scheduling Algorithm** to coordinate traffic signals so that groups of vehicles (platoons) can pass through multiple intersections without stopping.

The road network is modeled as a **directed graph**, where:

- **Vertices (nodes)** represent intersections
- **Edges** represent road segments with fixed travel time

The algorithm calculates **arrival times of platoons** at intersections and schedules **green signals** while preventing conflicts between crossing traffic.

---

# Problem Statement

Vehicles frequently stop at traffic signals because intersections are not properly synchronized. This leads to increased travel time and congestion.

The objective of this project is to design a scheduling algorithm that allows **vehicle platoons to move through intersections without stopping**, while ensuring that **conflicting traffic flows do not receive green signals at the same time**.

---

# Algorithm Used

This project uses a **Graph-Based Platoon Scheduling Algorithm**.

### Algorithm Idea

1. Represent the road network as a **directed graph**
2. Each **intersection is represented as a node**
3. Each **road is represented as an edge with travel time**
4. Vehicle platoons enter the network at a specific **entry time**
5. Calculate **arrival time at each intersection**
6. If the signal is available → **assign GREEN**
7. If the signal is occupied → **platoon is blocked**
8. Generate traffic statistics

---

# Traffic Network Model

The road network is represented as a **directed graph**.

```
        (3)
   0 --------> 1
               | \
             (4)|  \(5)
               v   v
               2 -> 3
                (2)
```

**Edge travel times**

| Road | Travel Time |
|-----|-------------|
| 0 → 1 | 3 |
| 1 → 2 | 4 |
| 2 → 3 | 2 |
| 1 → 3 | 5 |

---

# Platoon Paths Example

Example vehicle platoon movements:

```
Platoon 1: 0 → 1 → 2 → 3
Platoon 2: 0 → 1 → 3
```

The algorithm computes **arrival times** and schedules traffic signals accordingly.

---

# Algorithm Workflow

```
Input road network
        |
        v
Input platoons and paths
        |
        v
Sort platoons by entry time
        |
        v
Compute arrival time at intersections
        |
        v
Check signal availability
   /            \
GREEN         RED
  |             |
Allow        Block
movement     platoon
        |
        v
Generate results and statistics
```

---

# Time Complexity

```
O(P × L)
```

Where:

- **P** = number of platoons  
- **L** = number of intersections in a platoon path

### Space Complexity

```
O(V + E)
```

Where:

- **V** = number of intersections
- **E** = number of roads

---

# Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Structures Used**
  - Adjacency List (Graph)
  - Arrays (Signal Scheduling)
  - Structures (Platoon Representation)

---

# Project Structure

```
No-More-Traffic
│
├── src
│   └── traffic_scheduler.c
│
├── report
│   └── project_report.pdf
│
├── presentation
│   └── project_presentation.pptx
│
├── sample_input
│   └── example_input.txt
│
└── README.md
```

---

# Sample Input

```
Enter number of intersections: 4
Enter number of roads: 4

0 1 3
1 2 4
2 3 2
1 3 5

Enter number of platoons: 2

Platoon 1
Entry time: 2
Path length: 4
Path: 0 1 2 3

Platoon 2
Entry time: 3
Path length: 3
Path: 0 1 3
```

---

# Example Output

```
Platoon 1 Simulation
Time 5 : Intersection 1 GREEN for 0 -> 1
Time 9 : Intersection 2 GREEN for 1 -> 2
Time 11 : Intersection 3 GREEN for 2 -> 3

Platoon 2 Simulation
Time 6 : Intersection 1 GREEN for 0 -> 1
Time 11 : Intersection 3 RED

------ RESULTS ------
Successful Platoons: 1
Blocked Platoons: 1
Success Rate: 50%

Traffic Load per Intersection
Intersection 1 : 2 vehicles
Intersection 2 : 1 vehicles
Intersection 3 : 1 vehicles
```

---

# How to Run the Program

Compile the program:

```
gcc traffic_scheduler.c -o traffic
```

Run the program:

```
./traffic
```

Enter the required input when prompted.

---

# Applications

- Smart Traffic Management Systems
- Intelligent Transportation Systems
- Traffic Simulation and Research
- Smart City Infrastructure

---

# Future Improvements

- Real-time traffic data integration
- Dynamic signal optimization
- AI-based traffic prediction
- Graph visualization of the road network

---

# Author

Developed as part of **Design and Analysis of Algorithms (DAA)** coursework.

---

# License

This project is open-source and intended for **educational purposes**.
