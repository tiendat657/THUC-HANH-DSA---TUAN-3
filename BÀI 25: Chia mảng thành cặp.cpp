Divide Array Into Equal Pairs

Cach 1: mang danh dau
bool divideArray(vector<int>& nums) {
    int countFreq[507] = {0};
    
    for (int x : nums) {
        countFreq[x]++;
    }
    
    for (int i = 0; i < 501; i++) {
        if (countFreq[i] % 2 == 1) return false; // khong chan -> khong chia duoc
    }
    
    return true; // kiem tra het ma thoa dieu kien -> true
}

Cach 2: sap xep

/* Voi cach nay, ta gia su:
 - Ta xep thanh cac cap theo thu tu dang dan
 - Va vi cach xep cap nay, ta se co duy nhat 1 truong hop sai: 1 so bi le ra (khong co du so luong de tao thanh cap) -> false
 */
bool divideArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < (int)nums.size() - 1; i += 2) {
        if (nums[i] != nums[i + 1]) return false;
    }
    
    return true; // kiem tra het ma thoa dieu kien -> true
}
