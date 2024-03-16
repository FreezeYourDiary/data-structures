#include "ArrayList.h"


ArrayList::ArrayList():List() {
    this->capacity = 0;
    this->size = 0;
    this->array = nullptr;
}

ArrayList::ArrayList(int size): List(),capacity(2*size), size(size), array(new int[capacity]){
    for(int i = 0;i<size;i++){
        array[i]= rand()% UINT_MAX;
    }

}

ArrayList::~ArrayList() {
    delete[] array;
}

void ArrayList::AddBack(int element) {
    // Sprawdź, czy wystarcza miejsca w tablicy
    Enlarge();
    // Dodaj element do tablicy, size tu występuję jako index ostatniego elementu
    array[size++] = element;
    std::cout<<capacity<<size;
}

void ArrayList::AddFront(int element) {
    Enlarge(); //skipnie jak size != capacity
    for (int i = size; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = element;
    size++;
}

void ArrayList::Add(int element, int index) {
    for (int i = size; i > 0; --i) {
        array[i] = array[i - 1];
    }
    array[index] = element;
    size++;
}

int ArrayList::ReturnElement(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Błąd: Nieprawidłowy indeks" << std::endl;
        return -1; // Zwróć wartość domyślną w przypadku błędnego indeksu
    }
    return array[index];
}

bool ArrayList::RemoveBack() {
    if(isEmpty()){
        return false;
    }
    --size;
}

bool ArrayList::RemoveFront() {
    if(isEmpty()){
        return false;
    }
    for(int i =0;i<size-1;++i){
        array[i]=array[i+1];
    }
    size--;
}

bool ArrayList::Remove(int index) {
    if(isEmpty()){
        return false;
    }
    for(int i =index;i<size-1;++i){
        array[i]=array[i+1];
    }
    size--;
}

void ArrayList::Print() {
    for (int i =0;i<size;i++){
        std::cout<<"Liczba: "<<array[i]<<std::endl<<"Pod adresem: "<<&array[i]<<std::endl;
    }
}

bool ArrayList::Find(int element) {
    if(isEmpty()){
        return 0;
    }

    for(int i =0;i<size;i++){
        if(element==array[i]){
            std::cout<<"\n Znaleziono element pod adresem: "<<&array[i]<< "Liczba wynosi: "<<array[i];
        }
    }

}

void ArrayList::Enlarge() {

    if(Size_Capacity()){
        std::cout<<"\nEnlarging\n";
        // Jeśli nie, zwiększ pojemność tablicy dwukrotnie
        capacity *= 2;
        int* newArray = new int[capacity];
        // Skopiuj istniejące elementy do nowej tablicy
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        // Usuń starą tablicę i przypisz nową
//        std::cout<<"Adresy tablic:\n " <<&array <<std::endl << &newArray;
        delete[] array;
        array = newArray;

    }

}
bool ArrayList::Size_Capacity() {
    return size==capacity;
}
bool ArrayList::isEmpty() {
    return size==0;
}
int ArrayList::ReturnCapacity() {
    return this->capacity;
}
int ArrayList::ReturnSize() {
    return this->size;
}


