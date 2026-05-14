Isomorphic strings

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mp; // s-> t
    unordered_set<char> se; // can phai su dung them set/ map de kiem tra xem t -> s hay khong
    
    if (s.length() != t.length()) return false; // khac do dai thi false luon
    
    for (int i = 0; i < (int)s.length(); i++) {
        if (mp.find(s[i]) == mp.end()) { // s[i] la ky tu moi
            if (se.find(t[i]) != se.end()) return false; // kiem tra xem da co ky tu khac chiem dung s[i] truoc do hay chua
            
            // ghi nhan anh xa moi
            mp[s[i]] = t[i];
            se.insert(t[i]);
        } else {
            if (mp[s[i]] != t[i]) return false; // anh xa s -> t la sao => false
        }
    }
    
    return true;
}
