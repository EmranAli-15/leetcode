#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {

    }
};


int main()
{

    // 1 1 2 2 2 3 3 4 5 7 9

    // 1 1 2 2 4 5 7 11 15     2 3 3 9

    int a[] = {1,1,2,2,4,5,7,11,15};
    int b[] = {2,3,3,9};

    int c[13];

    int i=0, j=0, k=0;

    while(k<13)
    {
        while((a[i] <= b[j]) && i<9)
        {
            c[k] = a[i];
            i++;
            k++;
        }

        while((b[j] <= a[i]) && j<4)
        {
            c[k] = b[j];
            j++;
            k++;
        }
        if(i==9 || j==4)break;
    }

    cout << endl;

    while(i<9)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j<4)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    for(int k=0; k<13; k++) cout << c[k] << " ";


    return 0;
}
