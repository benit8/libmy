/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** tree.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdlib.h>

#include "dsa_types.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct tree_node
{
	void *data;

	struct tree_node *left;
	struct tree_node *right;
} tree_node_t;

typedef struct tree
{
	tree_node_t *root;

	comp_func_t *comp;
	clean_func_t *clean_up;
} tree_t;

////////////////////////////////////////////////////////////////////////////////

tree_t *tree_create(comp_func_t *comp, clean_func_t *clean_up);
void tree_destroy(tree_t *tree);
void tree_clear(tree_t *tree);

size_t tree_get_size(tree_t *tree);
size_t tree_get_depth(tree_t *tree);

bool tree_is_empty(tree_t *tree);

bool tree_insert(tree_t *tree, void *data);
void tree_remove(tree_t *tree);