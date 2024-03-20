#include "DLinkedList.h"

DLinkedList::DLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

DLinkedList::~DLinkedList() {
    DNode* current = head;
    while (current != nullptr) {
        DNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DLinkedList::AddFront(int element) {
    DNode* newNode = new DNode(element);
    if (!head) {            //If head=nullptr, lista pusta.
        head = newNode;     //Czyli ustawiamy head i tail jako nowy element. 
        tail = newNode;
    }
    else {                          //Lista nie jest pusta.
        newNode->next = head;       //Ustawia next na nowego wez³¹ na obecny head 
        head->prev = newNode;       //Ustawua preva na bie¿¹cego heda na nowy wêze³ 
        head = newNode;             //Head ma wskazywac na nowy wêze³ 
    }
}

void DLinkedList::AddBack(int element) {
    DNode* newNode = new DNode(element);
    if (!tail) {
        head = newNode;
        tail = newNode;
    }
    //ustawia poprzednika nowego Node na aktualny tail(ogn) listy--->ustawia wskaŸnik na nastêpny element ogona 
    // na nowy wêze³, a dalej linia aktualizuje wskaŸnik ogona na nowy wêze³, który staje siê nowym koñcem listy.
    else {
        newNode->prev = tail;
        tail->next = newNode;   
        tail = newNode;         
    }
}

void DLinkedList::Add(int element, int index) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index\n";
        return;
    }

    if (index == 0) {
        AddFront(element);
    }
    else if (index == size) {
        AddBack(element);
    }
    else {
        DNode* newNode = new DNode(element);
        DNode* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
  
    }
}

bool DLinkedList::RemoveFront() {
    if (isEmpty()) {
        std::cout << "List is empty\n";
        return false;
    }
    DNode* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete temp;

    return true;
}
bool DLinkedList::Remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid position\n";
        return false;
    }
    if (index == 0) {
        return RemoveFront();
    }
    if (index == size - 1) {
        return RemoveBack();
    }
    DNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    //usuwa ten wêze³.Pierwsza linia aktualizuje wskaŸnik nastêpnego elementu poprzednika, 
    // natomiast druga aktualizuje wskaŸnik poprzedniego elementu nastêpnego wêz³a bie¿¹cego, 
    // a nastêpnie usuwa bie¿¹cy wêze³, zmniejsza rozmiar listy o 1.(Rozmiar jeszcze ustalimy czy jest potrzebny) XD
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
    return true;
}

void DLinkedList::Print() {
    DNode* current = head;
    while (current != nullptr) {
        std::cout << current->number << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool DLinkedList::Find(int element) { //S¹ ciê¿ary, jutro bêdzie lepiej :-P

}

int DLinkedList::ReturnElement(int index) { //Jestem bardzo zmêczony, trzeba zrbiæ to jeszcze i bêdzie ok:)
 
}