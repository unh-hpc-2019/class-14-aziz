
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>
#include <assert.h>

//#define BOUNDS_CHECK

// ----------------------------------------------------------------------
// struct vector

struct vector {
  double *vals;
  int n;
};

#ifdef BOUNDS_CHECK
#define VEC(v, i) (*({				\
	assert((i) >= 0 && (i) < (v)->n);	\
	&((v)->vals[(i)]);			\
      }))
#else
#define VEC(v, i) ((v)->vals[i])
#endif

struct vector *vector_create(int n);
struct vector *vector_create_and_set(int n, const double *vals);
void vector_destroy(struct vector *v);
double vector_dot(const struct vector *x, const struct vector *y);
void vector_add(const struct vector *x, const struct vector *y, struct vector *z);
bool vector_is_equal(const struct vector *x, const struct vector *y);
void vector_print(struct vector *v);

// ----------------------------------------------------------------------
// struct matrix

struct matrix {
  double *vals;
  int m, n;
};

#define MAT(m, i, j) ((m)->vals[(i) * (m)->n + (j)])

struct matrix *matrix_create(int m, int n);
void matrix_destroy(struct matrix *M);
void matrix_print(struct matrix *M);
void matrix_vector_mul(const struct matrix *A, const struct vector *x, struct vector *y);

#endif
