//
// Created by Laila Nasser ElKoussy 900160812 on 11/6/17.
//

#include "hashTable.h"
#include <iostream>
#include <cmath>

using namespace std;

template <class keyType, class dataType>
hashTable<keyType, dataType>::hashTable(int nelements)
{
    MaxSize = nelements;
    T = new slot[MaxSize];
    h = -1;
    csize = 0;

}

template <class keyType, class dataType>
hashTable<keyType, dataType>::~hashTable() {
    slot * temp1, *temp2;

    for (int i =0; i<MaxSize; i++) {
        temp1 = T[h].next;
        T[h].next = nullptr;

        while ((temp1 != nullptr)|| (temp2 != nullptr)){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2->next;
            delete temp2;
        }
    }
    delete T;
}

template <class keyType, class dataType>
void hashTable<keyType,dataType>::makeTableEmpty(const keyType &k) {
    slot * temp1, *temp2;
    Empty = k;
    for (int i =0; i<MaxSize; i++) {
        T[h].next = nullptr;
        T[h].key= k;
        temp1 = T[h].next;
        temp2 = temp1;

        while ((temp1 != nullptr)|| (temp2 != nullptr)){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2->next;
            delete temp2;
        }
    }

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
{   int k=1;
    h = hash (d, k);
    csize++;

    if (T[h].key == Empty) {
        T[h].key = k;
        T[h].data = d;
            return;
        }
    else
    {
        slot * temp1 = T[h].next, *temp2 = nullptr ;

        while (temp1!= nullptr) {
            temp2 = temp1;
            temp1 = temp1->next;
            }

        temp2->next = new slot;
        temp1 = temp2->next;
        temp1->key = k;
        temp1->data = d;
        temp1->next = nullptr;

        }

    }

template <class keyType, class dataType>
int hashTable<keyType, dataType>::hash(const string &d, int &k ) const
{ int temp = 1;
    for (int i = 0; i<d.length(); i++)
        temp = int(int(d[i]) * pow(26, i));
    k = temp;
    temp %= MaxSize;


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