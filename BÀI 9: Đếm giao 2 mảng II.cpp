Intersection of two arrays II

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res; // tao mang ket qua
    map<int, int> mp; // dem tan suat cua nums1
    
    for (int x : nums1) {
        mp[x]++; // dua tat ca phan tu cua num1 vao map va tan suat tung ky tu
    }
    
    for (int x : nums2) { // duyet tung ky tu trong mang nums2
        if (mp[x] > 0) {  // neu ky tu do ton tai (co tan xuat > 0)
            res.push_back(x); // them vao mang ket qua
            mp[x]--; // giam bot 1 lan tan suat de khong dem trung
        }
    }
    
    return res; // tra ve mang ket qua
}
