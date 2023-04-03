#include<iostream>
using namespace std;


class DynArray
{
    //find
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        DynArray(int size);
        void doubleArray();
        void halfArray();
        int Ccapacity();
        bool checkArrayempty();
        void append(int element);
        void insert(int index,int element);
        void edit(int index,int element);
        void deleteElement(int index);
        void displayArray();
        int getlastindex();
};

//version 2 we will copy data first array when we make double array or half array
void DynArray::displayArray()
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}
int DynArray::getlastindex()
{
    return lastindex;
}


//this is version 1 in this we created just basic structure of our class
void DynArray::deleteElement(int index)
{
    if (lastindex == -1)
    {
        halfArray();
          int i;
        for (i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;

    }
    else if (index == -1 || index > lastindex)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        int i;
        for (i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;
    }
}
void DynArray::edit(int index,int element)
{
    ptr[index] = element;
}
void DynArray::insert(int index, int element)
{
    if (lastindex == capacity - 1)
    {
        doubleArray();
        int i;
        for (i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        lastindex++;
        ptr[index] =element;
    }
    else if (index < 0 || index >= lastindex + 1)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        int i;
        for (i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = element;
        lastindex++;
    }
}
void DynArray::append(int element)
{
    if (lastindex == capacity - 1)
    {
        doubleArray();
        lastindex++;
        ptr[lastindex]=element;
        
    }
    else
    {
        lastindex++;
        ptr[lastindex] = element;
    }
}

bool DynArray::checkArrayempty()
{
    if (lastindex == -1)
        return 1;
    else
        return 0;
}
DynArray::DynArray(int size)
{
    ptr=new int[size];
    lastindex=-1;
    capacity=size;
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    int i;
    for(i=0;i<=lastindex;i++)
    {
        temp[i]=ptr[i];
    }
    delete[]ptr;
    ptr=temp;
    capacity=capacity*2;
    
}
void DynArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    delete[]ptr;
    ptr=temp;
    capacity=capacity/2;
}
int DynArray::Ccapacity()
{
    return capacity;
}



int main()
{
    DynArray a(5);
    a.append(12);
    a.append(23);
    a.append(34);
    a.append(45);
    a.append(56);
    a.displayArray();
    cout<<a.Ccapacity()<<endl;
    a.append(67);
    a.displayArray();
    cout<<a.Ccapacity()<<endl;
    cout<<a.getlastindex()<<endl;
    a.insert(5,44);
    a.displayArray();

    return 0;
}