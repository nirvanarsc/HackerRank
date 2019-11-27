import static java.lang.Character.getNumericValue;

public final class SamSubstrings {

    public static void main(String[] args) {
        System.out.println(substrings("123"));
        System.out.println(substrings("972698438521"));
    }

    static int substrings(String n) {
        final char[] chars = n.toCharArray();
        final int mod = 1000000000 + 7;
        final int length = n.length() - 1;
        long t = 1, sum = 0, prev = 0;
        for (int i = length; i >= 0; i--) {
            prev += t * getNumericValue(chars[i]) % mod;
            sum = (sum + prev) % mod;
            t = (t * 10 + 1) % mod;
        }
        return (int) sum;
    }

    private SamSubstrings() {}
}
