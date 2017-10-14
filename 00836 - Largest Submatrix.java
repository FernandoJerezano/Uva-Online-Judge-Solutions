// Problema: 836 - Largest Submatrix
// Nombre:   FernandoJerezano
// Fecha:    14-Octubre-2017
import java.io.*;

class Main{
	
	public static void main(String[]args)throws IOException{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		int t = Integer.parseInt(br.readLine());
		br.readLine();
		String s;
		
		int mat[][] = new int[100][100];
		int r;
		int c;
		
		for(int i=0;i<t;i++){
			r = 0;
			c = 0;
			
			while(true){
				s = br.readLine();
				if(s==null)
					break;
				if(s.equals(""))
				   break;
				c = s.length();
				for(int j=0;j<c;j++){
					mat[r][j] = s.charAt(j)-'0';
				}
				r++;
			}			
			//print_mat(mat,r,c);
			pw.println(max_2d_rect(mat,r,c));
			if(s!=null)
				pw.println();
		}
		
		br.close();
		pw.close();
	}
	
	public static void print_mat(int mat[][], int r, int c){
		
		System.out.println();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				System.out.printf("%d",mat[i][j]);
			}
			System.out.println();
		}
	}
	
	public static int max_2d_rect(int mat[][], int r, int c){
		int i,j,k;
		int max = -1;
		int cont;
		for(i=1;i<r;i++){
			for(j=0;j<c;j++){
				if(mat[i][j]==1){
					mat[i][j] = mat[i-1][j]+1;
				}
			}
		}
		
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cont = mat[i][j];
				for(k=j+1;k<c && mat[i][j]<=mat[i][k];k++){
					cont+=mat[i][j];
				}
				for(k=j-1;k>=0 && mat[i][j]<=mat[i][k];k--){
					cont+=mat[i][j];
				}
				if(cont>max)
					max = cont;
			}
		}
		
		return max;
	}
	
	public static int minimo(int a, int b){
		return a<b ? a : b;
	}
}
