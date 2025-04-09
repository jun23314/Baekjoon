import java.io.*;
import java.util.*;

public class Main {
    void solve(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            String input = br.readLine();

            List<Character> str = new ArrayList<>(input.length()*2+1);
            str.add('#');
            for(int i = 0; i < input.length(); ++i){
                str.add(input.charAt(i));
                str.add('#');
            }

            int ans = palindrome(str, str.size());
            System.out.println(ans);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    int palindrome(List<Character> str, int length){
        int[] palindrome = new int[length];

        int r = 0;
        int c = 0;
        for(int i = 0; i < length; ++i){
            if(i > r) palindrome[i] = 0;
            else palindrome[i] = Math.min(r-i, palindrome[2*c - i]);

            while(
                (i + palindrome[i] + 1 < length && i - palindrome[i] - 1 >= 0) // 범위 내
                && str.get(i+palindrome[i]+1) == str.get(i-palindrome[i]-1) // 양 끝이 같으면
            ){
                palindrome[i]++; // 팰린드롬 추가요~
            }

            if(r < i + palindrome[i]){
                r = i + palindrome[i];
                c = i;
            }
        }

        int ans = 0;
        for(int i = 0; i < length; ++i){
            ans = Math.max(ans, palindrome[i]);
        }

        return ans;
    }



    public static void main(String[] args) throws Exception{
        new Main().solve();
    }

}
