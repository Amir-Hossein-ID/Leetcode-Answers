#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
}();

// the idea is to find median of each array, then compute where it would be in the merged array
// and return it if it is in the middle
// otherwise move with respect of the previous position until either the answer is found or the array has ended
// then do the same for the other array
// if the answer was not found, find the two best answers that divide the merged array better (the medians, lefts = rights+1, rights = lefts+1)
// then return mean of them

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int min_found = -1000001;
        int max_found = 1000001;

        int low = 0, high = s1 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // the highmid and lowmid is because of handling equal elements, lowmid:first occurance, highmid=last occurance+1
            int mid_low = lower_bound(nums1.begin(), nums1.end(), nums1[mid]) - nums1.begin();
            int mid_high = upper_bound(nums1.begin(), nums1.end(), nums1[mid]) - nums1.begin();
            int lefts = mid_low, rights = s1 - mid_high;
            int mid2_low = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
            int mid2_high = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin();
            lefts += mid2_low;
            rights += s2 - mid2_high;
            // if the element is in middle of merged array or the difference between rights and lefts as lower than the count of this element
            if (rights == lefts || abs(lefts - rights) <= mid2_high - mid2_low + mid_high - mid_low - 1) {
                return nums1[mid];
            } else if (lefts > rights) {
                high = mid_low - 1;
                // max_found refers to minimum value greater than actual answer (I know the naming is awful)
                max_found = min(max_found, nums1[mid]);
            } else {
                low = mid_high;
                // min_found refers to maximum value less than the actual answer
                min_found = max(min_found, nums1[mid]);
            }
        }
        low = 0, high = s2 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int mid_low = lower_bound(nums2.begin(), nums2.end(), nums2[mid]) - nums2.begin();
            int mid_high = upper_bound(nums2.begin(), nums2.end(), nums2[mid]) - nums2.begin();
            int lefts = mid_low, rights = s2 - mid_high;
            int mid1_low = lower_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
            int mid1_high = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin();
            lefts += mid1_low;
            rights += s1 - mid1_high;
            if (rights == lefts || abs(lefts - rights) <= mid1_high - mid1_low + mid_high - mid_low - 1) {
                return nums2[mid];
            } else if (lefts > rights) {
                high = mid_low - 1;
                max_found = min(max_found, nums2[mid]);
            } else {
                low = mid_high;
                min_found = max(min_found, nums2[mid]);
            }
        }
        return (double) (min_found + max_found) / 2;
    }
};
