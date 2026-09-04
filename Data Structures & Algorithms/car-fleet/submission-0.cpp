class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double cartime = 0.0;
        stack<double> stk;
        int i = 0;
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }
        sort(cars.rbegin(), cars.rend());  // sort from large to small
        for (auto [pos, sp] : cars) {
            cartime = static_cast<double>(target - pos) / sp;
            if (stk.empty() || cartime > stk.top()) {
                stk.push(cartime);
            }
        }

        return stk.size();
    }
};
