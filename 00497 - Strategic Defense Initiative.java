// Problema: 497 - Strategic Defense Initiative
// Autor:    FernandoJerezano
// Fecha:    02-Septiembre-2017
import java.io.*;

class Main{
	
	static BufferedReader br;
	static PrintWriter pw;
	static int MAX_N = 10005;
	static int arr[];
	
	public static void main(String[]args)throws IOException{
		
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//br = new BufferedReader(new FileReader("entrada.txt"));
		//pw = new PrintWriter("salida.txt");
		arr = new int[MAX_N];
		
		int t = Integer.parseInt(br.readLine());
		int n;
		br.readLine();
		String s;
		
		while(t>0){
			n = 0;
			
			while( (s = br.readLine())!=null){
				
				if(s.equals(""))
				   break;
				arr[n] = Integer.parseInt(s);
				n++;
			}
			
			LIS(n);
			
			t--;
			if(t!=0)
				pw.println();
			
		}
		
		br.close();
		pw.close();
		
		
	}
	
	public static void LIS(int n){
		
		int lis[] = new int[n];
		int ind[] = new int[n];
		
		for(int i=0;i<n;i++){
			lis[i] = 1;
			ind[i] = -1;
		}
		
		int max = 0;
		int mi = 0;
		
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(arr[i]>arr[j] && lis[i]<lis[j]+1){
					lis[i] = lis[j]+1;
					ind[i] = j;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			if(lis[i]>max){	
				max = lis[i];
				mi = i;
			}
		}
		
		pw.println("Max hits: "+max);
		print(ind,mi);
		
	}
	
	public static void print(int ind[], int i){
		if(i==-1)
			return;
		print(ind, ind[i]);
		pw.println(arr[i]);
	}
}

