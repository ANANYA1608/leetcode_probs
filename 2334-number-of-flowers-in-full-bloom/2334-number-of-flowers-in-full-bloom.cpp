class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans(people.size());

        
        vector<int> flower_starts;
        vector<int> flower_ends;

        for (const auto& flower : flowers)
        {
            flower_starts.push_back(flower[0]);
            
            flower_ends.push_back(flower[1] + 1);
        }

        vector<pair<int, int>> people_with_id;
        people_with_id.reserve(people.size());

      
        for (int i = 0; i < people.size(); i++)
        {
            people_with_id.push_back(make_pair(people[i], i));
        }

       
        sort(flower_starts.begin(), flower_starts.end());
        sort(flower_ends.begin(), flower_ends.end());
        sort(people_with_id.begin(), people_with_id.end());

       
        int next_flower_start = 0;
        int next_flower_end = 0;

       
        int num_flowers = 0;

       
        for (int i = 0; i < people_with_id.size(); i++)
        {
            int target_time = people_with_id[i].first;
            int person_id = people_with_id[i].second;
            
            
            while (next_flower_start < flower_starts.size() &&
                flower_starts[next_flower_start] <= target_time)
            {
              
                num_flowers++;
                next_flower_start++;
            }

            while (next_flower_end < flower_ends.size() && flower_ends[next_flower_end] <= target_time)
            {
                num_flowers--;
                next_flower_end++;
            }

           
            ans[person_id] = num_flowers;
        }

        return ans;
    }
};