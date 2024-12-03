//Question - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
  public:
    int maximumProfit(vector<int> &prices) 
    {
        // code here
        int n = prices.size(); 
        if (n == 0) return 0; 
        int min_price = INT_MAX; 
        int max_profit = 0; 
        for (int i = 0; i < n; ++i) 
        { 
            if (prices[i] < min_price) 
        { 
            min_price = prices[i]; 
            
        } 
        else 
        { 
            max_profit = max(max_profit, prices[i] - min_price); 
            
        } 
            
        }
            return max_profit; 
        
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends