// Problema: 11830 - Contract revision
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
		
		String s,p;
		String str[];
		BigInteger n;
		
		while(true){
			
			str = br.readLine().split("\\s+");
			s = str[0];
			p = str[1];
			if(s.equals("0") && p.equals("0"))
				break;
			p = p.replaceAll(s,"");
			if(p.equals(""))
				p = "0";
			n = new BigInteger(p);
			pw.println(n);
		}
		
		br.close();
		pw.close();
	
	}
}
