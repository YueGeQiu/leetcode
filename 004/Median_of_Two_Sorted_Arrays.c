int minTwo(int a, int b) {
    return a < b ? a : b;
}

double findKthSmallestInSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
    int base1 = 0, base2 = 0;
    int i, j, a, b;
    while (true) {
        if (nums1Size == 0) return nums2[base2 + k - 1];
        if (nums2Size == 0) return nums1[base1 + k - 1];
        if (k == 1) return minTwo(nums1[base1], nums2[base2]);

        i = minTwo(k / 2, nums1Size);
        j = minTwo(k - i, nums2Size);
        a = nums1[base1 + i - 1];
        b = nums2[base2 + j - 1];

        if (i + j == k && a == b) return a;

        if (a <= b) {
            base1 += i;
            nums1Size -= i;
            k -= i;
        }

        if (a >= b) {
            base2 += j;
            nums2Size -= j;
            k -= j;
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    if (sum & 1) return findKthSmallestInSortedArrays(nums1, nums1Size, nums2, nums2Size, sum/2 + 1);
    else {
        double a = findKthSmallestInSortedArrays(nums1, nums1Size, nums2, nums2Size, sum/2);
        double b = findKthSmallestInSortedArrays(nums1, nums1Size, nums2, nums2Size, sum/2 + 1);
        return (a + b) / 2;
    }
}
