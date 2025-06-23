#include <stdio.h>  // Para funções de entrada e saída padrão (printf, scanf)
#include <string.h> // Para funções de manipulação de strings (strcmp)

// --- Definição da Estrutura da Carta ---
// Esta estrutura define o "molde" para cada carta do Super Trunfo,
// contendo todos os atributos necessários.
struct CartaSuperTrunfo {
    char estado;              // Uma letra de 'A' a 'H' (representando um estado)
    char codigoCarta[5];      // Código da carta (ex: "A01", "B03"). Tamanho 5 para 4 caracteres + terminador nulo '\0'.
    char nomeCidade[50];      // Nome da cidade (tamanho suficiente para nomes longos).
    unsigned long int populacao; // Número de habitantes. 'unsigned long int' para acomodar valores grandes e positivos.
    float areaKm2;            // Área da cidade em quilômetros quadrados.
    float pib;                // Produto Interno Bruto da cidade (em bilhões).
    int pontosTuristicos;     // Quantidade de pontos turísticos.
    float densidadePopulacional; // Densidade populacional calculada (habitantes/km²).
    float pibPerCapita;       // PIB per capita calculado (PIB por pessoa).
};

// --- Função Principal do Programa ---
int main() {
    // Declaração de duas variáveis do tipo 'struct CartaSuperTrunfo' para armazenar os dados das cartas.
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;

    // --- Coleta de Dados para a CARTA 1 ---
    printf("--- Insira os dados para a CARTA 1 ---\n");

    printf("Estado (A-H): ");
    // O espaço antes de %c é crucial para consumir qualquer caractere de 'whitespace' (como o Enter)
    // que possa ter sido deixado no buffer de entrada por um 'scanf' anterior.
    scanf(" %c", &carta1.estado);

    printf("Codigo da Carta (ex: A01): ");
    // %s lê uma string até encontrar um espaço em branco ou Enter.
    // Não usamos '&' para arrays de caracteres, pois o nome do array já é um ponteiro.
    scanf("%s", carta1.codigoCarta);

    printf("Nome da Cidade: ");
    // %[^\n] lê todos os caracteres até encontrar uma nova linha ('\n').
    // O espaço antes de %[^\n] consome o Enter remanescente do scanf anterior.
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao (Ex: 12300000): ");
    // %lu é o especificador de formato para 'unsigned long int'.
    scanf("%lu", &carta1.populacao);

    printf("Area (em km^2, Ex: 1521.11): ");
    // %f é o especificador de formato para 'float'.
    scanf("%f", &carta1.areaKm2);

    printf("PIB (em bilhoes de reais, Ex: 699.28): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos (Ex: 50): ");
    // %d é o especificador de formato para 'int'.
    scanf("%d", &carta1.pontosTuristicos);

    // --- Cálculos para CARTA 1 ---
    // Cálculo da Densidade Populacional: População / Área
    // Garante que a área seja maior que zero para evitar divisão por zero.
    if (carta1.areaKm2 > 0) {
        carta1.densidadePopulacional = (float)carta1.populacao / carta1.areaKm2;
    } else {
        carta1.densidadePopulacional = 0.0; // Define como 0 se a área for inválida ou zero.
    }

    // Cálculo do PIB per Capita: (PIB em bilhões * 1.000.000.000) / População
    // Garante que a população seja maior que zero para evitar divisão por zero.
    if (carta1.populacao > 0) {
        // Converte o PIB de bilhões para o valor total em reais antes de dividir.
        // O cast (float) na população garante que a divisão seja de ponto flutuante.
        carta1.pibPerCapita = (carta1.pib * 1000000000.0F) / (float)carta1.populacao;
    } else {
        carta1.pibPerCapita = 0.0; // Define como 0 se a população for inválida ou zero.
    }

    // --- Coleta de Dados para a CARTA 2 ---
    printf("\n--- Insira os dados para a CARTA 2 ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigoCarta);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Populacao (Ex: 6748000): ");
    scanf("%lu", &carta2.populacao);
    printf("Area (em km^2, Ex: 1200.25): ");
    scanf("%f", &carta2.areaKm2);
    printf("PIB (em bilhoes de reais, Ex: 300.50): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos (Ex: 30): ");
    scanf("%d", &carta2.pontosTuristicos);

    // --- Cálculos para CARTA 2 ---
    // Mesmos cálculos de Densidade Populacional e PIB per Capita para a segunda carta.
    if (carta2.areaKm2 > 0) {
        carta2.densidadePopulacional = (float)carta2.populacao / carta2.areaKm2;
    } else {
        carta2.densidadePopulacional = 0.0;
    }

    if (carta2.populacao > 0) {
        carta2.pibPerCapita = (carta2.pib * 1000000000.0F) / (float)carta2.populacao;
    } else {
        carta2.pibPerCapita = 0.0;
    }

    // --- ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO ---
    // Este é o ponto onde você define qual atributo será comparado.
    // Altere o valor desta string para comparar outro atributo.
    // Opções válidas: "Populacao", "Area", "PIB", "Densidade Populacional", "PIB per Capita"
    const char *atributoComparacao = "Populacao"; // Exemplo: Comparando por População.

    // --- Exibição Detalhada das Cartas (Opcional - Para verificação) ---
    printf("\n--- Dados Detalhados das Cartas ---\n");

    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigoCarta);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km%c\n", carta1.areaKm2, 253); // 253 é o código ASCII estendido para o sobrescrito 2 (²)
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km%c\n", carta1.densidadePopulacional, 253);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigoCarta);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km%c\n", carta2.areaKm2, 253);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km%c\n", carta2.densidadePopulacional, 253);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    // --- Lógica de Comparação das Cartas ---
    printf("\n--- Comparacao de Cartas (Atributo: %s) ---\n", atributoComparacao);

    // Usa 'strcmp' para comparar a string do atributo escolhido com as strings pré-definidas.
    // 'strcmp' retorna 0 se as strings forem iguais.
    if (strcmp(atributoComparacao, "Populacao") == 0) {
        printf("Carta 1 - %s (%c): %lu\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%c): %lu\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: E um empate!\n");
        }
    } else if (strcmp(atributoComparacao, "Area") == 0) {
        printf("Carta 1 - %s (%c): %.2f km%c\n", carta1.nomeCidade, carta1.estado, carta1.areaKm2, 253);
        printf("Carta 2 - %s (%c): %.2f km%c\n", carta2.nomeCidade, carta2.estado, carta2.areaKm2, 253);
        if (carta1.areaKm2 > carta2.areaKm2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.areaKm2 > carta1.areaKm2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: E um empate!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB") == 0) {
        printf("Carta 1 - %s (%c): %.2f bilhoes de reais\n", carta1.nomeCidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%c): %.2f bilhoes de reais\n", carta2.nomeCidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: E um empate!\n");
        }
    } else if (strcmp(atributoComparacao, "Densidade Populacional") == 0) {
        printf("Carta 1 - %s (%c): %.2f hab/km%c\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional, 253);
        printf("Carta 2 - %s (%c): %.2f hab/km%c\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional, 253);
        // Para Densidade Populacional, a carta com o MENOR valor vence.
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: E um empate!\n");
        }
    } else if (strcmp(atributoComparacao, "PIB per Capita") == 0) {
        printf("Carta 1 - %s (%c): %.2f reais\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
        printf("Carta 2 - %s (%c): %.2f reais\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: E um empate!\n");
        }
    } else {
        // Mensagem de erro caso o atributo escolhido para comparação não seja válido.
        printf("Erro: Atributo escolhido para comparacao invalido. Verifique 'atributoComparacao'.\n");
    }

    return 0; // Indica que o programa terminou com sucesso.
}
