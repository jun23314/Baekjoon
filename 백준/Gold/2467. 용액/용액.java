import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int[] liquid;

    void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(br.readLine());

            liquid = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int n = 0; n < N; ++n) {
                liquid[n] = Integer.parseInt(st.nextToken());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        Arrays.sort(liquid);

        int ans = Integer.MAX_VALUE;
        int left = 0, right = N - 1;
        int ansLeft = 0, ansRight = N-1;
        while (left < right) {
            int sum = liquid[left] + liquid[right];
            if (sum == 0) {
                ansLeft = left;
                ansRight = right;
                break;
            }

            if(Math.abs(ans) > Math.abs(sum)){ // 크면 줄여.
                ans = sum;
                ansLeft = left;
                ansRight = right;
            }
            if (sum < 0) left++;
            else right--;
        }

        System.out.println(liquid[ansLeft] + " " + liquid[ansRight]);
    }

    public static void main(String[] args) throws Exception {
        new Main().solve();
    }

}
