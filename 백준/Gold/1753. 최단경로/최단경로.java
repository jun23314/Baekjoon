import java.io.*;
import java.util.*;

public class Main {
    private static int V, E, start;
    private static List<int[]>[] routes;
    private static int[] minimumDistance;
    private static PriorityQueue<Node> pq = new PriorityQueue<>();

    void solve(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            StringTokenizer st = new StringTokenizer(br.readLine());
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            start = Integer.parseInt(br.readLine());

            routes = new ArrayList[V+1];
            for(int i = 1; i <= V; ++i){
                routes[i] = new ArrayList<>();
            }
            minimumDistance = new int[V+1];
            for(int i = 1; i <= V; ++i){
                if(i == start) minimumDistance[i] = 0;
                else minimumDistance[i] = Integer.MAX_VALUE;
            }
            pq.add(new Node(start, 0));

            for(int e = 0; e < E; ++e){
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                routes[u].add(new int[]{v, w});
            }
        }catch(Exception e){
            e.printStackTrace();
        }

        while(!pq.isEmpty()){
            Node now = pq.poll();
            int startPoint = now.v;
            int curDistance = now.w;

            for(int[] nextPoint : routes[startPoint]) {
                int newDistance = curDistance + nextPoint[1];
                if(minimumDistance[nextPoint[0]] > newDistance){ // 무조건 지금이 최단거리
                    minimumDistance[nextPoint[0]] = newDistance;
                    pq.offer(new Node(nextPoint[0], newDistance));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= V; ++i){
            if(minimumDistance[i] == Integer.MAX_VALUE)
                sb.append("INF").append("\n");
            else sb.append(minimumDistance[i]).append("\n");
        }

        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception{
        new Main().solve();
    }

    private static class Node implements Comparable<Node> {
        int v, w;
        public Node(int v, int w){
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Node o){
            if(this.w != o.w) return this.w - o.w;
            return this.v - o.v;
        }
    }
}
