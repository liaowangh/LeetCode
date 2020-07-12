class Node {
friend class NumArray;
public:
    Node(){}
    Node(int l_, int r_, int v_): l(l_), r(r_), val(v_) {}
private:
    int l;
    int r;
    int val;
};

class NumArray {
public:
    NumArray(vector<int>& nums): tree(4*nums.size()), array(nums) {
        if(nums.empty()) return;
        build(0, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        int left = 0, right = array.size() - 1;
        int n = 0;
        int diff = val - array[i];
        do {
            tree[n].val += diff;
            int mid = (left + right) / 2;
            if(i <= mid){
                right = mid;
                n = 2*n + 1;
            }
            else{
                left = mid + 1;
                n = 2*n+2;
            }
        } while(left != right);
        tree[n].val = val;
        array[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(0, i, j);
    }

private:
    vector<Node> tree;
    vector<int> &array;
    void build(int i, int l, int r);
    int query(int i, int l, int r);
};

void NumArray::build(int i, int l, int r) {
    tree[i].l = l;
    tree[i].r = r;
    if(l == r)
        tree[i].val = array[l];
    else{
        int mid = (l + r) >> 1;
        build(2*i+1, l, mid);
        build(2*i+2, mid+1, r);
        tree[i].val = tree[2*i+1].val + tree[2*i+2].val;
    }
}

int NumArray::query(int i, int l, int r) {
    if(tree[i].l >= l && tree[i].r <= r)
        return tree[i].val;
    else if (tree[i].l > r || tree[i].r < l)
        return 0;
    else
        return query(2*i+1, l, r) + query(2*i+2, l, r);
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
