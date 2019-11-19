import java.util.Arrays;

public final class ClimbingTheLeaderboard {

    private static int[] climbingLeaderboard(int[] scores, int[] alice) {
        int rank = 1;
        int prev = scores[0];
        int currentScoreIndex = 0;
        for (int i = alice.length - 1; i >= 0; i--) {
            if (alice[i] < prev) {
                while (currentScoreIndex < scores.length) {
                    if (scores[currentScoreIndex] < prev) {
                        rank++;
                        prev = scores[currentScoreIndex];
                    }
                    if (alice[i] >= scores[currentScoreIndex]) {
                        break;
                    }
                    currentScoreIndex++;
                }
            }

            alice[i] = currentScoreIndex == scores.length ? rank + 1 : rank;
        }

        return alice;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(climbingLeaderboard(new int[] { 100, 100, 50, 40, 40, 20, 10 },
                                                               new int[] { 5, 25, 50, 120 })));
        System.out.println(Arrays.toString(climbingLeaderboard(new int[] { 100, 90, 90, 80, 75, 60 },
                                                               new int[] { 50, 65, 77, 90, 102 })));
    }

    private ClimbingTheLeaderboard() {}
}
