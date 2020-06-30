class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       //total number of families that can be there in cinema
        // two families for each row
        // hence n*2
        int fam = n*2;
        
        //a map for each row
        //character to store the reserved seats
        unordered_map<int,char> map;
        
        // remove 1st and 10th seat reservation cause we just dont care about it
        for(auto x:reservedSeats)
            if(x[1] > 1 and x[1] < 10)
                //make a pattern of the reserved seats and store it as binary value 
                //represented by 1 in the map
                map[x[0]] |= 1<<(x[1]-2);
            
        
        
        for(auto seat: map){
            //if a fimily is able to seat by a pattern then p1,p2,p3 is true
            bool p1 = !(seat.second & 0b11110000);
            bool p2 = !(seat.second & 0b00111100);
            bool p3 = !(seat.second & 0b00001111);
            
            
            if(p1 and p3)
                // matlab ek row main do families aa jaigi
                continue;
            else if(p1 or p2 or p3)
                //-1 matlab is row main sirf ek family aa paigi 
                fam = fam-1;
            //-2 matlab kuch bhi karle is row man ek bhi family ni ghusa paiga
                else fam = fam-2;
        }
    return fam;
    }
};