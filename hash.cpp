#include <iostream>
using namespace std;

const int SIZE_ARR = 26; 
struct hashTable {
    string username, password;
} dataAkun[SIZE_ARR];

int hashFunction(string username) {
    char firstLetter = tolower(username[0]);
    if (firstLetter >= 'a' && firstLetter <= 'z') {
        return firstLetter - 'a';
    }
    return SIZE_ARR - 1; 
}

void printAll() {
    for (int i = 0; i < SIZE_ARR; i++) {
        cout << i << "[" << dataAkun[i].username << "-" << dataAkun[i].password << " ] " << endl;
    }
}

void menu() {
    while (true) {
        int input_user;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl << endl;
        cin >> input_user;
        cout << endl;

        if (input_user == 1) {
            string username, password;
            cout << "Masukkan Username.:" << endl;
            cin >> username;
            cout << "Masukkan Password:" << endl;
            cin >> password;

            int index = hashFunction(username);
            dataAkun[index].username = username;
            dataAkun[index].password = password;
        }
        else if (input_user == 2) {
            cout << "Menu Login" << endl;
        }
        else if (input_user == 3) {
            printAll();
            break;
        }
    }
}

int main() {
    menu();
    return 0;
}
