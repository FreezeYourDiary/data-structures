#ifndef PROJECT1_LIST_H
#define PROJECT1_LIST_H

class List{
public:
    List()= default;
    ~List() = default;

    virtual void AddFront(int element)=0;
    virtual void AddBack(int element) =0;
    virtual void Add(int element, int index)=0;

    virtual bool RemoveFront()=0;
    virtual bool RemoveBack()=0;
    virtual bool Remove(int index)=0;

    virtual bool Find(int element)=0;
    virtual int ReturnElement(int index)=0;
    virtual int ReturnSize()=0;
    virtual bool isEmpty()=0;

    virtual void Print()=0;


};



#endif //PROJECT1_LIST_H