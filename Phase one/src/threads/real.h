
#ifndef PINTOS_struct real_H
#define PINTOS_struct real_H
struct  real {
    int x;
};
int convert_real_to_int(struct real r);
struct real convert_int_to_real(int n);
struct  real
add_real(struct real r1,struct real r2);

struct  real
subtract_real(struct real r1,struct real r2);

struct  real
multiply_real(struct real r1,struct real r2);

struct  real
divide_real(struct real r1,struct real r2);
#endif //PINTOS_struct real_H
