Buddy Strings

/*
 Ta phai tim ra duoc 2 vi tri i != j sao cho khi hoan doi s[i] va goal[j] thi s == goal
 Chia ra 2 truong hop:
 TH1: 2 chuoi giong het nhau -> dua tat ca vao map va dem xem co ky nao lon hon 1 d khong (khi do ta co the hoan doi ma khong lam thay doi thanh chuoi khac)
 TH2: 2 chuoi khac nhau 1 hoac > 2 vi tri: tra ve sai vi khong the hoan doi
 TH3:2 chuoi khac nhau dung 2 cho: tao ra 2 chuoi temp bang cach hoan doi, so sanh voi goal de tra ve ket qua
 */

bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length()) return false;
    

    int index1 = -1, index2 = -1; // lu 2 vi tri khac nhau (neu co)
    int count = 0; // so luong vi tri khac nhau
    int n = (int)s.length();
    unordered_set<char> se; // kiem tra neu co ky tu xuat hien > 1 lan (th1)
    
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            count++;
            if (index1 == -1) index1 = i;
            else index2 = i;
        }
        
        se.insert(s[i]);
    }
    
    if (count == 1 || count > 2) return false; // th2
    else if (count == 0) { // th1: giong het nhau
        unordered_set<char> se; // kiem tra neu co ky tu xuat hien > 1 lan
        
        for (char c : s) {
            if (se.find(c) != se.end()) return true; // co the hoan doi ma khong lam thay doi
            se.insert(c);
        }
    
        return false; // khong the hoan doi
    }
    
    // th3: count = 2
    if (s[index1] == goal[index2] && s[index2] == goal[index1]) return true;
    return false;
}
