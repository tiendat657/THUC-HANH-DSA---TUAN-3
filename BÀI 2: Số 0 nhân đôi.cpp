Duplicate Zeros

void duplicateZeros(vector<int>& a) {
    int n = (int)a.size();
    int posDup = 0; // bien dem so luong so 0 co the co trong mang moi (da nhan doi)
    int last = n - 1; // bien luu vi tri ranh gioi (phan tu cuoi cung cua mang cu nam o mang moi sau khi nhan doi cac so 0 phia truoc)
    
    for (int i = 0; i <= last - posDup; i++) {
        if (a[i] == 0) {
            if (i == last - posDup) { // truong hop khi khong con cho nhan doi -> chi gan duoc 1 so 0 vao cuoi de tranh loi bo nho
                a[last] = 0;
                last--; // giam ranh gioi sau khi nhan doi
                break;
            }
            posDup++;
        }
    }
    
    int r = last - posDup;
    int w = last;
    
    for (int i = r; i >= 0; i--) {
        if (a[i] == 0) {
            a[w] = 0;
            a[w - 1] = 0;
            w -= 2;
        } else {
            a[w] = a[i];
            w--;
        }
    }
}
