Distribute Candies

// so luong loai keo toi da an duoc = min(so luong loai keo co the co, n / 2 cai keo)
int distributeCandies(vector<int>& candyType) {
    unordered_set<int> se;
    int n = (int)candyType.size() / 2; // so luong cai keo ma Alice co the an
    
    for (int x : candyType) {
        se.insert(x); // tim so luong toi da loai keo co the co
    }
    
    // so luong loai keo co the an
    if ((int)se.size() > n) return n;
    return (int)se.size();
}
