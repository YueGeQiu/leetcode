func findUnsortedSubarray(nums []int) int {
    n := len(nums)
    if n < 2 {
        return 0
    }

    i, j := 0, -1
    max, min := nums[0], nums[n - 1]

    for k := 1; k < n; k++ {
        if nums[k] < max {
            j = k
        } else {
            max = nums[k]
        }

        if nums[n - k - 1] > min {
            i = n - k - 1
        } else {
            min = nums[n - k - 1]
        }
    }

    return j - i + 1
}