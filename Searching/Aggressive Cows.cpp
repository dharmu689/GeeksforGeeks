
//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

   // int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        bool check(vector<int> &stalls, int k, int dist) {
    
    // Place first cow at 0th index
    int cnt = 1;  
    int prev = stalls[0]; 
    for (int i = 1; i < stalls.size(); i++) {
        
        // If the current stall is at least dist away
        // from the previous one place the cow here
        if (stalls[i] - prev >= dist) {
            prev = stalls[i]; 
            cnt++;
        }
    }

    // Return true if we are able to place all 'k' cows
    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k) {
  
      // sorting the array to ensure stalls in sequence
      sort(stalls.begin(), stalls.end());
    int res = 0; 
  
    // Search Space for Binary Search
      int lo = 1;
      int hi = stalls.back() - stalls[0];
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        // If the mid ditance is possible, update
        // the result and search for larger ditance
        if(check(stalls, k, mid)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends