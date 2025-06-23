#include <stdio.h>  // Para funções de entrada e saída padrão (printf, scanf)
#include <string.h> // Para funções de manipulação de strings (strcpy, strcmp)

// --- Definição da Estrutura da Carta ---
// A 'struct' organiza todos os atributos de uma carta de Super Trunfo.
struct CartaSuperTrunfo {
    char estado;              // Uma letra de 'A' a 'H' para o estado.
    char codigoCarta[5];      // Código da carta (ex: "A01"). Tamanho 5 para 4 caracteres + '\0'.
    char nomeCidade[50];      // Nome da cidade (com espaço para nomes mais longos).
    unsigned long int populacao; // População: 'unsigned long int' para números muito grandes e positivos.
    float areaKm2;            // Área em quilômetros quadrados.
    float pib;                // Produto Interno Bruto (em bilhões de reais).
    int pontosTuristicos;     // Quantidade de pontos turísticos.
    float densidadePopulacional; // Densidade populacional calculada (hab/km²).
    float pibPerCapita;       // PIB per capita calculado (reais/pessoa).
    float superPoder;         // O "Super Poder" da carta, calculado a partir de outros atributos.
};

// --- Função Principal do Programa ---
int main() {
    // Declaração de duas variáveis do tipo 'struct CartaSuperTrunfo' para as cartas do jogo.
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;

    printf("--- Insira os dados da CARTA 1 ---\n");

    // --- Coleta de Dados para a CARTA 1 ---
    // Solicita e lê as informações de cada atributo para a primeira carta.
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado); // Espaço antes de %c para consumir o caractere de nova linha pendente.
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigoCarta);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade); // Lê a linha completa, incluindo espaços, até o Enter.
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &carta1.populacao); // %lu é o especificador para 'unsigned long int'.
    printf("Area (em km^2): ");
    scanf("%f", &carta1.areaKm2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // --- Cálculos Essenciais para CARTA 1 ---
    // Calcula a Densidade Populacional, garantindo que não haja divisão por zero.
    if (carta1.areaKm2 > 0) {
        carta1.densidadePopulacional = (float)carta1.populacao / carta1.areaKm2;
    } else {
        carta1.densidadePopulacional = 0.0; // Define como 0 se a área for inválida.
    }
    // Calcula o PIB per Capita, convertendo o PIB para o valor total em reais e tratando divisão por zero.
    if (carta1.populacao > 0) {
        carta1.pibPerCapita = (carta1.pib * 1000000000.0F) / (float)carta1.populacao;
    } else {
        carta1.pibPerCapita = 0.0; // Define como 0 se a população for inválida.
    }

    printf("\n--- Insira os dados da CARTA 2 ---\n");

    // --- Coleta de Dados para a CARTA 2 ---
    // Repete o processo de coleta de dados para a segunda carta.
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigoCarta);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &carta2.populacao);
    printf("Area (em km^2): ");
    scanf("%f", &carta2.areaKm2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // --- Cálculos Essenciais para CARTA 2 ---
    // Repete os cálculos para a segunda carta.
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

    // --- Cálculo do "Super Poder" para cada Carta ---
    // O "Super Poder" é a soma de vários atributos numéricos.
    // Para a densidade populacional, usamos o inverso (1/densidade) para que um valor MENOR na densidade
    // (que é uma vantagem no jogo) se traduza em um valor MAIOR no "Super Poder".
    // É crucial fazer o 'cast' para 'float' nos atributos inteiros antes de somar.
    // Tratamos o caso de densidade zero para evitar divisão por zero, atribuindo um valor alto para o inverso.
    float inversoDensidade1 = (carta1.densidadePopulacional > 0.0001F) ? (1.0F / carta1.densidadePopulacional) : 1000000.0F;
    float inversoDensidade2 = (carta2.densidadePopulacional > 0.0001F) ? (1.0F / carta2.densidadePopulacional) : 1000000.0F;

    carta1.superPoder = (float)carta1.populacao + carta1.areaKm2 + carta1.pib +
                        (float)carta1.pontosTuristicos + carta1.pibPerCapita + inversoDensidade1;

    carta2.superPoder = (float)carta2.populacao + carta2.areaKm2 + carta2.pib +
                        (float)carta2.pontosTuristicos + carta2.pibPerCapita + inversoDensidade2;


    // --- Exibição Detalhada dos Dados das Cartas (Para verificação) ---
    printf("\n--- Dados Detalhados das Cartas ---\n");

    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigoCarta);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %lu\n", carta1.populacao); // %lu para unsigned long int
    printf("Area: %.2f km%c\n", carta1.areaKm2, 2); // Tentativa de exibir km²
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km%c\n", carta1.densidadePopulacional, 2);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigoCarta);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km%c\n", carta2.areaKm2, 2);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km%c\n", carta2.densidadePopulacional, 2);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);


    // --- Comparação das Cartas Atributo por Atributo ---
    // Utilizamos uma série de condicionais 'if-else if' para comparar cada atributo.
    printf("\n--- Comparacao de Cartas ---\n");

    // Comparação da População (maior valor vence)
    printf("Populacao: %s venceu (%d)\n", (carta1.populacao > carta2.populacao) ? "Carta 1" : "Carta 2", (carta1.populacao > carta2.populacao) ? 1 : 0);

    // Comparação da Área (maior valor vence)
    printf("Area: %s venceu (%d)\n", (carta1.areaKm2 > carta2.areaKm2) ? "Carta 1" : "Carta 2", (carta1.areaKm2 > carta2.areaKm2) ? 1 : 0);

    // Comparação do PIB (maior valor vence)
    printf("PIB: %s venceu (%d)\n", (carta1.pib > carta2.pib) ? "Carta 1" : "Carta 2", (carta1.pib > carta2.pib) ? 1 : 0);

    // Comparação do Número de Pontos Turísticos (maior valor vence)
    printf("Pontos Turisticos: %s venceu (%d)\n", (carta1.pontosTuristicos > carta2.pontosTuristicos) ? "Carta 1" : "Carta 2", (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 0);

    // Comparação da Densidade Populacional (MENOR valor vence)
    printf("Densidade Populacional: %s venceu (%d)\n", (carta1.densidadePopulacional < carta2.densidadePopulacional) ? "Carta 1" : "Carta 2", (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 0);

    // Comparação do PIB per Capita (maior valor vence)
    printf("PIB per Capita: %s venceu (%d)\n", (carta1.pibPerCapita > carta2.pibPerCapita) ? "Carta 1" : "Carta 2", (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 0);

    // Comparação do Super Poder (maior valor vence)
    printf("Super Poder: %s venceu (%d)\n", (carta1.superPoder > carta2.superPoder) ? "Carta 1" : "Carta 2", (carta1.superPoder > carta2.superPoder) ? 1 : 0);

    return 0; // Indica que o programa foi executado com sucesso.
}
