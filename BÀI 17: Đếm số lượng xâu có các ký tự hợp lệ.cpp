Count the Number of Consistent Strings

int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> se;
    for (char c : allowed) {
        se.insert(c); // dua tat ca cac chu cac vao set de kiem tra su ton tai
    }
    
    int count = 0;
    
    for (string w : words) { // duyet tat ca tu trong vector
        bool isValid = true;

        for (char c : w) { // voi moi tu, duyet tat ca ky tu torng tu do
            if (se.find(c) == se.end()) { // neu khong tim thay
                isValid = false; // thi danh dau va chuyen sang tu ke tiep (neu co)
                break;
            }
        }
        if (isValid) {
            count++;
            isValid = true; // sau khi them xong thi xoa trang thai hop le
        }
    }
    
    return count;
}
