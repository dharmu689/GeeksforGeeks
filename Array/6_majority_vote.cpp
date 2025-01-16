//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        
          int n = arr.size();
          
    unordered_map<int, int> freq;
    vector<int> res;

    // find frequency of each number
    for (int ele : arr)
    
        freq[ele]++;

    // Iterate over each key-value pair in the hash map
    for (auto it : freq) 
    {
        int ele = it.first;
        int cnt = it.second;

        // Add the element to the result, if its frequency
        // if greater than floor(n/3)
        if (cnt > n / 3)
        {
            res.push_back(ele);
        }    
    }

    if (res.size() == 2 && res[0] > res[1])
    {
        swap(res[0], res[1]);
    }
    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

