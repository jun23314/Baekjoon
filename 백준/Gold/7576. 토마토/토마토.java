import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/**
 * 1 익은 토마토 0 안익은 토마토 -1 없는 토마토
 */
public class Main {

    int N, M;
    int[][] tomatos;
    int[][] ripenTomatos;
    int totalTomato = 0;
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};
    /**
     * int[0] n int[1] m int[2] 며칠?
     */
    Deque<int[]> q = new ArrayDeque<>();

    void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());

            tomatos = new int[N][M];
            ripenTomatos = new int[N][M];

            totalTomato = N * M;
            for (int n = 0; n < N; ++n) {
                st = new StringTokenizer(br.readLine());
                for (int m = 0; m < M; ++m) {
                    int tmp = Integer.parseInt(st.nextToken());
                    tomatos[n][m] = tmp;

                    if (tmp == 1) {
                        q.offer(new int[]{n, m, 0});
                        ripenTomatos[n][m] = 1;
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        int minDay = 0;
        while (!q.isEmpty()) {
            int[] now = q.poll();
            int nn = now[0];
            int nm = now[1];
            int nd = now[2];
            
            minDay = Math.max(minDay, nd);
            for (int dir = 0; dir < 4; ++dir) {
                int nx = nn + dx[dir];
                int ny = nm + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    continue;
                }
                if (tomatos[nx][ny] == -1) {
                    continue;
                }
                if (ripenTomatos[nx][ny] != 0) {
                    continue;
                }

                ripenTomatos[nx][ny] = nd+1;
                q.offer(new int[]{nx, ny, nd + 1});
            }
        }


        for(int n = 0; n < N; ++n){
            for(int m = 0; m < M; ++m){
                if(ripenTomatos[n][m] == 0 && tomatos[n][m] == 0) continue;
                totalTomato--;
            }
        }

        if(totalTomato == 0)
            System.out.print(minDay);
        else System.out.print(-1);
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }

}
