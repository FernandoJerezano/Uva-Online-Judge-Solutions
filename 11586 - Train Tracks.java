// Problema: 11586 - Train Tracks
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018

import java.io.*;

class Main{

	public static void main(String[]args)throws IOException{
	
		int n;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		String s;
		String str[];
		
		int m0,f0,m1,f1;
		
		n = Integer.parseInt(br.readLine());
		
		while(true){
			n--;
			
			if(n<0)
				break;
			
			s = br.readLine();
			s = s.trim();
			str = s.split("\\s+");
			
			m0 = f0 = m1 = f1 = 0;
			
			for(int i=0;i<str.length;i++){
				if(str[i].charAt(0)=='M')
					m0++;
				if(str[i].charAt(0)=='F')
					f0++;
				if(str[i].charAt(1)=='M')
					m1++;
				if(str[i].charAt(1)=='F')
					f1++;
			}
			
			if(str.length != 1 && m0==f1 && f0==m1)
				pw.println("LOOP");
			else
				pw.println("NO LOOP");
		}
		pw.close();
	}
}
