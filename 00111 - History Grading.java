// Problema: 111 - History Grading
// Autor:    FernandoJerezano
// Fecha:    31-Agosto-2017
import java.io.*;

class Main{
	
	public static void main(String[]args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		int n;
		String s;
		int rank[];
		int arr[];
		String str[];
		
		s = br.readLine();
		n = Integer.parseInt(s);
		
		while(true){
			rank = new int[n];
			str = br.readLine().split("\\s+");
			for(int i=0;i<n;i++){
				rank[i] = Integer.parseInt(str[i]);
			}
			rank = rank(rank);
			arr = new int[n];
			while((s=br.readLine())!=null){
				str = s.split("\\s+");
				if(str.length==1)
					break;
				for(int i=0;i<n;i++){
					arr[i] = Integer.parseInt(str[i]);
				}
				arr = rank(arr);
				pw.println(lcs(rank,arr));
			}
			if(s == null)
				break;
			n = Integer.parseInt(s);
		}
		
		
		
		
		br.close();
		pw.close();
	}
	
	public static int[] rank(int arr[]){
		int rank[] = new int[arr.length];
		
		for(int i=0;i<rank.length;i++){
			rank[arr[i]-1] = i+1;
		}
		return rank;
	}
	
	public static int lcs(int a[], int b[]){
		int n = a.length;
		
		int lcs[][] = new int[n+1][n+1];
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(i==0 || j==0)
					lcs[i][j] = 0;
				else{
					if(a[i-1]==b[j-1])
						lcs[i][j] = lcs[i-1][j-1]+1;
					else
						lcs[i][j] = maximo(lcs[i-1][j],lcs[i][j-1]);
				}
			}
		}
		return lcs[n][n];
	}
	
	public static int maximo(int a, int b){
		return a>b? a : b;	
	}
	
}
