
//Given numbers from 1 to n, find the duplicate number in 0(n) time complexity and O(1) space complexity


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Define an empty set
        set<int> con;
        set<int>::iterator it;
        
        //Iterate over the array
        for(int i=0;i<nums.size();i++){
            it = con.find(nums[i]);
            
            //Number already present in set
            if(it != con.end())
                return nums[i];
            else
                con.insert(nums[i]);
        }
   
};

int main() {
   
        vector<int> nums = {1, 2, 3, 7, 5, 6, 7}
        
        int ret = Solution().findDuplicate(nums);
        cout << ret << endl;
    
        return 0;
}
