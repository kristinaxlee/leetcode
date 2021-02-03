class Item {
    public:
        int val;
        int freq;
    
        Item(int val, int freq) {
            this->val = val;
            this->freq = freq;
        }
};

struct higherFreq {
    inline bool operator() (const Item& a, const Item& b) {
        return (a.freq > b.freq);
    }
};

class Solution {
public:
    unordered_map<int, int> frequency;
    vector<Item> items;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> elements;
        
        // insert elements into hash map
        for(int i=0; i<nums.size(); i++) {
            auto it = frequency.find(nums[i]);
            
            // if not in hash map, add to hashmap
            if(it == frequency.end()) {
                frequency.insert({nums[i], 1});
            }
            else {
                it->second++;
            }
        }
        
        // insert elements into array
        for (auto const& pair: frequency) {
            Item it = Item(pair.first, pair.second);
            items.push_back(it);
        }
        
        // sort the items
        sort(items.begin(), items.end(), higherFreq());
        
        // take the first k elements
        for(int i=0; i<k; i++) {
            elements.push_back(items[i].val);
        }
        
        return elements;
    }
};