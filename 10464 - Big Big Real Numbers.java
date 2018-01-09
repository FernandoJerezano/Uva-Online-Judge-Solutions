// Problema: 10464 - Big Big Real Numbers
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
		
		String s,p,r;
		String str[];
		int n;
		BigDecimal d1,d2;
		
		n = Integer.parseInt(br.readLine());
		
		while(n>0){
			n--;
			str = br.readLine().split("\\s+");
			s = str[0];
			p = str[1];
			d1 = new BigDecimal(s);
			d2 = new BigDecimal(p);
			d1 = d1.add(d2).stripTrailingZeros();
			r = d1.toPlainString();
			
			if(r.equals("0") || isDecimal(s,p) && !r.contains("."))
				r = r+".0";
			pw.println(r);
		}
		
		br.close();
		pw.close();
	
	}
	
	static boolean isDecimal(String s, String p){
		if(s.contains(".") || p.contains("."))
		   return true;
		return false;
	}
}
