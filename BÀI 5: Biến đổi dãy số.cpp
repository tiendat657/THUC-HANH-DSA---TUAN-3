int main(void) {
    int n; cin >> n;
    
    deque<int> dq; // khoi tao hang doi 2 chieu
    bool isReversed = false; // co bao hieu de biet them dau hay cuoi hang doi
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        
        if (!isReversed) { // khi chua bi dao chieu thi them vao cuoi va nguoc lai
            dq.push_back(x);
        } else {
            dq.push_front(x);
        }
        
        isReversed = !isReversed;
    }
    
    if (isReversed) { // khi bi dao chieu thi in ket qua nguoc tu duoi len tren dau
        for (auto it = dq.rbegin(); it != dq.rend(); it++) {
            cout << *it << " ";
        }
    } else {
        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it << " ";
        }
    }
    
    cout << endl;
    
    return 0;
}
