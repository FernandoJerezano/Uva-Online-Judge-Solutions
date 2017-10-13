// Problema: 10664 - Luggage
// Autor:    FernandoJerezano
// Fecha:    28-Septiembre-2017
import java.io.*;

class Main{
	
	static int MAX_N = 25;
	static int MAX_K = 205;
	
	static int arr[] = new int[MAX_N];
	static int table[][] = new int[MAX_N][MAX_K];

	public static void main(String[]args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		int t = Integer.parseInt(br.readLine());
		String s,str[];
		int n,sum,r1,r2;
		
		
		for(int i=0;i<t;i++){
			s = br.readLine();
			str = s.split("\\s+");
			sum = 0;
			n = str.length;
			
			for(int j=1;j<=n;j++){
				arr[j] = Integer.parseInt(str[j-1]);
				sum += arr[j];
			}
			
			
			r1 = subset_sum_bu(n,sum/2);
			r2 = sum-r1;
			if(r1==r2)
				pw.println("YES");
			else
				pw.println("NO");
		}
		
		br.close();
		pw.close();
	}
	
	public static int maximo(int a, int b){
		return a>b?a:b;	
	}

	public static int subset_sum_bu(int n, int rw){
		int i,w;

		for(i=0;i<=rw;i++){
			table[0][i] = 0;
		}

		for(i=1;i<=n;i++){
			for(w=0;w<=rw;w++){
				if(arr[i]<=w){
					table[i][w] = maximo(table[i-1][w],table[i-1][w-arr[i]]+arr[i]);
				}else{
					table[i][w] = table[i-1][w];
				}
			}
		}
		return table[n][rw];
	}
}
