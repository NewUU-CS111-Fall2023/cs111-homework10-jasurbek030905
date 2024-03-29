#include <iostream>
#include <vector>
using namespace std;
bool hasZeroSumTriplet(const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

int task_5 () {
    vector<int> nums = {-5, -17, 7, -4, 3, -2, 4};
    bool result = hasZeroSumTriplet(nums);
    if (result) {
        cout << "True" << endl;
    } else {
       cout << "False" << endl;
    }
    return 0;
}
