
//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
  
    // last element added to the merged sorted array
    int last = 0;
    int i = 0, j = 0;

    for (int d = 0; d < k; ++d) {
        if (i < n) {
          
            // If a[i] > b[j] then increment j
            if (j < m && a[i] > b[j]) {
                last = b[j];
                j++;
            } 
            // Otherwise increment i
            else {
                last = a[i];
                i++;
            }
        }
        
        // If reached end of first array then increment j
        else if (j < m) {
            last = b[j];
            j++;
        }
    }

    // Return the last (kth) element
    return last;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends