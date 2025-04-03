import java.io.*;
import java.util.*;


/*
1. 물의 그룹 별로 2차원 배열에 저장해둠
2. 다음에 사라질 얼음 큐에 넣어둠. {x좌표, y좌표, 그룹 idx}
while
3. 백조 두마리가 같은 그룹에 있는지 확인
4. 얼음 녹이고, 다음에 사라질 얼음 큐에 넣어둠
5. 한덩이가 됐는지 확인해줌
    5-1. 숫자가 맞닿아있지 않으면 넘어감
    5-2. 숫자가 맞닿아있으면 하나로 합쳐줌

 */
public class Main {

    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    int[][] map;
    boolean[][] visited;
    char[][] tmpMap;
    List<int[]> swan = new ArrayList<>();
    int R, C;
    Deque<int[]> water;
    int[] group;

    void union(int x, int y) {
        x = find(x);
        y = find(y);

        if(x < y) group[y] = x;
        else group[x] = y;
    }

    int find(int x) {
        if(group[x] == x) return x;
        return group[x] = find(group[x]);
    }
    public void solve() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        tmpMap = new char[R][C];
        for(int r = 0; r < R; ++r){
            String input = br.readLine();
            for(int c = 0; c < C; ++c){
                tmpMap[r][c] = input.charAt(c);

                if(Objects.equals(tmpMap[r][c], 'L')){
                    swan.add(new int[]{r, c});
                    tmpMap[r][c] = '.';
                }
            }
        }

        int idx = 1;
        map = new int[R][C];
        water = new ArrayDeque<>();
        visited = new boolean[R][C];
        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                if(visited[r][c]) continue;
                if(tmpMap[r][c] != '.') continue;
                map[r][c] = idx;
                visited[r][c] = true;
                checkWater(r, c, idx++);
            }
        }



        group = new int[idx];
        for(int i = 0; i < idx; ++i)
            group[i] = i;

        int day = 0;
        while(true){
            /*for(int i = 0; i < idx; ++i){
                System.out.print(group[i] + " ");
                if(group[i] != i) {
                    System.out.print("*");
                    union(group[i], i);
                }
            }
            System.out.println();

            System.out.println(water.size());*/
            int swan1 = map[swan.get(0)[0]][swan.get(0)[1]];
            int swan2 = map[swan.get(1)[0]][swan.get(1)[1]];

            if(find(swan1) == find(swan2)) break;
            if(water.size() == 0) break;


            day++;
            meltWater();
        }

        System.out.println(day);

    }

    public void meltWater(){
        int length = water.size();
        for(int i = 0; i < length; ++i){ // 원래 있던 물만 처리
            int[] now = water.poll();
            int x = now[0];
            int y = now[1];
            int idx = now[2];

            map[x][y] = idx;
            for(int dir = 0; dir < 4; ++dir){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(map[nx][ny] == idx) continue;

                if(map[nx][ny] == 0 && !visited[nx][ny]) { // 얼음이었던 애들은 다음턴에 녹여줘요
                    water.offer(new int[]{nx, ny, idx});
                    visited[nx][ny] = true;
                    continue;
                }
                if(map[nx][ny] == 0) continue;
                if(map[nx][ny] != idx) { // 얘네 닿았어요! 합쳐줘요!
                    union(idx, map[nx][ny]);
                }


            }
        }

    }

    public void checkWater(int x, int y, int idx){
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{x, y});

        visited[x][y] = true;

        while(!q.isEmpty()){
            int[] now = q.poll();

            for(int i = 0; i < 4; ++i){
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(visited[nx][ny]) continue;

                if(tmpMap[nx][ny] == '.'){
                    map[nx][ny] = idx;
                    q.offer(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
                else if(tmpMap[nx][ny] == 'X'){ // 물과 닿아있는 얼음
                    water.offer(new int[]{nx, ny, idx});
                    visited[nx][ny] = true;
                }
            }
        }

    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}