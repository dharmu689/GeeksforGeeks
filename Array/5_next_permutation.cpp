//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
     int n = arr.size(); 

     // Find the pivot index
    int pivot = -1; 
    for (int i = n - 2; i >= 0; i--) 
    {
        if (arr[i] < arr[i + 1]) 
        {
            pivot = i;
            break;
        }
    }

    // If pivot point does not exist, reverse the
    // whole array
    if (pivot == -1) 
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element from the right that
    // is greater than pivot
    for (int i = n - 1; i > pivot; i--) 
    {
        if (arr[i] > arr[pivot]) 
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Reverse the elements from pivot + 1 to the 
    // end to get the next permutation
    reverse(arr.begin() + pivot + 1, arr.end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends