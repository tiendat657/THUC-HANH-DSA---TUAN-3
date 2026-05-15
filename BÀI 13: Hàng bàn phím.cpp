Keyboard Row

// tao set cac ky tu chua cai o rieng moi hang cua ban phim
// uu tien set vi ta chi can dinh tinh (co/ khong) va unordered vi ta khong can duoc sap xep va can toc do truy xuat nhanh
unordered_set<char> se1 = {'q','w','e','r','t','y','u','i','o','p'};
unordered_set<char> se2 = {'a','s','d','f','g','h','j','k','l'};
unordered_set<char> se3 = {'z','x','c','v','b','n','m'};

bool isGood(string s) {
    for (char &c : s) { // chuyen cac chu cai sang chu thuong
        c = tolower(c);
    }
    
    if (se1.find(s[0]) != se1.end()) { // neu chu cai dau o hang dau -> kiem tra hang dau
        for (char &c : s) {
            if (se1.find(c) == se1.end()) return false; // neu khong thay chu cai trong set chu cai cua ban phim -> co it nhat 1 ky tu sai -> false
        }
    } else if (se2.find(s[0]) != se2.end()) { // tuong tu voi hang 2
        for (char c : s) {
            if (se2.find(c) == se2.end()) return false;
        }
    } else {
        for (char c : s) {
            if (se3.find(c) == se3.end()) return false;
        }
    }

    return true; // chi dung khi tat ca chu cai o 1 hang cua ban phim
}

vector<string> findWords(vector<string>& words) {
    vector<string> res;
    
    for (string s : words) {
        if (isGood(s)) {
            res.push_back(s);
        }
    }
    
    return res;
}
