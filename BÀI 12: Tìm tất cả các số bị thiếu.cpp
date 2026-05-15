Find All Numbers Dissappear

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    
    int n = (int)nums.size();
    
    for (int i = 0; i < n; i++) {
        int index = abs(nums[i] - 1); // chu y phai dung abs vi ta co the gap truong hop danh dau nhieu lan
        if (nums[index] > 0 ) nums[index] = - nums[index]; // danh dau neu chua danh dau (tranh bi danh dau nhieu lan, anh huong ket qua
    }
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) { // so duong la so bi du
            res.push_back(i + 1); // them vi tri (so bi thieu) vao mang ket qua
        }
    }
    
    return res;
}
