import java.util.ArrayList;
import java.util.List;

class Solution {

    List<Spot> queue;
    int m = 0;
    int n = 0;
    int[][] dir = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public void solve(char[][] board) {
        queue = new ArrayList<>();
        m = board.length;
        n = board[0].length;
        boolean[][] visited = new boolean[m][n];

        // col == 0
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                func(board, i, 0, visited);
            }
        }

        // col == n - 1
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                func(board, i, n - 1, visited);
            }
        }

        // row == 0
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                func(board, 0, j, visited);
            }
        }

        // row == m - 1
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O') {
                func(board, m - 1, j, visited);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }

    }

    private void func(char[][] board, int x, int y, boolean[][] visited) {

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            if (isOutside(dx, dy) || visited[dx][dy] || board[dx][dy] == 'X') continue;

            func(board, dx, dy, visited);
        }
    }

    private boolean isOutside(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n) return false;
        else return true;
    }

    public void print(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");
        }
    }

    class Spot {
        int x;
        int y;

        Spot(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
