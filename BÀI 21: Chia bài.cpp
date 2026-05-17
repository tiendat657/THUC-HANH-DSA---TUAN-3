X of a Kind in a Deck of Cards

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> mp;
    
    for (int x : deck) {
        mp[x]++;
    }
    
    int g = mp.begin()->second; // g la gia tri dau tien (tranh loi uninitialization val)
    for (const auto &[x, f] : mp) {
        g = gcd(g, f); // su dung tinh chat cua uoc chung lon nhat: gcd(a, b, c) = gcd(a, gcd(b, c))...
        if (g == 1) return false; // neu co 1 so khong nguyen to cung nhau -> khong the chia duoc theo de bai
    }
    
    return true;
}
