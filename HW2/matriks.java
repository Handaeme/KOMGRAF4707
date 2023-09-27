public class matriks{
    public static void main(String[] args) throws Exception {
        int[][] matriks_a = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        int[][] matriks_b = {
            {10,11,12},
            {13,14,15},
            {16,17,18}
        };  
        printArray(matriks_a);
        printArray(matriks_b);

        int[][] hasilTambah = tambah(matriks_a, matriks_b);
        int[][] hasilkurang = kurang(matriks_a, matriks_b);
        System.out.println("Penambahan Matriks");
        printArray(hasilTambah);
        System.out.println("Pengurangan Matriks");
        printArray(hasilkurang);

        int[][] matriks_c = {
            {1,2},
            {3,4},
        };
        int[][] matriks_d = {
            {11,12},
            {13,14},
        }; 
        int[][] hasilKali = kali(matriks_c, matriks_d);
        printArray(hasilKali);
    }

    private static int[][] tambah(int[][] dataArray_a, int[][] dataArray_b){
        int baris_a = dataArray_a.length;
        int kolom_a = dataArray_a.length;

        int baris_b = dataArray_b.length;
        int kolom_b = dataArray_b.length;

        int[][] hasil = new int[baris_a][kolom_b];

        if(baris_a == baris_b && kolom_a == kolom_b){
            for(int i = 0; i < baris_a; i++){
            for(int j = 0; j < kolom_b; j++){
                hasil[i][j] = dataArray_a[i][j] + dataArray_b[i][j];
                }
            }
        }
        
        return hasil;
    }

    private static int[][] kurang(int[][] dataArray_a, int[][] dataArray_b){

        int baris_a = dataArray_a.length;
        int kolom_a = dataArray_a.length;

        int baris_b = dataArray_b.length;
        int kolom_b = dataArray_b.length;

        int[][] hasil = new int[baris_a][kolom_b];

        if(baris_a == baris_b && kolom_a == kolom_b){
            for(int i = 0; i < baris_a; i++){
            for(int j = 0; j < kolom_b; j++){
                hasil[i][j] = dataArray_b[i][j] - dataArray_a[i][j];
                }
            }
        }
        return hasil;
    }

    private static int[][] kali(int[][] dataArray_1, int[][] dataArray_2){
        int baris_1 = dataArray_1.length;
        int kolom_1 = dataArray_1[0].length;

        int baris_2 = dataArray_2.length;
        int kolom_2 = dataArray_2[0].length;

        int[][] hasil = new int[baris_1][baris_2];


        int buffer;
        for(int i = 0; i < baris_1; i++){
            for(int j = 0; j < kolom_2; j++){
                buffer = 0;
                for(int k = 0; k < kolom_1; k++){
                    buffer += dataArray_1[i][k] * dataArray_2[k][j];
                }
                hasil[i][j] = buffer; 
            }
        }
        return hasil;
    }

    public static void printArray(int[][] dataArray){
        int baris = dataArray.length;
        int kolom = dataArray.length;

        for(int i = 0; i < baris; i++){
            System.out.print("{");
            for(int j = 0; j < kolom; j++){
                System.out.print(dataArray[i][j]);
                
                if(j < kolom-1 ){
                    System.out.print(",");
                }
                else{
                    System.out.print("}");
                }
                
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }
}