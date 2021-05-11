// C++ code to find Two elements
// whose sum is closest to zero
# include <bits/stdc++.h>
# include <stdlib.h> /* for abs() */
# include <math.h>
#include <vector>

using namespace std;
int minAbsSumPair(int arr[], int arr_size)
{
	    int currentValue = 0;
        int closestVal = arr[0];
        vector <int> num;
        int temp;
        // Arrays.sort(a);
        sort(arr, arr + arr_size);
        int i=0;
        for(i=0; i<arr_size; i++)
        {
            num.push_back(abs(0-arr[i]));
        }

        int minElementIndex = std::min_element(num.begin(),num.end()) - num.begin();
        cout << "\nMin Element = " << arr[minElementIndex]<<endl;

        return arr[minElementIndex];
}

// Driver Code
int main()
{
	int arr[] = {-15, 60, -10, -1, -2, -12, 70, -80, 85};
	int result = minAbsSumPair(arr, 6);
    cout<<endl<<"The Closest Number To Zero in this Array is : " << result<<endl;
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
