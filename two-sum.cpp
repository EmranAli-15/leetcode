#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2,7,15,11};
    int target = 9;

    sort(arr, arr + 4);

    int s=0, e=3;

    while(s<e)
    {
        int sum = arr[s] + arr[e];
        if(sum == target)
        {
            cout << arr[s] << " + " << arr[e] << " = " << target;
            break;
        }
        else if(sum > target) e--;
        else s++;
    }

    return 0;
}
