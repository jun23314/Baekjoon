import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int[] dp = new int[10001], memory = new int[N], cost = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            memory[i] = Integer.parseInt(st.nextToken());
        }
        int sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
            sum += cost[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = sum; j >= cost[i]; j--) {
                dp[j] = Math.max(dp[j-cost[i]] + memory[i], dp[j]);
            }
        }

        for (int i = 0; i < sum+1; i++) {
            if (dp[i] >= M) {
                System.out.println(i);
                return;
            }
        }


    }

}