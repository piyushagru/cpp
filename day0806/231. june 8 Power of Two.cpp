class Solution {
public:
    bool isPowerOfTwo(int n) {
    int count = 0;
    if(n<0)return false;
        while(n and count <= 1){
        n = n & (n-1);
        count++;
        //cout<<"n: "<<n<<endl;
    }
    return (count == 1?true:false);
}
};