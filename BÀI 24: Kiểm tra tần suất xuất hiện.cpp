Check if All Characters Have Equal Number of Occurence

bool areOccurrencesEqual(string s) {
    unordered_map<char, int> mp;
    
    for (char c : s) {
        mp[c]++;
    }
    
    int goal = mp.begin()->second;
    for (const auto& [ch, fr] : mp) {
        if (fr != goal) return false;
    }
    
    return true;
}
