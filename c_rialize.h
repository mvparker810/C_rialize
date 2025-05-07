#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef union vec3 {
    struct {
        float x;
        float y;
        float z;
    };
    float v[3];
} vec3;

typedef struct json_parser_test_str {
    int amount; // ------------- Primitive - int
    double weight; // ---------- Primitive - double
    char name[512]; // --------- Primitive - string

    int scores[5]; // ---------- Stack Array - Primitives - int
    char students[3][512];  // - Stack Array - Primitives - string

    int ids_len; // ------------ Primitive - int
    int* ids; // --------------- Heap Array - Primitives - int

    vec3 position; // ---------- Composite - vec3

    vec3 triangle_verts[3]; // - Stack Array - Composites - vec3

    int polygon_verts_len; // -- Primitive - int
    vec3* polygon_verts; // ---- Heap Array - Composites - vec3
} json_parser_test_str;



#define STRUCT_SERIALIZATION_DATA           \
    SERIALIZABLE_STRUCT(vec3, 3,            \
        PRIMITIVE(float, x)                 \
        PRIMITIVE(float, y)                 \
        PRIMITIVE(float, z)                 \
    )                                       \
                                                                    \
    SERIALIZABLE_STRUCT(json_parser_test_str, 11,                   \
        PRIMITIVE(int, amount)                                      \
        PRIMITIVE(double, weight)                                   \
        PRIMITIVE(string, name)                                     \
                                                                    \
        ARRAY_STACK(string, students, PRIM)                         \
        ARRAY_STACK(int, scores, PRIM)                              \
                                                                    \
        PRIMITIVE(int, ids_len)                                     \
        ARRAY_HEAP(int, ids, PRIM, ids_len)                         \
                                                                    \
        COMPOSITE(vec3, position)                                   \
                                                                    \
        ARRAY_STACK(vec3, triangle_verts, COMP)                     \
                                                                    \
        PRIMITIVE(int, polygon_verts_len)                           \
        ARRAY_HEAP(vec3, polygon_verts, COMP, polygon_verts_len)    \
    )                                                               \

#define SERIALIZABLE_STRUCT(type, num_fields, ...)          \
    char* type##_SERIALIZE(const type obj);                 \
    int type##_DESERIALIZE(char* json_str, type* obj);     \

//Make prototypes
STRUCT_SERIALIZATION_DATA
