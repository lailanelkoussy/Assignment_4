#include <iostream>
#include <fstream>

using namespace std;

void opening (ifstream &file, const string& filename);

int main() {
    ifstream file;
    string filename = "wordlist.txt";
    opening (file, filename);


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
