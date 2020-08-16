class Solution {
public:
    int sourceColor = -1;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    void flood(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // if new pixel is out of bounds or not source color, return
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != sourceColor || image[sr][sc] == newColor) {
            return;
        }

        // else, pixel not explored, change color and explore neighbors
        else {
            image[sr][sc] = newColor;

            for(int i=0; i<4; i++) {
                flood(image, sr + row[i], sc + col[i], newColor);
            }
        }

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if(sourceColor == -1) {
            sourceColor = image[sr][sc];
        }

        flood(image, sr, sc, newColor);

        return image;

    }

};
