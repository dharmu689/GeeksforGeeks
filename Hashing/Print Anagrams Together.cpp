
//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    //vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        const int MAX_CHAR = 26;

// function to generate hash of word s
string getHash(string &s) {
    string hash;
    vector<int> freq(MAX_CHAR, 0);
    
    // Count frequency of each character
    for(char ch: s)
        freq[ch - 'a'] += 1;
    
    // Append the frequency to construct the hash
    for(int i = 0; i < MAX_CHAR; i++) {
        hash.append(to_string(freq[i]));
        hash.append("$");
    }
    
    return hash;
}

vector<vector<string>> anagrams(vector<string> &arr) {
    vector<vector<string>> res;
    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        string key = getHash(arr[i]);
      
        // If key is not present in the hash map, add
        // an empty group (vector) in the result and
        // store the index of the group in hash map
        if (mp.find(key) == mp.end()) {
            mp[key] = res.size();
            res.push_back({});
        }
      
        // Insert the string in its correct group
        res[mp[key]].push_back(arr[i]);
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends