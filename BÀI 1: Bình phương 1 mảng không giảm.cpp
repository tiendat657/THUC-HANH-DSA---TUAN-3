Squares of a Sorted Array 

int lowerBound(vector<int> &v, int x) {
    int n = (int)v.size();
    int l = 0, r = n - 1;
    int ans = n; // mac dinh la khong tim thay
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (v[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}

vector<int> sortedSquares(vector<int>& v) {
    int n = (int)v.size();
    vector<int> res;
        
    // su dung lowerbound de tim ra vi tri dau tien >= 0
    int j = lowerBound(v, 0);
    int i = j - 1;
    
    while (i >= 0 && j < n) {
        if (abs(v[i]) < abs(v[j])) {
            res.push_back(v[i] * v[i]);
            i--;
        } else {
            res.push_back(v[j] * v[j]);
            j++;
        }
    }
    
    while (i >= 0) {
        res.push_back(v[i] * v[i]);
        i--;
    }
    
    while (j < n) {
        res.push_back(v[j] * v[j]);
        j++;
    }

    for (int x : res) cout << x << " ";
    cout << endl;
    
    return res;
}
