class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point on rectangle to the center 
        int xNearest,yNearest;
        if (x1 > xCenter){
            xNearest = x1;
        }
        else if (x2 < xCenter){
            xNearest = x2;
        }
        else{
            xNearest = xCenter;
        }
        if (y1 > yCenter){
            yNearest = y1;
        }
        else if (y2 < yCenter){
            yNearest = y2;
        }
        else{
            yNearest = yCenter;
        }
        int dis = (xCenter - xNearest)*(xCenter - xNearest) + (yCenter - yNearest)*(yCenter - yNearest);
        if (dis <= radius*radius){
            return true;
        }
        return false;
    }
};
