Shortest Completing Word

bool isValid(const map<char, int> &mp, string w) { // truyen tham chieu hang
    map<char, int> wordMap; // tao 1 map rieng cua tu dang can xet
        for (char c : w) {
            wordMap[c]++;
        }
    
    // duyet map lai de kiem tra xem co tu nao ma xau s khong co du so luong hay khong
    for (const auto &[key, freq] : mp) {
        if (freq > wordMap[key]) return false; // xau s khong co du ky tu
    }
    
    return true;
}

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string ans = "";
    map<char, int> mp;
    
    // them cac ky tu (bien doi sang lowercase) vao map 1 lan duy nhat
    for (char c : licensePlate) {
        if (isalpha(c)) {
            mp[tolower(c)]++;
        }
    }
    
    for (const string &w : words) {
        if (isValid(mp, w)) { // neu tu do chua tat ca cac ky tu va du/ hon so lan
            if (w.length() < ans.length() || ans.empty()) { // dung dau '<' vi ta uu tien thu tu xet tu dau den cuoi mang
                ans = w;
            }
        }
    }
    
    return ans;
}
