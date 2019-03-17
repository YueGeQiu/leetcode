func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func maxSlidingWindow(nums []int, k int) []int {
    if k == 0 || nums == nil {
        return nil
    }
    length := len(nums)

    var ret []int

    maxFromLeft := make([]int, length)
    maxFromRight := make([]int, length)

    maxFromLeft[0] = nums[0]
    maxFromRight[length - 1] = nums[length - 1]

    for i, j := 1, length - 2; i < length; i, j = i + 1, j - 1 {
        if i % k == 0 {
            maxFromLeft[i] = nums[i]
        } else {
            maxFromLeft[i] = max(maxFromLeft[i - 1], nums[i])
        }

        if j % k == k - 1 {
            maxFromRight[j] = nums[j]
        } else {
            maxFromRight[j] = max(maxFromRight[j + 1], nums[j])
        }
    }

    for i := 0; i < length - k + 1; i++ {
        ret = append(ret, max(maxFromLeft[i + k - 1], maxFromRight[i]))
    }

    return ret
}
