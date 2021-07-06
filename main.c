// @autor: Felipe Ucelli
// @github: github.com/felipeucelli

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

//Identificação do sistema operacional
#ifdef __unix__
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
    #define OS_Windows

#endif

void screen_wipe(){
    //Fução responsável por limpar o console de acordo com o comando de cada sistema operacional
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    int quantidade_cartela;
 
    printf("Digite a quatidade de cartelas: ");
    scanf("%i", &quantidade_cartela);
    fflush(stdin);

    int cartela[quantidade_cartela][10];
    
    screen_wipe();

    srand(time(NULL));

    for(int i = 0; i < quantidade_cartela; i++){
        
        if(i == 0){
            printf("---------------------");
            printf("\nCartela %d: \n", i+1);
        }else{
            printf("\n\n\n---------------------\n");
            printf("Cartela %d: \n", i+1);
        }
                
        for(int j = 0; j < 10; j++){
            int random_num = rand() % 99;
            bool flag = false;
           
            for(int a = 0; a < 10; a++){
                if(cartela[i][a] == random_num || random_num > 99){
                    flag = true;
                    break;
                }else{
                    flag = false;
                }
            }
            if(flag == true){
                j--;                
            }else{
                cartela[i][j] = random_num;
                if(j < 3){
                    printf("%i\t", cartela[i][j]);

                }else if(j == 3 && flag == false){
                    printf("\n\n%i\t\t", cartela[i][j]);

                }else if(j == 4 && flag == false){
                    printf("%i\n", cartela[i][j]);

                }else if(j == 5 && flag == false){
                    printf("\n%i\t\t", cartela[i][j]);

                }else if(j == 6 && flag == false){
                    printf("%i\n\n", cartela[i][j]);
                    
                }else if(j > 6 && flag == false){
                    printf("%i\t", cartela[i][j]);
                }
            }                                   
        }
        printf("\n---------------------\n");
    }
    printf("\n");
    return 0;
}
