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
void hashTable<keyType, dataType>::insert(const keyType &k, const dataType &d)
{

        h = hash (k);
        csize++;

        if (T[h].key == Empty) {
            T[h].key = k;
            T[h].data = d;
            return;
        }
        else
        {
            slot * temp;

        }



    }

template <class keyType, class dataType>
int hashTable<keyType, dataType>::hash(const string &k) const
{ int temp = 1;
    for (int i = 0; i<k.length(); i++)
        temp = int(k[i]) * pow(26, i);
        temp %= MaxSize;


    return temp;
}