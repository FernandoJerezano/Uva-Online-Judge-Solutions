// Problema: 10141 - Request for Proposal
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018
import java.io.*;

class Main{
	
	public static void main(String[]rgs)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		int n,p;
		String s,f,name;
		double mc,d,lp;
		int r;
		String str[];
		
		int t = 1;
		
		s = br.readLine().trim();
		
		str = s.split("\\s+");
		
		n = Integer.parseInt(str[0]);
		p = Integer.parseInt(str[1]);
			
			
		while(true){
			
			for(int i=0;i<n;i++){
				s = br.readLine();
			}
			lp = mc = -1;
			f = "";
			for(int i=0;i<p;i++){
				name = br.readLine();
				s = br.readLine();
				str = s.split("\\s+");
				d = Double.parseDouble(str[0]);
				r = Integer.parseInt(str[1]);
				
				for(int j=0;j<r;j++){
					s = br.readLine();
				}
				
				if((double)r/n > mc){
					f = name;
					mc = (double)r/n;
					lp = d;
				}else{
					if((double)r/n == mc){
						if(d<lp){
							lp = d;
							f = name;
						}
					}
				}
			}
			pw.println("RFP #"+t);
			pw.println(f);
			
			s = br.readLine().trim();
			str = s.split("\\s+");
		
			n = Integer.parseInt(str[0]);
			p = Integer.parseInt(str[1]);
			
			if(n==0 && p==0)
				break;
			else
				pw.println();
			
			t++;
		}
		br.close();
		pw.close();
	}
	
}
