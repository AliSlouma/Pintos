#include "real.h"
#include <stdio.h>

/* Fixed-point numbers are in signed p:q format where p + q = 31, and f is 1 << q*
 */
const int F = 1 << 14;

/* Convert x to integer (rounding toward zero): x / f
 * Convert x to integer (rounding to nearest):
 * (x + f / 2) / f if x >= 0
 * (x - f / 2) / f if x <= 0
 */
int
convert_real_to_int(struct real r) {
    if (r.x >= 0) return (r.x + F / 2)/F;
    return (r.x - F / 2)/F;
}

/* Convert n to fixed point: n * f
 * */
struct real
convert_int_to_real(int n) {
    struct real r = {.x = n * F};
    return r;
}

/* Add x and y: x + y
 * */
struct real
add_real(struct real r1, struct real r2) {
    struct real r = {.x = r1.x + r2.x};
    return r;
}

/* Add x and y: x - y
 * */
struct real
subtract_real(struct real r1, struct real r2) {
    struct real r = {.x = r1.x - r2.x};
    return r;
}

/* Multiply x by y: ((int64_t) x) * y / f
 * */
struct real
multiply_real(struct real r1, struct real r2) {
    struct real r = {.x = (int64_t)(r1.x) * (r2.x)/F};
    return r;
}

/* Divide x by y: ((int64_t) x) * f / y
 * */
struct real
divide_real(struct real r1, struct real r2) {
    if(r2.x==0){
        struct real a = {.x=-1};
        return a;
    }
    struct real r = {.x = ((int64_t)(r1.x) * F) / r2.x};
    return r;
}

