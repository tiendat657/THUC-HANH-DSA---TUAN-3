Happy Number

int getNext(int n) { // ham tinh tong luy thua tiep theo
    int totalSum = 0;
    
    while (n > 0) {
        int digit = n % 10;
        totalSum += digit * digit;
        n /= 10;
    }
    
    return totalSum;
}

/* Su dung tu duy:
 - Cho 1 con tro chay cham va 1 con tro chay nhanh,
 - neu co 1 vong lap vo tan thi 2 con tro se gap nhau vao 1 thoi diem nao do
 - hoac con tro nhanh se ket thuc tai diem cuoi (tai 1 vi 1^2 luon = 1)
 - khi do ta kiem tra fast == 1 de tra ve ket qua true hoac nguoc lai
 */

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    return fast == 1;
}
