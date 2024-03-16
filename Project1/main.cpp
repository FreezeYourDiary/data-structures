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
    lista.Add(1,0);
    lista.AddFront(5);
    lista.AddBack(6);

    lista.RemoveFront();
    lista.Print();

}

