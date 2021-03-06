class Solution {
    // Time: O(n**2)
    // Space: O(1)
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int dir[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cnt = 1;
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            res[row][col] = cnt++;
            int r = Math.floorMod(row + dir[d][0], n);
            int c = Math.floorMod(col + dir[d][1], n);
            if (res[r][c] != 0) {
                d = (d + 1) % 4;
            }
            row += dir[d][0];
            col += dir[d][1];
        }
        return res;
    }
}