//
// Created by Laila Nasser ElKoussy 900160812 on 11/6/17.
//

#ifndef ASSIGNMENT_4_HASHTABLE_H
#define ASSIGNMENT_4_HASHTABLE_H

#include <iostream>

template <class keyType, class dataType>

class hashTable {
public:

    // Member Functions
    hashTable();		// Constructor
    ~hashTable();						// Destructor

    // Functions Prototype Definitions

    void makeTableEmpty(const keyType &);
    bool tableIsEmpty() const;
    bool tableIsFull() const;
    void insert(const dataType &);
    bool search(const dataType &);
    void Suggest(const std::string & A);
    dataType retrieve(keyType k) const;
    int Occupancy()const;
    void Update(keyType k,dataType d);
    int hammingDistance(const std::string & A, const std::string &B)const;
    void traverse ();
    void order(std::string s[], int p[], int n);

private:
    // Slot Class
    class slot
    {
    public:
        keyType key; 		// key
        dataType data;		// Data
        slot * next;
    }; // end of class slot declaration

    slot *T;							// Pointer to Storage Array
    unsigned long h;								// Index to a slot
    int MaxSize, csize;					// Maximum and Current Sizes
    keyType Empty;						// empty symbol

    unsigned long hash(dataType d, keyType & k) const;


};


#endif //ASSIGNMENT_4_HASHTABLE_H
