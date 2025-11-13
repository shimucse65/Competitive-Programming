#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PI 3.1415926535897932385

const int N = 1e5 + 10;

struct Point {
    int x, y;
    void setf(int xx, int yy) {
        x = xx;
        y = yy;
    }
} p0, ans[N], points[N];

int dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double angle(Point A, Point B, Point C) {
    double a = sqrt((double)dist(A, B));
    double b = sqrt((double)dist(B, C));
    double c = sqrt((double)dist(C, A));
    return acos((a * a + c * c - b * b) / (2 * a * c));
}

int orientation(Point p, Point q, Point r) {
    return ((q.y - p.y) * (r.x - q.x)) - ((r.y - q.y) * (q.x - p.x));
}

bool compare(Point a, Point b) {
    int o = orientation(p0, a, b);
    if (o == 0) return dist(p0, a) < dist(p0, b);
    return o > 0;
}

double Hull(Point points[], int n) {

    int ymin = points[0].y, mn = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[mn].x)) {
            ymin = points[i].y;
            mn = i;
        }
    }
    swap(points[0], points[mn]);

    p0 = points[0];
    sort(points + 1, points + n, compare);

    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) i++;
        points[m++] = points[i];
    }

    if (m < 3) return 0.0;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (S.size() >= 2) {
            Point top = S.top(); S.pop();
            Point nextTop = S.top();
            if (orientation(nextTop, top, points[i]) > 0) {
                S.push(top);
                break;
            }
        }
        S.push(points[i]);
    }

    int cnt = 0;
    while (!S.empty()) {
        ans[cnt++] = S.top();
        S.pop();
    }

    vector<Point> hull(cnt);
    for (int i = 0; i < cnt; i++) {
        hull[i] = ans[cnt - 1 - i];
    }

    double min_angle = 180.0;
    for (int i = 0; i < cnt; i++) {
        int j = (i + 1) % cnt;
        int k = (i - 1 + cnt) % cnt;
        double ang = angle(hull[i], hull[j], hull[k]) * 180.0 / PI;
        min_angle = min(min_angle, ang);
    }

    return min_angle;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        points[i].setf(xx, yy);
    }
    double result = Hull(points, n);
    cout <<setprecision(10) <<fixed <<result<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, c = 1;
    cin >> t;
    while (t--) {
        cout <<"Case " <<c++ <<": ";
        solve();
    }
}
