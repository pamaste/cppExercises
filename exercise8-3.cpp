#include <iostream>

using namespace std;

int lastLargestIndex(int intList[]);

int main() {
    // Write your main here
    int intList[15];

    cout << "Enter list of 15 integers: ";
    for (int index = 0; index <15; index++)
      cin >> intList[index];

    int largestIndex = lastLargestIndex(intList);

    /*for (int index = 0; index <15; index++)
      cout <<  intList[index] << " ";
    */
    
    lastLargestIndex(intList);
    cout << "largest index: " << largestIndex << endl;
    cout<< "value of: " << intList[largestIndex] << endl;

    return 0;
}

int lastLargestIndex(int intList[]) {
    int largest = 0;
    int i;
    for (i = 0; i < 15; i++){
      if (intList[largest] <= intList[i]){
        largest = i;
      }
    }
    return largest;
}

