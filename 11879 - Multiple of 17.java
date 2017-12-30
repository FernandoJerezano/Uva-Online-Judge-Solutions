// Problema: 11879 - Multiple of 17
// Autor:    FernandoJerezano
// Fecha:    28-Diciembre-2017
import java.io.*;
import java.math.*;

class Main{

	public static void main(String[]args)throws IOException{		
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br = new BufferedReader(new FileReader("./entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");		
		
		BigInteger n,d;
		String s;
		
		while(true){
			s = br.readLine();
			n = new BigInteger(s);
			
			if(n.compareTo(BigInteger.ZERO)==0)
				break;
			
			d = n.mod(BigInteger.TEN).multiply(new BigInteger("5"));
			n = n.divide(BigInteger.TEN);
			n = n.subtract(d);
			if(n.compareTo(BigInteger.ZERO)==-1){
				n = n.multiply(new BigInteger("-1"));
			}
			n = n.mod(new BigInteger("17"));
			if(n.compareTo(BigInteger.ZERO)==0){
				pw.println("1");
			}else{
				pw.println("0");
			}
		}
		
		
		br.close();
		pw.close();
	
	}
}
