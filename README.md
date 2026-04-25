# GraphLib

Biblioteca de grafos em C++ focada em simplicidade, desempenho e organização.

## ✨ Funcionalidades

> Em desenvolvimento:
* Criação de grafos
* Adicionar Arestas e vértices
* Classificar grafos
* Criar Dígrafos

---

## 📁 Estrutura do projeto

```
graphlib/
├── include/graphlib/     # Headers públicos
├── src/                  # Implementações
├── tests/                # Testes
├── examples/             # Exemplos de uso
├── CMakeLists.txt
```

---

## ⚙️ Como compilar

```bash
git clone https://github.com/seu-usuario/graphlib.git
cd graphlib

mkdir build
cd build

cmake ..
make
```

---

## ▶️ Como usar

```cpp
#include <graphlib/graph.h>
#include <iostream>

int main() {
    graphlib::Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    for (int v : g.neighbors(0)) {
        std::cout << v << std::endl;
    }

    return 0;
}
```

---

## 🧪 Rodando os testes

```bash
cd build
ctest
```

Ou diretamente:

```bash
./test_graph
```

---

## 📌 Dependências

* C++17 ou superior
* CMake 3.10+

---

## 🧠 Design

* Uso de `namespace graphlib` para evitar conflitos
* Separação clara entre `include/` e `src/`
* API simples e extensível

---

## 🤝 Contribuição

Pull requests são bem-vindos. Para mudanças grandes, abra uma issue antes para discutir.

---

## 📄 Licença

MIT License (ou escolha outra de sua preferência)

---

## 💡 Objetivo

Este projeto foi criado com foco educacional e evolução para uma biblioteca reutilizável de grafos em C++.

---
