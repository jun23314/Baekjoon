import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int K = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());

        int[][] map = new int[H][W];
        for(int i = 0; i < H; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < W; ++j){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] dx = {0, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
        int[] dy = {1, 0, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1};

        boolean[][][] visited = new boolean[H][W][K+1]; // (H,W)에 k를 몇 번 쓰고 도착했는지?
        int ansCnt = -1;
        Deque<Loc> pq = new ArrayDeque<>();
        pq.offer(new Loc(0, 0, 0, 0));
        visited[0][0][0] = true;
       
        while(!pq.isEmpty()){
            Loc now = pq.poll();

            if(now.x == H-1 && now.y == W-1){
                ansCnt = now.cnt;
                break;
            }

            for (int i = 0; i < 12; ++i) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                int nk = now.k + 1;

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue; // 범위 아웃
                if (map[nx][ny] == 1) continue; // 장애물 못밟아

                if(i < 4){ // 원숭이
                    if (visited[nx][ny][now.k]) continue; // 더 빠르게 도착했었다면
                    pq.offer(new Loc(nx, ny, now.cnt+1, now.k));
                    visited[nx][ny][now.k] = true;
                }
                else{
                    if(now.k == K) break;
                    if (visited[nx][ny][nk]) continue; // 더 빠르게 도착했었다면
                    pq.offer(new Loc(nx, ny, now.cnt+1, nk));
                    visited[nx][ny][nk] = true;
                }
            }
        }

        System.out.println(ansCnt);
    }

    static class Loc{
        int x, y;
        int cnt;
        int k;

        public Loc(int a, int b, int c, int k){
            this.x = a;
            this.y = b;
            this.cnt = c;
            this.k = k;
        }
    }
}