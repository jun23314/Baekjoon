import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    private static int T, N, M;
    private static int[] A, B;

    private static List<Integer> aSum = new ArrayList<>();
    private static List<Integer> bSum = new ArrayList<>();
    private static Map<Integer, Long> aM = new HashMap<>();
    private static Map<Integer, Long> bM = new HashMap<>();

    void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            T = Integer.parseInt(br.readLine());
            N = Integer.parseInt(br.readLine());

            A = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; ++i) {
                A[i] = Integer.parseInt(st.nextToken());
            }

            M = Integer.parseInt(br.readLine());

            B = new int[M];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; ++i) {
                B[i] = Integer.parseInt(st.nextToken());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += A[j];
                aSum.add(sum);
            }
        }

        for(int i = 0; i < M; ++i){
            int sum = 0;
            for(int j = i; j < M; ++j){
                sum += B[j];
                bSum.add(sum);
            }
        }

        Collections.sort(aSum);
        Collections.sort(bSum);

        for(int a : aSum){
            aM.put(a, aM.getOrDefault(a, 0L) + 1);
        }

        for(int b : bSum){
            bM.put(b, bM.getOrDefault(b, 0L) + 1);
        }

        long ans = 0;
        for(int key : aM.keySet()){
            int toFind = T - key;
            if(bM.containsKey(toFind)){
                ans += (aM.get(key) * bM.get(toFind));
            }
        }
        System.out.println(ans);

    }

    public static void main(String[] args) throws Exception {
        new Main().solve();
    }

}
