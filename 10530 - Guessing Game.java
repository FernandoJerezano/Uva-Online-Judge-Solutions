// Problema: 10530 - Guessing Game
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
import java.io.*;

class Main{

	public static void main(String[]args)throws IOException{
		int n;
		String s;
		BufferedReader br = new BufferedReader(
		new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(
		new OutputStreamWriter(System.out));
		//PrintWriter pw2 = new PrintWriter("out.txt");
		int low,high;
		
		while(true){
			low = 0;
			high = 11;
			n = Integer.parseInt(br.readLine());
			if(n==0)
				break;
			s = br.readLine();
			while(true){
				if(s.charAt(0)=='r')
					break;
				if(s.charAt(4)=='h'){
					//high = n;
					high = minimo(n,high);
				}else{
					//low = n;
					low = maximo(low,n);
				}
				n = Integer.parseInt(br.readLine());
				s = br.readLine();
			}
			if(n<high && n>low){
				pw.println("Stan may be honest");
				//pw2.println("Stan may be honest");
			}else{
				pw.println("Stan is dishonest");
				//pw2.println("Stan is dishonest");
			}
			
		}
		pw.close();
		//pw2.close();
		br.close();
	}
	
	public static int maximo(int a, int b){
		return a>b?a:b;
	}
	
	public static int minimo(int a, int b){
		return a<b?a:b;
	}
}










