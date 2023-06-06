#include <iostream>
#include <unordered_map>

using namespace std;

class TelephoneBook {
    unordered_map<int, int> hashTable;

public:
    void insert(int phoneNumber) {
        hashTable[phoneNumber] = phoneNumber;
    }

    void remove(int phoneNumber) {
        if (hashTable.count(phoneNumber) > 0) {
            hashTable.erase(phoneNumber);
            cout << "Phone number " << phoneNumber << " removed." << endl;
        } else {
            cout << "Phone number " << phoneNumber << " not found." << endl;
        }
    }

    void display() {
        for (int i = 0; i < hashTable.bucket_count(); i++) {
            cout << "Slot " << i << ": ";
            for (const auto& entry : hashTable) {
                if (hashTable.bucket(entry.first) == i) {
                    cout << entry.first << " ";
                }
            }
            cout << endl;
        }
    }

    int search(int phoneNumber) {
        if (hashTable.count(phoneNumber) > 0) {
            return 1;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter the number of telephone numbers to insert: ";
    cin >> n;

    TelephoneBook book;

    cout << "Enter the telephone numbers to insert:\n";
    for (int i = 0; i < n; i++) {
        int phoneNumber;
        cin >> phoneNumber;
        book.insert(phoneNumber);
    }

    cout << "\nHash Table Contents:\n";
    book.display();

    // Search and remove
    cout << "\nEnter the telephone number to search and remove: ";
    int phoneNumber;
    cin >> phoneNumber;

    int comparisons = book.search(phoneNumber);
    if (comparisons == -1) {
        cout << "Phone number " << phoneNumber << " not found." << endl;
    } else {
        book.remove(phoneNumber);
    }

    return 0;
}
