import java.io.*;
import java.util.*;

public class Main {
    private static int R, C;
    private int[][] miro;
    private int[][] jihoonRoute;
    private static final String LOST = "IMPOSSIBLE";
    private Deque<int[]> fire = new ArrayDeque<>();
    private Deque<int[]> jihoon = new ArrayDeque<>();
    private static final int[] dx = {0, 1, 0, -1};
    private static final int[] dy = {1, 0, -1, 0};

    void solve(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            StringTokenizer st = new StringTokenizer(br.readLine());
            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            miro = new int[R][C];
            jihoonRoute = new int[R][C];
            for(int r = 0; r < R; ++r){
                String input = br.readLine();
                for(int c = 0; c < C; ++c){
                    char tmp = input.charAt(c);
                    if(tmp == '#') miro[r][c] = -1;
                    if(tmp == '0') miro[r][c] = 0;
                    if(tmp == 'F') { // 불이야 불!
                        fire.offer(new int[]{r, c});
                        miro[r][c] = 1;
                    }
                    if(tmp == 'J'){ // 지훈이
                        jihoon.offer(new int[]{r, c, 1});
                        miro[r][c] = 0;
                        jihoonRoute[r][c] = 1;

                        if(r == 0 || r == R-1 || c == 0 || c == C-1 ){
                            System.out.println(1);
                            return ;
                        }
                    }
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }

        while(!fire.isEmpty() || !jihoon.isEmpty()){
            moveFire();
            Integer moving = moveJihoon();
            if(moving != null) {
                System.out.print(moving);
                return ;
            }
        }
        System.out.print(LOST);

    }

    Integer moveJihoon(){
        int leng = jihoon.size();
        for(int i = 0; i < leng; ++i){
            int[] now = jihoon.poll();
            int nr = now[0];
            int nc = now[1];
            int nt = now[2];

            for(int dir = 0; dir < 4; ++dir){
                int nx = nr + dx[dir];
                int ny = nc + dy[dir];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(miro[nx][ny] != 0) continue;
                if(jihoonRoute[nx][ny] == 1) continue;
                if(nx == 0 || nx == R-1 || ny == 0 || ny == C-1 ){
                    return nt+1;
                }

                jihoonRoute[nx][ny] = 1;
                jihoon.offer(new int[]{nx, ny, nt+1});
            }
        }
        return null;
    }

    void moveFire(){
        int leng = fire.size();
        for(int i = 0; i < leng; ++i){
            int[] now = fire.poll();
            int nr = now[0];
            int nc = now[1];
            int nt = miro[nr][nc];

            for(int dir = 0; dir < 4; ++dir){
                int nx = nr + dx[dir];
                int ny = nc + dy[dir];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(miro[nx][ny] != 0) continue;

                miro[nx][ny] = nt + 1;
                fire.offer(new int[]{nx, ny});
            }
        }
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }

}
