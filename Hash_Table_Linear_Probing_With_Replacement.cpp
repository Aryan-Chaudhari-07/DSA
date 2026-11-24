#include <iostream> 
using namespace std; 
class HashTable 

{ 

    int hash[10]; 

    int size; 

public: 

    // Initialize hash table 

    HashTable() 

    { 

        size = 10; 

        for(int i = 0; i < size; i++) 

        { 

            hash[i] = -1; 

        } 

    } 

    // Insert key with replacement 

    void insert(int key) 

    { 

        int index = key % size; 

        // If position is empty 

        if(hash[index] == -1) 

        { 

            hash[index] = key; 

            return; 

        } 

        // Check whether existing key belongs 

        // to a different hash address 

        if(hash[index] % size != index) 

        { 

            int temp = hash[index]; 

            // Replace existing key 

            hash[index] = key; 

            cout << temp << " is displaced from index " 

                 << index << endl; 

            // Find next empty position 

            int i = (index + 1) % size; 

            while(hash[i] != -1 && i != index) 

            { 

                i = (i + 1) % size; 

            } 

            if(hash[i] == -1) 

            { 

                hash[i] = temp; 

            } 

            else 

            { 

                cout << "Hash Table is Full!" << endl; 

            } 

        } 

        else 

        { 

            // Normal linear probing 

            int i = (index + 1) % size; 

            while(hash[i] != -1 && i != index) 

            { 

                i = (i + 1) % size; 

            } 

            if(hash[i] == -1) 

            { 

                hash[i] = key; 

            } 

            else 

            { 

                cout << "Hash Table is Full!" << endl; 

            } 

        } 

    } 

    // Display hash table 

    void display() 

    { 

        cout << "\nIndex\tValue\n"; 

        for(int i = 0; i < size; i++) 

        { 

            cout << i << "\t"; 

 

            if(hash[i] == -1) 

                cout << "Empty"; 

            else 

                cout << hash[i]; 

            cout << endl; 

        } 

    } 

}; 

 

int main() 

{ 

    HashTable h; 

    int n, key; 

    cout << "Enter number of keys: "; 

    cin >> n; 

    cout << "Enter keys:\n"; 

    for(int i = 0; i < n; i++) 

    { 

        cin >> key; 

        h.insert(key); 

    } 

    h.display(); 

    return 0; 

} 