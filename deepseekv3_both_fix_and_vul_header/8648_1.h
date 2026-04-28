#include <stdlib.h>
#include <string.h>

typedef unsigned long mpi_limb_t;
typedef long mpi_limb_signed_t;
typedef mpi_limb_t *mpi_ptr_t;
typedef size_t mpi_size_t;

typedef struct {
    mpi_ptr_t d;
    int alloced;
    mpi_size_t nlimbs;
    int sign;
} *MPI;

struct karatsuba_ctx {
    mpi_ptr_t tspace;
    mpi_size_t tspace_size;
    mpi_ptr_t tp;
    mpi_size_t tp_size;
};

#define BITS_PER_MPI_LIMB (8 * sizeof(mpi_limb_t))
#define KARATSUBA_THRESHOLD 16
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define ENOMEM (-1)
#define EINVAL (-2)

mpi_ptr_t mpi_alloc_limb_space(mpi_size_t size);
void mpi_free_limb_space(mpi_ptr_t a);
void mpi_assign_limb_space(MPI a, mpi_ptr_t p, mpi_size_t size);
int mpi_resize(MPI a, mpi_size_t size);
mpi_limb_t mpihelp_lshift(mpi_ptr_t wp, mpi_ptr_t up, mpi_size_t usize, unsigned int cnt);
void MPN_COPY(mpi_ptr_t wp, mpi_ptr_t up, mpi_size_t size);
mpi_limb_t mpihelp_divrem(mpi_ptr_t qp, mpi_size_t qextra_limbs, mpi_ptr_t np, mpi_size_t nsize, mpi_ptr_t dp, mpi_size_t dsize);
void MPN_NORMALIZE(mpi_ptr_t p, mpi_size_t size);
unsigned int count_leading_zeros(mpi_limb_t x);
void mpih_sqr_n_basecase(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t size);
void mpih_sqr_n(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t size, mpi_ptr_t tspace);
mpi_limb_t mpihelp_mul(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t usize, mpi_ptr_t vp, mpi_size_t vsize, mpi_limb_t *_result);
int mpihelp_mul_karatsuba_case(mpi_ptr_t prodp, mpi_ptr_t up, mpi_size_t usize, mpi_ptr_t vp, mpi_size_t vsize, struct karatsuba_ctx *ctx);
mpi_limb_t mpihelp_rshift(mpi_ptr_t wp, mpi_ptr_t up, mpi_size_t usize, unsigned int cnt);
mpi_limb_t mpihelp_sub(mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr, mpi_size_t s1_size, mpi_ptr_t s2_ptr, mpi_size_t s2_size);
void mpihelp_release_karatsuba_ctx(struct karatsuba_ctx *ctx);