First Unique Character

int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    
    int first = -1; // bine ket qua (mac dinh = -1 neu khong tim thay)
    for (char c : s) mp[c]++; // dua vao map de kiem tra ky tu co lap lai hay khong
    
    for (int i = 0; i < (int)s.length(); i++) {
        if (mp[s[i]] == 1) { // neu khong lap lai
            first = i; // gan vao bien ket qua
            break; // thoat ngay vi chi can tim vi tri dau tien
        }
    }
    
    return first;
}
