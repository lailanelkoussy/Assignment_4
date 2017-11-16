//
// Created by Laila Nasser ElKoussy 900160812 on 11/6/17.
//

#include "hashTable.h"
#include <iostream>
#include <cmath>

using namespace std;

template <class keyType, class dataType>
hashTable<keyType, dataType>::hashTable()
{
    MaxSize = 149;
    T = new slot[MaxSize];
    Empty = 0;
    for (int i=0; i<MaxSize; i++)
    {   T[i].key = Empty;
        T[i].next = nullptr; }
    h = 0;

    csize = 0;

}

template <class keyType, class dataType>
hashTable<keyType, dataType>::~hashTable() {
   /* slot * temp1, *temp2;

    for (int i =0; i<MaxSize; i++) {
        temp1 = T[i].next;
        T[i].next = nullptr;
        temp2 = temp1;

        while ((temp1 != nullptr) && (temp2 != nullptr)){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2->next;
            delete temp2;
        }
    }
    delete T;*/
}

template <class keyType, class dataType>
void hashTable<keyType,dataType>::makeTableEmpty(const keyType &k) {
    slot *temp1, *temp2;
    Empty = k;
    for (int i = 0; i<MaxSize; i++) {
        T[i].next = nullptr;
        T[i].key = Empty;
        temp1 = T[i].next;
        temp2 = temp1;

        while ((temp1 != nullptr) && (temp2 != nullptr)){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2->next;
            delete temp2;
        }
    }

    csize = 0;

}

template <class keyType, class dataType>
bool hashTable<keyType, dataType>::tableIsEmpty() const
{
    if (csize == 0)
        return true;
    else return false;
}

template <class keyType, class dataType>
bool hashTable<keyType, dataType>::tableIsFull() const
{
    if (csize == 60389)
        return true;
    else return false;
}

template <class keyType, class dataType>
void hashTable<keyType, dataType>::insert(const dataType &d)
{
    keyType k;
    h = hash(d, k);
    csize++;
    slot * temp1;;
    if (tableIsFull())
        return;

    if (T[h].key == Empty)
    {
        T[h].key = k;
        T[h].data = d;
        T[h].next = nullptr;
        return;
    }
    else if (T[h].key != Empty)
    {
        temp1 = T[h].next;
        while (temp1 != nullptr)
        {
            temp1 = temp1->next;
        }
        temp1 = new slot;
        //temp1 = newslot;
        temp1->key = k;
        temp1->data = d;
        temp1->next = nullptr;
        return;
    }
    else
        cout << "failed" << endl;
}

template <class keyType, class dataType>
unsigned long  hashTable<keyType, dataType>::hash(const dataType d, keyType & k) const
{
    unsigned long temp = 0, n = d.length();
    for (int i = 0; i < n; i++)
        temp = temp + int(tolower(d[i])) * pow(26, i);
    k = temp;
    temp = temp % MaxSize;

    return temp;
}


template <class keyType, class dataType>
void hashTable <keyType, dataType>::traverse() {
    slot * temp;
    for (int i = 0; i<MaxSize; i++){
        if (T[i].key != Empty) {
            cout<<T[i].data<<" ";
            temp = T[i].next;
            while (temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

    }

}

template <class keyType, class dataType>
bool  hashTable<keyType, dataType>::search(const dataType& d)
{   double k;
    unsigned long h = hash(d,k);
    slot* temp = T[h].next;
    if (T[h].key == k)
        return true;

    while (temp != nullptr)  //Unique key
    {
        if (temp->key == k)
            return true;
        else
            temp = temp->next;
    }
    return false;
}


template <class keyType, class dataType>
int hashTable<keyType, dataType>::Occupancy()const
{
    return csize;
}

template<class keyType,class dataType>
int hashTable<keyType, dataType>::hammingDistance(const std::string &A, const std::string &B) const
{
    int x ,y,M = 0,Big;
    x = A.length();
    y = B.length();
    if (y > x)
        Big = y;
    else Big = x;


    for (int i = 0; i <Big; i++)
    {
        if (A[i] == B[i])
            M++;
    }

    return (Big-M);
}


template<class keyType, class dataType>
void hashTable<keyType, dataType>::Suggest(const string & A)
{
    //Suggestions B[5];

    int cpointer = 0, s, n = 5, B[5];
    string temps, f, Bs [5];
    char c = A[0];
    slot * temp1;
    temp1 = &T[cpointer];

    for (int i = 0; i < n; i++)
    {
        if (T[cpointer].key != Empty)
        {
            f = temp1->data;
            if (f[0] == c)
            {
                s = hammingDistance(A, f);
                B[i] = s;
                Bs[i] = f;
            }
            if (temp1->next != NULL)
                temp1 = temp1->next;
            else
            {
                cpointer++;
                temp1 = &T[cpointer];
            }
        }
        cpointer++;
    }
    order(Bs, B, n);

    for (int i = cpointer; i < MaxSize; i++)
    {
        temp1 = &T[i];
        while (temp1->next != NULL)
        {
            f = temp1->data;
            if (f[0] == c)
            {
                s = hammingDistance(A, f);
                if (s < B[0])
                {
                    Bs[0]= f;
                    B[0]= s;
                    order(Bs, B, n);

            }

        }
        temp1 = temp1->next;
    }


}
    for (int i = 0; i < n; i++)
    {
        cout << Bs[i] << " ";
    }
}

template <class keyType, class dataType>
void hashTable<keyType, dataType>::order(string s[], int p[], int n)
{
    int tempint;
    string temps;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[i] < p[j + 1])
            {
                tempint = p[j + 1];
                p[j + 1] = p[j];
                p[j]= tempint;
                temps = s[j + 1];
                s[j + 1] = s[j];
                s[j] = temps;
            }
}