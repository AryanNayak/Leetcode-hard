759. Employee Free Time
https://leetcode.com/problems/employee-free-time/
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> mergeFreeTime(vector<vector<vector<int>>>& freeTime)
    {
     
        sort(freeTime.begin(), freeTime.end()); 
        
        vector<vector<int>> ans; 
        vector<vector<int>> firstList = freeTime[0];

        for(int k = 1; k < freeTime.size(); k++)
        {
           
            vector<vector<int>> secondList = freeTime[k];
            
            sort(firstList.begin(), firstList.end()); 
            sort(secondList.begin(), secondList.end()); 
            
            int i = 0, j = 0; 
           
            int n1 = firstList.size(); 
            int n2 = secondList.size(); 
            
            while(i < n1 && j < n2)
            {
                  
                int low = max({firstList[i][0], secondList[j][0]}); 
                int high = min({firstList[i][1], secondList[j][1]}); 
            
                if(low < high)
                {
                    ans.push_back({low, high});
                }
                
                if(firstList[i][1] > secondList[j][1])
                {
                    j++; 
                }
                else
                {
                    i++; 
                }
            }
            firstList = ans;
            ans.clear(); 
        }
    
        return firstList; 
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        int minTime  = INT_MAX; 
        int maxTime = INT_MIN; 
        
        for(auto e : schedule)
        {
            for(auto f : e)
            {
                
                minTime = min({minTime, f.start, f.end}); 
                maxTime = max({maxTime, f.start, f.end}); 
                
            }
        }
            
        vector<vector<vector<int>>> freeTime; 
            
        for(int i = 0; i < schedule.size(); i++)
        {
            int n = schedule[i].size();  
            vector<vector<int>> eachTime;         
            if(schedule[i][0].start - minTime > 0)
            {
                eachTime.push_back({minTime, schedule[i][0].start}); 
            }
            if(maxTime - schedule[i][n - 1].end  > 0)
            {
                eachTime.push_back({schedule[i][n-1].end, maxTime}); 
            }
            
            for(int j = 0; j < schedule[i].size() - 1; j++)
            {
                
                if(schedule[i][j + 1].start - schedule[i][j].end > 0)
                {
                   eachTime.push_back({schedule[i][j].end ,schedule[i][j + 1].start });  
                }
                
            }
            freeTime.push_back(eachTime); 
        }
            
    
        vector<vector<int>> ans = mergeFreeTime(freeTime); 
        
        
        int sz = ans.size(); 
            
        vector<Interval> fans(sz); 
        
        
        for(int i = 0; i < sz; i++)
        {
            fans[i].start = ans[i][0]; 
            fans[i].end = ans[i][1]; 
        }
        
    
        return fans; 
    }
};