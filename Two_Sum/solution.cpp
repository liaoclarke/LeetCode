class TwoSum {
  public:
    /*
     * Time complexity: O(n^2)
     * Space complexity: O(1)
     * */
    vector<int> BruteForce(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
          if (nums[i] + nums[j] == target) {
            vector<int> result = {i, j};
            return result;  
          }
        }
      }
    }

    /*
     * Time complexity: O(n)
     * Space complexity: O(n)
     * */
    vector<int> TwoPassHashTable(vector<int>& nums, int target) {
      std::map<int, int> table;
      for (int i = 0; i < nums.size(); i++) {
        table.emplace(nums[i], i);
      }
      for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto search = table.find(complement);
        if (search != table.end() && table[complement] != i) {
          vector<int> result = {i, table[complement]};
          return result;
        }
      }
    }

    /*
     * Time complexity: O(n)
     * Space complexity: O(n)
     * */
    vector<int> OnePassHashTable(vector<int>& nums, int target) {
      std::map<int, int> table;
      for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto search = table.find(complement);
        if (search != table.end()) {
          vector<int> result = {table[complement], i};
          return result;
        } else {
          table.emplace(nums[i], i);
        }
      }
    }
};


