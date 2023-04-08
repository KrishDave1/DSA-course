#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivot_index(vector<int> a)
{
    // base case
    if (a.size() == 0)
        return -1;
    int low = 0, high = a.size() - 1, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // checking if mid is the pivot element
        if (a[mid] < a[(mid + 1) % a.size()] && a[mid] < a[(mid + a.size() - 1) % a.size()])
        {
            return mid;
        }
        else
        {
            // checking if the pivot is on the left side
            if (a[mid] > a[low] && a[mid] >= a[high])
                low = mid + 1;
            // checking if the pivot is on the right side
            else
                high = mid - 1;
        }
    }
    return -1;
}

int binary_search1(vector<int> v,int n,int low,int high){
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if (v[mid]==n)
            return mid;
        else if (v[mid]>n)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int rotated_array_index(vector<int> v,int n){
    int pivot=pivot_index(v);
    int i1=binary_search1(v,n,0,pivot-1);
    int i2=binary_search1(v,n,pivot,v.size()-1);
    if (i1!=-1)
        return i1;
    else if (i2!=-1)
        return i2;
    else
        return -1;
}

//Combining all 3 functions 
int search(vector<int>& nums, int target) {
     int n = nums.size();
     int low = 0;
     int high = n-1;
     int mid= low + (high - low) / 2;
     while(low <= high){
        mid = low + (high - low) / 2;
        if(nums[mid] == target) 
         return mid;
        if(nums[mid] >= nums[low]) { // means left side is SORTED.
          if(target >= nums[low] && target <= nums[mid])// IF target is one of the rotated part then we will search in the unsorted array otherwise in the sorted part. 
            {
                high = mid - 1;
            }
           else low = mid + 1;
        } 
        else {  // means the sorted part is on the right side.
          if(target >= nums[mid] && target <= nums[high]) //Just reverse the conditionswritten above.
            low = mid + 1;
          else high = mid - 1;
        }
      }
      return -1;
}
int main()
{
    vector<int> a = {6, 7, 0, 1, 2, 3, 4, 5};
    cout << rotated_array_index(a,4) << endl;
    return 0;
}
