/**
 * @file     book-3-pointers-on-c/chapter-8/8-2/main.c
 * @author   mtueih
 * @date     2025-12-14 20:12
 * @brief    计算税额的函数。
 */

#include <stdio.h>
#include <stdlib.h>

#define TAX_RATE_BRACKETS 5

static const float  tax_thresholds[TAX_RATE_BRACKETS] = {
    0.0f, 23350.0f, 56550.0f, 117950.0f, 256500.0f
};

static const float tax_rates[TAX_RATE_BRACKETS] = {
    0.15f, 0.28f, 0.31f, 0.36f, 0.396f
};

static const float tax_bases[TAX_RATE_BRACKETS] = {
    0.0f, 3502.5f, 12798.5f, 31832.5f, 81710.5f
};


float single_tax(float income);

int main(void) {
    float income;

    printf("请输入税前收入：");
    scanf("%f", &income);

    printf("应纳税额：%.2f\n", single_tax(income));

    return EXIT_SUCCESS;
}

float single_tax(float income) {
    unsigned bracket;

    for (bracket = 0; bracket < TAX_RATE_BRACKETS; ++bracket) {
        if (income <= tax_thresholds[bracket])
            break;
    }

    return tax_bases[bracket] + (income - tax_thresholds[bracket]) * tax_rates[bracket];
}