// Problema: 12542 - Prime Substring
// Autor:    FernandoJerezano
// Fecha:    02-Enero-2018

import java.io.*;
import java.math.*;

class Main{

	public static void main(String[]args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		//BufferedReader br = new BufferedReader(new FileReader("./entrada.txt"));
		//PrintWriter pw = new PrintWriter("./salida.txt");
		
		String s;
		String p;
		int m,l;
		BigInteger n;
		BigInteger r;;
		BigInteger c10 = new BigInteger("100001");
		
		while(true){
			s = br.readLine();
			if(s.equals("0"))
				break;
			m = 0;
			r = new BigInteger("0");
			for(int i=0;i<6;i++){
				for(int j=0;j<s.length()-i;j++){
					p = s.substring(j,j+1+i);
					n = new BigInteger(p);
					
					if(n.compareTo(c10)==-1 && n.isProbablePrime(10)){
						if(n.compareTo(r)==1){
							r = n;
						}
					}
				}
			}
			pw.println(r);
		}		
		br.close();
		pw.close();
		
	}
	
	public static int maximo(int a, int b){
		return a>b?a:b;
	}
	
}
