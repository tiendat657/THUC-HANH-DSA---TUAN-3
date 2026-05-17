Verifying an Alien Dictionary

/*
 Tao 1 mang danh dau kieu int de kiem tra vi tri 2 tu co dung hay chua
 Voi 2 tu, ta co 2 truong hop:
 - Neu 2 tu giong nhau k ky tu dau tien, tu co ki tu thu k + 1 hoac tu co do dai dai hon se xep o sau
 */
bool isAlienSorted(vector<string>& words, string order) {
    vector<int> alienOrder(26);
    
    for (int i = 0; i < 26; i++) {
        alienOrder[order[i] - 'a'] = i; // xep gia tri tang tang cho tung chu cai tu dau bang chu cai alien
    }
    
    for (int i = 0; i < (int)words.size() - 1; i++) {
        string w1 = words[i], w2 = words[i + 1];
        bool hasDiff = false; // bien trang thai cho truong hop sai o vi tri k nao do (th1) hoac giong nhau toan bo nhung co 1 tu dai hon (th2)
        int minLength = min((int)w1.length(), (int)w2.length()); // kiem tra den do dai cua tu ngan hon
        
        for (int j = 0; j < minLength; j++) {
            if (w1[j] != w2[j]) {
                if (alienOrder[w1[j] - 'a'] > alienOrder[w2[j] - 'a']) {
                    return false;
                }
                hasDiff = true;
                break; // thoat ngay de vi khi nay da tim thay khac biet
            }

        }
        
        // truong hop 2: vd:"app" va "apple"
        if (!hasDiff && w1.length() > w2.length()) {
            return false;
        }
    }
    
    return true;
}
