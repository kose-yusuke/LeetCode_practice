
// 普通にやると全探索だが, ハッシュマップを使って計算量を減らす. 衝突しなければ速い
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap ;
        for (int i=0; i< nums.size();i++){
            hashMap[nums[i]] = i;
        }
        // hashMapにキーがない場合値は0を返す(つまり合わせるとtargetになるpairが存在しない)
        for (int i=0; i<nums.size();i++){
            if (i!=hashMap[target-nums[i]] && hashMap[target-nums[i]] != 0){
                return {i, hashMap[target-nums[i]]};
            }
        }
        return {-1};
    }
};
