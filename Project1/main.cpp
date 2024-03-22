#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"
#include "SinglyLinkedListHT.h"
#include "DLinkedList.h"
#include <chrono>
#include <list>
// LISTA [ADT] ---> ArrayList [kluczowe parametry size, capacity]
//             ---> Lista jednokierunkowa ---> Lista Dwukierunkowa????
// [ADT] nie przechowuje zmiennych?
// deklarujemy podstawowe operacje: stworzenie pustej(), add(), remove(), get(), set()
//

// funkcje :
// dodawania i usuwania elementu na różnych pozycjach:
//                  początek, koniec, losowe miejsce?
// dodatkowo: print(), clear(), printLenght(), find()...



void loop(List* lista);
bool listchoice();

/*int main() {
    const char *filename = "D:\\Downloads\\random_numbers.txt";
    const char* resfilename = "D:\\Downloads\\results.txt";
    std::ofstream resultFile(resfilename);
    if (!resultFile.is_open()) {
        std::cerr << "Issue with file, cannot open 'results.txt'" << std::endl;
        return 1;
    }
    std::ifstream file(filename); // Use ifstream for reading from a file
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    int array[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};

    for (int a = 0; a < 8; a++) {
        int *tab = new int[array[a]];
        int number;
        int i = 0;
        while (file >> number && i < array[a]) {
            tab[i] = number;
            i++;
        }
        auto start = std::chrono::steady_clock::now();
        SinglyLinkedList lista;
        for (int i = 0; i < array[a]; i++) {
            lista.Add(4000,tab[i]);
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        resultFile << elapsed << std::endl;
    }
    resultFile.close();
    file.close(); // File will be closed automatically when the ifstream object goes out of scope
}*/
int main() {
   while (!listchoice()); // no bo zwraca false dopoki nie default;
}
void loop(List* lista){

    lista->Print();
    bool cond = true;
    while (cond) {
        unsigned int wybor;
        std::cout << "Choose option 1-10? Or leave \"any other character on keyboard\": ";
        std::cout << "\n1. Load list from base[.txt file path required].\n2. Add a number to front of the list.\n3. Add a number to back of the list.\n4. Add number to place defined by you [index required].";
        std::cout << "\n5. Remove number from front of the list\n6. Remove number from back of the list\n7. Remove number from place defined by you [index required].";
        std::cout << "\n8. Clear the list [in process].\n9. Print the list.\n10. Find whether element (number) is in the list.\n";
        std::cin >> wybor; //dodać zabezpieczenie chociaz default jest zabezpieczeniem )
        int number, index;
        switch (wybor) {
            case 1:
                // obv dodać możliwość użytkownika wpisać adres.
                lista->Load("D:\\Downloads\\random_numbers.txt");
                break;
            case 2:
                std::cout << "Enter number to add to front: ";
                std::cin >> number;
                lista->AddFront(number);
                break;
            case 3:
                std::cout << "Enter number to add to back: ";
                std::cin >> number;
                lista->AddBack(number);
                break;
            case 4:
                std::cout << "Enter number and index to add: ";
                std::cin >> number >> index;
                lista->Add(number, index);
                break;
            case 5:
                lista->RemoveFront();
                break;
            case 6:
                lista->RemoveBack();
                break;
            case 7:
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                lista->Remove(index);
                break;
            case 8:
                lista->Clear();

                break;
            case 9:
                lista->Print();
                break;
            case 10:
                std::cout << "Enter number to find: ";
                std::cin >> number;
                lista->Find(number);
                break;
            default:
                std::cout << "Returning to main menu.\n";
                cond = false;
                break;
        }
    }
}
bool listchoice(){

    std::cout << "Choose your option\n";
    std::cout << "1. ArrayList\n2. SinglyLinkedList\n3. SinglyLinkedListHT\n4. DoubleLinkedList\n";
    std::cout << "Enter your choice (1-4): ";
    unsigned int choice;
    std::cin >> choice;
    List* lista = nullptr;
    switch (choice) {
        case 1:
            std::cout << "You chose ArrayList\n";
            lista = new ArrayList;
            loop(lista);
            // po pętli wyczyszcza listę, chociaż oczywisty problem kiedy chcemy w programie mieć 2 listy
            // ale myślę że dla tego typu projektu to nie jest ważne
            delete lista;
            return false;
        case 2:
            std::cout << "You chose SinglyLinkedList\n";
            lista = new SinglyLinkedList;
            loop(lista);
            delete lista;
            return false;
        case 3:
            std::cout << "You chose SinglyLinkedListHT\n";
            lista = new SinglyLinkedListHT;
            loop(lista);
            delete lista;
            return false;
        case 4:
            std::cout << "You chose DoubleLinkedList\n";
            lista = new DLinkedList;
            loop(lista);
            delete lista;
            return false;
        default:
            std::cout << "Exiting program.\n";
            return true;
    }
}

