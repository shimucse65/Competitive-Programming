
int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int xx = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    if (xx > 0) return 0; // ccw 
    else if (xx < 0) return 1; // cw
    return 2;
}
bool onSeg(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (orientation(x1, y1, x2, y2, x3, y3) != 2) return false;
    if (min(x1, x2) <= x3 && max(x1, x2) >= x3 && min(y1, y2) <= y3 && max(y1, y2) >= y3)
    return true;
    return false;
}
bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
       int xx = onSeg(x1,y1,x2,y2,x3,y3);
       int yy=  onSeg(x1,y1,x2,y2,x4,y4);
       int zz = onSeg(x3,y3, x4,y4,x1,y1);
       int aa = onSeg(x3,y3,x4,y4,x2,y2);

    if (xx==1 || yy==1 || zz==1 || aa==1){
        return true;
    }

    int f1 = orientation(x1, y1, x2, y2, x3, y3);
    int f2 = orientation(x1, y1, x2, y2, x4, y4);
    int f3 = orientation(x3, y3, x4, y4, x1, y1);
    int f4 = orientation(x3, y3, x4, y4, x2, y2);

    if ((f1 ^ f2) && (f3 ^ f4)) return true;
    return false;
}
int RayCast (vector <pii>&v , int x1, int y1) {

        int n= v.size();
        int x2 = INT_MAX, y2 = INT_MAX + 1;
        int cnt = 0, f = 0;

        for (int i = 0; i < v.size(); i++) {
            int x3 = v[i].ff, y3 = v[i].ss;
            int x4 = v[(i + 1) % n].ff, y4 = v[(i + 1) % n].ss;

            int res = intersect(x3, y3, x4, y4, x1, y1, x2, y2);

            if (onSeg(x3,y3 ,x4,y4 ,x1,y1)) {
                f = 1;
                break;
            } else if (res) {
                cnt++;
            }
        }
        if (f) return 1; //boundary
        else if (cnt & 1) return 2; // inside
        return 3; //outside
}
