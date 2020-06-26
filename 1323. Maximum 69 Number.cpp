//26 june
class Solution {
public:
    int maximum69Number (int num) {
        string abc = to_string(num);
        for(int i = 0;i<abc.size();i++){
            if(abc[i] == '6'){
                abc[i] = '9';
                break;
            }
        }
        // cout<<abc;
        return stoi(abc);
    }
};

// just a method with pass by reference inside loop
class Solution {
public:
    int maximum69Number (int num) {
        string abc = to_string(num);
        for(auto &x:abc){
            if(x == '6'){
                x = '9';
                break;
            }
        }
        return stoi(abc);
    }
};