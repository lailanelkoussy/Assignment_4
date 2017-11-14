#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "hashTable.cpp"
#include <string>




using namespace std;

void opening (ifstream &file, const string& filename);
void fillTable(hashTable<double, string> &, string &filename);
void lowerCase (string&);
void spellCheck (hashTable<double, string>& , string &filename);


int main() {
    hashTable <double, string> a;

    string filename, check;
    cout<<"Please type in filename with .txt extension with the dictionary : ";
    cin>>filename;
    fillTable(a, filename);
    a.traverse();
    cout<<"Imported words successfully, enter name of file to spell check with .txt extension: ";
    cin>>check;

    return 0;
}


void opening (ifstream &file, const string& filename)
{ file.open(filename);
    if (file.is_open())
    return;

    else
        cout << "Could not open " << filename;

}

void fillTable(hashTable<double, string> &a, string &filename)
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
    for (int i =0; i<a.length(); i++){
        temp+= char(tolower(int(a[i])));
    }
    a = temp;
}

void spellCheck (hashTable<double, string>&a , string &filename){
    ifstream file;
    bool found;
    string word;
    char c;
    opening(file, filename);


    if (file.is_open()) {
        while (file.good()) {
            while ((file.good()) && !isspace(file.get())) {
                file.get(c);
                if (!isspace(c))
                    word += c;

            }

            found = a.search(word);

            if (!found) {
                cout<<"Misspelled word found: "<<word;
                a.Suggest(word);
                cout<<endl;

            }

        }
    }

}