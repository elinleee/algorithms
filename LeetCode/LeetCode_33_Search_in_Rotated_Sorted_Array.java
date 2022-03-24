class Solution {
    public int search(int[] nums, int target) {
        
        int len = nums.length;
        
        if (len <= 3) {
            for (int i = 0; i < len; i++) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        int p = len / 2;
        int l = 0;
        int r = len - 1;
        
        while (!(l == p || p == r)) {
            if (nums[p] == target) return p;
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            
            if (nums[l] < nums[r]) {
                if (target < nums[p]) { // l < target < p < r
                    r = p;
                } else { // l < p < target < r
                    l = p;
                }
            } else {
                if (nums[l] < nums[p]) {
                    if (nums[l] < target && target < nums[p]) {
                        r = p;
                    } else {
                        l = p;
                    }
                } else {
                    if (nums[p] < target && target < nums[r]) {
                        l = p;
                    } else {
                        r = p;
                    }
                } 
            }
            p = l + (r - l) / 2;
        }
        
        return -1;
    }
}
