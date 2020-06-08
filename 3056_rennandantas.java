// https://www.urionlinejudge.com.br/judge/en/problems/view/3056

// Esta solução foi implementada para testar o uso da classe Big Integer.

// Foi baseada nesta solução em C++, que encontra-se altamente documentada:

// https://github.com/GEMP-UFC-Crateus/uri/blob/master/3056_rennandantas.c

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		BigInteger a, result, base;
		int n;
		
		base = BigInteger.valueOf(2);
		
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		
		a = base.pow(n);
		
		a = a.add(BigInteger.valueOf(1));
		
		result = a.pow(2);
		
		System.out.println(result);		
	}
}
