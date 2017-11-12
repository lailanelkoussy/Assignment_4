#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "hashTable.cpp"
#include <string>



using namespace std;

void opening (ifstream &file, const string& filename);
void fillTable (hashTable& , string &filename);
void lowerCase (string&);


int main() {
    hashTable <int, string> a;
    string filename, check;
    cout<<"Please type in filename with .txt extension";
    cin>>filename;

    fillTable(a, filename);
    a.traverse();

    cout<<"Please enter a word to spellcheck";
    cin>>check;
    lowerCase(check);
    a.search(check);




    return 0;
}


void opening (ifstream &file, const string& filename)
{ file.open(filename);
    if (file.is_open())
        return;
    else {
        cout << "Could not open " << filename;
        return;
    }

}

void fillTable (hashTable<int, string> &a, string &filename)
{
    ifstream file;
    opening (file, filename);
    string temp;


    while (file.good()) {

        getline(file, temp);
        lowerCase(temp);
        a.insert(temp);

    }

    file.close();


}

void lowerCase (string& a){
    string temp="";
    locale loc;
    for (std::string::size_type i=0; i<a.length(); ++i)
        temp+=std::tolower(a[i],loc);
    a = temp;
}