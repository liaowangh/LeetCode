class Solution {
public:
    Solution(double radius, double x_center, double y_center):
        r(radius), x(x_center), y(y_center) {}
    
    vector<double> randPoint() {
        double theta = uniform() * 2 * M_PI;
        double radius = sqrt(uniform()) * r;
        return {x + radius*cos(theta), y + radius*sin(theta)};
    }
private:
    double r, x, y;
    
    double uniform() {
        return (double)rand() / RAND_MAX;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
