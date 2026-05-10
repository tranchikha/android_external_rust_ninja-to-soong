#include "bifrost_nir.h"

#include "nir.h"
#include "nir_builder.h"
#include "nir_search.h"
#include "nir_search_helpers.h"

/* What follows is NIR algebraic transform code for the following 4
 * transforms:
 *    ('iand', 'a@1', 'b@1') => ('bcsel', 'a', 'b', False)
 *    ('ior', 'a@1', 'b@1') => ('bcsel', 'a', 'a', 'b')
 *    ('iand', 'a@1', ('inot', 'b@1')) => ('bcsel', 'b', 0, 'a')
 *    ('ior', 'a@1', ('inot', 'b@1')) => ('bcsel', 'b', 'a', True)
 */


static const nir_search_value_union bifrost_nir_opt_boolean_bitwise_values[] = {
   /* ('iand', 'a@1', 'b@1') => ('bcsel', 'a', 'b', False) */
   { .variable = {
      { nir_search_value_variable, 1 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .variable = {
      { nir_search_value_variable, 1 },
      1, /* b */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_iand,
      0, 1,
      { 0, 1 },
      -1,
   } },

   /* replace0_0 -> 0 in the cache */
   /* replace0_1 -> 1 in the cache */
   { .constant = {
      { nir_search_value_constant, 1 },
      nir_type_bool, { NIR_FALSE /* False */ },
   } },
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_bcsel,
      -1, 0,
      { 0, 1, 3 },
      -1,
   } },

   /* ('ior', 'a@1', 'b@1') => ('bcsel', 'a', 'a', 'b') */
   /* search1_0 -> 0 in the cache */
   /* search1_1 -> 1 in the cache */
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ior,
      0, 1,
      { 0, 1 },
      -1,
   } },

   /* replace1_0 -> 0 in the cache */
   /* replace1_1 -> 0 in the cache */
   /* replace1_2 -> 1 in the cache */
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_bcsel,
      -1, 0,
      { 0, 0, 1 },
      -1,
   } },

   /* ('iand', 'a@1', ('inot', 'b@1')) => ('bcsel', 'b', 0, 'a') */
   /* search2_0 -> 0 in the cache */
   /* search2_1_0 -> 1 in the cache */
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_inot,
      -1, 0,
      { 1 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_iand,
      0, 1,
      { 0, 7 },
      -1,
   } },

   /* replace2_0 -> 1 in the cache */
   { .constant = {
      { nir_search_value_constant, 1 },
      nir_type_int, { 0x0ull /* 0 */ },
   } },
   /* replace2_2 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_bcsel,
      -1, 0,
      { 1, 9, 0 },
      -1,
   } },

   /* ('ior', 'a@1', ('inot', 'b@1')) => ('bcsel', 'b', 'a', True) */
   /* search3_0 -> 0 in the cache */
   /* search3_1_0 -> 1 in the cache */
   /* search3_1 -> 7 in the cache */
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ior,
      0, 1,
      { 0, 7 },
      -1,
   } },

   /* replace3_0 -> 1 in the cache */
   /* replace3_1 -> 0 in the cache */
   { .constant = {
      { nir_search_value_constant, 1 },
      nir_type_bool, { NIR_TRUE /* True */ },
   } },
   { .expression = {
      { nir_search_value_expression, 1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_bcsel,
      -1, 0,
      { 1, 0, 12 },
      -1,
   } },

};



static const struct transform bifrost_nir_opt_boolean_bitwise_transforms[] = {
   { ~0, ~0, ~0 }, /* Sentinel */

   { 2, 4, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 5, 6, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 2, 4, 0 },
   { 8, 10, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 5, 6, 0 },
   { 11, 13, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

};

static const struct per_op_table bifrost_nir_opt_boolean_bitwise_pass_op_table[nir_num_search_ops] = {
   [nir_op_iand] = {
      .filter = (const uint16_t []) {
         0,
         0,
         0,
         0,
         1,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         2,
         5,
         5,
         5,
      },
   },
   [nir_op_ior] = {
      .filter = (const uint16_t []) {
         0,
         0,
         0,
         0,
         1,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         3,
         6,
         6,
         6,
      },
   },
   [nir_op_inot] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         4,
      },
   },
};

/* Mapping from state index to offset in transforms (0 being no transforms) */
static const uint16_t bifrost_nir_opt_boolean_bitwise_transform_offsets[] = {
   0,
   0,
   1,
   3,
   0,
   5,
   8,
};

static const nir_algebraic_table bifrost_nir_opt_boolean_bitwise_table = {
   .transforms = bifrost_nir_opt_boolean_bitwise_transforms,
   .transform_offsets = bifrost_nir_opt_boolean_bitwise_transform_offsets,
   .pass_op_table = bifrost_nir_opt_boolean_bitwise_pass_op_table,
   .values = bifrost_nir_opt_boolean_bitwise_values,
   .expression_cond = NULL,
   .variable_cond = NULL,
};

bool
bifrost_nir_opt_boolean_bitwise(
   nir_shader *shader
) {
   bool progress = false;
   bool condition_flags[1];
   const nir_shader_compiler_options *options = shader->options;
   const shader_info *info = &shader->info;
   (void) options;
   (void) info;

   STATIC_ASSERT(14 == ARRAY_SIZE(bifrost_nir_opt_boolean_bitwise_values));
   condition_flags[0] = true;

   nir_foreach_function_impl(impl, shader) {
     progress |= nir_algebraic_impl(impl, condition_flags, &bifrost_nir_opt_boolean_bitwise_table);
   }

   return progress;
}


#include "nir.h"
#include "nir_builder.h"
#include "nir_search.h"
#include "nir_search_helpers.h"

/* What follows is NIR algebraic transform code for the following 48
 * transforms:
 *    ('fmul', 'a', 2.0) => ('fadd', 'a', 'a')
 *    ('fmin', ('fmax', 'a', -1.0), 1.0) => ('fsat_signed', 'a')
 *    ('fmax', ('fmin', 'a', 1.0), -1.0) => ('fsat_signed', 'a')
 *    ('fmax', 'a', 0.0) => ('fclamp_pos', 'a')
 *    ('b32csel', 'b@32', ('iadd', 'a@32', 1), 'a') => ('iadd', 'a', ('b2i32', 'b'))
 *    ('imin', 'a@8', 'b@8') => ('b8csel', ('ilt8', 'a', 'b'), 'a', 'b')
 *    ('imax', 'a@8', 'b@8') => ('b8csel', ('ilt8', 'a', 'b'), 'b', 'a')
 *    ('umin', 'a@8', 'b@8') => ('b8csel', ('ult8', 'a', 'b'), 'a', 'b')
 *    ('umax', 'a@8', 'b@8') => ('b8csel', ('ult8', 'a', 'b'), 'b', 'a')
 *    ('f2i8', 'a') => ('i2i8', ('f2i16', 'a'))
 *    ('f2u8', 'a') => ('u2u8', ('f2u16', 'a'))
 *    ('unpack_64_2x32', 'a') => ('vec2', ('unpack_64_2x32_split_x', 'a'), ('unpack_64_2x32_split_y', 'a'))
 *    ('i2f32', 'a@8') => ('i2f32', ('i2i32', 'a'))
 *    ('i2f32', 'a@16') => ('i2f32', ('i2i32', 'a'))
 *    ('u2f32', 'a@8') => ('u2f32', ('u2u32', 'a'))
 *    ('u2f32', 'a@16') => ('u2f32', ('u2u32', 'a'))
 *    ('i2f16', 'a') => ('f2f16', ('i2f32', ('i2i32', 'a')))
 *    ('u2f16', 'a') => ('f2f16', ('u2f32', ('u2u32', 'a')))
 *    ('i2f16', 'a@32') => ('f2f16', ('i2f32', 'a'))
 *    ('u2f16', 'a@32') => ('f2f16', ('u2f32', 'a'))
 *    ('f2i16', 'a@16') => ('f2i16', ('f2f32', 'a'))
 *    ('f2u16', 'a@16') => ('f2u16', ('f2f32', 'a'))
 *    ('pack_half_2x16_split', 'a', 'b') => ('pack_32_2x16_split', ('f2f16', 'a'), ('f2f16', 'b'))
 *    ('f2i32', 'a@16') => ('f2i32', ('f2f32', 'a'))
 *    ('f2u32', 'a@16') => ('f2u32', ('f2f32', 'a'))
 *    ('ffract', 'a') => ('fadd', 'a', ('fneg', ('ffloor', 'a')))
 *    ('i2i8', 'a@8') => a
 *    ('i2i16', 'a@16') => a
 *    ('i2i32', 'a@32') => a
 *    ('ilt8', 'a', 'b') => ('i2i8', ('ilt16', ('i2i16', 'a'), ('i2i16', 'b')))
 *    ('ige8', 'a', 'b') => ('i2i8', ('ige16', ('i2i16', 'a'), ('i2i16', 'b')))
 *    ('ieq8', 'a', 'b') => ('i2i8', ('ieq16', ('i2i16', 'a'), ('i2i16', 'b')))
 *    ('ine8', 'a', 'b') => ('i2i8', ('ine16', ('i2i16', 'a'), ('i2i16', 'b')))
 *    ('ult8', 'a', 'b') => ('u2u8', ('ult16', ('u2u16', 'a'), ('u2u16', 'b')))
 *    ('uge8', 'a', 'b') => ('u2u8', ('uge16', ('u2u16', 'a'), ('u2u16', 'b')))
 *    ('b2f16', ('inot', 'a@8')) => ('b16csel', ('i2i16', 'a'), 0.0, 1.0)
 *    ('b2f16', 'a@8') => ('b16csel', ('i2i16', 'a'), 1.0, 0.0)
 *    ('b2f32', ('inot', 'a@8')) => ('b32csel', ('i2i32', 'a'), 0.0, 1.0)
 *    ('b2f32', 'a@8') => ('b32csel', ('i2i32', 'a'), 1.0, 0.0)
 *    ('b2f16', ('inot', 'a@16')) => ('b16csel', 'a', 0.0, 1.0)
 *    ('b2f16', 'a@16') => ('b16csel', 'a', 1.0, 0.0)
 *    ('b2f32', ('inot', 'a@16')) => ('b32csel', ('i2i32', 'a'), 0.0, 1.0)
 *    ('b2f32', 'a@16') => ('b32csel', ('i2i32', 'a'), 1.0, 0.0)
 *    ('b2f16', ('inot', 'a@32')) => ('b16csel', ('i2i16', 'a'), 0.0, 1.0)
 *    ('b2f16', 'a@32') => ('b16csel', ('i2i16', 'a'), 1.0, 0.0)
 *    ('b2f32', ('inot', 'a@32')) => ('b32csel', 'a', 0.0, 1.0)
 *    ('b2f32', 'a@32') => ('b32csel', 'a', 1.0, 0.0)
 *    ('ldexp', 'a@16', 'b') => ('ldexp16_pan', 'a', ('i2i16', ('imin', ('imax', 'b', -127), 127)))
 */


static const nir_search_value_union bifrost_nir_lower_algebraic_late_values[] = {
   /* ('fmul', 'a', 2.0) => ('fadd', 'a', 'a') */
   { .variable = {
      { nir_search_value_variable, -1 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .constant = {
      { nir_search_value_constant, -1 },
      nir_type_float, { 0x4000000000000000ull /* 2.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmul,
      0, 1,
      { 0, 1 },
      -1,
   } },

   /* replace4_0 -> 0 in the cache */
   /* replace4_1 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_fadd,
      -1, 0,
      { 0, 0 },
      -1,
   } },

   /* ('fmin', ('fmax', 'a', -1.0), 1.0) => ('fsat_signed', 'a') */
   /* search5_0_0 -> 0 in the cache */
   { .constant = {
      { nir_search_value_constant, -1 },
      nir_type_float, { 0xbff0000000000000ull /* -1.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmax,
      1, 1,
      { 0, 4 },
      -1,
   } },
   { .constant = {
      { nir_search_value_constant, -1 },
      nir_type_float, { 0x3ff0000000000000ull /* 1.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmin,
      0, 2,
      { 5, 6 },
      -1,
   } },

   /* replace5_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_fsat_signed,
      -1, 0,
      { 0 },
      -1,
   } },

   /* ('fmax', ('fmin', 'a', 1.0), -1.0) => ('fsat_signed', 'a') */
   /* search6_0_0 -> 0 in the cache */
   /* search6_0_1 -> 6 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmin,
      1, 1,
      { 0, 6 },
      -1,
   } },
   /* search6_1 -> 4 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmax,
      0, 2,
      { 9, 4 },
      -1,
   } },

   /* replace6_0 -> 0 in the cache */
   /* replace6 -> 8 in the cache */

   /* ('fmax', 'a', 0.0) => ('fclamp_pos', 'a') */
   /* search7_0 -> 0 in the cache */
   { .constant = {
      { nir_search_value_constant, -1 },
      nir_type_float, { 0x0ull /* 0.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_fmax,
      0, 1,
      { 0, 11 },
      -1,
   } },

   /* replace7_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_fclamp_pos,
      -1, 0,
      { 0 },
      -1,
   } },

   /* ('b32csel', 'b@32', ('iadd', 'a@32', 1), 'a') => ('iadd', 'a', ('b2i32', 'b')) */
   { .variable = {
      { nir_search_value_variable, 32 },
      0, /* b */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .variable = {
      { nir_search_value_variable, 32 },
      1, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .constant = {
      { nir_search_value_constant, 32 },
      nir_type_int, { 0x1ull /* 1 */ },
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_iadd,
      0, 1,
      { 15, 16 },
      -1,
   } },
   /* search8_2 -> 15 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b32csel,
      -1, 1,
      { 14, 17, 15 },
      -1,
   } },

   /* replace8_0 -> 15 in the cache */
   /* replace8_1_0 -> 14 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2i32,
      -1, 0,
      { 14 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_iadd,
      0, 1,
      { 15, 19 },
      -1,
   } },

   /* ('imin', 'a@8', 'b@8') => ('b8csel', ('ilt8', 'a', 'b'), 'a', 'b') */
   { .variable = {
      { nir_search_value_variable, 8 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .variable = {
      { nir_search_value_variable, 8 },
      1, /* b */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_imin,
      0, 1,
      { 21, 22 },
      -1,
   } },

   /* replace9_0_0 -> 21 in the cache */
   /* replace9_0_1 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ilt8,
      -1, 0,
      { 21, 22 },
      -1,
   } },
   /* replace9_1 -> 21 in the cache */
   /* replace9_2 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b8csel,
      -1, 0,
      { 24, 21, 22 },
      -1,
   } },

   /* ('imax', 'a@8', 'b@8') => ('b8csel', ('ilt8', 'a', 'b'), 'b', 'a') */
   /* search10_0 -> 21 in the cache */
   /* search10_1 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_imax,
      0, 1,
      { 21, 22 },
      -1,
   } },

   /* replace10_0_0 -> 21 in the cache */
   /* replace10_0_1 -> 22 in the cache */
   /* replace10_0 -> 24 in the cache */
   /* replace10_1 -> 22 in the cache */
   /* replace10_2 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b8csel,
      -1, 0,
      { 24, 22, 21 },
      -1,
   } },

   /* ('umin', 'a@8', 'b@8') => ('b8csel', ('ult8', 'a', 'b'), 'a', 'b') */
   /* search11_0 -> 21 in the cache */
   /* search11_1 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_umin,
      0, 1,
      { 21, 22 },
      -1,
   } },

   /* replace11_0_0 -> 21 in the cache */
   /* replace11_0_1 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ult8,
      -1, 0,
      { 21, 22 },
      -1,
   } },
   /* replace11_1 -> 21 in the cache */
   /* replace11_2 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b8csel,
      -1, 0,
      { 29, 21, 22 },
      -1,
   } },

   /* ('umax', 'a@8', 'b@8') => ('b8csel', ('ult8', 'a', 'b'), 'b', 'a') */
   /* search12_0 -> 21 in the cache */
   /* search12_1 -> 22 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_umax,
      0, 1,
      { 21, 22 },
      -1,
   } },

   /* replace12_0_0 -> 21 in the cache */
   /* replace12_0_1 -> 22 in the cache */
   /* replace12_0 -> 29 in the cache */
   /* replace12_1 -> 22 in the cache */
   /* replace12_2 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b8csel,
      -1, 0,
      { 29, 22, 21 },
      -1,
   } },

   /* ('f2i8', 'a') => ('i2i8', ('f2i16', 'a')) */
   /* search13_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i8,
      -1, 0,
      { 0 },
      -1,
   } },

   /* replace13_0_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i16,
      -1, 0,
      { 0 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 0,
      { 34 },
      -1,
   } },

   /* ('f2u8', 'a') => ('u2u8', ('f2u16', 'a')) */
   /* search14_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u8,
      -1, 0,
      { 0 },
      -1,
   } },

   /* replace14_0_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u16,
      -1, 0,
      { 0 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u8,
      -1, 0,
      { 37 },
      -1,
   } },

   /* ('unpack_64_2x32', 'a') => ('vec2', ('unpack_64_2x32_split_x', 'a'), ('unpack_64_2x32_split_y', 'a')) */
   { .variable = {
      { nir_search_value_variable, 64 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_unpack_64_2x32,
      -1, 0,
      { 39 },
      -1,
   } },

   /* replace15_0_0 -> 39 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_unpack_64_2x32_split_x,
      -1, 0,
      { 39 },
      -1,
   } },
   /* replace15_1_0 -> 39 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_unpack_64_2x32_split_y,
      -1, 0,
      { 39 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_vec2,
      -1, 0,
      { 41, 42 },
      -1,
   } },

   /* ('i2f32', 'a@8') => ('i2f32', ('i2i32', 'a')) */
   /* search16_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 21 },
      -1,
   } },

   /* replace16_0_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i32,
      -1, 0,
      { 21 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 45 },
      -1,
   } },

   /* ('i2f32', 'a@16') => ('i2f32', ('i2i32', 'a')) */
   { .variable = {
      { nir_search_value_variable, 16 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace17_0_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i32,
      -1, 0,
      { 47 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 49 },
      -1,
   } },

   /* ('u2f32', 'a@8') => ('u2f32', ('u2u32', 'a')) */
   /* search18_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 21 },
      -1,
   } },

   /* replace18_0_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u32,
      -1, 0,
      { 21 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 52 },
      -1,
   } },

   /* ('u2f32', 'a@16') => ('u2f32', ('u2u32', 'a')) */
   /* search19_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace19_0_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u32,
      -1, 0,
      { 47 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 55 },
      -1,
   } },

   /* ('i2f16', 'a') => ('f2f16', ('i2f32', ('i2i32', 'a'))) */
   /* search20_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f16,
      -1, 0,
      { 0 },
      -1,
   } },

   /* replace20_0_0_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i32,
      -1, 0,
      { 0 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 58 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 59 },
      -1,
   } },

   /* ('u2f16', 'a') => ('f2f16', ('u2f32', ('u2u32', 'a'))) */
   /* search21_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f16,
      -1, 0,
      { 0 },
      -1,
   } },

   /* replace21_0_0_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u32,
      -1, 0,
      { 0 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 62 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 63 },
      -1,
   } },

   /* ('i2f16', 'a@32') => ('f2f16', ('i2f32', 'a')) */
   { .variable = {
      { nir_search_value_variable, 32 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f16,
      -1, 0,
      { 65 },
      -1,
   } },

   /* replace22_0_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2f32,
      -1, 0,
      { 65 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 67 },
      -1,
   } },

   /* ('u2f16', 'a@32') => ('f2f16', ('u2f32', 'a')) */
   /* search23_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f16,
      -1, 0,
      { 65 },
      -1,
   } },

   /* replace23_0_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2f32,
      -1, 0,
      { 65 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 70 },
      -1,
   } },

   /* ('f2i16', 'a@16') => ('f2i16', ('f2f32', 'a')) */
   /* search24_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i16,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace24_0_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f32,
      -1, 0,
      { 47 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i16,
      -1, 0,
      { 73 },
      -1,
   } },

   /* ('f2u16', 'a@16') => ('f2u16', ('f2f32', 'a')) */
   /* search25_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u16,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace25_0_0 -> 47 in the cache */
   /* replace25_0 -> 73 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u16,
      -1, 0,
      { 73 },
      -1,
   } },

   /* ('pack_half_2x16_split', 'a', 'b') => ('pack_32_2x16_split', ('f2f16', 'a'), ('f2f16', 'b')) */
   /* search26_0 -> 65 in the cache */
   { .variable = {
      { nir_search_value_variable, 32 },
      1, /* b */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_pack_half_2x16_split,
      -1, 0,
      { 65, 77 },
      -1,
   } },

   /* replace26_0_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 65 },
      -1,
   } },
   /* replace26_1_0 -> 77 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2f16,
      -1, 0,
      { 77 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_pack_32_2x16_split,
      -1, 0,
      { 79, 80 },
      -1,
   } },

   /* ('f2i32', 'a@16') => ('f2i32', ('f2f32', 'a')) */
   /* search27_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i32,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace27_0_0 -> 47 in the cache */
   /* replace27_0 -> 73 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2i32,
      -1, 0,
      { 73 },
      -1,
   } },

   /* ('f2u32', 'a@16') => ('f2u32', ('f2f32', 'a')) */
   /* search28_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u32,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace28_0_0 -> 47 in the cache */
   /* replace28_0 -> 73 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_f2u32,
      -1, 0,
      { 73 },
      -1,
   } },

   /* ('ffract', 'a') => ('fadd', 'a', ('fneg', ('ffloor', 'a'))) */
   /* search29_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ffract,
      -1, 0,
      { 0 },
      -1,
   } },

   /* replace29_0 -> 0 in the cache */
   /* replace29_1_0_0 -> 0 in the cache */
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ffloor,
      -1, 0,
      { 0 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_fneg,
      -1, 0,
      { 87 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, -1 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_fadd,
      0, 1,
      { 0, 88 },
      -1,
   } },

   /* ('i2i8', 'a@8') => a */
   /* search30_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 0,
      { 21 },
      -1,
   } },

   /* replace30 -> 21 in the cache */

   /* ('i2i16', 'a@16') => a */
   /* search31_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace31 -> 47 in the cache */

   /* ('i2i32', 'a@32') => a */
   /* search32_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i32,
      -1, 0,
      { 65 },
      -1,
   } },

   /* replace32 -> 65 in the cache */

   /* ('ilt8', 'a', 'b') => ('i2i8', ('ilt16', ('i2i16', 'a'), ('i2i16', 'b'))) */
   { .variable = {
      { nir_search_value_variable, -2 },
      0, /* a */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .variable = {
      { nir_search_value_variable, -2 },
      1, /* b */
      false,
      -1,
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ilt8,
      -1, 0,
      { 93, 94 },
      -1,
   } },

   /* replace33_0_0_0 -> 93 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 0,
      { 93 },
      -1,
   } },
   /* replace33_0_1_0 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 0,
      { 94 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ilt16,
      -1, 0,
      { 96, 97 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 0,
      { 98 },
      -1,
   } },

   /* ('ige8', 'a', 'b') => ('i2i8', ('ige16', ('i2i16', 'a'), ('i2i16', 'b'))) */
   /* search34_0 -> 93 in the cache */
   /* search34_1 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ige8,
      -1, 0,
      { 93, 94 },
      -1,
   } },

   /* replace34_0_0_0 -> 93 in the cache */
   /* replace34_0_0 -> 96 in the cache */
   /* replace34_0_1_0 -> 94 in the cache */
   /* replace34_0_1 -> 97 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ige16,
      -1, 0,
      { 96, 97 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 0,
      { 101 },
      -1,
   } },

   /* ('ieq8', 'a', 'b') => ('i2i8', ('ieq16', ('i2i16', 'a'), ('i2i16', 'b'))) */
   /* search35_0 -> 93 in the cache */
   /* search35_1 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ieq8,
      0, 1,
      { 93, 94 },
      -1,
   } },

   /* replace35_0_0_0 -> 93 in the cache */
   /* replace35_0_0 -> 96 in the cache */
   /* replace35_0_1_0 -> 94 in the cache */
   /* replace35_0_1 -> 97 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ieq16,
      0, 1,
      { 96, 97 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 1,
      { 104 },
      -1,
   } },

   /* ('ine8', 'a', 'b') => ('i2i8', ('ine16', ('i2i16', 'a'), ('i2i16', 'b'))) */
   /* search36_0 -> 93 in the cache */
   /* search36_1 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ine8,
      0, 1,
      { 93, 94 },
      -1,
   } },

   /* replace36_0_0_0 -> 93 in the cache */
   /* replace36_0_0 -> 96 in the cache */
   /* replace36_0_1_0 -> 94 in the cache */
   /* replace36_0_1 -> 97 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ine16,
      0, 1,
      { 96, 97 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i8,
      -1, 1,
      { 107 },
      -1,
   } },

   /* ('ult8', 'a', 'b') => ('u2u8', ('ult16', ('u2u16', 'a'), ('u2u16', 'b'))) */
   /* search37_0 -> 93 in the cache */
   /* search37_1 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ult8,
      -1, 0,
      { 93, 94 },
      -1,
   } },

   /* replace37_0_0_0 -> 93 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u16,
      -1, 0,
      { 93 },
      -1,
   } },
   /* replace37_0_1_0 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u16,
      -1, 0,
      { 94 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ult16,
      -1, 0,
      { 110, 111 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u8,
      -1, 0,
      { 112 },
      -1,
   } },

   /* ('uge8', 'a', 'b') => ('u2u8', ('uge16', ('u2u16', 'a'), ('u2u16', 'b'))) */
   /* search38_0 -> 93 in the cache */
   /* search38_1 -> 94 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_uge8,
      -1, 0,
      { 93, 94 },
      -1,
   } },

   /* replace38_0_0_0 -> 93 in the cache */
   /* replace38_0_0 -> 110 in the cache */
   /* replace38_0_1_0 -> 94 in the cache */
   /* replace38_0_1 -> 111 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_uge16,
      -1, 0,
      { 110, 111 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_u2u8,
      -1, 0,
      { 115 },
      -1,
   } },

   /* ('b2f16', ('inot', 'a@8')) => ('b16csel', ('i2i16', 'a'), 0.0, 1.0) */
   /* search39_0_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 8 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_inot,
      -1, 0,
      { 21 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 117 },
      -1,
   } },

   /* replace39_0_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 0,
      { 21 },
      -1,
   } },
   { .constant = {
      { nir_search_value_constant, 16 },
      nir_type_float, { 0x0ull /* 0.0 */ },
   } },
   { .constant = {
      { nir_search_value_constant, 16 },
      nir_type_float, { 0x3ff0000000000000ull /* 1.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 119, 120, 121 },
      -1,
   } },

   /* ('b2f16', 'a@8') => ('b16csel', ('i2i16', 'a'), 1.0, 0.0) */
   /* search40_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 21 },
      -1,
   } },

   /* replace40_0_0 -> 21 in the cache */
   /* replace40_0 -> 119 in the cache */
   /* replace40_1 -> 121 in the cache */
   /* replace40_2 -> 120 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 119, 121, 120 },
      -1,
   } },

   /* ('b2f32', ('inot', 'a@8')) => ('b32csel', ('i2i32', 'a'), 0.0, 1.0) */
   /* search41_0_0 -> 21 in the cache */
   /* search41_0 -> 117 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 117 },
      -1,
   } },

   /* replace41_0_0 -> 21 in the cache */
   /* replace41_0 -> 45 in the cache */
   { .constant = {
      { nir_search_value_constant, 32 },
      nir_type_float, { 0x0ull /* 0.0 */ },
   } },
   { .constant = {
      { nir_search_value_constant, 32 },
      nir_type_float, { 0x3ff0000000000000ull /* 1.0 */ },
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 45, 126, 127 },
      -1,
   } },

   /* ('b2f32', 'a@8') => ('b32csel', ('i2i32', 'a'), 1.0, 0.0) */
   /* search42_0 -> 21 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 21 },
      -1,
   } },

   /* replace42_0_0 -> 21 in the cache */
   /* replace42_0 -> 45 in the cache */
   /* replace42_1 -> 127 in the cache */
   /* replace42_2 -> 126 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 45, 127, 126 },
      -1,
   } },

   /* ('b2f16', ('inot', 'a@16')) => ('b16csel', 'a', 0.0, 1.0) */
   /* search43_0_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_inot,
      -1, 0,
      { 47 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 131 },
      -1,
   } },

   /* replace43_0 -> 47 in the cache */
   /* replace43_1 -> 120 in the cache */
   /* replace43_2 -> 121 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 47, 120, 121 },
      -1,
   } },

   /* ('b2f16', 'a@16') => ('b16csel', 'a', 1.0, 0.0) */
   /* search44_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace44_0 -> 47 in the cache */
   /* replace44_1 -> 121 in the cache */
   /* replace44_2 -> 120 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 47, 121, 120 },
      -1,
   } },

   /* ('b2f32', ('inot', 'a@16')) => ('b32csel', ('i2i32', 'a'), 0.0, 1.0) */
   /* search45_0_0 -> 47 in the cache */
   /* search45_0 -> 131 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 131 },
      -1,
   } },

   /* replace45_0_0 -> 47 in the cache */
   /* replace45_0 -> 49 in the cache */
   /* replace45_1 -> 126 in the cache */
   /* replace45_2 -> 127 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 49, 126, 127 },
      -1,
   } },

   /* ('b2f32', 'a@16') => ('b32csel', ('i2i32', 'a'), 1.0, 0.0) */
   /* search46_0 -> 47 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 47 },
      -1,
   } },

   /* replace46_0_0 -> 47 in the cache */
   /* replace46_0 -> 49 in the cache */
   /* replace46_1 -> 127 in the cache */
   /* replace46_2 -> 126 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 49, 127, 126 },
      -1,
   } },

   /* ('b2f16', ('inot', 'a@32')) => ('b16csel', ('i2i16', 'a'), 0.0, 1.0) */
   /* search47_0_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_inot,
      -1, 0,
      { 65 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 140 },
      -1,
   } },

   /* replace47_0_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 0,
      { 65 },
      -1,
   } },
   /* replace47_1 -> 120 in the cache */
   /* replace47_2 -> 121 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 142, 120, 121 },
      -1,
   } },

   /* ('b2f16', 'a@32') => ('b16csel', ('i2i16', 'a'), 1.0, 0.0) */
   /* search48_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f16,
      -1, 0,
      { 65 },
      -1,
   } },

   /* replace48_0_0 -> 65 in the cache */
   /* replace48_0 -> 142 in the cache */
   /* replace48_1 -> 121 in the cache */
   /* replace48_2 -> 120 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b16csel,
      -1, 0,
      { 142, 121, 120 },
      -1,
   } },

   /* ('b2f32', ('inot', 'a@32')) => ('b32csel', 'a', 0.0, 1.0) */
   /* search49_0_0 -> 65 in the cache */
   /* search49_0 -> 140 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 140 },
      -1,
   } },

   /* replace49_0 -> 65 in the cache */
   /* replace49_1 -> 126 in the cache */
   /* replace49_2 -> 127 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 65, 126, 127 },
      -1,
   } },

   /* ('b2f32', 'a@32') => ('b32csel', 'a', 1.0, 0.0) */
   /* search50_0 -> 65 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_b2f32,
      -1, 0,
      { 65 },
      -1,
   } },

   /* replace50_0 -> 65 in the cache */
   /* replace50_1 -> 127 in the cache */
   /* replace50_2 -> 126 in the cache */
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_b32csel,
      -1, 0,
      { 65, 127, 126 },
      -1,
   } },

   /* ('ldexp', 'a@16', 'b') => ('ldexp16_pan', 'a', ('i2i16', ('imin', ('imax', 'b', -127), 127))) */
   /* search51_0 -> 47 in the cache */
   /* search51_1 -> 77 in the cache */
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ldexp,
      -1, 0,
      { 47, 77 },
      -1,
   } },

   /* replace51_0 -> 47 in the cache */
   /* replace51_1_0_0_0 -> 77 in the cache */
   { .constant = {
      { nir_search_value_constant, 32 },
      nir_type_int, { 0xffffffffffffff81ull /* -127 */ },
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_imax,
      1, 1,
      { 77, 151 },
      -1,
   } },
   { .constant = {
      { nir_search_value_constant, 32 },
      nir_type_int, { 0x7full /* 127 */ },
   } },
   { .expression = {
      { nir_search_value_expression, 32 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      true,
      -1,
      nir_op_imin,
      0, 2,
      { 152, 153 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_i2i16,
      -1, 2,
      { 154 },
      -1,
   } },
   { .expression = {
      { nir_search_value_expression, 16 },
      nir_fp_fast_math,
      nir_fp_fast_math,
      false,
      -1,
      nir_op_ldexp16_pan,
      -1, 2,
      { 47, 155 },
      -1,
   } },

};



static const struct transform bifrost_nir_lower_algebraic_late_transforms[] = {
   { ~0, ~0, ~0 }, /* Sentinel */

   { 2, 3, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 12, 13, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 23, 25, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 26, 27, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 28, 30, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 31, 32, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 33, 35, 0 },
   { 72, 74, 1 },
   { 82, 83, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 36, 38, 0 },
   { 75, 76, 1 },
   { 84, 85, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 40, 43, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 44, 46, 1 },
   { 48, 50, 1 },
   { 57, 60, 1 },
   { 66, 68, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 51, 53, 1 },
   { 54, 56, 1 },
   { 61, 64, 1 },
   { 69, 71, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 78, 81, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 86, 89, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 90, 21, 0 },
   { 91, 47, 0 },
   { 92, 65, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 95, 99, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 100, 102, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 103, 105, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 106, 108, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 109, 113, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 114, 116, 1 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 123, 124, 0 },
   { 129, 130, 0 },
   { 134, 135, 0 },
   { 138, 139, 0 },
   { 144, 145, 0 },
   { 148, 149, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 150, 156, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 10, 8, 0 },
   { 12, 13, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 7, 8, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 18, 20, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

   { 118, 122, 0 },
   { 123, 124, 0 },
   { 125, 128, 0 },
   { 129, 130, 0 },
   { 132, 133, 0 },
   { 134, 135, 0 },
   { 136, 137, 0 },
   { 138, 139, 0 },
   { 141, 143, 0 },
   { 144, 145, 0 },
   { 146, 147, 0 },
   { 148, 149, 0 },
   { ~0, ~0, ~0 }, /* Sentinel */

};

static const struct per_op_table bifrost_nir_lower_algebraic_late_pass_op_table[nir_num_search_ops] = {
   [nir_op_fmul] = {
      .filter = (const uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         0,
         2,
         2,
         2,
      },
   },
   [nir_op_fmin] = {
      .filter = (const uint16_t []) {
         0,
         1,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 3,
      .table = (const uint16_t []) {
      
         0,
         3,
         0,
         3,
         3,
         28,
         0,
         28,
         0,
      },
   },
   [nir_op_fmax] = {
      .filter = (const uint16_t []) {
         0,
         1,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
      },
      
      .num_filtered_states = 3,
      .table = (const uint16_t []) {
      
         0,
         4,
         0,
         4,
         4,
         27,
         0,
         27,
         0,
      },
   },
   [nir_op_b32csel] = {
      .filter = (const uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         0,
         0,
         29,
         29,
         0,
         0,
         29,
         29,
      },
   },
   [nir_op_iadd] = {
      .filter = (const uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         0,
         5,
         5,
         5,
      },
   },
   [nir_op_imin] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         6,
      },
   },
   [nir_op_imax] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         7,
      },
   },
   [nir_op_umin] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         8,
      },
   },
   [nir_op_umax] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         9,
      },
   },
   [nir_search_op_f2i] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         10,
      },
   },
   [nir_search_op_f2u] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         11,
      },
   },
   [nir_op_unpack_64_2x32] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         12,
      },
   },
   [nir_search_op_i2f] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         13,
      },
   },
   [nir_search_op_u2f] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         14,
      },
   },
   [nir_op_pack_half_2x16_split] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         15,
      },
   },
   [nir_op_ffract] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         16,
      },
   },
   [nir_search_op_i2i] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         17,
      },
   },
   [nir_op_ilt8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         18,
      },
   },
   [nir_op_ige8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         19,
      },
   },
   [nir_op_ieq8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         20,
      },
   },
   [nir_op_ine8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         21,
      },
   },
   [nir_op_ult8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         22,
      },
   },
   [nir_op_uge8] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         23,
      },
   },
   [nir_search_op_b2f] = {
      .filter = (const uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (const uint16_t []) {
      
         24,
         30,
      },
   },
   [nir_op_inot] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         25,
      },
   },
   [nir_op_ldexp] = {
      .filter = NULL,
      
      .num_filtered_states = 1,
      .table = (const uint16_t []) {
      
         26,
      },
   },
};

/* Mapping from state index to offset in transforms (0 being no transforms) */
static const uint16_t bifrost_nir_lower_algebraic_late_transform_offsets[] = {
   0,
   0,
   1,
   0,
   3,
   0,
   5,
   7,
   9,
   11,
   13,
   17,
   21,
   23,
   28,
   33,
   35,
   37,
   41,
   43,
   45,
   47,
   49,
   51,
   53,
   0,
   60,
   62,
   65,
   67,
   69,
};

static const nir_algebraic_table bifrost_nir_lower_algebraic_late_table = {
   .transforms = bifrost_nir_lower_algebraic_late_transforms,
   .transform_offsets = bifrost_nir_lower_algebraic_late_transform_offsets,
   .pass_op_table = bifrost_nir_lower_algebraic_late_pass_op_table,
   .values = bifrost_nir_lower_algebraic_late_values,
   .expression_cond = NULL,
   .variable_cond = NULL,
};

bool
bifrost_nir_lower_algebraic_late(
   nir_shader *shader
   , unsigned  gpu_arch
) {
   bool progress = false;
   bool condition_flags[2];
   const nir_shader_compiler_options *options = shader->options;
   const shader_info *info = &shader->info;
   (void) options;
   (void) info;

   STATIC_ASSERT(157 == ARRAY_SIZE(bifrost_nir_lower_algebraic_late_values));
   condition_flags[0] = true;
   condition_flags[1] = gpu_arch >= 11;

   nir_foreach_function_impl(impl, shader) {
     progress |= nir_algebraic_impl(impl, condition_flags, &bifrost_nir_lower_algebraic_late_table);
   }

   return progress;
}

