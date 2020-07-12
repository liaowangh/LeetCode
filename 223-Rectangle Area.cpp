class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        double sum, offset;
        sum = double((C - A) * (D - B)) + double((G - E) * (H - F));
        if(C <= E || G <= A || B >= H || D <= F){
            offset = 0;
        } else{
            int X = max(A, E);
            int Y = max(B, F);
            int S = min(C, G);
            int T = min(D, H);
            offset = (S - X) * (T - Y);
        }
        return sum - offset;
    }
};
