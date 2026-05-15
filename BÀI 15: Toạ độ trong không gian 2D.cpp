Path Crossing

// neu di qua 1 diem 2 lan -> diem do se co gia tri tan suat la 2 trong set (set luu tat ca vi tri bao gom ca O ma diem di qua)
// -> 0 gian 2D -> pair de luu dong thoi cap x va y

bool isPathCrossing(string path) {
    unordered_set<pair<int, int>> se;

    int curX = 0;
    int curY = 0;
    
    se.insert({0, 0}); // diem xuat phat mac dinh la da di qua

    for (char c : path) {
        if (c == 'N') { // bac
            curY++;
        } else if (c == 'S') { // nam
            curY--;
        } else if (c == 'E') { // dong
            curX++;
        } else { // tay
            curX--;
        }
        if(se.find({curX,curY}) != se.end()) { // neu co bat ki vi tri nao co tan suat xuat hien > 1 -> da di qua
            return true;
        }
        se.insert({curX, curY}); // them toa do hien tai sau khi di chuyen vao set
    }
    
    return false;
}
