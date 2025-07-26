#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#define STATIC_LIST_CAPACITY     100u
#define STUDENT_NAME_MAX_LEN     50u

typedef struct student_t // <- tipo de dado a ser armazenado
{
    int student_id;
    char name[STUDENT_NAME_MAX_LEN];
    float nota1;
    float nota2;
    float nota3;
};

typedef struct static_list static_list_t;

#ifdef __cplusplus 
extern "C" {
#endif

static_list_t* static_list_create(void);
void static_list_destroy(static_list_t *self);
int static_list_get_size(static_list_t *self);
int static_list_is_at_capacity(static_list_t *self);
int static_list_is_empty(static_list_t *self);
int static_list_append(static_list_t *self, student_t student);
int static_list_prepend(static_list_t *self, student_t student);
int static_list_insert_sorted(static_list_t *self, student_t student);
int static_list_remove_last(static_list_t *self);
int static_list_remove_first(static_list_t *self);
int static_list_remove_by_student_id(static_list_t *self, int student_id);
int static_list_get_by_index(static_list_t *self, int pos, student_t *student);
int static_list_get_by_student_id(static_list_t *self, int student_id, student_t *student);

#ifdef __cplusplus 
}
#endif
#endif