/*
 * Collections-C
 * Copyright (C) 2013-2015 Srđan Panić <srdja.panic@gmail.com>
 *
 * This file is part of Collections-C.
 *
 * Collections-C is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Collections-C is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Collections-C.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIST_H_
#define LIST_H_

#include "common.h"

typedef struct list_s List;

typedef struct node_s {
    void          *data;
    struct node_s *next;
    struct node_s *prev;
} Node;

typedef struct list_iter_s {
    size_t  index;
    List   *list;
    Node   *last;
    Node   *next;
} ListIter;

typedef struct list_conf_s {
    void  *(*mem_alloc)  (size_t size);
    void  *(*mem_calloc) (size_t blocks, size_t size);
    void   (*mem_free)   (void *block);
} ListConf;

void       list_conf_init       (ListConf *conf);

List*      list_new             (void);
List*      list_new_conf        (ListConf *conf);
bool       list_destroy         (List *list);
bool       list_destroy_free    (List *list);

bool       list_splice          (List *list1, List *list2);
bool       list_splice_at       (List *list, List *list2, size_t index);

bool       list_add             (List *list, void *element);
bool       list_add_at          (List *list, void *element, size_t index);
bool       list_add_all         (List *list1, List *list2);
bool       list_add_all_at      (List *list, List *list2, size_t index);
bool       list_add_first       (List *list, void *element);
bool       list_add_last        (List *list, void *element);

void*      list_remove          (List *list, void *element);
void*      list_remove_first    (List *list);
void*      list_remove_last     (List *list);
void*      list_remove_at       (List *list, size_t index);

bool       list_remove_all      (List *list);
bool       list_remove_all_free (List *list);

void*      list_get             (List *list, size_t index);
void*      list_get_first       (List *list);
void*      list_get_last        (List *list);

List*      list_sublist         (List *list, size_t from, size_t to);
List*      list_copy_shallow    (List *list);
List*      list_copy_deep       (List *list, void *(*cp) (void*));
 
void*      list_replace_at      (List *list, void *element, size_t index);

size_t     list_contains        (List *list, void *element);
size_t     list_index_of        (List *list, void *element);
void**     list_to_array        (List *list);

void       list_reverse         (List *list);
void       list_sort            (List *list, int (*cmp) (void const*, void const*));
void       list_sort_in_place   (List *list, int (*cmp) (void const*, void const*));
size_t     list_size            (List *list);

void       list_foreach         (List *list, void (*op) (void *));

ListIter*  list_iter_new        (List *list);
void       list_iter_destroy    (ListIter *iter);
void*      list_iter_remove     (ListIter *iter);
bool       list_iter_add        (ListIter *iter,  void *element);
void*      list_iter_replace    (ListIter *iter, void *element);
bool       list_iter_has_next   (ListIter *iter);
size_t     list_iter_index      (ListIter *iter);
void*      list_iter_next       (ListIter *iter);

ListIter*  list_diter_new       (List *list);
void       list_diter_destroy   (ListIter *iter);
void*      list_diter_remove    (ListIter *iter);
bool       list_diter_add       (ListIter *iter, void *element);
void*      list_diter_replace   (ListIter *iter, void *element);
bool       list_diter_has_next  (ListIter *iter);
size_t     list_iter_index      (ListIter *iter);
void*      list_diter_next      (ListIter *iter);

#endif /* LIST_H_ */
