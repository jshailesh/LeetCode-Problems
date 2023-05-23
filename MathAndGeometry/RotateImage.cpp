// LC 48
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

#include <vector>
#include <algorithm>

class Solution {
public:
    void rotateImage(std::vector<std::vector<int>>& image) {
        // 90 Deg clock-wise rotation can be achieved by
        // 1. Reversing the matrix
        // 2. Swapping the elements at the mirror images across the diagonal

        // Reverse the matrix
        std::reverse(image.begin(), image.end());

        // Swap the elements at the mirror images
        for (int row = 0; row < image.size(); ++row) {
            for (int col = row + 1; col < image[0].size(); ++col) {
                std::swap(image[row][col], image[col][row]);
            }
        }
    }
};