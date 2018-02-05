// Problema: 10424 - Love Calculator
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
import java.io.*;

class Main{
	
	public static int valores[] = new int[255];
	
	public static void main(String[]args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		//PrintWriter pw2 = new PrintWriter("salida.txt");
		
		init();
		
		String name1,name2;
		int a,b;
		double r;
		while((name1= br.readLine())!=null){
			name2 = br.readLine();
			//System.out.println(getValue(name1));
			//System.out.println(getValue(name2));
			a = getValue(name1);
			b = getValue(name2);
			r = getRatio(max(a,b),min(a,b));
			pw.printf("%.2f %%\n",r);
			//pw2.printf("%.2f %%\n",r);
		}
		
		
		br.close();
		pw.close();
		//pw2.close();
	}
	
	
	public static void init(){
		for(int i='a';i<='z';i++){
			valores[i] = i-'a'+1;
			//System.out.println(valores[i]);
		}
		
		for(int i='A';i<='Z';i++){
			valores[i] = i-'A'+1;
			//System.out.println(valores[i]);
		}
		
	}
	
	public static double getRatio(int may, int men){
		double a = may;
		double b = men;
		
		return b*100.00/a;
	}
	
	public static int getValue(String s){
		int sum = 0;
		char c;
		for(int i=0;i<s.length();i++){
			c = s.charAt(i);
			sum+=valores[c];
		}
		int val;
		
		while(sum/10!=0){
			val = 0;
			while(sum!=0){
				val+=sum%10;
				sum/=10;
			}
			sum = val;
		}
		return sum;
	}
	
	public static int max(int a, int b){
		return a>b?a:b;
	}
	
	public static int min(int a, int b){
		return a<b?a:b;
	}
	
}
