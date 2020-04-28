#ifndef SPICES_LIBRARY_H
#define SPICES_LIBRARY_H

#include <stdint.h>

#ifndef SPICES_VEC
#define SPICES_VEC
enum spice_vec_tags {
    auto_alloc = 1u,
    n_alloc = 2u,
    cpy_ref = 4u,
    default_mode = auto_alloc | cpy_ref,
};
typedef struct spices_vec__ spc_vec_t;
typedef enum spice_vec_tags spc_vtags_t;
#endif

/**
 * Initialize a new vector
 * @param init_size the initial cap to be allocated
 * @param itm_size the cap of an individual item of this vector
 * @param tags vector feature tags
 * @return a pointer to the new vector
 */
spc_vec_t *spc_veci(uint64_t init_size, uint64_t itm_size, spc_vtags_t tags);

void spc_vec_free(spc_vec_t *vec);

void spc_vec_clear(spc_vec_t *vec);

int spc_vec_put_ord(spc_vec_t *vec, void *item_ptr);

void *spc_vec_greft(spc_vec_t *vec, uint64_t index);

void *spc_vec_popref(spc_vec_t *vec);

/**
 * How many items are used within the vector
 * @param vec vector
 * @return
 */
uint64_t spc_vec_len(spc_vec_t *vec);

uint64_t spc_vec_sizeof(spc_vec_t *vec);

#endif //SPICES_LIBRARY_H
