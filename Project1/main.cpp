#include <iostream>
#include "ArrayList.h"
#include <vector>

#include "LinkedList.h"

// LISTA [ADT] ---> ArrayList [kluczowe parametry size, capacity]
//             ---> Lista jednokierunkowa ---> Lista Dwukierunkowa????
// [ADT] nie przechowuje zmiennych?
// deklarujemy podstawowe operacje: stworzenie pustej(), add(), remove(), get(), set()
//

// funkcje :
// dodawania i usuwania elementu na różnych pozycjach:
//                  początek, koniec, losowe miejsce?
// dodatkowo: print(), clear(), printLenght(), find()...




int main() {
    SinglyLinkedList lista;
    lista.Add(0,0);
    lista.Add(9,9);
    lista.Print();
    std::cout<<lista.Find(0);
    std::cout<<lista.Find(2);
}

