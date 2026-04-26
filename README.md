# 📊 GraphLib

A lightweight C++ library focused on simplicity, performance, and clean organization for graph-based data structures and algorithms.

## ✨ Features

### **✅ Completed**
* **ADT Graph Implementation**: Core Abstract Data Type defining the standard graph interface.
* **Adjacency Matrix (`GraphMatrix`)**: Efficient implementation for dense graphs.
* **Simple and Unweighted Graphs**:
    * `getVertexCount()`: Returns the total number of vertices.
    * `getEdgeCount()`: Returns the total number of edges.
    * `getAdjacencyList(v)`: Retrieves the neighbors of a specific vertex.
    * `toString()`: Returns a formatted string representation of the graph.
    * `addEdge(u, v)`: Inserts an edge between two vertices.

### **🛠️ In Development**
* **Adjacency List (`GraphList`)**: Optimized implementation for sparse graphs.
* **Dynamic Management**: Methods for adding/removing vertices and edges at runtime.
* **Graph Classification**: Algorithms to identify properties (connectivity, cycles, bipartite, etc.).
* **Directed Graphs (Digraphs)**: Support for directed edge implementation and algorithms.

---

## 📁 Project Structure

```text
graphlib/
├── include/graphlib/     # Public Headers (.hpp)
├── src/                  # Implementation Files (.cpp)
├── tests/                # Unit Tests (Catch2/GTest or Custom)
├── examples/             # Usage Examples
└── CMakeLists.txt        # Build System Configuration
```

---

## ⚙️ Building the Project

Ensure you have **CMake 3.10+** and a **C++17** compatible compiler installed.

```bash
# Clone the repository
git clone https://github.com/Gian-Figueiredo/graphlib.git
cd graphlib

# Configure and build
cmake -S . -B build
cmake --build build
```

---

## ▶️ Usage Example

```cpp
#include <iostream>
#include "graphlib/graph_matrix.hpp"

int main() {
    // Example: Creating a simple graph with 5 vertices
    graphlib::GraphMatrix myGraph(5);

    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 4);

    std::cout << "Vertex Count: " << myGraph.getVertexCount() << std::endl;
    std::cout << myGraph.toString() << std::endl;

    return 0;
}
```

---

## 🧪 Running Tests

After building the project, run the tests using `ctest` or the generated executable:

```bash
cd build
ctest --output-on-failure
```

Or run the test binary directly:

```bash
./build/tests/test_graph
```

---

## 📌 Requirements

* **Standard:** C++17 or higher.
* **Build System:** CMake 3.15+.
* **Compiler:** GCC 9+, Clang 10+, or MSVC 2019+.

---

## 🧠 Design Principles

* **Namespacing**: All components are wrapped in the `namespace graphlib` to prevent naming collisions.
* **Decoupling**: Strict separation between interface (`include/`) and implementation (`src/`).
* **Performance**: Minimal overhead with a focus on efficient memory usage for matrix representations.

---

## 🤝 Contributing

Contributions make the open-source community an amazing place to learn and create.
1. Fork the Project.
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`).
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the Branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

---

## 📄 License

Distributed under the **MIT License**. See `LICENSE` for more information.

---

## 🎯 Project Goal

This project started as an educational endeavor to master Data Structures and is evolving into a modular, reusable C++ library for academic and professional applications.