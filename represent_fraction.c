/*Program to create, store and operate on fractions*/

#include <stdio.h>
#include <stdlib.h>

struct fraction {
    int nominator;
    int denominator;
};


int find_least_common_divisor(int nominator, int denominator) {
    nominator = abs(nominator);
    denominator = abs(denominator);
    int smaller_number = (nominator < denominator) ? nominator : denominator;
    for(int i = 2; i <= smaller_number; ++i) {
        if(nominator % i == 0 && denominator % i == 0) {
            return i;
        }
    }
    return -1;
}

void normalize_fraction(int* nominator, int* denominator) {
    int least_common_divisor =  find_least_common_divisor(*nominator,*denominator);
    //can´t be normalized anymore
    if(least_common_divisor < 0) {
        return;
    }
    else {
        *nominator = *nominator / least_common_divisor;
        *denominator = *denominator / least_common_divisor;
        normalize_fraction(nominator,denominator);
    }
}

void create_fraction(struct fraction* my_fraction, int nominator, int denominator) {
    my_fraction->nominator = nominator;
    my_fraction->denominator = denominator;
    normalize_fraction(&(my_fraction->nominator),&(my_fraction->denominator));
}

void  sum_fractions(struct fraction* fraction_a, struct fraction* fraction_b, struct fraction* result_fraction) {
    result_fraction->nominator = (fraction_a->nominator*fraction_b->denominator) + (fraction_a->denominator*fraction_b->nominator);
    result_fraction->denominator = fraction_a->denominator*fraction_b->denominator;
    normalize_fraction(&(result_fraction->nominator),&(result_fraction->denominator));
}

void  sub_fractions(struct fraction* fraction_a, struct fraction* fraction_b, struct fraction* result_fraction) {
    result_fraction->nominator = (fraction_a->nominator*fraction_b->denominator) - (fraction_a->denominator*fraction_b->nominator);
    result_fraction->denominator = fraction_a->denominator*fraction_b->denominator;
    normalize_fraction(&(result_fraction->nominator),&(result_fraction->denominator));
}

void  mul_fractions(struct fraction* fraction_a, struct fraction* fraction_b, struct fraction* result_fraction) {
    result_fraction->nominator = (fraction_a->nominator*fraction_b->nominator); 
    result_fraction->denominator = fraction_a->denominator*fraction_b->denominator;
    normalize_fraction(&(result_fraction->nominator),&(result_fraction->denominator));
}

void  div_fractions(struct fraction* fraction_a, struct fraction* fraction_b, struct fraction* result_fraction) {
    result_fraction->nominator = (fraction_a->nominator*fraction_b->denominator); 
    result_fraction->denominator = fraction_a->denominator*fraction_b->nominator;
    normalize_fraction(&(result_fraction->nominator),&(result_fraction->denominator));
}

int main() {
    struct fraction fraction_a;
    struct fraction fraction_b;
    struct fraction result_sum_fraction;
    struct fraction result_sub_fraction;
    struct fraction result_mul_fraction;
    struct fraction result_div_fraction;
    create_fraction(&fraction_a,3,2);
    create_fraction(&fraction_b,5,2);
    printf("fraction A is  %d/%d\n", fraction_a.nominator, fraction_a.denominator);
    printf("fraction B is %d/%d\n", fraction_b.nominator, fraction_b.denominator);
    sum_fractions(&fraction_a, &fraction_b,&result_sum_fraction);
    sub_fractions(&fraction_a, &fraction_b,&result_sub_fraction);
    mul_fractions(&fraction_a, &fraction_b,&result_mul_fraction);
    div_fractions(&fraction_a, &fraction_b,&result_div_fraction);
    printf("the sum of the fractions is %d/%d\n", result_sum_fraction.nominator, result_sum_fraction.denominator);
    printf("the sub of the fractions is %d/%d\n", result_sub_fraction.nominator, result_sub_fraction.denominator);
    printf("the mul of the fractions is %d/%d\n", result_mul_fraction.nominator, result_mul_fraction.denominator);
    printf("the div of the fractions is %d/%d\n", result_div_fraction.nominator, result_div_fraction.denominator);
    return 0;
}