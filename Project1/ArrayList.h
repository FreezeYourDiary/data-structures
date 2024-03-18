#ifndef PROJECT1_ARRAYLIST_H
#define PROJECT1_ARRAYLIST_H
#include "List.h"
#include <iostream>
#include <random>

class ArrayList: List {
private:
    int capacity; // Pojemność listy (rozmiar tablicy)
    int size;     // Aktualna liczba elementów w liście
    int* array;   // Wskaźnik na tablicę przechowującą elementy

public:
    // Konstruktor (stwarza pustą listę)
    ArrayList();
    // Konstruktor listy o zdefiniowanym rozmiarze + generuje wypełnia tą listę losowymi liczbami
    ArrayList(int size);
    ~ArrayList();

    int ReturnCapacity();
    int ReturnSize() override;
    bool isEmpty() override;

    int ReturnElement(int index)override;

    bool Find(int element)override;
    // Funkcja dodająca element do listy
    bool Size_Capacity();
    void Enlarge();

    void AddBack(int element) override;
    void AddFront(int element) override;
    void Add(int element, int index) override;

    bool RemoveBack()override;
    bool RemoveFront()override;
    bool Remove(int index)override;

    // Funkcja zwracająca element na podanej pozycji

    void Print()override;
};


#endif //PROJECT1_ARRAYLIST_H