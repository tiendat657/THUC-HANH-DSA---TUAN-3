Check Array Formation Through Distinct Pieces

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    // tao hash map luu ky tu dau tien va vector cua ky tu dau tien do
    unordered_map<int, vector<int>> mp;
    
    for (const auto &it : pieces) { // su dung it nhu con tro chi den vi tri dau tien cua vector
        mp[it[0]] = it; // dua vector vao map theo dang [first, vector of first]
    }
    
    int i = 0; // con tro chay tu dau den cuoi mang arr
    while (i < (int)arr.size()) {
        if (mp.find(arr[i]) == mp.end()) return false; // khong tim thay manh ghep do
        
        vector<int> target = mp[arr[i]]; // khi tim duoc, ta so sanh xem dung thu tu hay khong
        
        for (int x : target) {
            if (arr[i] != x) return false;
            i++; // tang i de kiem tra tung gia tri cua arr
        }
    }
    
    return true;
}
