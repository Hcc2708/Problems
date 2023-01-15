// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort pairs
// according to second value
static bool cmp(pair<int, int>& a,
		pair<int, int>& b)
{
	return a.second < b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<int, int>& M)
{

	// Declare vector of pairs
	vector<pair<int, int> > A;

	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : M) {
		A.push_back(it);
	}

	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);

	// Print the sorted value
	vector<int>arr;
	int sum = 0;
	for (auto& it : A) {

        sum += it.second;
        if(sum>12)
            break;
        arr.push_back(it.first);
	}
	sort(arr.begin(), arr.end());
	int j =0;
	for(int i : arr)
    {
        cout<<M.at(i)<<" " ;
    }
}

// Driver Code
int main()
{

	// Declare Map
	map<int, int> M;


	// Given Map
	M = { { 1, 8 },
		{2, 6},
		{ 3, 5 } };

	// Function Call
	sort(M);
	return 0;
}
