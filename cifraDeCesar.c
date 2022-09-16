/*
Aluna: Lila Maria Salvador Frazão
Matrícula: 510809
Matéria: Laboratório de Programação, Turma 1
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // Variáveis
    int escolhaCrptDrpt;
    char escolhaLoop;
    int erro = 0;

    unsigned int chave;
    char frase[150+1];

    while(1)
    {
        printf("Desejas criptografar(1) ou descriptografar(2)?\n");   
        fflush(stdin); // Limpar scanf
        scanf("%d", &escolhaCrptDrpt);

        erro = escolhaCrptDrpt > 2 || escolhaCrptDrpt <= 0 ? 1 : 0; //Pulará todo o código por causa do erro

        if (erro == 0)
        {
            printf("Digite a frase que desejas usar (Até 150 caracteres): ");   
            fflush(stdin); // Limpar scanf
            scanf("%[^\n]s", &frase);

            printf("Agora, digite a chave que desejas usar (Não pode ser negativa): ");   
            fflush(stdin); // Limpar scanf
            scanf("%d", &chave);
        }
        
        switch (escolhaCrptDrpt)
        {
        
        #pragma region Case 1

        case 1:
            // Vai passando por todos os caracteres da frase digitada
            for (int i = 0; frase[i] != '\0'; i++)
            {
                // Ignorar os espaços em branco
                if (frase[i] == ' '){
                    continue;
                }
                // Ignorar símbolos especiais e números
                else if(frase[i] < 'A' || (frase[i] > 'Z' && frase[i] < 'a') || frase[i] > 'z'){
                    continue;
                }

                // Caso seja uma chave 0, este loop não ocorre
                // Segue passando para o próximo caractere até chegar na chave (onde irá parar)
                for (int j = 0; j < chave; j++)
                {
                    // Minúsculas
                    if (frase[i] >= 'z') {
                        frase[i] = 'a';
                    }
                    // Maiúsculas
                    else if(frase[i] >= 'Z' && frase[i] < 'a'){
                        frase[i] = 'A';
                    }
                    // Muda o caractere para o seguinte
                    else {
                        frase[i] = frase[i] + 1;
                    }
                }
            }
            break;

        #pragma endregion

        #pragma region Case 2
        
        case 2:
            // Vai passando por todos os caracteres da frase digitada
            for (int i = 0; frase[i] != '\0'; i++)
            {
                // Ignorar os espaços em branco
                if (frase[i] == ' '){
                    continue;
                }
                // Ignorar símbolos especiais e números
                else if(frase[i] < 'A' || (frase[i] > 'Z' && frase[i] < 'a') || frase[i] > 'z'){
                    continue;
                }

                // Caso seja uma chave 0, este loop não ocorre
                // Segue passando para o próximo caractere até chegar na chave (onde irá parar)
                for (int j = 0; j < chave; j++)
                {
                    // Minúsculas
                    if (frase[i] <= 'a' && frase[i] > 'Z') {
                        frase[i] = 'z';
                    }
                    // Maiúsculas
                    else if(frase[i] <= 'A' && frase[i] < 'Z'){
                        frase[i] = 'Z';
                    }
                    // Muda o caractere para o seguinte
                    else {
                        frase[i] = frase[i] - 1;
                    }
                }
            }
            break;
            
        #pragma endregion

        default:
            printf("Número não encontrado, repita a execução, por favor.\n");
            break;
        }

        // Apenas para mostrar mensagens diferentes
        if (erro == 0)
        {
            printf("%s\n", frase);
            printf("\nDesejas continuar?(S/N)\n");
        }
        else
        {
            printf("\nDesejas tentar novamente?(S/N)\n");
        }
        
        fflush(stdin);
        scanf("%c", &escolhaLoop);

        if (escolhaLoop == 'n' || escolhaLoop == 'N')
        {
            break; // Sairá do loop
        }
    }

    return 0;
}