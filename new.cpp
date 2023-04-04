#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    // find
    Array(int size);
    string checkArrayEmpty();
    void append(int num);
    void insert(int element, int index);
    void edit(int element, int index);
    void displayArray();
    void deleteElement(int index);
    int getEle(int index);
    bool isArrayFull();
    void countEle();
    void sort();
    int greatestEle();
    int smallEle();
    int search(int ele);
    int sum();
    float avg();
    void rotatearr(int by);
    int secondLargest();
    void swap(int index1, int index2);
    void remdupli();

    ~Array();
};

// version 2 in this version we are going to add sorting,greatest element ,smallest element,search ele,sum of all element,average of all ele,rotate,
void Array::remdupli()
{
    int i, j;
    int temp;
    for (j = 0; j <= lastindex; j++)
    {
        temp = ptr[j];
        for (i = 1; i <= lastindex; i++)
        {
            if (temp == ptr[i])
            {
                deleteElement(ptr[i]);
            }
        }
    }
}
void Array::swap(int index1, int index2)
{
    int temp;
    temp = ptr[index1];
    ptr[index1] = ptr[index2];
    ptr[index2] = temp;
}
int Array::secondLargest()
{
    sort();
    return ptr[lastindex - 1];
}
void Array::rotatearr(int by)
{
    int i;
    int j;
    int temp;

    for (j = 0; j < by; j++)
    {
        temp = ptr[0];
        for (i = 0; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        ptr[lastindex] = temp;
    }
}
float Array::avg()
{
    int i;
    float avg = 0;
    float sum = 0;
    for (i = 0; i <= lastindex; i++)
    {
        sum = sum + ptr[i];
    }
    avg = sum / (lastindex + 1);
    return avg;
}
int Array::sum()
{
    int i;
    int sum = 0;
    for (i = 0; i <= lastindex; i++)
    {
        sum = sum + ptr[i];
    }
    return sum;
}
int Array::search(int ele)
{
    int i;
    int count = 0;
    for (i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == ele)
        {
            count++;
            break;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
int Array::smallEle()
{
    sort();
    return ptr[0];
}
int Array::greatestEle()
{
    sort();
    return ptr[lastindex];
}
void Array::sort()
{
    int i,j;
    int temp;
    // in sorting we are using bubble sort technique
      for(j=0;j<lastindex;j++)
    {
      for (i = 0; i < lastindex; i++)
      {
         if (ptr[i + 1] < ptr[i])
        {
            temp = ptr[i];
            ptr[i] = ptr[i + 1];
            ptr[i + 1] = temp;
        }
      }
        
    }
}

// version 1
Array::~Array()
{
    delete[] ptr;
}
void Array::countEle()
{
    cout << "Number element present is " << lastindex + 1 << endl;
}
bool Array::isArrayFull()
{
    // this is how sir taught to make this function
    return lastindex == capacity - 1;
}
int Array::getEle(int index)
{
    if (index == -1 || index > lastindex)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        return ptr[index];
    }
}
void Array::deleteElement(int index)
{
    if (lastindex == -1)
    {
        cout << "Array is Empty" << endl;
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
void Array::displayArray()
{
    int i;
    for (i = 0; i <= lastindex; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}
void Array::edit(int index, int num)
{
    ptr[index] = num;
}
void Array::insert(int index, int num)
{
    if (lastindex == capacity - 1)
    {
        cout << "Array is already full" << endl;
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
        ptr[index] = num;
        lastindex++;
    }
}
Array::Array(int size)
{
    // inside Array constructor we will make dynamic array with the help of new
    ptr = new int[size];
    capacity = size;
    lastindex = -1;
    cout << capacity << endl;
    cout << lastindex << endl;
}

string Array::checkArrayEmpty()
{
    if (lastindex == -1)
        return "True";
    else
        return "False";
}

void Array::append(int num)
{
    if (lastindex == capacity - 1)
    {
        cout << endl;
        cout << "Error Array is already full";
    }
    else
    {
        lastindex++;
        ptr[lastindex] = num;
    }
}

int main()
{
    // Array a(11);
    // cout << a.checkArrayEmpty();
    // a.append(11);
    // cout << endl;
    // a.append(22);
    // a.append(33);
    // a.append(44);
    // a.displayArray();
    // a.insert(1, 9);
    // a.displayArray();
    // a.edit(3, 32);
    // a.displayArray();
    // a.append(55);
    // a.append(67);
    // a.append(78);
    // a.displayArray();
    // a.deleteElement(5);
    // a.displayArray();
    // cout << a.getEle(4) << endl;
    // if (a.isArrayFull())
    //     cout << "Array is full" << endl;
    // else
    //     cout << "Array is not full" << endl;
    // a.countEle();
    // a.sort();
    // a.displayArray();
    // cout << a.greatestEle() << endl;
    // cout << a.smallEle() << endl;
    // cout << a.search(67) << endl;
    // cout << a.sum() << endl;
    // cout << a.avg() << endl;
    // a.rotatearr(1);
    // a.displayArray();
    // a.rotatearr(2);
    // a.displayArray();
    // a.rotatearr(3);
    // a.displayArray();
    // a.swap(1, 2);
    // a.displayArray();
    // a.append(11);
    // a.append(22);
    // a.append(78);
    // a.append(67);
    // a.displayArray();
    // a.remdupli();
    // a.displayArray();
      Array a(5);
      a.append(8);
      a.append(9);
      a.append(1);
      a.append(3);
      a.append(5);
      a.sort();
      a.displayArray();
    return 0;
}