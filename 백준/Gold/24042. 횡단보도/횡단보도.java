import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static int N, M;
    private static long[] minimumTime;
    private static List<Route>[] crossRoad;
    private static PriorityQueue<Node> pq = new PriorityQueue<>();

    void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            minimumTime = new long[N + 1];
            crossRoad = new ArrayList[N + 1];

            minimumTime[1] = 0;
            for (int i = 2; i <= N; ++i) {
                minimumTime[i] = Long.MAX_VALUE;
            }

            for (int i = 1; i <= N; ++i) {
                crossRoad[i] = new ArrayList<>();
            }

            for (int i = 0; i < M; ++i) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                crossRoad[a].add(new Route(b, i));
                crossRoad[b].add(new Route(a, i));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }


        if(N == 2){
            System.out.print(1);
            return ;
        }
        
        pq.offer(new Node(1, 0));
        while(!pq.isEmpty()){
            Node now = pq.poll();
            int startCity = now.start;
            int currentCycle = (int) (now.time % M);

            for(Route i : crossRoad[startCity]){
                int canGoCity = i.dest;
                int cycle = i.cycle;

                if(cycle == currentCycle){
                    if(now.time+1 >= minimumTime[canGoCity]) continue;
                    minimumTime[canGoCity] = now.time + 1;
                    pq.offer(new Node(canGoCity, now.time+1));
                }
                else if(cycle < currentCycle){
                    int haveToWait = M - (currentCycle - cycle);
                    if(haveToWait + now.time >= minimumTime[canGoCity]) continue;
                    minimumTime[canGoCity] = haveToWait + now.time;
                    pq.offer(new Node(canGoCity, haveToWait + now.time));
                }
                else if(cycle > currentCycle){
                    int haveToWait = cycle - currentCycle;
                    if(haveToWait + now.time >= minimumTime[canGoCity]) continue;
                    minimumTime[canGoCity] = haveToWait + now.time;
                    pq.offer(new Node(canGoCity, haveToWait + now.time));
                }
            }
        }

        System.out.print(minimumTime[N] + 1);

    }

    public static void main(String[] args) throws Exception {
        new Main().solve();
    }

    private static class Route {

        int dest;
        int cycle;

        public Route(int dest, int cycle) {
            this.dest = dest;
            this.cycle = cycle;
        }
    }

    private static class Node implements Comparable<Node> {

        int start;
        long time;

        public Node(int start, long time) {
            this.start = start;
            this.time = time;
        }

        @Override
        public int compareTo(Node o) {
            if (o.time == this.time) {
                return this.start - o.start;
            }
            return (int) (this.time - o.time);
        }
    }

}
