#include "Ejercicio02.h"
#include <unordered_map>

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head) {
    vector<string>* result = new vector<string>();
    if (head == nullptr) return result;

    unordered_map<string, int> sequenceCount;
    Node<char>* current = head;
    string currentSequence;

    // Recopilar secuencias de 10 caracteres
    while (current != nullptr) {
        currentSequence.push_back(current->value);
        if (currentSequence.size() > 10) {
            currentSequence.erase(0, 1); // Mantiene solo los últimos 10 caracteres
        }

        if (currentSequence.size() == 10) {
            sequenceCount[currentSequence]++;
        }

        current = current->next;
    }

    // Identificar secuencias repetidas
    for (const auto& pair : sequenceCount) {
        if (pair.second > 1) {
            result->push_back(pair.first);
        }
    }

    return result;
}

