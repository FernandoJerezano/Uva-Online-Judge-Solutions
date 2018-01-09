// Problema: 10473 - Simple Base Conversion
// Autor:    FernandoJerezano
// Fecha:    30-Diciembre-2017

import java.io.*;
import java.math.*;

class Main{
	
	public static void main(String[]args)throws IOException{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		//BufferedReader br = new BufferedReader(new FileReader("./entrada.txt"));
		//PrintWriter pw = new PrintWriter("./salida.txt");
		
		BigInteger bi;
		String s;
		
		while(true){
			s = br.readLine();
			if(s.charAt(0)=='-')
				break;
			if(s.contains("x")){
				s = s.replace("0x","");
				s = new BigInteger(s,16).toString(10);
			}else{
				s = new BigInteger(s).toString(16);
				s = "0x"+s;
			}
			for(int i=0;i<s.length();i++){
				if(s.charAt(i)>='a' && s.charAt(i)<='f'){
					pw.print((char)(s.charAt(i)-32));
				}else{
					pw.print(s.charAt(i));
				}
			}
			
			pw.println();
		}
		
		br.close();
		pw.close();
		
	}
}
