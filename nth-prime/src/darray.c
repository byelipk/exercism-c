#include "darray.h"

DArray *DArray_create(size_t element_size, size_t initial_max)
{
  DArray *array = malloc(sizeof(DArray));
  check_mem(array);

  array->max = initial_max;
  check(array->max > 0, "You must set an initial max > 0.");

  array->contents = calloc(initial_max, sizeof(void *));
  check_mem(array->contents);

  array->end = 0;
  array->element_size = element_size;
  array->expand_rate  = DEFAULT_EXPAND_RATE;

  return array;

error:
  DArray_destroy(array);

  return NULL;
}

static inline int DArray_resize(DArray * array, size_t new_size)
{
  check(array != NULL, "Invalid array.");

  array->max = new_size;
  check(array->max > 0, "The new size must by > 0.");

  void *contents = realloc(array->contents, array->max * sizeof(void *));
  // check the contents and assume realloc doesn't harm the original on error

  check_mem(contents);

  array->contents = contents;

  return 0;

error:
  return -1;
}

int DArray_expand(DArray * array)
{
  check(array != NULL, "Invalid array.");

  size_t old_max = array->max;
  check(DArray_resize(array, array->max + array->expand_rate) == 0,
      "Failed to expand array to new size: %d", array->max + (int)array->expand_rate);

  memset(array->contents + old_max, 0, array->expand_rate + 1);

  return 0;

error:
  return -1;
}

int DArray_contract(DArray * array)
{
  check(array != NULL, "Invalid array.");
  int new_size = array->end < (int)array->expand_rate ?
    (int)array->expand_rate : array->end;

  return DArray_resize(array, new_size + 1);
error:
  return -1;
}

void DArray_clear(DArray * array)
{
  int i = 0;
  check(array != NULL, "Invalid array.");

  if (array->element_size > 0) {
    for (i = 0; i < array->max; i++) {
      if (array->contents[i] != NULL) {
        free(array->contents[i]);
      }
    }
  }

error:
  return;
}

void DArray_destroy(DArray * array)
{
  if (array) {
    if (array->contents) {
      free(array->contents);
    }
    free(array);
  }
}

void DArray_clear_destroy(DArray * array)
{
  check(array != NULL, "Invalid array.");
  DArray_clear(array);
  DArray_destroy(array);
error: // fallthrough
  return;
}

int DArray_push(DArray * array, void *el)
{
  check(array != NULL, "Invalid array.");

  array->contents[array->end] = el;
  array->end++;

  if (DArray_end(array) >= DArray_max(array)) {
    return DArray_expand(array);
  } else {
    return 0;
  }

error:
  return -1;
}

void *DArray_pop(DArray * array)
{
  check(array != NULL, "Invalid array.");
  check(array->end - 1 >= 0, "Attempt to pop from empty array.");

  void *el = DArray_remove(array, array->end - 1);
  array->end--;

  if (DArray_end(array) > (int)array->expand_rate
      && DArray_end(array) % array->expand_rate) {
    check(DArray_contract(array) != -1, "Failed to contact.");
  }

  return el;
error:
  return NULL;
}
