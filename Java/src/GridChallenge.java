import java.util.Arrays;

public final class GridChallenge {

    public static void main(String[] args) {
        final String[] grid1 = { "abcdz", "fghij", "klmno", "pqrst", "uvwxy", };
        final String[] grid2 = { "abcdj", "fghij", "klmno", "pqrst", "uvwxy", };

        System.out.println(gridChallenge(grid1));
        System.out.println(gridChallenge(grid2));
    }

    private static String gridChallenge(String[] grid) {
        for (int i = 0; i < grid.length; i++) {
            final char[] t = grid[i].toCharArray();
            Arrays.sort(t);
            grid[i] = new String(t);
        }

        for (int i = 0; i < grid.length; i++) {
            for (int j = 1; j < grid.length; j++) {
                if (grid[0].charAt(i) > grid[j].charAt(i)) {
                    return "NO";
                }
            }
        }
        return "YES";
    }
}
