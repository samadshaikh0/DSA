#include <iostream>
#include <vector>

using namespace std;

int findRepeatingNumber(vector<int>& arr) {
    int n = arr.size();
    int repeatingNumber = -1;

    for (int i = 0; i < n; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0) {
            arr[index] = -arr[index];
        } else {
            repeatingNumber = abs(arr[i]);
        }
    }

    return repeatingNumber;
}

/*
The findRepeatingNumber function takes a reference to a vector of integers (arr) as its parameter.
It initializes the size of the array (n) and a variable (repeatingNumber) to -1. The repeatingNumber variable will be used to store the repeating number in the array.
The function enters a loop that iterates through each element of the array.
Inside the loop, it calculates the index to access in the array using abs(arr[i]) - 1. This is because the numbers in the array are from the set {1, 2, ..., N}, and the array is 0-indexed.
It checks whether the element at the calculated index is positive. If it is, it means this is the first time encountering the number, so it negates the value to mark it as visited.
If the element at the calculated index is not positive, it means the number has been encountered before, and it assigns the absolute value of the current element to repeatingNumber. This is the repeating number.
The function returns the repeatingNumber after the loop completes.
*/

int findMissingNumber(vector<int>& arr) {
    int n = arr.size();
    int missingNumber = -1;

    for (int i = 0; i < n; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0) {
            arr[index] = -arr[index];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            missingNumber = i + 1;
            break;
        }
    }

    return missingNumber;
}



/*
The findMissingNumber function is similar to findRepeatingNumber but is used to find the missing number.
It initializes the size of the array (n) and a variable (missingNumber) to -1. The missingNumber variable will be used to store the missing number in the array.
The function enters a loop that iterates through each element of the array.
Inside the loop, it calculates the index to access in the array using abs(arr[i]) - 1.
It checks whether the element at the calculated index is positive. If it is, it means this is the first time encountering the number, so it negates the value to mark it as visited.
After the first loop, the function enters a second loop to find the missing number. It iterates through each element of the array.
If it finds an element that is still positive, it means that index + 1 is the missing number, and it assigns this value to missingNumber. The loop then breaks since we have found the missing number.
The function returns the missingNumber after the loop completes.
*/
int main() {
    vector<int> arr = {3, 7, 1, 8, 4, 5, 6, 6};

    int repeatingNumber = findRepeatingNumber(arr);
    int missingNumber = findMissingNumber(arr);

    cout << "Repeating Number: " << repeatingNumber << endl;
    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}




/*
mycode:
int repeatingNum(vector<int> &arr, int n){
        int ans = -1;
        for(int i=0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                ans = arr[i];
                arr[i] = -1;
                break;
            }
        }
        return ans;
    }
    
    int missingNum(vector<int> &arr,int n){
        int ans = -1;
        bool flag = false;
        
        for(int i=0;i<n;i++){
            
            if(arr[i] == -1){
                flag = true;
            }
            
            else if(arr[i] != -1){
                if(arr[i] != i+1 && !flag){
                    ans = i+1;
                    break;
                }
                if(arr[i] != i && flag){
                    ans = i;
                    break;
                }
            }
        }
        if(ans == -1) 
            ans = n;
        return ans;
    }
*/