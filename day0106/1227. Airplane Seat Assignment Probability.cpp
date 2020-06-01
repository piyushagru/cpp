/*
Combinatorics Proof

Assume , s=(x1,x2,.....,xm) is the set of passengers that does not get their own seat
then x1 will be the first passenger ( because if 1st passenger sit on its assigned seat then everyone else will also sit on their respective seats ) and each passenger xi must sit on the seat assigned for x((i+1)%m) ( because xi can not sit on the seats that are already occupied and if xi sit on the seat let say assined to x(i+2) then x(i+1) must have got its own seat) . So there is only one way of seating .

So , Arrangements in which last person get its seat will be given by -
1+C(n-2,1)+C(n-2,2)+--------------+C(n-2,n-2)=2^(n-2)
1 => Everyone sit on their respective seats
C(n-2,1) => Choose 1 passenger out of n except first and last one , so set s will have 2 passengers now (
chosen one + 1st passenger )
Similarly for other combinations

Total Arrangements is given by -
1+C(n-1,1)+C(n-1,2)+---------------------+C(n-1,n-1) = 2^(n-1)
1 => Everyone sit on their respective seats
C(n-1,1) => Choose 1 passenger out of n except first ( here we can also choose the last one to be part of set s )

Answer= No. of seating arrangements in which last person get its seat / Total arrangement
= 2^(n-2) / 2^(n-1) = 0.5 ( for n>1 )

*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1.0;
        else return 0.5;
    }
};