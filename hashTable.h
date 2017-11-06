//
// Created by Laila Nasser ElKoussy 900160812 on 11/6/17.
//

#ifndef ASSIGNMENT_4_HASHTABLE_H
#define ASSIGNMENT_4_HASHTABLE_H

template <class keyType, class dataType>

class hashTable {
public:

    // Member Functions
    hashTable(int nelements = 149);		// Constructor
    ~hashTable();						// Destructor

    // Functions Prototype Definitions

    void makeTableEmpty(const keyType &);
    bool tableIsEmpty() const;
    bool tableIsFull() const;
    void insert(const keyType &, const dataType &);
    bool search(const keyType &);

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
    int h;								// Index to a slot
    int MaxSize, csize;					// Maximum and Current Sizes
    keyType Empty;						// empty symbol

    int hash(const keyType &) const;

};


#endif //ASSIGNMENT_4_HASHTABLE_H
