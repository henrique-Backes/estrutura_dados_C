#include <stdlib.h>
#include "static_list.h"

typedef enum 
{
    STATIC_LIST_OK         =  0,
    STATIC_LIST_EMPTY      = -3,
    STATIC_LIST_FULL       = -2,
    STATIC_LIST_ERROR      = -1
}static_list_error_t;

struct static_list
{
    int size;
    student_t buffer[STATIC_LIST_CAPACITY];
};

static_list_t* static_list_create(void)
{
    static_list_t *list_new;
    list_new = (static_list_t*)malloc(sizeof(static_list_t));

    if (NULL != list_new)
    {
        list_new->size = 0;
    }

    return list_new;
}
void static_list_destroy(static_list_t *self)
{
    free(self);
}
int static_list_get_size(static_list_t *self)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    return self->size;
}
int static_list_is_at_capacity(static_list_t *self)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }
    
    return ((STATIC_LIST_CAPACITY == self->size) ? STATIC_LIST_FULL : STATIC_LIST_OK);
}
int static_list_is_empty(static_list_t *self)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }
    
    return ((0 == self->size) ? STATIC_LIST_EMPTY : STATIC_LIST_OK);
}
int static_list_append(static_list_t *self, student_t student)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_FULL == static_list_is_at_capacity(self))
    {
        return STATIC_LIST_FULL;
    }

    self->buffer[self->size] = student;
    self->size++;
    return STATIC_LIST_SUCCESS;
}
int static_list_prepend(static_list_t *self, student_t student)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_FULL == static_list_is_at_capacity(self))
    {
        return STATIC_LIST_FULL;
    }

    for(int index = (self->size - 1); index >= 0; index--)
    {
        self->buffer[(index + 1)] = self->buffer[index];
    }

    self->buffer[0] = student;
    self->size++;
    return STATIC_LIST_SUCCESS;
}
int static_list_insert_sorted(static_list_t *self, student_t student)
{
    int new_element_index = 0;

    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_FULL == static_list_is_at_capacity(self))
    {
        return STATIC_LIST_FULL;
    }

    while ((new_element_index < self->size) && (self->buffer[new_element_index].student_id < student.student_id))
    {
        new_element_index++;
    }

    for (int index = (self->size - 1); index >= new_element_index; index--)
    {
        self->buffer[(index + 1)] = self->buffer[index];
    }

    self->buffer[new_element_index] = student;
    self->size++;
    return STATIC_LIST_SUCCESS;
}
int static_list_remove_last(static_list_t *self)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_EMPTY == static_list_is_empty(self))
    {
        return STATIC_LIST_EMPTY;
    }

    self->size--;
    return STATIC_LIST_SUCCESS;
}
int static_list_remove_first(static_list_t *self)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_EMPTY == static_list_is_empty(self))
    {
        return STATIC_LIST_EMPTY;
    }

    for (int index = 0; index < (self->size - 1); index++)
    {
        self->buffer[index] = self->buffer[(index + 1)];
    }

    self->size--;
    return STATIC_LIST_SUCCESS;
}
int static_list_remove_by_student_id(static_list_t *self, int student_id)
{
    int remove_element_index = 0;

    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_EMPTY == static_list_is_empty(self))
    {
        return STATIC_LIST_EMPTY;
    }

    while ((remove_element_index < self->size) && (self->buffer[remove_element_index].student_id != student_id))
    {
        remove_element_index++;
    }
    
    if (remove_element_index == self->size)
    {
        return STATIC_LIST_ERROR;
    }

    for (int index = remove_element_index; index < (self->size - 1); index++)
    {
        self->buffer[index] = self->buffer[(index + 1)];
    }

    self->size--;
    return STATIC_LIST_SUCCESS;
}
int static_list_get_by_index(static_list_t *self, int pos, student_t *student)
{
    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }

    if (NULL == student)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_EMPTY == static_list_is_empty(self))
    {
        return STATIC_LIST_ERROR;
    }

    if ((pos >= self->size) || (pos < 0))
    {
        return STATIC_LIST_ERROR;
    }

    *student = self->buffer[pos];
    return STATIC_LIST_SUCCESS;
}
int static_list_get_by_student_id(static_list_t *self, int student_id, student_t *student)
{
    int element_position = 0;

    if (NULL == self)
    {
        return STATIC_LIST_ERROR;
    }
    
    if (NULL == student)
    {
        return STATIC_LIST_ERROR;
    }

    if (STATIC_LIST_EMPTY == static_list_is_empty(self))
    {
        return STATIC_LIST_EMPTY;
    }

    while ((element_position < self->size) && (self->buffer[element_position].student_id != student_id))
    {
        element_position++;
    }

    if (element_position == self->size)
    {
        return STATIC_LIST_ERROR;
    }

    *student = self->buffer[element_position];
    return STATIC_LIST_SUCCESS;
}