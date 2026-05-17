Find Common Characters

vector<string> commonChars(vector<string>& words) {
    vector<int> minFreq(26, 0);
    for (char c : words[0]) { // gia  su bang tan suat moc la cua tu dau tien
        minFreq[c - 'a']++;
    }
    
    for (string s : words) {
        vector<int> curFreq(26, 0);
        for (char c : s) { // them cac ky tu o tu hien tai vao 1 bang tan suat de so sanh
            curFreq[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            minFreq[i] = min(minFreq[i], curFreq[i]); // them vao mang ket qua phan giao ky tu cua 2 bang tan suat
        }
    }
    
    vector<string> res;
    for (int i = 0; i < 26; i++) {
        while (minFreq[i] > 0) { // them toi da cac ban sao cua ky tu
            res.push_back(string(1, 'a' + i));
            minFreq[i]--;
        }
    }
    return res;
}
