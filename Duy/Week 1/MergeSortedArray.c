/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Tạo một mảng tạm để chứa các phần tử đã hợp nhất
    int num[m+n];
    
    // Sao chép m phần tử đầu tiên từ nums1 vào mảng tạm
    for(int j = 0; j < m; j++) {
        num[j] = nums1[j];
    }
    
    // Sao chép n phần tử từ nums2 vào mảng tạm, bắt đầu từ vị trí m
    for (int l = m; l < m+n; l++) {
        num[l] = nums2[l-m];
    }
    
    // Sắp xếp mảng tạm (Bubble Sorting)
    for(int i = 0; i < m+n-1; i++) {
        for(int k = i+1; k < m+n; k++) {
            if (num[i] > num[k]) {
                int tmp = num[i];
                num[i] = num[k];
                num[k] = tmp;
            }
        }
    }
    
    // Sao chép các phần tử đã sắp xếp từ mảng tạm trở lại nums1
    for(int i = 0; i < m+n; i++) {
        nums1[i] = num[i];
    }
}