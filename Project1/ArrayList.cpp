#include "ArrayList.h"

ArrayList::ArrayList(): List() {
    this->capacity = 0;
    this->size = 0;
    this->array = nullptr;
}

ArrayList::ArrayList(int size): List(), capacity(2 * size), size(size), array(new int[capacity]) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % UINT_MAX;
    }
}

ArrayList::~ArrayList() {
    delete[] array;
}

void ArrayList::AddBack(int element) {
    if (Size_Capacity()) {
        Enlarge();
    }
    array[size++] = element; // 2 in 1, dodaje element na pozycji size -> incrementuje size
}

void ArrayList::AddFront(int element) {
    if (Size_Capacity()) {
        Enlarge();
    }//skipnie jak size != capacity
    for (int i = size; i > 0; --i) {
        array[i] = array[i - 1];
    }
    array[0] = element;
    size++;
}

void ArrayList::Add(int element, int index) {
    if (Size_Capacity()) {
        Enlarge();
    }
    if (index < 0 || index > size) {
        std::cerr << "Error: Invalid index" << std::endl;
        return;
    }
    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];//każdy w prawo o pozycje
    }
    array[index] = element;
    size++;
}
// todo dodać ? możliwe to do metody FIND() by po prostu nie definiować 2 razy prawie to samo.
int ArrayList::ReturnElement(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Error: Invalid index" << std::endl;
        return 1;
    }
    return array[index];
}

bool ArrayList::RemoveBack() {
    if (isEmpty()) {
        return false;
    }
    //todo zwolnienie pamięci jeszcze??
    //Shrink();
    --size;

    return true;
}

bool ArrayList::RemoveFront() {
    if (isEmpty()) {
        return false;
    }
    for (int i = 0; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    //Shrink();
    size--;

    return true;
}

bool ArrayList::Remove(int index) {
    if (isEmpty() || index < 0 || index >= size) {
        return false;
    }
    for (int i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    //Shrink();
    size--;

    return true;
}

void ArrayList::Print() {
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout<<"Liczba: "<<array[i]<<std::endl<<"Pod adresem: "<<&array[i]<<std::endl;
    }
}

bool ArrayList::Find(int element) {
    if (isEmpty()) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (element == array[i]) {
            std::cout<<"Liczba: "<<array[i]<<std::endl<<"Pod adresem: "<<&array[i]<<std::endl;
            return true;
        }
    }
    std::cerr<<"Nieprawidlowy index";
    return false;
}

void ArrayList::Enlarge() {
    if(capacity!=0) //5 10
        capacity *= 2;
    else
        capacity = 2;
    int* newArray = new int[capacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

bool ArrayList::Size_Capacity() {
    return size == capacity;
}

bool ArrayList::isEmpty() {
    return size == 0;
}

int ArrayList::ReturnCapacity() {
    return this->capacity;
}

int ArrayList::ReturnSize() {
    return this->size;
}

void ArrayList::Load(const char *filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "issue with file, cannot open" << filename << std::endl;
        return;
    }
    int number;
    while(file>>number){
        AddBack(number);//addback bo jakby zczytywało linijka po linijce to by było też z tyłu
    }
    file.close();
}

//void ArrayList::Shrink() {
//    if (size < capacity / 2) {
//        int *newArray = new int[size];//shrinking itself 1
//        for (int i = 0; i < size; ++i) {
//            newArray[i] = array[i];
//        }//copy as usual
//        delete[] array;
//        array = newArray;
//        capacity = size;//shrinking itself 2
//    }
//}