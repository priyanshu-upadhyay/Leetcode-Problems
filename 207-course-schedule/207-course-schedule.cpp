class Solution {
private:
    bool checkCycle(int start, vector<int> arr[], vector<int> &visited, vector<int> &dfsVisited)
    {
        visited[start] = 1;
        dfsVisited[start] = 1;
        
        for(int element : arr[start])
        {
            if(visited[element] == 0)
            {
                if(checkCycle(element, arr, visited, dfsVisited)) return true;
            }
            else if(dfsVisited[element] == 1) return true;
        }
        dfsVisited[start] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> arr[numCourses];
        for(vector<int> each : prerequisites)
        {
            arr[each[0]].push_back(each[1]);
        }
        
        vector<int> visited(numCourses);
        vector<int> dfsVisited(numCourses);
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == 0)
            {
                if(checkCycle(i, arr, visited, dfsVisited)) return false;
            }
        }
        return true;
        
    }
};