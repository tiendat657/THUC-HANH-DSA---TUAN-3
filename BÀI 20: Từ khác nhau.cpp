Uncommon Words for Two Strings

/*
 Duyet ca 2 xau va them cac tu vao chi 1 hash map
 - Y tuong o day la 1 tu duoc xem la 'uncommon' khi no  xuat hien 1 lan va o 1 xau
 -> Khong co truong hop tu xuat hien nhieu lan 1 xau ma duoc xem la uncommon
 -> Them vao vector ket qua nhung tu trong map co freq = 1
 */

vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> res;
    
    unordered_map<string, int> mp;
    
    stringstream ss1(s1);
    string word;
    
    while (ss1 >> word) {
        mp[word]++;
    }
    
    stringstream ss2(s2);
    while (ss2 >> word) {
        mp[word]++;
    }
    
    for (const auto &[s, fr] : mp) {
        if (fr == 1) res.push_back(s);
    }
    
    return res;
}
