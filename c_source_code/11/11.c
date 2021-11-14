int maxArea(int* height, int heightSize)
{
    int left = 0;;
    int right = heightSize - 1;
    int maxArea = 0;
    int tmpArea = 0;
    while (left < right) {
        tmpArea = (height[right] - height[left]) * fmax(height[right], height[left])
        maxArea = fmax(maxArea, tmpArea);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
