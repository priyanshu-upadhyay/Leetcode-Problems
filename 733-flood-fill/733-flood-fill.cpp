class Solution {
    
private:
    void dfs_coloring(int i, int j, int n, int m, vector<vector<int>>& image, int colorToChange, int newColor)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != colorToChange) return;
        
        image[i][j] = newColor;
        dfs_coloring(i+1, j, n, m, image, colorToChange, newColor);
        dfs_coloring(i-1, j, n, m, image, colorToChange, newColor);
        dfs_coloring(i, j+1, n, m, image, colorToChange, newColor);
        dfs_coloring(i, j-1, n, m, image, colorToChange, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(newColor == color) return image;
            
        int n = image.size(), m = image[0].size();
        
        dfs_coloring(sr, sc, n, m, image, color, newColor);
        
        return image;
    }
};