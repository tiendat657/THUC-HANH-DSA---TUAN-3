Most Common Word

/*
 - Buoc 1: dua tat ca tu trong banned vao 1 hash set de tim kiem nhanh hon (neu co)
 - Buoc 2: dua tat ca trong paragraph vao 1 hash map neu tu do khong co trong set banned
 - Buoc 3: duyet qua hash map va tim ra tu co tan suat lon nhat (uu tien thu tu)
 
 *Luu y: can chuan hoa sang chu thuong
 */

void stdardize (string &s){
    for (char &c : s) c = tolower(c);
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> se;
    
    for (string s : banned) {
        se.insert(s); // de dam bao tu se duoc chuan hoa san -> khong can goi ham chuan hoa
    }
    
    unordered_map<string, int> mp;
    
    for (char &c : paragraph) { // chuyen ve dang chuan ve tach tu khong dinh dau cau
        if (isalpha(c)) c = ' ';
    }
    stringstream ss(paragraph); // cach tu trong cau
    string word;
    
    while (ss >> word) { // voi moi tu duoc tach
        stdardize(word); // chuan hoa
        
        if (se.find(word) == se.end()) { // tim kiem xem co phai la tu bi cam hay khong
            mp[word]++; // them vao map de dem tan suat
        }
        
    }
    string smostFr = "";
    int mostFr = 0;
    
    for (const auto &[s, fr] : mp) {
        if (fr > mostFr) { // tim tu co tan saut xuat hien nhie nhat
            mostFr = fr;
            smostFr = s;
        }
    }
        
    return smostFr;
}
