#include<bits/stdc++.h>

int n = 0;
int matriz[4][100010];
int pos[2][100010];

void swap(int* a, int* b){ 

    int t = *a; 
    *a = *b; 
    *b = t; 

} 
  
int partition(int arr[], int pos[], int precios[], int low, int high){

    int pivot = arr[high];     
    int i = (low - 1);   
  
    for (int j = low; j <= high- 1; j++){ 

        if(arr[j] <= pivot){

            i++;    
            swap(&arr[i], &arr[j]); 
            swap(&pos[i], &pos[j]); 
            swap(&precios[i], &precios[j]); 
        }
    } 

    swap(&arr[i + 1], &arr[high]);
    swap(&pos[i + 1], &pos[high]);
    swap(&precios[i + 1], &precios[high]);
    
    return (i + 1); 
} 
  

void quickSort(int arr[], int pos[], int precios[], int low, int high){

    if (low < high){ 
        
        int pi = partition(arr, pos, precios, low, high); 
  
        quickSort(arr, pos, precios, low, pi - 1); 

        quickSort(arr, pos, precios, pi + 1, high); 
    } 
} 

void decswap(int* a, int* b){ 

    int t = *a; 
    *a = *b; 
    *b = t; 

} 
  
int decpartition(int arr[], int pos[], int precios[], int low, int high){

    int pivot = arr[high];     
    int i = (low - 1);   
  
    for (int j = low; j <= high- 1; j++){ 

        if(arr[j] >= pivot){
    
            i++;    
            decswap(&arr[i], &arr[j]); 
            decswap(&pos[i], &pos[j]); 
            decswap(&precios[i], &precios[j]); 
        }
    } 

    decswap(&arr[i + 1], &arr[high]);
    decswap(&pos[i + 1], &pos[high]);
    decswap(&precios[i + 1], &precios[high]);
    
    return (i + 1); 
} 
  

void decquickSort(int arr[], int pos[], int precios[], int low, int high){

    if (low < high){ 
        
        int pi = decpartition(arr, pos, precios, low, high); 
  
        decquickSort(arr, pos, precios, low, pi - 1); 

        decquickSort(arr, pos, precios, pi + 1, high); 
    } 

} 

void imprimir_Matriz(int n, int matriz[][100010]){ 
   
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }
    
    printf("\n");
} 

void revisar_Igual(int n, int pos[][100010], int ar[]){

    int n2 = (n - 1);
    int cont = 0;
    int valeq = 0;
    int iguales[n] = {};

    for(int i = 0; i < n2; i++){

        if(ar[i] == ar[i + 1] && ar[i] != valeq){

            valeq = ar[i];
            cont++;
            iguales[i] = cont;
            iguales[i + 1] = cont;
        }
        else if(ar[i] == ar[i + 1] && ar[i] == valeq){

            iguales[i] = cont;
            iguales[i + 1] = cont;

        }
    }

    for(int i = 0; i < n; i++){

        printf("%d ", iguales[i]);
    }

    printf("\n");

}

void validar_Res(int n, int matriz[][100010]){

    int estaBien = 0;
    int estamuyBien = 0;
    int estasuperBien = 0;
    int cnt2 = n - 1;
    
    for(int i = 0; i < 3; i+=2){
        for(int j = 0; j < cnt2; j++){
            
             //printf("j: %d jplus: %d ", matriz[i][j], matriz[i][j+1]);
            
            if(matriz[i][j] > matriz[i][j+1]){
                
               
                estaBien = 1;
                break;
            }
            
        }
        if(estaBien == 1) break;
    }

    for(int i = 0; i < n; i++){

        if(matriz[1][i] <= matriz[3][i]){

            estamuyBien = 1;
            break;
        }
    }
    
    for(int i = 1; i < 4; i+=2){
        for(int j = 0; j < cnt2; j++){
            
             //printf("j: %d jplus: %d ", matriz[i][j], matriz[i][j+1]);
            
            if(matriz[i][j] < matriz[i][j+1]){
                
               
                estasuperBien = 1;
                break;
            }
            
        }
        if(estasuperBien == 1) break;
    }

    
    if(estaBien == 1 || estamuyBien == 1 || estasuperBien == 1){

        printf("impossible");

    }
    
    else
        imprimir_Matriz(n, pos);
  
}

int main(){ 

    scanf("%d", &n);
    
    //matriz[4][n] = {};
    
    //pos[2][n] = {};
    
    for(int i = 0; i < 4; i++){
        
        for(int j = 0; j < n; j++){
            
            scanf("%d",  &matriz[i][j]);
            
        }
    }

    for(int i = 0; i < 2; i++){
       for(int j = 0; j < n; j++){ 
        
             pos[i][j] = (j + 1);
         
       }
    }
 
    quickSort(matriz[0], pos[0], matriz[1], 0, n-1);
    
    quickSort(matriz[2], pos[1], matriz[3], 0, n-1);
    
    int cnt2 = n - 1;
    int estasuperBien = 0;
    
    for(int i = 1; i < 4; i+=2){
        for(int j = 0; j < cnt2; j++){
            
             //printf("j: %d jplus: %d ", matriz[i][j], matriz[i][j+1]);
            
            if(matriz[i][j] > matriz[i][j+1]){
                
               
                estasuperBien = 1;
                break;
            }
            
        }
        if(estasuperBien == 1) break;
    }
    
    if(estasuperBien == 1){
        
        decquickSort(matriz[1], pos[0], matriz[0], 0, n-1);
    
        decquickSort(matriz[3], pos[1], matriz[2], 0, n-1);
        
    }
    
    validar_Res(n, matriz);
    
    //validar_Res(n, matriz, 0, 0);
    
    //imprimir_Matriz(n, matriz);

    return 0; 
} 