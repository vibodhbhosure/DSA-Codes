//  Swarna Shikhar Das
// 14/10/2022

// This function wil tell us from 0 to n which number is prime or which number is not

import java.util.Arrays;
public class PrimeNum {

	public static void main(String[] args) {
		boolean isPrime[] = seiveOfErathosthenes(20);
		for(int i=0; i<20; i++) {
			System.out.println(i + " " + isPrime[i]);
		}
	}

		static boolean[] seiveOfErathosthenes(int n) {
			
			boolean isPrime[] = new boolean[n+1];
			
			Arrays.fill(isPrime , true);
			
			isPrime[0] = false;
			isPrime[1] = false;
			
			for(int i=2; i*i<n; i++) {
				for(int j=2*i; j<=n; j+=i) {
					isPrime[j]=false;
				}
			}			
			return isPrime;
		}
}
