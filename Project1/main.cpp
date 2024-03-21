#include <iostream>

#include "ArrayList.h"
#include "LinkedList.h"
#include "SinglyLinkedListHT.h"
#include "DLinkedList.h"
// LISTA [ADT] ---> ArrayList [kluczowe parametry size, capacity]
//             ---> Lista jednokierunkowa ---> Lista Dwukierunkowa????
// [ADT] nie przechowuje zmiennych?
// deklarujemy podstawowe operacje: stworzenie pustej(), add(), remove(), get(), set()
//

// funkcje :
// dodawania i usuwania elementu na różnych pozycjach:
//                  początek, koniec, losowe miejsce?
// dodatkowo: print(), clear(), printLenght(), find()...

//void LoadFrom(){
//    // też dać zabezpieczenie przed -/ dziwnymi znakami+spcjami chyba.
//}


int main() {
    
    ArrayList Option1;
    SinglyLinkedList Option2;
    SinglyLinkedListHT Option3;
    DLinkedList Option4;

    //W badaniach sprawdzamy: Operacje dodawania i usuwania na:
    //Początku list
    //Końcu List
    //Losowe miejsce na liście.
    //Dodatkowo użytkownik stawrza pustą listę, przeszukuje liste, Struktura zwraca element o podanym indexe.
    //Lista wypisuje swoje elementy.
    //TODO: Na wejściu decydujesz na której liście działasz (Option1, Option2 ...), i co nowe menu co chcesz zrobić.
    //dokończyć ten doublelinkedlist
    //Miernik czasu.
    //Ewenatulanie zapisywanie do pliku.
//    for (int i =0;i<=40;i++){
//        Option1.AddFront(i);
//        Option2.AddFront(i);
//        Option3.AddFront(i);
//        Option4.AddFront(i);
//    }
//    Option1.Find(32);
//    Option2.Find(32);
//    Option3.Find(32);
//    Option4.Find(32);
//
//    for (int i =0;i<=20;i++){
//        Option4.RemoveBack();
//    }
//    Option4.Print();
    const char* filename = R"(D:\Repos\SD\Project1\test.txt)"; //issue with relative path still.
    Option1.Load(filename);
    Option1.Print();


}
// function to menu
