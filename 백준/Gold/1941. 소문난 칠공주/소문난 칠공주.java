import java.io.*;
import java.util.*;

public class Main {
    private static char[][] seats = new char[5][5];
    private static int[][] princess = new int[5][5];
    private static int count = 0;

    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, -1, 0, 1};
    private static Deque<int[]> q = new ArrayDeque<>();
    void solve(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            for(int i = 0; i < 5; ++i){
                String input = br.readLine();
                for(int j = 0; j < 5; ++j){
                    seats[i][j] = input.charAt(j);
                    princess[i][j] = 0;
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }

        find7Princess(0,0);
        System.out.print(count);
    }

    private void find7Princess(int idx, int cnt){
        if(cnt == 7) { // 7공주 다 골랐다
            checkPrincessGroup();
            return;
        }

        for(int i = idx; i < 25; ++i){
            if(princess[i / 5][i % 5] == 1) continue;
            princess[i / 5][i % 5] = 1;
            find7Princess(i+1, cnt + 1);
            princess[i / 5][i % 5] = 0;
        }
    }

    private void checkPrincessGroup(){
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                if(princess[i][j] == 0) continue;

                if(!isConnectedAndSFamily(i, j)) return;
                count++;
                return;
            }
        }
    }

    private boolean isConnectedAndSFamily(int x, int y){
        int cnt = 1;
        int sFamily = 0;

        int[][] tmp = new int[5][5];

        q.push(new int[]{x, y});
        tmp[x][y] = 1;
        if(seats[x][y] == 'S') sFamily++;

        while(!q.isEmpty()){
            int[] now = q.poll();

            for(int i = 0; i < 4; ++i){
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];

                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if(princess[nx][ny] == 0) continue;
                if(tmp[nx][ny] == 1) continue;

                cnt++;
                if(seats[nx][ny] == 'S') sFamily++;
                tmp[nx][ny] = 1;
                q.offer(new int[]{nx, ny});
            }
        }

        if(cnt != 7) return false;
        if(sFamily < 4) return false;
        return true;
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }

}
