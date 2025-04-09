import java.io.*;
import java.util.*;

public class Main {
    int[] palindrome;

    void solve(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            StringBuilder sb = new StringBuilder();

            int N = Integer.parseInt(br.readLine());

            //수열 입력
            int[] input = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; ++i){
                input[i] = Integer.parseInt(st.nextToken());
            }

            setPalindrome(input);

            int M = Integer.parseInt(br.readLine());
            for(int i = 0; i < M; ++i){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());

                if(isPalindrome(--s, --e)) sb.append(1).append("\n");
                else sb.append(0).append("\n");
            }

            System.out.println(sb);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    boolean isPalindrome(int s, int e){
        int len = e - s + 1;

        s = (s * 2) + 1;
        e = (e * 2) + 1;
        int mid = (s + e) / 2;

        if(palindrome[mid] >= len) return true;
        else return false;
    }

    void setPalindrome(int[] input){
        List<Integer> nums = setList(input);
        int length = nums.size();

        int r = 0;
        int c = 0;
        palindrome = new int[length];
        for(int i = 0; i < length; ++i){
            if(i > r) palindrome[i] = 0;
            else palindrome[i] = Math.min(r-i, palindrome[2*c - i]);

            while(
                (i + palindrome[i] + 1 < length && i - palindrome[i] - 1 >= 0)
                && nums.get(i + palindrome[i] + 1) == nums.get(i - palindrome[i] - 1)
            ){
                palindrome[i]++;
            }

            if(i + palindrome[i] > r){
                r = i + palindrome[i];
                c = i;
            }
        }

    }

    List<Integer> setList(int[] input){
        int length = input.length;

        List<Integer> list = new ArrayList<>(length * 2);

        list.add(0);
        for(int i = 0; i < length; ++i){
            list.add(input[i]);
            list.add(0);
        }

        return list;
    }


    public static void main(String[] args) throws Exception{
        new Main().solve();
    }
}
