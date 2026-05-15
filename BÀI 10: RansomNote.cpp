RansomNote

bool canConstruct(string ransomNote, string magazine) {
    map<char, int> mp; // co the dung hash map hoac vector(26, 0)

    for (char c : magazine) { // tat ca cac ky tu trong m
        mp[c]++;
    }
    
    for (char c : ransomNote) {
        mp[c]--; // so luong ky tu can de tao tu ransomNote
    }
    
    for (const auto &[key, freq] : mp) {
        if (freq < 0) return false; // neu bi thieu ky tu -> freq cau 1 key nao do < 0
    }
    
    return true;
}
