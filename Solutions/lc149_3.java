/*  22ms beats 47%
**  Long type as key, with bit-opration transforming.
*/
import java.util.*;
class Point {
    int x;
    int y;
    Point() { x = 0; y = 0; }
    Point(int a, int b) { x = a; y = b; }
}
class lc149_3 { 
    private long getSlopeKey(Point p1, Point p2){
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;
        //vertical line
        if(dx == 0) return (long) p1.x << 32 | 0;
        //horizontal line
        if(dy == 0) return (long) 0 << 32 | p1.y;
        int divisor = gcd(dx, dy);
        return (long) (dy / divisor) << 32 | (dx / divisor);    //the simplest slope
    }
    private int gcd(int m, int n){
        if(n == 0) return m;
        return gcd(n, m % n);
    }
    public int maxPoints(Point[] points) {
        int n = points.length;
        if(n < 2) return n;
        int ans = 1;
        for(int i = 0; i < n; i++){
            Point p1 = points[i];
            int samePoints = 0;
            int maxPoints = 1;
            Map<Long, Integer> map = new HashMap<>();   //(slopekey, count)
            for(int j = i + 1; j < n; j++){
                Point p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y){
                    samePoints++;
                    continue;
                }
                long sk = getSlopeKey(p1, p2);
                map.put(sk, map.getOrDefault(sk, 1) + 1);
                maxPoints = Math.max(maxPoints, map.get(sk));
            }
            ans = Math.max(ans, samePoints + maxPoints);
        }
        return ans;
    }
}