//　中央値を二分探索で探索する問題
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 常に nums1 を短い配列にする
        // 二分探索を短い配列で行うことで計算量削減
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            // ここの分割端の決め方が肝っぽい. 二分探索で, どう分割設定という部分
            int partitionM = (low + high) / 2;
            int partitionN = (m + n + 1) / 2 - partitionM;
            
            //短い方の配列nums1の左半分の最大値
            int maxM = (partitionM == 0) ? INT_MIN : nums1[partitionM - 1];
            //短い方の配列nums1の右半分の最小値
            int minM = (partitionM == m) ? INT_MAX : nums1[partitionM];
            //長い方の配列nums2の左半分の最大値
            int maxN = (partitionN == 0) ? INT_MIN : nums2[partitionN - 1];
            //長い方の配列nums2の右半分の最小値
            int minN = (partitionN == n) ? INT_MAX : nums2[partitionN];
            
            // nums1の左半分の最大値がnums2の右半分の最小値より小さく,  ...
            // 二分探索における停止条件の設定
            if (maxM <= minN && maxN <= minM) {
                if ((m + n) % 2 == 0) {
                    return (double)(max(maxM, maxN) + min(minM, minN)) / 2;
                } else {
                    // nums1とnums2の要素の合計が奇数→左半分の最大値で大きい方が中央値
                    return (double)max(maxM, maxN);
                }
            } 
            //二分探索における更新の部分
            // nums1の左の最大がnums2の右の最小より大きい時
            else if (maxM > minN) {
                // Mの分割端をずらす, するとそれに引きづられてNの分割端もずれて調整される
                high = partitionM - 1;
            } else {
                // Mのlowを増やすことでpartitionMの位置を右にずらす
                low = partitionM + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted or invalid.");
    }
};