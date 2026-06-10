class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;// to force the minprice to be the firstprice in the array
        int maxprofit=0;
        for(auto price: prices){
            if(price<minprice){
                minprice=price;
            }
           maxprofit=max(maxprofit,price-minprice); 
        }
        return maxprofit;
    }
};
