import java.io.*;
import java.util.*;

/*
(r, c)에 벽 부순 경험이 있는지
1. 0이면 그냥 갈 수 있다
2. 1인데 벽 부순 경험이 있으면 못가
3. 1인데 벽 부순 경험이 없으면 부수고 가
 */
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 1,000,000 백만
        int[][] map = new int[N][M];
        for(int i = 0; i < N; ++i){
            String input = br.readLine();
            for(int j = 0; j < M; ++j){
                map[i][j] = input.charAt(j) - '0';
            }
        }

        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0, 0, 0, 1});

        boolean[][][] visited = new boolean[N][M][2];
        visited[0][0][0] = true;

        int ans = -1;
        while(!q.isEmpty()){
            int[] now = q.poll();
            int x = now[0];
            int y = now[1];
            int isBroken = now[2]; // 0이면 초범, 1이면 전과자
            int cnt = now[3]; // 횟수

            if(x == N-1 && y == M-1){
                ans = cnt;
                break;
            }
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                if(isBroken == 1){ // 전과가 있으면 빈칸만 갈 수 있음
                    if(map[nx][ny] == 1) continue;
                    if(visited[nx][ny][isBroken]) continue;

                    visited[nx][ny][isBroken] = true;
                    q.offer(new int[]{nx, ny, isBroken, cnt+1});

                }
                else{ // 초범이면
                    if(map[nx][ny] == 0) { // 빈칸이면 그냥 갈 수 있음
                        if(visited[nx][ny][isBroken]) continue;

                        visited[nx][ny][isBroken] = true;
                        q.offer(new int[]{nx, ny, isBroken, cnt+1});
                    }
                    else{ // 벽이면 부수고 갈 수 있음
                        if(visited[nx][ny][1]) continue;

                        visited[nx][ny][1] = true;
                        q.offer(new int[]{nx, ny, 1, cnt+1});
                    }
                }
            }
        }

        System.out.println(ans);
        br.close();
    }
}
