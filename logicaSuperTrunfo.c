#include <stdio.h>
#include <string.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

float calcularDensidade(int pop, float area) {
    return area == 0 ? 0 : (float)pop / area;
}

float calcularPIBPerCapita(float pib, int pop) {
    return pop == 0 ? 0 : pib * 1e9f / pop;
}

void exibirCarta(struct Carta c) {
    printf("📄 Estado: %c\n", c.estado);
    printf("📄 Codigo: %s\n", c.codigo);
    printf("📄 Nome da Cidade: %s\n", c.nomeCidade);
    printf("👥 Populacao: %d\n", c.populacao);
    printf("🌍 Area: %.2f km²\n", c.area);
    printf("💰 PIB: %.2f bilhoes\n", c.pib);
    printf("📸 Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("📊 Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("💵 PIB per Capita: R$ %.2f\n", c.pibPerCapita);
}

int comparar(float v1, float v2, int maiorVence) {
    if (v1 == v2) return 0;
    if (maiorVence) {
        return (v1 > v2) ? 1 : 2;
    } else {
        return (v1 < v2) ? 1 : 2;
    }
}

int escolherAtributo() {
    int escolha;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite o numero do atributo: ");
    scanf("%d", &escolha);
    while (escolha < 1 || escolha > 6) {
        printf("Entrada invalida. Tente novamente: ");
        scanf("%d", &escolha);
    }
    return escolha;
}

int escolherMaiorOuMenor() {
    int escolha;
    printf("Quem vence?\n");
    printf("1 - Maior valor vence\n");
    printf("2 - Menor valor vence\n");
    printf("Digite a opcao: ");
    scanf("%d", &escolha);
    while (escolha != 1 && escolha != 2) {
        printf("Entrada invalida. Tente novamente: ");
        scanf("%d", &escolha);
    }
    return (escolha == 1) ? 1 : 0;
}

float getValorPorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0.0f;
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "";
    }
}

void compararEExibir(struct Carta c1, struct Carta c2, int attr, int maiorVence) {
    float val1 = getValorPorAtributo(c1, attr);
    float val2 = getValorPorAtributo(c2, attr);
    int resultado = comparar(val1, val2, maiorVence);

    printf("\n📊 Comparacao pelo atributo: %s\n", nomeAtributo(attr));
    printf("Carta 1 (%s): %.2f\n", c1.nomeCidade, val1);
    printf("Carta 2 (%s): %.2f\n", c2.nomeCidade, val2);

    if (resultado == 0) {
        printf("⚖️ Empate nesta categoria!\n");
    } else if (resultado == 1) {
        printf("🏆 Carta 1 (%s) venceu nesta categoria!\n", c1.nomeCidade);
    } else {
        printf("🏆 Carta 2 (%s) venceu nesta categoria!\n", c2.nomeCidade);
    }
}

int main() {
    struct Carta c1, c2;

    printf("🃏 Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", c1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &c1.populacao);
    printf("Area (km²): ");
    scanf("%f", &c1.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &c1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c1.pontosTuristicos);
    c1.densidade = calcularDensidade(c1.populacao, c1.area);
    c1.pibPerCapita = calcularPIBPerCapita(c1.pib, c1.populacao);

    printf("\n🃏 Digite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", c2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &c2.populacao);
    printf("Area (km²): ");
    scanf("%f", &c2.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &c2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c2.pontosTuristicos);
    c2.densidade = calcularDensidade(c2.populacao, c2.area);
    c2.pibPerCapita = calcularPIBPerCapita(c2.pib, c2.populacao);

    printf("\n📄 Carta 1:\n");
    exibirCarta(c1);
    printf("\n📄 Carta 2:\n");
    exibirCarta(c2);

    int nAtributos;
    printf("\nQuantos atributos deseja comparar? (1 ou 2): ");
    scanf("%d", &nAtributos);
    while (nAtributos != 1 && nAtributos != 2) {
        printf("Entrada invalida. Digite 1 ou 2: ");
        scanf("%d", &nAtributos);
    }

    int attr1 = escolherAtributo();
    int maiorVence1 = escolherMaiorOuMenor();

    if (nAtributos == 1) {
        compararEExibir(c1, c2, attr1, maiorVence1);
    } else {
        int attr2;
        do {
            attr2 = escolherAtributo();
            if (attr2 == attr1) {
                printf("Voce ja escolheu este atributo, escolha outro.\n");
            }
        } while (attr2 == attr1);
        int maiorVence2 = escolherMaiorOuMenor();

        // Comparação dos dois atributos
        printf("\n--- Comparacao para o primeiro atributo ---");
        compararEExibir(c1, c2, attr1, maiorVence1);

        printf("\n--- Comparacao para o segundo atributo ---");
        compararEExibir(c1, c2, attr2, maiorVence2);

        // Pontuação final:
        int pontos1 = 0, pontos2 = 0;
        float val1a = getValorPorAtributo(c1, attr1);
        float val2a = getValorPorAtributo(c2, attr1);
        int res1 = comparar(val1a, val2a, maiorVence1);

        float val1b = getValorPorAtributo(c1, attr2);
        float val2b = getValorPorAtributo(c2, attr2);
        int res2 = comparar(val1b, val2b, maiorVence2);

        if (res1 == 1) pontos1++;
        else if (res1 == 2) pontos2++;

        if (res2 == 1) pontos1++;
        else if (res2 == 2) pontos2++;

        printf("\n📈 Pontuacao Final:\n");
        printf("Carta 1 (%s): %d pontos\n", c1.nomeCidade, pontos1);
        printf("Carta 2 (%s): %d pontos\n", c2.nomeCidade, pontos2);

        printf("\n🎯 Resultado Geral: ");
        if (pontos1 > pontos2)
            printf("🏅 Carta 1 (%s) venceu a rodada!\n", c1.nomeCidade);
        else if (pontos2 > pontos1)
            printf("🏅 Carta 2 (%s) venceu a rodada!\n", c2.nomeCidade);
        else
            printf("🤝 Empate geral!\n");
    }

    return 0;
}
