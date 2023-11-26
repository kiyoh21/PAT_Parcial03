#include "Ejercicio01.h"
#include <queue>
#include <functional>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists) {
    auto comp = [](Node<int>* a, Node<int>* b) { return a->value < b->value; };
    std::priority_queue<Node<int>*, std::vector<Node<int>*>, decltype(comp)> pq(comp);

    // Insertar el primer elemento de cada lista en el heap
    Node<Node<int>*>* curr = lists;
    while (curr != nullptr) {
        if (curr->value != nullptr) {
            pq.push(curr->value);
        }
        curr = curr->next;
    }

    Node<int>* dummy = new Node<int>();
    Node<int>* tail = dummy;

    // Construir la lista resultante
    while (!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;

        if (tail->next != nullptr) {
            pq.push(tail->next);
        }
    }

    Node<int>* result = dummy->next;
    delete dummy;
    return result;
}
