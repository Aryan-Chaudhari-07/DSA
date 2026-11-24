
#include <iostream> 
using namespace std; 
class HeapSort 

{ 

    int a[50]; 

    int n; 

public: 

    // Read array elements 

    void read() 

    { 

        cout << "Enter number of elements: "; 

        cin >> n; 
        
        cout << "Enter elements:\n"; 

        for(int i = 0; i < n; i++) 

        { 

            cin >> a[i]; 

        } 

    } 

 

    // Maintain Min Heap 

    void heapify(int n, int i) 

    { 

        int smallest = i; 

        int left = 2 * i + 1; 

        int right = 2 * i + 2; 

 

        if(left < n && a[left] < a[smallest]) 

        { 

            smallest = left; 

        } 

        if(right < n && a[right] < a[smallest]) 

        { 

            smallest = right; 

        } 

        if(smallest != i) 

        { 

            int temp = a[i]; 

            a[i] = a[smallest]; 

            a[smallest] = temp; 

            heapify(n, smallest); 

        } 

    } 

 

    // Heap Sort using Min Heap 

    void sort() 

    { 

        // Build Min Heap 

        for(int i = n / 2 - 1; i >= 0; i--) 

        { 

            heapify(n, i); 

        } 

        // Extract minimum element 

        for(int i = n - 1; i > 0; i--) 

        { 

            int temp = a[0]; 

            a[0] = a[i]; 

            a[i] = temp; 

 

            heapify(i, 0); 

        } 

    } 

    // Display sorted array 

    void display() 

    { 

        cout << "\nSorted elements in Descending Order:\n"; 

        for(int i = 0; i < n; i++) 

        { 

            cout << a[i] << " "; 

        } 

        cout << endl; 

    } 

}; 

 

int main() 

{ 

    HeapSort h; 

    h.read(); 

    h.sort(); 

    h.display(); 

    return 0; 

} 