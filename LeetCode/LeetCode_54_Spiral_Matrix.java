class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>();
        
        int top = 0;
        int bottom = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;
        
        int x = 0, y = -1;
        
        while (top <= bottom && left <= right) {
            while (y < right) {
                answer.add(matrix[x][++y]);
            }
            
            while (x < bottom) {
                answer.add(matrix[++x][y]);
            }
            
            while (y > left && top < bottom) {
                answer.add(matrix[x][--y]);
            }
            
            while (x - 1 > top && left < right) {
                answer.add(matrix[--x][y]);
            }
            top++; bottom--;
            left++; right--;
        }
        
        return answer;
    }
}
