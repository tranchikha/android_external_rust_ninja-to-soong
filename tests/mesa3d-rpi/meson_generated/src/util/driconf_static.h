/* Copyright (C) 2021 Google, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

struct driconf_option {
    const char *name;
    const char *value;
};

struct driconf_application {
    const char *name;
    const char *executable;
    const char *executable_regexp;
    const char *blake3;
    const char *application_name_match;
    const char *application_versions;
    unsigned num_options;
    const struct driconf_option *options;
};

struct driconf_engine {
    const char *engine_name_match;
    const char *engine_versions;
    unsigned num_options;
    const struct driconf_option *options;
};

struct driconf_device {
    const char *driver;
    const char *device;
    unsigned num_engines;
    const struct driconf_engine *engines;
    unsigned num_applications;
    const struct driconf_application *applications;
};



    
static const struct driconf_option engine_403_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};


static const struct driconf_engine device_1_engines[] = {
    { .engine_name_match = "UnrealEngine4.*",
      .engine_versions = "0:23",
      .num_options = 1,
      .options = engine_403_options,
    },
};

    
static const struct driconf_option application_2_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_4_options[] = {
    { .name = "force_glsl_extensions_warn", .value = "true" },
    { .name = "disable_blend_func_extended", .value = "true" },
    { .name = "disable_arb_gpu_shader5", .value = "true" },
};

    
static const struct driconf_option application_8_options[] = {
    { .name = "force_glsl_extensions_warn", .value = "true" },
    { .name = "disable_blend_func_extended", .value = "true" },
    { .name = "disable_arb_gpu_shader5", .value = "true" },
};

    
static const struct driconf_option application_12_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_15_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_18_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_21_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_24_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_27_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_30_options[] = {
    { .name = "disable_blend_func_extended", .value = "true" },
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_33_options[] = {
    { .name = "disable_blend_func_extended", .value = "true" },
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_36_options[] = {
    { .name = "disable_glsl_line_continuations", .value = "true" },
};

    
static const struct driconf_option application_38_options[] = {
    { .name = "disable_uniform_array_resize", .value = "true" },
};

    
static const struct driconf_option application_40_options[] = {
    { .name = "always_have_depth_buffer", .value = "true" },
};

    
static const struct driconf_option application_42_options[] = {
    { .name = "always_have_depth_buffer", .value = "true" },
};

    
static const struct driconf_option application_44_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
};

    
static const struct driconf_option application_47_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
};

    
static const struct driconf_option application_49_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
    { .name = "force_glsl_extensions_warn", .value = "true" },
};

    
static const struct driconf_option application_52_options[] = {
    { .name = "disable_uniform_array_resize", .value = "true" },
};

    
static const struct driconf_option application_54_options[] = {
    { .name = "disable_uniform_array_resize", .value = "true" },
    { .name = "alias_shader_extension", .value = "GL_ATI_shader_texture_lod:GL_ARB_shader_texture_lod" },
    { .name = "allow_vertex_texture_bias", .value = "true" },
};

    
static const struct driconf_option application_58_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_60_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
    { .name = "dual_color_blend_by_location", .value = "true" },
};

    
static const struct driconf_option application_63_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_65_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
};

    
static const struct driconf_option application_67_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
    { .name = "force_gl_map_buffer_synchronized", .value = "true" },
};

    
static const struct driconf_option application_70_options[] = {
    { .name = "allow_glsl_builtin_variable_redeclaration", .value = "true" },
    { .name = "force_gl_map_buffer_synchronized", .value = "true" },
};

    
static const struct driconf_option application_73_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_75_options[] = {
    { .name = "force_gl_depth_component_type_int", .value = "true" },
};

    
static const struct driconf_option application_77_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_79_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_81_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_83_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
    { .name = "force_gl_vendor", .value = "ATI Technologies, Inc." },
};

    
static const struct driconf_option application_87_options[] = {
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_89_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_91_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_93_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_95_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_97_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_99_options[] = {
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_101_options[] = {
    { .name = "force_explicit_uniform_loc_zero", .value = "fQualityFactor" },
    { .name = "force_compat_profile", .value = "true" },
};

    
static const struct driconf_option application_104_options[] = {
    { .name = "force_compat_shaders", .value = "true" },
};

    
static const struct driconf_option application_106_options[] = {
    { .name = "force_compat_shaders", .value = "true" },
};

    
static const struct driconf_option application_108_options[] = {
    { .name = "force_glsl_version", .value = "440" },
};

    
static const struct driconf_option application_110_options[] = {
    { .name = "force_glsl_abs_sqrt", .value = "true" },
};

    
static const struct driconf_option application_112_options[] = {
    { .name = "force_glsl_abs_sqrt", .value = "true" },
};

    
static const struct driconf_option application_114_options[] = {
    { .name = "force_compat_shaders", .value = "true" },
    { .name = "glx_clear_context_reset_isolation_bit", .value = "true" },
};

    
static const struct driconf_option application_117_options[] = {
    { .name = "force_compat_profile", .value = "true" },
};

    
static const struct driconf_option application_119_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_121_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_123_options[] = {
    { .name = "force_glsl_version", .value = "130" },
    { .name = "glsl_ignore_write_to_readonly_var", .value = "true" },
};

    
static const struct driconf_option application_126_options[] = {
    { .name = "allow_glsl_embedded_structure_declarations", .value = "true" },
};

    
static const struct driconf_option application_128_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_130_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_132_options[] = {
    { .name = "allow_glsl_cross_stage_interpolation_mismatch", .value = "true" },
};

    
static const struct driconf_option application_134_options[] = {
    { .name = "allow_glsl_cross_stage_interpolation_mismatch", .value = "true" },
};

    
static const struct driconf_option application_136_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_138_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_140_options[] = {
    { .name = "allow_glsl_cross_stage_interpolation_mismatch", .value = "true" },
};

    
static const struct driconf_option application_142_options[] = {
    { .name = "allow_glsl_cross_stage_interpolation_mismatch", .value = "true" },
};

    
static const struct driconf_option application_144_options[] = {
    { .name = "allow_glsl_cross_stage_interpolation_mismatch", .value = "true" },
};

    
static const struct driconf_option application_146_options[] = {
    { .name = "allow_glsl_builtin_const_expression", .value = "true" },
    { .name = "allow_glsl_relaxed_es", .value = "true" },
};

    
static const struct driconf_option application_149_options[] = {
    { .name = "allow_extra_pp_tokens", .value = "true" },
};

    
static const struct driconf_option application_151_options[] = {
    { .name = "force_compat_profile", .value = "true" },
};

    
static const struct driconf_option application_153_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_155_options[] = {
    { .name = "force_compat_profile", .value = "true" },
};

    
static const struct driconf_option application_157_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_159_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_161_options[] = {
    { .name = "force_integer_tex_nearest", .value = "true" },
};

    
static const struct driconf_option application_163_options[] = {
    { .name = "force_integer_tex_nearest", .value = "true" },
};

    
static const struct driconf_option application_165_options[] = {
    { .name = "vs_position_always_invariant", .value = "true" },
};

    
static const struct driconf_option application_167_options[] = {
    { .name = "force_integer_tex_nearest", .value = "true" },
};

    
static const struct driconf_option application_169_options[] = {
    { .name = "lower_depth_range_rate", .value = "0.8" },
};

    
static const struct driconf_option application_171_options[] = {
    { .name = "lower_depth_range_rate", .value = "0.8" },
};

    
static const struct driconf_option application_173_options[] = {
    { .name = "allow_multisampled_copyteximage", .value = "true" },
    { .name = "vertex_program_default_out", .value = "true" },
};

    
static const struct driconf_option application_176_options[] = {
    { .name = "allow_multisampled_copyteximage", .value = "true" },
    { .name = "vertex_program_default_out", .value = "true" },
};

    
static const struct driconf_option application_179_options[] = {
    { .name = "vblank_mode", .value = "0" },
    { .name = "glthread_nop_check_framebuffer_status", .value = "true" },
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
    { .name = "force_gl_vendor", .value = "NVIDIA Corporation" },
    { .name = "force_glsl_extensions_warn", .value = "true" },
    { .name = "mesa_no_error", .value = "true" },
    { .name = "allow_rgb10_configs", .value = "false" },
    { .name = "allow_invalid_glx_destroy_window", .value = "true" },
    { .name = "allow_rgb16_configs", .value = "false" },
};

    
static const struct driconf_option application_190_options[] = {
    { .name = "ignore_map_unsynchronized", .value = "true" },
};

    
static const struct driconf_option application_192_options[] = {
    { .name = "force_integer_tex_nearest", .value = "true" },
    { .name = "allow_glsl_extension_directive_midshader", .value = "true" },
};

    
static const struct driconf_option application_195_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_197_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_199_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_201_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_203_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_205_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_207_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_209_options[] = {
    { .name = "allow_glsl_120_subset_in_110", .value = "true" },
};

    
static const struct driconf_option application_211_options[] = {
    { .name = "mesa_extension_override", .value = "-GL_MESA_pack_invert -GL_MESA_framebuffer_flip_y -GL_MESA_window_pos" },
};

    
static const struct driconf_option application_213_options[] = {
    { .name = "mesa_extension_override", .value = "-GL_MESA_pack_invert -GL_MESA_framebuffer_flip_y -GL_MESA_window_pos" },
    { .name = "do_dce_before_clip_cull_analysis", .value = "true" },
};

    
static const struct driconf_option application_216_options[] = {
    { .name = "mesa_extension_override", .value = "-GL_MESA_pack_invert -GL_MESA_framebuffer_flip_y -GL_MESA_window_pos" },
};

    
static const struct driconf_option application_218_options[] = {
    { .name = "force_glsl_extensions_warn", .value = "true" },
};

    
static const struct driconf_option application_220_options[] = {
    { .name = "force_direct_glx_context", .value = "true" },
};

    
static const struct driconf_option application_222_options[] = {
    { .name = "keep_native_window_glx_drawable", .value = "true" },
    { .name = "allow_rgb10_configs", .value = "false" },
};

    
static const struct driconf_option application_225_options[] = {
    { .name = "force_gl_vendor", .value = "ATI Technologies Inc." },
};

    
static const struct driconf_option application_227_options[] = {
    { .name = "force_compat_shaders", .value = "true" },
};

    
static const struct driconf_option application_229_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
};

    
static const struct driconf_option application_231_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_234_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_237_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_240_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_243_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_246_options[] = {
    { .name = "vk_wsi_force_swapchain_to_current_extent", .value = "true" },
    { .name = "vk_x11_ignore_suboptimal", .value = "true" },
};

    
static const struct driconf_option application_249_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
};

    
static const struct driconf_option application_251_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
};

    
static const struct driconf_option application_253_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
};

    
static const struct driconf_option application_255_options[] = {
    { .name = "adaptive_sync", .value = "false" },
    { .name = "v3d_nonmsaa_texture_size_limit", .value = "true" },
};

    
static const struct driconf_option application_258_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_260_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_262_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_264_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_266_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_268_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_270_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_272_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_274_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_276_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_278_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_280_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_282_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_284_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_286_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_288_options[] = {
    { .name = "adaptive_sync", .value = "false" },
    { .name = "v3d_nonmsaa_texture_size_limit", .value = "true" },
};

    
static const struct driconf_option application_291_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_293_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_295_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_297_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_299_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_301_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_303_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_305_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_307_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_309_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_311_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_313_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_315_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_317_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_319_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_321_options[] = {
    { .name = "adaptive_sync", .value = "false" },
};

    
static const struct driconf_option application_323_options[] = {
    { .name = "v3d_nonmsaa_texture_size_limit", .value = "true" },
};

    
static const struct driconf_option application_325_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
    { .name = "vk_x11_override_min_image_count", .value = "2" },
    { .name = "vk_wsi_force_bgra8_unorm_first", .value = "true" },
};

    
static const struct driconf_option application_329_options[] = {
    { .name = "vk_x11_override_min_image_count", .value = "2" },
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_332_options[] = {
    { .name = "vk_x11_override_min_image_count", .value = "2" },
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_335_options[] = {
    { .name = "vk_x11_override_min_image_count", .value = "3" },
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_338_options[] = {
    { .name = "glx_extension_override", .value = "-GLX_OML_swap_method" },
    { .name = "allow_higher_compat_version", .value = "true" },
};

    
static const struct driconf_option application_341_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_343_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_345_options[] = {
    { .name = "vs_position_always_precise", .value = "true" },
};

    
static const struct driconf_option application_347_options[] = {
    { .name = "vs_position_always_precise", .value = "true" },
};

    
static const struct driconf_option application_349_options[] = {
    { .name = "vs_position_always_precise", .value = "true" },
};

    
static const struct driconf_option application_351_options[] = {
    { .name = "vs_position_always_precise", .value = "true" },
};

    
static const struct driconf_option application_353_options[] = {
    { .name = "glsl_zero_init", .value = "true" },
};

    
static const struct driconf_option application_355_options[] = {
    { .name = "ignore_discard_framebuffer", .value = "true" },
};

    
static const struct driconf_option application_357_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_359_options[] = {
    { .name = "vk_x11_ensure_min_image_count", .value = "true" },
};

    
static const struct driconf_option application_361_options[] = {
    { .name = "vk_zero_vram", .value = "true" },
};

    
static const struct driconf_option application_363_options[] = {
    { .name = "vk_zero_vram", .value = "true" },
};

    
static const struct driconf_option application_365_options[] = {
    { .name = "vk_zero_vram", .value = "true" },
};

    
static const struct driconf_option application_367_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_369_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_371_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_373_options[] = {
    { .name = "vk_dont_care_as_load", .value = "true" },
};

    
static const struct driconf_option application_375_options[] = {
    { .name = "vk_dont_care_as_load", .value = "true" },
};

    
static const struct driconf_option application_377_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_379_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_381_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_383_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_385_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_387_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_389_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_391_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_393_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_395_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_397_options[] = {
    { .name = "no_fp16", .value = "true" },
};

    
static const struct driconf_option application_399_options[] = {
    { .name = "vk_x11_strict_image_count", .value = "true" },
};

    
static const struct driconf_option application_401_options[] = {
    { .name = "wgl_require_gdi_compat", .value = "true" },
};


static const struct driconf_application device_1_applications[] = {
    { .name = "Akka Arrh",
      .executable = "Project-A.exe",
      .num_options = 1,
      .options = application_2_options,
    },
    { .name = "Unigine Sanctuary",
      .executable = "Sanctuary",
      .num_options = 3,
      .options = application_4_options,
    },
    { .name = "Unigine Tropics",
      .executable = "Tropics",
      .num_options = 3,
      .options = application_8_options,
    },
    { .name = "Unigine Heaven (32-bit)",
      .executable = "heaven_x86",
      .num_options = 2,
      .options = application_12_options,
    },
    { .name = "Unigine Heaven (64-bit)",
      .executable = "heaven_x64",
      .num_options = 2,
      .options = application_15_options,
    },
    { .name = "Unigine Heaven (Windows)",
      .executable = "heaven.exe",
      .num_options = 2,
      .options = application_18_options,
    },
    { .name = "Unigine Valley (32-bit)",
      .executable = "valley_x86",
      .num_options = 2,
      .options = application_21_options,
    },
    { .name = "Unigine Valley (64-bit)",
      .executable = "valley_x64",
      .num_options = 2,
      .options = application_24_options,
    },
    { .name = "Unigine Valley (Windows)",
      .executable = "valley.exe",
      .num_options = 2,
      .options = application_27_options,
    },
    { .name = "Unigine OilRush (32-bit)",
      .executable = "OilRush_x86",
      .num_options = 2,
      .options = application_30_options,
    },
    { .name = "Unigine OilRush (64-bit)",
      .executable = "OilRush_x64",
      .num_options = 2,
      .options = application_33_options,
    },
    { .name = "Savage 2",
      .executable = "savage2.bin",
      .num_options = 1,
      .options = application_36_options,
    },
    { .name = "Team Fortress 2",
      .executable = "tf_linux64",
      .num_options = 1,
      .options = application_38_options,
    },
    { .name = "Topogun (32-bit)",
      .executable = "topogun32",
      .num_options = 1,
      .options = application_40_options,
    },
    { .name = "Topogun (64-bit)",
      .executable = "topogun64",
      .num_options = 1,
      .options = application_42_options,
    },
    { .name = "Dead Island (incl. Definitive Edition)",
      .executable = "DeadIslandGame",
      .num_options = 2,
      .options = application_44_options,
    },
    { .name = "Dead Island Riptide Definitive Edition",
      .executable = "DeadIslandRiptideGame",
      .num_options = 1,
      .options = application_47_options,
    },
    { .name = "Doom 3: BFG",
      .executable = "Doom3BFG.exe",
      .num_options = 2,
      .options = application_49_options,
    },
    { .name = "Dune: Spice Wars",
      .executable = "D4X.exe",
      .num_options = 1,
      .options = application_52_options,
    },
    { .name = "The Chronicles of Riddick: Assault on Dark Athena",
      .executable = "DarkAthena.exe",
      .num_options = 3,
      .options = application_54_options,
    },
    { .name = "Cursemark",
      .executable = "Cursemark.exe",
      .num_options = 1,
      .options = application_58_options,
    },
    { .name = "Dying Light",
      .executable = "DyingLightGame",
      .num_options = 2,
      .options = application_60_options,
    },
    { .name = "Exanima",
      .executable = "Exanima.exe",
      .num_options = 1,
      .options = application_63_options,
    },
    { .name = "Full Bore",
      .executable = "fullbore",
      .num_options = 1,
      .options = application_65_options,
    },
    { .name = "RAGE (64-bit)",
      .executable = "Rage64.exe",
      .num_options = 2,
      .options = application_67_options,
    },
    { .name = "RAGE (32-bit)",
      .executable = "Rage.exe",
      .num_options = 2,
      .options = application_70_options,
    },
    { .name = "Second Life",
      .executable = "do-not-directly-run-secondlife-bin",
      .num_options = 1,
      .options = application_73_options,
    },
    { .name = "TombRaider 4-5-6 Remastered",
      .executable = "tomb456.exe",
      .num_options = 1,
      .options = application_75_options,
    },
    { .name = "Warsow (32-bit)",
      .executable = "warsow.i386",
      .num_options = 1,
      .options = application_77_options,
    },
    { .name = "Warsow (64-bit)",
      .executable = "warsow.x86_64",
      .num_options = 1,
      .options = application_79_options,
    },
    { .name = "Rust",
      .executable = "rust",
      .num_options = 1,
      .options = application_81_options,
    },
    { .name = "Divinity: Original Sin Enhanced Edition",
      .executable = "EoCApp",
      .num_options = 3,
      .options = application_83_options,
    },
    { .name = "Metro 2033 Redux / Metro Last Night Redux",
      .executable = "metro",
      .num_options = 1,
      .options = application_87_options,
    },
    { .name = "Worms W.M.D",
      .executable = "Worms W.M.Dx64",
      .num_options = 1,
      .options = application_89_options,
    },
    { .name = "Crookz - The Big Heist",
      .executable = "Crookz",
      .num_options = 1,
      .options = application_91_options,
    },
    { .name = "Tropico 5",
      .executable = "Tropico5",
      .num_options = 1,
      .options = application_93_options,
    },
    { .name = "Faster than Light (32-bit)",
      .executable = "FTL.x86",
      .num_options = 1,
      .options = application_95_options,
    },
    { .name = "Faster than Light (64-bit)",
      .executable = "FTL.amd64",
      .num_options = 1,
      .options = application_97_options,
    },
    { .name = "Final Fantasy VIII: Remastered",
      .executable = "FFVIII.exe",
      .num_options = 1,
      .options = application_99_options,
    },
    { .name = "Lethis - Path Of Progress",
      .executable = "Lethis-Path_Of_Progress.exe",
      .num_options = 2,
      .options = application_101_options,
    },
    { .name = "SNK HEROINES Tag Team Frenzy",
      .executable = "SNKHEROINES.exe",
      .num_options = 1,
      .options = application_104_options,
    },
    { .name = "Metal Slug XX",
      .executable = "MSXX_main.exe",
      .num_options = 1,
      .options = application_106_options,
    },
    { .name = "The Culling",
      .executable = "Victory",
      .num_options = 1,
      .options = application_108_options,
    },
    { .name = "Spec Ops: The Line (32-bit)",
      .executable = "specops.i386",
      .num_options = 1,
      .options = application_110_options,
    },
    { .name = "Spec Ops: The Line (64-bit)",
      .executable = "specops",
      .num_options = 1,
      .options = application_112_options,
    },
    { .name = "Interstellar Rift",
      .executable = "IR.exe",
      .num_options = 2,
      .options = application_114_options,
    },
    { .name = "Jamestown+",
      .executable = "JamestownPlus.exe",
      .num_options = 1,
      .options = application_117_options,
    },
    { .name = "Kerbal Space Program (32-bit)",
      .executable = "KSP.x86",
      .num_options = 1,
      .options = application_119_options,
    },
    { .name = "Kerbal Space Program (64-bit)",
      .executable = "KSP.x86_64",
      .num_options = 1,
      .options = application_121_options,
    },
    { .name = "Luna Sky",
      .executable = "lunasky",
      .num_options = 2,
      .options = application_123_options,
    },
    { .name = "MDK2 HD",
      .executable = "mdk2hd.exe",
      .num_options = 1,
      .options = application_126_options,
    },
    { .name = "Rocket League",
      .executable = "RocketLeague",
      .num_options = 1,
      .options = application_128_options,
    },
    { .name = "The Witcher 2",
      .executable = "witcher2",
      .num_options = 1,
      .options = application_130_options,
    },
    { .name = "Unreal 4 Editor",
      .executable = "UE4Editor",
      .num_options = 1,
      .options = application_132_options,
    },
    { .name = "Observer",
      .executable = "TheObserver-Linux-Shipping",
      .num_options = 1,
      .options = application_134_options,
    },
    { .name = "Pixel Game Maker MV",
      .executable = "player.exe",
      .num_options = 1,
      .options = application_136_options,
    },
    { .name = "Eden Gamma",
      .executable = "EdenGammaGame-0.3.0.2.exe",
      .num_options = 1,
      .options = application_138_options,
    },
    { .name = "Steamroll",
      .executable = "Steamroll-Linux-Shipping",
      .num_options = 1,
      .options = application_140_options,
    },
    { .name = "Refunct",
      .executable = "Refunct-Linux-Shipping",
      .num_options = 1,
      .options = application_142_options,
    },
    { .name = "We Happy Few",
      .executable = "GlimpseGame",
      .num_options = 1,
      .options = application_144_options,
    },
    { .name = "Google Earth VR",
      .executable = "Earth.exe",
      .num_options = 2,
      .options = application_146_options,
    },
    { .name = "Champions of Regnum",
      .executable = "game",
      .num_options = 1,
      .options = application_149_options,
    },
    { .name = "Wolfenstein The Old Blood",
      .executable = "WolfOldBlood_x64.exe",
      .num_options = 1,
      .options = application_151_options,
    },
    { .name = "ARMA 3",
      .executable = "arma3.x86_64",
      .num_options = 1,
      .options = application_153_options,
    },
    { .name = "Epic Games Launcher",
      .executable = "EpicGamesLauncher.exe",
      .num_options = 1,
      .options = application_155_options,
    },
    { .name = "GpuTest",
      .executable = "GpuTest",
      .num_options = 1,
      .options = application_157_options,
    },
    { .name = "Curse of the Dead Gods",
      .executable = "Curse of the Dead Gods.exe",
      .num_options = 1,
      .options = application_159_options,
    },
    { .name = "GRID Autosport",
      .executable = "GridAutosport",
      .num_options = 1,
      .options = application_161_options,
    },
    { .name = "DIRT: Showdown",
      .executable = "dirt.i386",
      .num_options = 1,
      .options = application_163_options,
    },
    { .name = "DiRT Rally",
      .executable = "DirtRally",
      .num_options = 1,
      .options = application_165_options,
    },
    { .name = "Foundation",
      .executable = "foundation.exe",
      .num_options = 1,
      .options = application_167_options,
    },
    { .name = "Homerun Clash",
      .executable = "com.haegin.homerunclash",
      .num_options = 1,
      .options = application_169_options,
    },
    { .name = "The Spirit and The Mouse",
      .executable = "TheSpiritAndTheMouse.exe",
      .num_options = 1,
      .options = application_171_options,
    },
    { .name = "Penumbra: Overture (Windows)",
      .executable = "Penumbra.exe",
      .num_options = 2,
      .options = application_173_options,
    },
    { .name = "Penumbra: Overture",
      .executable = "penumbra.bin",
      .num_options = 2,
      .options = application_176_options,
    },
    { .name = "SPECviewperf13",
      .executable = "viewperf",
      .num_options = 10,
      .options = application_179_options,
    },
    { .name = "Dead-Cells",
      .executable = "com.playdigious.deadcells.mobile",
      .num_options = 1,
      .options = application_190_options,
    },
    { .name = "Teardown",
      .executable = "teardown.exe",
      .num_options = 2,
      .options = application_192_options,
    },
    { .name = "Golf With Your Friends",
      .executable = "Golf With Your Friends.x86_64",
      .num_options = 1,
      .options = application_195_options,
    },
    { .name = "Cossacks 3",
      .executable = "cossacks.exe",
      .num_options = 1,
      .options = application_197_options,
    },
    { .name = "Kaiju-A-Gogo",
      .executable = "kaiju.exe",
      .num_options = 1,
      .options = application_199_options,
    },
    { .name = "Captain Lycop: Invasion of the Heters (Wine)",
      .executable = "lycop.exe",
      .num_options = 1,
      .options = application_201_options,
    },
    { .name = "Captain Lycop: Invasion of the Heters",
      .executable = "lycop",
      .num_options = 1,
      .options = application_203_options,
    },
    { .name = "Joe Danger (Wine)",
      .executable = "JoeDanger.exe",
      .num_options = 1,
      .options = application_205_options,
    },
    { .name = "Joe Danger 2 (Wine)",
      .executable = "JoeDanger2.exe",
      .num_options = 1,
      .options = application_207_options,
    },
    { .name = "Investigation Stories : gunsound (Wine)",
      .executable = "gunsound.exe",
      .num_options = 1,
      .options = application_209_options,
    },
    { .name = "BETA CAE Systems - GL detect tool",
      .executable = "detect_opengl_tool",
      .num_options = 1,
      .options = application_211_options,
    },
    { .name = "BETA CAE Systems - ANSA",
      .executable = "ansa_linux_x86_64",
      .num_options = 2,
      .options = application_213_options,
    },
    { .name = "BETA CAE Systems - META",
      .executable = "meta_post_x86_64",
      .num_options = 1,
      .options = application_216_options,
    },
    { .name = "Mari",
      .executable_regexp = "Mari[0-9]+[.][0-9]+v[0-9]+",
      .num_options = 1,
      .options = application_218_options,
    },
    { .name = "Discovery Studio 2020",
      .executable = "DiscoveryStudio2020-bin",
      .num_options = 1,
      .options = application_220_options,
    },
    { .name = "Abaqus",
      .executable = "ABQcaeK",
      .num_options = 2,
      .options = application_222_options,
    },
    { .name = "Maya",
      .executable = "maya.bin",
      .num_options = 1,
      .options = application_225_options,
    },
    { .name = "SD Gundam G Generation Cross Rays",
      .executable = "togg.exe",
      .num_options = 1,
      .options = application_227_options,
    },
    { .name = "FINAL FANTASY XI",
      .executable = "pol.exe",
      .num_options = 1,
      .options = application_229_options,
    },
    { .name = "Talos Principle",
      .executable = "Talos",
      .num_options = 2,
      .options = application_231_options,
    },
    { .name = "Talos Principle (Unrestricted)",
      .executable = "Talos_Unrestricted",
      .num_options = 2,
      .options = application_234_options,
    },
    { .name = "Talos Principle VR",
      .executable = "Talos_VR",
      .num_options = 2,
      .options = application_237_options,
    },
    { .name = "Talos Principle VR (Unrestricted)",
      .executable = "Talos_Unrestricted_VR",
      .num_options = 2,
      .options = application_240_options,
    },
    { .name = "Serious Sam Fusion",
      .executable = "Sam2017",
      .num_options = 2,
      .options = application_243_options,
    },
    { .name = "Serious Sam Fusion (Unrestricted)",
      .executable = "Sam2017_Unrestricted",
      .num_options = 2,
      .options = application_246_options,
    },
    { .name = "DeusExMD",
      .executable = "DeusExMD",
      .num_options = 1,
      .options = application_249_options,
    },
    { .name = "F1 2015",
      .executable = "F12015",
      .num_options = 1,
      .options = application_251_options,
    },
    { .name = "KWin Wayland",
      .executable = "kwin_wayland",
      .num_options = 1,
      .options = application_253_options,
    },
    { .name = "gnome-shell",
      .executable = "gnome-shell",
      .num_options = 2,
      .options = application_255_options,
    },
    { .name = "Desktop — Plasma",
      .executable = "plasmashell",
      .num_options = 1,
      .options = application_258_options,
    },
    { .name = "budgie-wm",
      .executable = "budgie-wm",
      .num_options = 1,
      .options = application_260_options,
    },
    { .name = "kwin_x11",
      .executable = "kwin_x11",
      .num_options = 1,
      .options = application_262_options,
    },
    { .name = "ksmserver-logout-greeter",
      .executable = "ksmserver-logout-greeter",
      .num_options = 1,
      .options = application_264_options,
    },
    { .name = "ksmserver-switchuser-greeter",
      .executable = "ksmserver-switchuser-greeter",
      .num_options = 1,
      .options = application_266_options,
    },
    { .name = "kscreenlocker_greet",
      .executable = "kscreenlocker_greet",
      .num_options = 1,
      .options = application_268_options,
    },
    { .name = "startplasma",
      .executable = "startplasma",
      .num_options = 1,
      .options = application_270_options,
    },
    { .name = "sddm-greeter",
      .executable = "sddm-greeter",
      .num_options = 1,
      .options = application_272_options,
    },
    { .name = "krunner",
      .executable = "krunner",
      .num_options = 1,
      .options = application_274_options,
    },
    { .name = "spectacle",
      .executable = "spectacle",
      .num_options = 1,
      .options = application_276_options,
    },
    { .name = "marco",
      .executable = "marco",
      .num_options = 1,
      .options = application_278_options,
    },
    { .name = "compton",
      .executable = "compton",
      .num_options = 1,
      .options = application_280_options,
    },
    { .name = "picom",
      .executable = "picom",
      .num_options = 1,
      .options = application_282_options,
    },
    { .name = "xfwm4",
      .executable = "xfwm4",
      .num_options = 1,
      .options = application_284_options,
    },
    { .name = "Enlightenment",
      .executable = "enlightenment",
      .num_options = 1,
      .options = application_286_options,
    },
    { .name = "mutter",
      .executable = "mutter",
      .num_options = 2,
      .options = application_288_options,
    },
    { .name = "muffin",
      .executable = "muffin",
      .num_options = 1,
      .options = application_291_options,
    },
    { .name = "cinnamon",
      .executable = "cinnamon",
      .num_options = 1,
      .options = application_293_options,
    },
    { .name = "compiz",
      .executable = "compiz",
      .num_options = 1,
      .options = application_295_options,
    },
    { .name = "Firefox",
      .executable = "firefox",
      .num_options = 1,
      .options = application_297_options,
    },
    { .name = "Firefox ESR",
      .executable = "firefox-esr",
      .num_options = 1,
      .options = application_299_options,
    },
    { .name = "Chromium",
      .executable = "chromium",
      .num_options = 1,
      .options = application_301_options,
    },
    { .name = "Google Chrome",
      .executable = "chrome",
      .num_options = 1,
      .options = application_303_options,
    },
    { .name = "Iceweasel",
      .executable = "iceweasel",
      .num_options = 1,
      .options = application_305_options,
    },
    { .name = "Epiphany",
      .executable = "epiphany",
      .num_options = 1,
      .options = application_307_options,
    },
    { .name = "Konqueror",
      .executable = "konqueror",
      .num_options = 1,
      .options = application_309_options,
    },
    { .name = "Falkon",
      .executable = "falkon",
      .num_options = 1,
      .options = application_311_options,
    },
    { .name = "Seamonkey",
      .executable = "seamonkey",
      .num_options = 1,
      .options = application_313_options,
    },
    { .name = "Waterfox",
      .executable = "waterfox",
      .num_options = 1,
      .options = application_315_options,
    },
    { .name = "VLC Media Player",
      .executable = "vlc",
      .num_options = 1,
      .options = application_317_options,
    },
    { .name = "Totem",
      .executable = "totem",
      .num_options = 1,
      .options = application_319_options,
    },
    { .name = "Dragon Player",
      .executable = "dragon",
      .num_options = 1,
      .options = application_321_options,
    },
    { .name = "Xorg",
      .executable = "Xorg",
      .num_options = 1,
      .options = application_323_options,
    },
    { .name = "gfxbench",
      .executable = "testfw_app",
      .num_options = 3,
      .options = application_325_options,
    },
    { .name = "Rainbow Six Siege (Vulkan)",
      .executable = "RainbowSix_Vulkan.exe",
      .num_options = 2,
      .options = application_329_options,
    },
    { .name = "Rainbow Six Extraction (Wine)",
      .executable = "R6-Extraction.exe",
      .num_options = 2,
      .options = application_332_options,
    },
    { .name = "Hades",
      .executable = "Hades.exe",
      .num_options = 2,
      .options = application_335_options,
    },
    { .name = "Brink",
      .executable = "brink.exe",
      .num_options = 2,
      .options = application_338_options,
    },
    { .name = "Enter The Gungeon (32 bits)",
      .executable = "EtG.x86",
      .num_options = 1,
      .options = application_341_options,
    },
    { .name = "Enter The Gungeon (64 bits)",
      .executable = "EtG.x86_64",
      .num_options = 1,
      .options = application_343_options,
    },
    { .name = "Assault Android Cactus (32-bit)",
      .executable = "cactus_demo.x86",
      .num_options = 1,
      .options = application_345_options,
    },
    { .name = "Assault Android Cactus (64-bit)",
      .executable = "cactus_demo.x86_64",
      .num_options = 1,
      .options = application_347_options,
    },
    { .name = "Assault Android Cactus (32-bit)",
      .executable = "cactus.x86",
      .num_options = 1,
      .options = application_349_options,
    },
    { .name = "Assault Android Cactus (64-bit)",
      .executable = "cactus.x86_64",
      .num_options = 1,
      .options = application_351_options,
    },
    { .name = "Limbo",
      .executable = "limbo",
      .num_options = 1,
      .options = application_353_options,
    },
    { .name = "Genshin Impact",
      .executable = "com.miHoYo.GenshinImpact",
      .num_options = 1,
      .options = application_355_options,
    },
    { .name = "DOOM",
      .executable = "DOOMx64vk.exe",
      .num_options = 1,
      .options = application_357_options,
    },
    { .name = "DOOMEternal",
      .executable = "DOOMEternalx64vk.exe",
      .num_options = 1,
      .options = application_359_options,
    },
    { .name = "Path of Exile",
      .executable = "PathOfExile_x64Steam.exe",
      .num_options = 1,
      .options = application_361_options,
    },
    { .name = "Path of Exile",
      .executable = "PathOfExileSteam.exe",
      .num_options = 1,
      .options = application_363_options,
    },
    { .name = "X4 Foundations",
      .executable = "X4",
      .num_options = 1,
      .options = application_365_options,
    },
    { .name = "Wolfenstein: Youngblood(x64vk)",
      .executable = "Youngblood_x64vk.exe",
      .num_options = 1,
      .options = application_367_options,
    },
    { .name = "Wolfenstein II: The New Colossus",
      .executable = "NewColossus_x64vk.exe",
      .num_options = 1,
      .options = application_369_options,
    },
    { .name = "Metro: Exodus",
      .application_name_match = "metroexodus",
      .num_options = 1,
      .options = application_371_options,
    },
    { .name = "Forsaken Remastered",
      .executable = "ForsakenEx",
      .num_options = 1,
      .options = application_373_options,
    },
    { .name = "Spilled!",
      .executable = "Spilled!.exe",
      .num_options = 1,
      .options = application_375_options,
    },
    { .name = "Atlas Fallen",
      .executable = "AtlasFallen (VK).exe",
      .num_options = 1,
      .options = application_377_options,
    },
    { .name = "Firefox",
      .executable = "firefox",
      .num_options = 1,
      .options = application_379_options,
    },
    { .name = "Firefox ESR",
      .executable = "firefox-esr",
      .num_options = 1,
      .options = application_381_options,
    },
    { .name = "Chromium",
      .executable = "chromium",
      .num_options = 1,
      .options = application_383_options,
    },
    { .name = "Google Chrome",
      .executable = "chrome",
      .num_options = 1,
      .options = application_385_options,
    },
    { .name = "Iceweasel",
      .executable = "iceweasel",
      .num_options = 1,
      .options = application_387_options,
    },
    { .name = "Epiphany",
      .executable = "epiphany",
      .num_options = 1,
      .options = application_389_options,
    },
    { .name = "Konqueror",
      .executable = "konqueror",
      .num_options = 1,
      .options = application_391_options,
    },
    { .name = "Falkon",
      .executable = "falkon",
      .num_options = 1,
      .options = application_393_options,
    },
    { .name = "Seamonkey",
      .executable = "seamonkey",
      .num_options = 1,
      .options = application_395_options,
    },
    { .name = "Waterfox",
      .executable = "waterfox",
      .num_options = 1,
      .options = application_397_options,
    },
    { .name = "Detroit Become Human",
      .application_name_match = "DetroitBecomeHuman",
      .num_options = 1,
      .options = application_399_options,
    },
    { .name = "文香白板",
      .executable = "WxBoardMain.exe",
      .num_options = 1,
      .options = application_401_options,
    },
};

static const struct driconf_device device_1 = {
    .num_engines = 1,
    .engines = device_1_engines,
    .num_applications = 174,
    .applications = device_1_applications,
};


    
static const struct driconf_option application_406_options[] = {
    { .name = "glx_extension_override", .value = "-GLX_OML_sync_control -GLX_SGI_video_sync" },
};

    
static const struct driconf_option application_408_options[] = {
    { .name = "glx_extension_override", .value = "-GLX_OML_sync_control -GLX_SGI_video_sync" },
};

    
static const struct driconf_option application_410_options[] = {
    { .name = "glx_extension_override", .value = "-GLX_OML_sync_control" },
};


static const struct driconf_application device_405_applications[] = {
    { .name = "gnome-shell",
      .executable = "gnome-shell",
      .num_options = 1,
      .options = application_406_options,
    },
    { .name = "cinnamon",
      .executable = "cinnamon",
      .num_options = 1,
      .options = application_408_options,
    },
    { .name = "Compiz",
      .executable = "Compiz",
      .num_options = 1,
      .options = application_410_options,
    },
};

static const struct driconf_device device_405 = {
    .driver = "vmwgfx",
    .num_engines = 0,
    .num_applications = 3,
    .applications = device_405_applications,
};


    
static const struct driconf_option application_413_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};

    
static const struct driconf_option application_415_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_417_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
    { .name = "radeonsi_clamp_div_by_zero", .value = "true" },
};

    
static const struct driconf_option application_420_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_422_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_424_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_426_options[] = {
    { .name = "radeonsi_sync_compile", .value = "true" },
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_429_options[] = {
    { .name = "radeonsi_sync_compile", .value = "true" },
};

    
static const struct driconf_option application_431_options[] = {
    { .name = "radeonsi_no_infinite_interp", .value = "true" },
};

    
static const struct driconf_option application_433_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_435_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};

    
static const struct driconf_option application_437_options[] = {
    { .name = "radeonsi_sync_compile", .value = "true" },
};

    
static const struct driconf_option application_439_options[] = {
    { .name = "radeonsi_clamp_div_by_zero", .value = "true" },
};

    
static const struct driconf_option application_441_options[] = {
    { .name = "radeonsi_clamp_div_by_zero", .value = "true" },
};

    
static const struct driconf_option application_443_options[] = {
    { .name = "radeonsi_clamp_div_by_zero", .value = "true" },
    { .name = "radeonsi_no_infinite_interp", .value = "true" },
};

    
static const struct driconf_option application_446_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};

    
static const struct driconf_option application_448_options[] = {
    { .name = "force_gl_vendor", .value = "ATI Technologies Inc." },
};

    
static const struct driconf_option application_450_options[] = {
    { .name = "force_gl_vendor", .value = "ATI Technologies Inc." },
};

    
static const struct driconf_option application_452_options[] = {
    { .name = "force_gl_vendor", .value = "ATI Technologies Inc." },
    { .name = "radeonsi_force_use_fma32", .value = "true" },
};

    
static const struct driconf_option application_455_options[] = {
    { .name = "radeonsi_zerovram", .value = "true" },
};


static const struct driconf_application device_412_applications[] = {
    { .name = "Alien Isolation",
      .executable = "AlienIsolation",
      .num_options = 1,
      .options = application_413_options,
    },
    { .name = "American Truck Simulator",
      .executable = "amtrucks",
      .num_options = 1,
      .options = application_415_options,
    },
    { .name = "Counter-Strike Global Offensive",
      .executable = "csgo_linux64",
      .num_options = 2,
      .options = application_417_options,
    },
    { .name = "Exanima",
      .executable = "Exanima.exe",
      .num_options = 1,
      .options = application_420_options,
    },
    { .name = "Nowhere Patrol",
      .executable = "NowherePatrol.exe",
      .num_options = 1,
      .options = application_422_options,
    },
    { .name = "Rocket League",
      .executable = "RocketLeague",
      .num_options = 1,
      .options = application_424_options,
    },
    { .name = "any runner executable",
      .executable = "runner",
      .num_options = 2,
      .options = application_426_options,
    },
    { .name = "Gun Godz",
      .executable = "GUNGODZ",
      .num_options = 1,
      .options = application_429_options,
    },
    { .name = "Kerbal Space Program",
      .executable = "KSP.x86_64",
      .num_options = 1,
      .options = application_431_options,
    },
    { .name = "7 Days to Die",
      .executable = "7DaysToDie.x86_64",
      .num_options = 1,
      .options = application_433_options,
    },
    { .name = "7 Days to Die",
      .executable = "7DaysToDie.x86",
      .num_options = 1,
      .options = application_435_options,
    },
    { .name = "SPECviewperf13",
      .executable = "viewperf",
      .num_options = 1,
      .options = application_437_options,
    },
    { .name = "Road Redemption",
      .executable = "RoadRedemption.x86_64",
      .num_options = 1,
      .options = application_439_options,
    },
    { .name = "Wasteland 2",
      .executable = "WL2",
      .num_options = 1,
      .options = application_441_options,
    },
    { .name = "Teardown",
      .executable = "teardown.exe",
      .num_options = 2,
      .options = application_443_options,
    },
    { .name = "SpaceEngine",
      .executable = "SpaceEngine.exe",
      .num_options = 1,
      .options = application_446_options,
    },
    { .name = "BETA CAE Systems - GL detect tool",
      .executable = "detect_opengl_tool",
      .num_options = 1,
      .options = application_448_options,
    },
    { .name = "BETA CAE Systems - ANSA",
      .executable = "ansa_linux_x86_64",
      .num_options = 1,
      .options = application_450_options,
    },
    { .name = "BETA CAE Systems - META",
      .executable = "meta_post_x86_64",
      .num_options = 2,
      .options = application_452_options,
    },
    { .name = "Black Geyser: Couriers of Darkness",
      .executable = "BlackGeyser.x86_64",
      .num_options = 1,
      .options = application_455_options,
    },
};

static const struct driconf_device device_412 = {
    .driver = "radeonsi",
    .num_engines = 0,
    .num_applications = 20,
    .applications = device_412_applications,
};


    
static const struct driconf_option application_458_options[] = {
    { .name = "mesa_glthread_app_profile", .value = "0" },
};

    
static const struct driconf_option application_460_options[] = {
    { .name = "glsl_correct_derivatives_after_discard", .value = "true" },
};

    
static const struct driconf_option application_462_options[] = {
    { .name = "mesa_extension_override", .value = "+GL_EXT_shader_image_load_store" },
};

    
static const struct driconf_option application_464_options[] = {
    { .name = "zink_emulate_point_smooth", .value = "true" },
};

    
static const struct driconf_option application_466_options[] = {
    { .name = "zink_emulate_point_smooth", .value = "true" },
};

    
static const struct driconf_option application_468_options[] = {
    { .name = "zink_emulate_point_smooth", .value = "true" },
};

    
static const struct driconf_option application_470_options[] = {
    { .name = "zink_shader_object_enable", .value = "true" },
};


static const struct driconf_application device_457_applications[] = {
    { .name = "Hyperdimension Neptunia Re;Birth1",
      .executable = "NeptuniaReBirth1.exe",
      .num_options = 1,
      .options = application_458_options,
    },
    { .name = "Borderlands 2 (Native, OpenGL, 32bit)",
      .executable = "Borderlands2",
      .num_options = 1,
      .options = application_460_options,
    },
    { .name = "SPECviewperf13",
      .executable = "viewperf",
      .num_options = 1,
      .options = application_462_options,
    },
    { .name = "Quake II",
      .executable = "quake2-engine",
      .num_options = 1,
      .options = application_464_options,
    },
    { .name = "Quake II (yamagi)",
      .executable = "yamagi-quake2",
      .num_options = 1,
      .options = application_466_options,
    },
    { .name = "Quake II (wine)",
      .executable = "quake2.exe",
      .num_options = 1,
      .options = application_468_options,
    },
    { .name = "Tomb Raider 2013",
      .executable = "TombRaider",
      .num_options = 1,
      .options = application_470_options,
    },
};

static const struct driconf_device device_457 = {
    .driver = "zink",
    .num_engines = 0,
    .num_applications = 7,
    .applications = device_457_applications,
};


    
static const struct driconf_option application_473_options[] = {
    { .name = "vs_position_always_invariant", .value = "true" },
};

    
static const struct driconf_option application_475_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_477_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};

    
static const struct driconf_option application_479_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};

    
static const struct driconf_option application_481_options[] = {
    { .name = "intel_disable_threaded_context", .value = "true" },
};

    
static const struct driconf_option application_483_options[] = {
    { .name = "intel_disable_threaded_context", .value = "true" },
};

    
static const struct driconf_option application_485_options[] = {
    { .name = "mesa_extension_override", .value = "+GL_EXT_shader_image_load_store" },
};


static const struct driconf_application device_472_applications[] = {
    { .name = "Middle Earth: Shadow of Mordor",
      .executable = "ShadowOfMordor",
      .num_options = 1,
      .options = application_473_options,
    },
    { .name = "glmark2",
      .executable = "glmark2",
      .num_options = 1,
      .options = application_475_options,
    },
    { .name = "Counter-Strike: Global Offensive",
      .executable = "csgo_linux64",
      .num_options = 1,
      .options = application_477_options,
    },
    { .name = "Insurgency",
      .executable = "insurgency_linux",
      .num_options = 1,
      .options = application_479_options,
    },
    { .name = "Amnesia Bunker",
      .executable = "AmnesiaTheBunker.exe",
      .num_options = 1,
      .options = application_481_options,
    },
    { .name = "Amnesia Bunker",
      .executable = "AmnesiaTheBunker_NoSteam.exe",
      .num_options = 1,
      .options = application_483_options,
    },
    { .name = "SPECviewperf13",
      .executable = "viewperf",
      .num_options = 1,
      .options = application_485_options,
    },
};

static const struct driconf_device device_472 = {
    .driver = "iris",
    .num_engines = 0,
    .num_applications = 7,
    .applications = device_472_applications,
};


    
static const struct driconf_option application_488_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_490_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};

    
static const struct driconf_option application_492_options[] = {
    { .name = "force_gl_vendor", .value = "X.Org" },
};


static const struct driconf_application device_487_applications[] = {
    { .name = "glmark2",
      .executable = "glmark2",
      .num_options = 1,
      .options = application_488_options,
    },
    { .name = "Counter-Strike: Global Offensive",
      .executable = "csgo_linux64",
      .num_options = 1,
      .options = application_490_options,
    },
    { .name = "Insurgency",
      .executable = "insurgency_linux",
      .num_options = 1,
      .options = application_492_options,
    },
};

static const struct driconf_device device_487 = {
    .driver = "crocus",
    .num_engines = 0,
    .num_applications = 3,
    .applications = device_487_applications,
};
    
static const struct driconf_option engine_605_options[] = {
    { .name = "anv_force_filter_addr_rounding", .value = "true" },
    { .name = "anv_promote_cbv_to_push_buffers", .value = "true" },
};

    
static const struct driconf_option engine_608_options[] = {
    { .name = "anv_enable_buffer_comp", .value = "true" },
};

    
static const struct driconf_option engine_610_options[] = {
    { .name = "anv_enable_buffer_comp", .value = "true" },
};

    
static const struct driconf_option engine_612_options[] = {
    { .name = "anv_disable_drm_ccs_modifiers", .value = "true" },
};

    
static const struct driconf_option engine_614_options[] = {
    { .name = "vk_wsi_disable_unordered_submits", .value = "true" },
};

    
static const struct driconf_option engine_616_options[] = {
    { .name = "no_16bit", .value = "true" },
};

    
static const struct driconf_option engine_618_options[] = {
    { .name = "anv_disable_fcv", .value = "true" },
    { .name = "anv_assume_full_subgroups", .value = "16" },
};

    
static const struct driconf_option engine_621_options[] = {
    { .name = "compression_control_enabled", .value = "true" },
};

    
static const struct driconf_option engine_623_options[] = {
    { .name = "custom_border_colors_without_format", .value = "true" },
};

    
static const struct driconf_option engine_625_options[] = {
    { .name = "anv_state_cache_perf_fix", .value = "true" },
};


static const struct driconf_engine device_494_engines[] = {
    { .engine_name_match = "vkd3d|DXVK",
      .num_options = 2,
      .options = engine_605_options,
    },
    { .engine_name_match = "Source2",
      .num_options = 1,
      .options = engine_608_options,
    },
    { .engine_name_match = "vkd3d",
      .num_options = 1,
      .options = engine_610_options,
    },
    { .engine_name_match = "GTK",
      .num_options = 1,
      .options = engine_612_options,
    },
    { .engine_name_match = "GTK",
      .engine_versions = "16777216:16859138",
      .num_options = 1,
      .options = engine_614_options,
    },
    { .engine_name_match = "mesa zink",
      .num_options = 1,
      .options = engine_616_options,
    },
    { .engine_name_match = "UnrealEngine5.1",
      .num_options = 2,
      .options = engine_618_options,
    },
    { .engine_name_match = "vkd3d",
      .num_options = 1,
      .options = engine_621_options,
    },
    { .engine_name_match = "ANGLE",
      .num_options = 1,
      .options = engine_623_options,
    },
    { .engine_name_match = "vkd3d",
      .num_options = 1,
      .options = engine_625_options,
    },
};

    
static const struct driconf_option application_495_options[] = {
    { .name = "anv_assume_full_subgroups", .value = "32" },
};

    
static const struct driconf_option application_497_options[] = {
    { .name = "intel_storage_cache_policy_wt", .value = "true" },
};

    
static const struct driconf_option application_499_options[] = {
    { .name = "anv_assume_full_subgroups_with_barrier", .value = "true" },
};

    
static const struct driconf_option application_501_options[] = {
    { .name = "hasvk_report_vk_1_3_version", .value = "true" },
};

    
static const struct driconf_option application_503_options[] = {
    { .name = "anv_assume_full_subgroups", .value = "32" },
};

    
static const struct driconf_option application_505_options[] = {
    { .name = "anv_assume_full_subgroups", .value = "32" },
    { .name = "fp64_workaround_enabled", .value = "true" },
};

    
static const struct driconf_option application_508_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_510_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_512_options[] = {
    { .name = "anv_large_workgroup_non_coherent_image_workaround", .value = "true" },
};

    
static const struct driconf_option application_514_options[] = {
    { .name = "anv_large_workgroup_non_coherent_image_workaround", .value = "true" },
};

    
static const struct driconf_option application_516_options[] = {
    { .name = "anv_assume_full_subgroups_with_shared_memory", .value = "true" },
};

    
static const struct driconf_option application_518_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_520_options[] = {
    { .name = "anv_sample_mask_out_opengl_behaviour", .value = "true" },
};

    
static const struct driconf_option application_522_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_524_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_526_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_528_options[] = {
    { .name = "vk_lower_terminate_to_discard", .value = "true" },
};

    
static const struct driconf_option application_530_options[] = {
    { .name = "anv_disable_link_time_optimization", .value = "true" },
};

    
static const struct driconf_option application_532_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_534_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_536_options[] = {
    { .name = "limit_trig_input_range", .value = "true" },
};

    
static const struct driconf_option application_538_options[] = {
    { .name = "shader_spilling_rate", .value = "15" },
};

    
static const struct driconf_option application_540_options[] = {
    { .name = "fake_sparse", .value = "true" },
};

    
static const struct driconf_option application_542_options[] = {
    { .name = "fake_sparse", .value = "true" },
};

    
static const struct driconf_option application_544_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
    { .name = "shader_spilling_rate", .value = "0" },
};

    
static const struct driconf_option application_547_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_549_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
    { .name = "intel_storage_cache_policy_wt", .value = "true" },
};

    
static const struct driconf_option application_552_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_554_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_556_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_558_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_560_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_562_options[] = {
    { .name = "intel_storage_cache_policy_wt", .value = "true" },
};

    
static const struct driconf_option application_564_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_566_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_568_options[] = {
    { .name = "anv_disable_fcv", .value = "true" },
};

    
static const struct driconf_option application_570_options[] = {
    { .name = "anv_brw_disable_subgroup_size_control", .value = "true" },
};

    
static const struct driconf_option application_572_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_574_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_576_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_578_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_580_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_582_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_584_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_586_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_588_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_590_options[] = {
    { .name = "fp64_workaround_enabled", .value = "true" },
};

    
static const struct driconf_option application_592_options[] = {
    { .name = "anv_upper_bound_descriptor_pool_sampler", .value = "true" },
};

    
static const struct driconf_option application_594_options[] = {
    { .name = "anv_fake_nonlocal_memory", .value = "true" },
    { .name = "anv_enable_opt_divergent_atomics", .value = "1" },
};

    
static const struct driconf_option application_597_options[] = {
    { .name = "anv_enable_opt_divergent_atomics", .value = "1" },
};

    
static const struct driconf_option application_599_options[] = {
    { .name = "anv_enable_opt_divergent_atomics", .value = "1" },
};

    
static const struct driconf_option application_601_options[] = {
    { .name = "anv_enable_opt_divergent_atomics", .value = "1" },
};

    
static const struct driconf_option application_603_options[] = {
    { .name = "anv_barrier_post_untyped_clear_shader", .value = "true" },
};


static const struct driconf_application device_494_applications[] = {
    { .name = "Aperture Desk Job",
      .executable = "deskjob",
      .num_options = 1,
      .options = application_495_options,
    },
    { .name = "A Plague Tale : Requiem",
      .executable = "APlagueTaleRequiem_x64.exe",
      .num_options = 1,
      .options = application_497_options,
    },
    { .name = "Breaking Limit",
      .executable = "GPUScoreVulkan",
      .num_options = 1,
      .options = application_499_options,
    },
    { .name = "Brawlhalla",
      .executable = "BrawlhallaGame.exe",
      .num_options = 1,
      .options = application_501_options,
    },
    { .name = "Detroit: Become Human",
      .executable = "DetroitBecomeHuman.exe",
      .num_options = 1,
      .options = application_503_options,
    },
    { .name = "DOOMEternal",
      .executable = "DOOMEternalx64vk.exe",
      .num_options = 2,
      .options = application_505_options,
    },
    { .name = "Drive Beyond Horizons",
      .executable = "DriveBeyondHorizons.exe",
      .num_options = 1,
      .options = application_508_options,
    },
    { .name = "Farming Simulator 2022",
      .executable = "FarmingSimulator2022Game.exe",
      .num_options = 1,
      .options = application_510_options,
    },
    { .name = "The Last Of Us Part I",
      .executable = "tlou-i.exe",
      .num_options = 1,
      .options = application_512_options,
    },
    { .name = "The Last Of Us Part II Remastered",
      .executable = "tlou-ii.exe",
      .num_options = 1,
      .options = application_514_options,
    },
    { .name = "RESIDENT EVIL 2",
      .executable = "re2.exe",
      .num_options = 1,
      .options = application_516_options,
    },
    { .name = "Wolfenstein: Youngblood(x64vk)",
      .executable = "Youngblood_x64vk.exe",
      .num_options = 1,
      .options = application_518_options,
    },
    { .name = "Batman™: Arkham Knight",
      .executable = "BatmanAK.exe",
      .num_options = 1,
      .options = application_520_options,
    },
    { .name = "Company of Heroes 3",
      .executable = "RelicCoH3.exe",
      .num_options = 1,
      .options = application_522_options,
    },
    { .name = "Rise of the Tomb Raider",
      .executable = "RiseOfTheTombRaider",
      .num_options = 1,
      .options = application_524_options,
    },
    { .name = "Rise of the Tomb Raider",
      .executable = "ROTTR.exe",
      .num_options = 1,
      .options = application_526_options,
    },
    { .name = "Sky: Children of the Light",
      .executable = "Sky.exe",
      .num_options = 1,
      .options = application_528_options,
    },
    { .name = "Monster Hunter Wilds",
      .executable = "MonsterHunterWilds.exe",
      .num_options = 1,
      .options = application_530_options,
    },
    { .name = "NieR Replicant ver.1.22474487139",
      .executable = "NieR Replicant ver.1.22474487139.exe",
      .num_options = 1,
      .options = application_532_options,
    },
    { .name = "NieR:Automata",
      .executable = "NieRAutomata.exe",
      .num_options = 1,
      .options = application_534_options,
    },
    { .name = "Valheim",
      .executable = "valheim.x86_64",
      .num_options = 1,
      .options = application_536_options,
    },
    { .name = "Cyberpunk 2077",
      .executable = "Cyberpunk2077.exe",
      .num_options = 1,
      .options = application_538_options,
    },
    { .name = "Elden Ring",
      .executable = "eldenring.exe",
      .num_options = 1,
      .options = application_540_options,
    },
    { .name = "Armored Core 6",
      .executable = "armoredcore6.exe",
      .num_options = 1,
      .options = application_542_options,
    },
    { .name = "Marvel's Spider-Man Remastered",
      .executable = "Spider-Man.exe",
      .num_options = 2,
      .options = application_544_options,
    },
    { .name = "Hitman 3",
      .executable = "hitman3.exe",
      .num_options = 1,
      .options = application_547_options,
    },
    { .name = "Hogwarts Legacy",
      .executable = "HogwartsLegacy.exe",
      .num_options = 2,
      .options = application_549_options,
    },
    { .name = "DEATH STRANDING",
      .executable = "ds.exe",
      .num_options = 1,
      .options = application_552_options,
    },
    { .name = "Diablo IV",
      .executable = "Diablo IV.exe",
      .num_options = 1,
      .options = application_554_options,
    },
    { .name = "Faaast Penguin",
      .executable = "FaaastPenguinClient.exe",
      .num_options = 1,
      .options = application_556_options,
    },
    { .name = "Satisfactory Steam",
      .executable = "FactoryGameSteam-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_558_options,
    },
    { .name = "Satisfactory EGS",
      .executable = "FactoryGameEGS-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_560_options,
    },
    { .name = "Space Engineers 2",
      .executable = "SpaceEngineers2.exe",
      .num_options = 1,
      .options = application_562_options,
    },
    { .name = "Dying Light 2",
      .executable = "DyingLightGame_x64_rwdi.exe",
      .num_options = 1,
      .options = application_564_options,
    },
    { .name = "Witcher3",
      .executable = "witcher3.exe",
      .num_options = 1,
      .options = application_566_options,
    },
    { .name = "Baldur's Gate 3",
      .executable = "bg3.exe",
      .num_options = 1,
      .options = application_568_options,
    },
    { .name = "Baldur's Gate 3",
      .executable = "bg3",
      .num_options = 1,
      .options = application_570_options,
    },
    { .name = "The Finals",
      .executable = "Discovery.exe",
      .num_options = 1,
      .options = application_572_options,
    },
    { .name = "Palworld2",
      .executable = "Palworld-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_574_options,
    },
    { .name = "Red Dead Redemption 2",
      .executable = "RDR2.exe",
      .num_options = 1,
      .options = application_576_options,
    },
    { .name = "Shadow of the Tomb Raider",
      .executable = "SOTTR.exe",
      .num_options = 1,
      .options = application_578_options,
    },
    { .name = "Silent Hill 2",
      .executable = "SHProto-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_580_options,
    },
    { .name = "Marvel Rivals",
      .executable = "Marvel-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_582_options,
    },
    { .name = "Bellwright",
      .executable = "BellwrightGame-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_584_options,
    },
    { .name = "A Game About Digging A Hole",
      .executable = "DiggingGame.exe",
      .num_options = 1,
      .options = application_586_options,
    },
    { .name = "Jusant",
      .executable = "ASC-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_588_options,
    },
    { .name = "DIRT 5",
      .executable = "DIRT5.exe",
      .num_options = 1,
      .options = application_590_options,
    },
    { .name = "X4 Foundations",
      .executable = "X4",
      .num_options = 1,
      .options = application_592_options,
    },
    { .name = "Total War: WARHAMMER III",
      .executable = "TotalWarhammer3",
      .num_options = 2,
      .options = application_594_options,
    },
    { .name = "Total War: WARHAMMER III",
      .executable = "Warhammer3.exe",
      .num_options = 1,
      .options = application_597_options,
    },
    { .name = "The Elder Scrolls IV: Oblivion Remastered",
      .executable = "OblivionRemastered-Win.exe",
      .num_options = 1,
      .options = application_599_options,
    },
    { .name = "Call of Duty: Black Ops III",
      .executable = "BlackOps3.exe",
      .num_options = 1,
      .options = application_601_options,
    },
    { .name = "Horizon Forbidden West",
      .executable = "HorizonForbiddenWest.exe",
      .num_options = 1,
      .options = application_603_options,
    },
};

static const struct driconf_device device_494 = {
    .driver = "anv",
    .num_engines = 10,
    .engines = device_494_engines,
    .num_applications = 53,
    .applications = device_494_applications,
};


    
static const struct driconf_option application_628_options[] = {
    { .name = "dzn_enable_8bit_loads_stores", .value = "true" },
    { .name = "dzn_claim_wide_lines", .value = "true" },
};

    
static const struct driconf_option application_631_options[] = {
    { .name = "dzn_claim_wide_lines", .value = "true" },
};

    
static const struct driconf_option application_633_options[] = {
    { .name = "dzn_disable", .value = "true" },
};

    
static const struct driconf_option application_635_options[] = {
    { .name = "dzn_disable", .value = "true" },
};


static const struct driconf_application device_627_applications[] = {
    { .name = "DOOMEternal",
      .executable = "DOOMEternalx64vk.exe",
      .num_options = 2,
      .options = application_628_options,
    },
    { .name = "No Man's Sky",
      .executable = "NMS.exe",
      .num_options = 1,
      .options = application_631_options,
    },
    { .name = "Red Dead Redemption 2",
      .executable = "RDR2.exe",
      .num_options = 1,
      .options = application_633_options,
    },
    { .name = "Baldur's Gate 3",
      .executable = "bg3.exe",
      .num_options = 1,
      .options = application_635_options,
    },
};

static const struct driconf_device device_627 = {
    .driver = "dzn",
    .num_engines = 0,
    .num_applications = 4,
    .applications = device_627_applications,
};


    
static const struct driconf_option application_638_options[] = {
    { .name = "mesa_extension_override", .value = "+GL_ARB_texture_view" },
};


static const struct driconf_application device_637_applications[] = {
    { .name = "Blender",
      .executable = "blender.exe",
      .num_options = 1,
      .options = application_638_options,
    },
};

static const struct driconf_device device_637 = {
    .driver = "d3d12",
    .num_engines = 0,
    .num_applications = 1,
    .applications = device_637_applications,
};


    
static const struct driconf_option application_641_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_643_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_645_options[] = {
    { .name = "nvk_app_layer", .value = "metroexodus" },
};

    
static const struct driconf_option application_647_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};

    
static const struct driconf_option application_649_options[] = {
    { .name = "force_vk_vendor", .value = "-1" },
};


static const struct driconf_application device_640_applications[] = {
    { .name = "Artifact Classic",
      .executable = "dcg",
      .num_options = 1,
      .options = application_641_options,
    },
    { .name = "Deep Rock Galactic",
      .executable = "FSD.exe",
      .num_options = 1,
      .options = application_643_options,
    },
    { .name = "Metro Exodus (Linux native)",
      .application_name_match = "metroexodus",
      .num_options = 1,
      .options = application_645_options,
    },
    { .name = "No Man's Sky",
      .executable = "NMS.exe",
      .num_options = 1,
      .options = application_647_options,
    },
    { .name = "X4 Foundations",
      .executable = "X4",
      .num_options = 1,
      .options = application_649_options,
    },
};

static const struct driconf_device device_640 = {
    .driver = "nvk",
    .num_engines = 0,
    .num_applications = 5,
    .applications = device_640_applications,
};


    
static const struct driconf_option application_652_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_655_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_658_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_661_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_664_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_667_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_670_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_673_options[] = {
    { .name = "r300_nohiz", .value = "true" },
    { .name = "r300_nozmask", .value = "true" },
};

    
static const struct driconf_option application_676_options[] = {
    { .name = "r300_ffmath", .value = "true" },
};

    
static const struct driconf_option application_678_options[] = {
    { .name = "r300_ffmath", .value = "true" },
};


static const struct driconf_application device_651_applications[] = {
    { .name = "X server",
      .executable = "X",
      .num_options = 2,
      .options = application_652_options,
    },
    { .name = "X server",
      .executable = "Xorg",
      .num_options = 2,
      .options = application_655_options,
    },
    { .name = "Compiz",
      .executable = "check_gl_texture_size",
      .num_options = 2,
      .options = application_658_options,
    },
    { .name = "Compiz",
      .executable = "Compiz",
      .num_options = 2,
      .options = application_661_options,
    },
    { .name = "GNOME Shell",
      .executable = "gnome-session-check-accelerated-helper",
      .num_options = 2,
      .options = application_664_options,
    },
    { .name = "GNOME Shell",
      .executable = "gnome-shell",
      .num_options = 2,
      .options = application_667_options,
    },
    { .name = "KWin",
      .executable = "kwin_opengl_test",
      .num_options = 2,
      .options = application_670_options,
    },
    { .name = "KWin",
      .executable = "kwin",
      .num_options = 2,
      .options = application_673_options,
    },
    { .name = "Unigine Tropics",
      .executable = "Tropics",
      .num_options = 1,
      .options = application_676_options,
    },
    { .name = "Oilrush",
      .executable = "Oilrush_x86",
      .num_options = 1,
      .options = application_678_options,
    },
};

static const struct driconf_device device_651 = {
    .driver = "r300",
    .num_engines = 0,
    .num_applications = 10,
    .applications = device_651_applications,
};


    
static const struct driconf_option application_681_options[] = {
    { .name = "mesa_extension_override", .value = "-GL_ARB_shader_image_load_store" },
};


static const struct driconf_application device_680_applications[] = {
    { .name = "Tomb Raider 2013",
      .executable = "TombRaider",
      .num_options = 1,
      .options = application_681_options,
    },
};

static const struct driconf_device device_680 = {
    .driver = "r600",
    .num_engines = 0,
    .num_applications = 1,
    .applications = device_680_applications,
};


    
static const struct driconf_option application_684_options[] = {
    { .name = "format_l8_srgb_enable_readback", .value = "true" },
};


static const struct driconf_application device_683_applications[] = {
    { .name = "Counter-Strike Global Offensive",
      .executable = "csgo_linux64",
      .num_options = 1,
      .options = application_684_options,
    },
};

static const struct driconf_device device_683 = {
    .driver = "virtio_gpu",
    .num_engines = 0,
    .num_applications = 1,
    .applications = device_683_applications,
};


    
static const struct driconf_option application_687_options[] = {
    { .name = "force_gl_renderer", .value = "Adreno (TM) 618" },
    { .name = "force_gl_vendor", .value = "Qualcomm" },
};

    
static const struct driconf_option application_690_options[] = {
    { .name = "force_gl_renderer", .value = "Adreno (TM) 630" },
    { .name = "force_gl_vendor", .value = "Qualcomm" },
};

    
static const struct driconf_option application_693_options[] = {
    { .name = "force_gl_renderer", .value = "Adreno (TM) 618" },
    { .name = "force_gl_vendor", .value = "Qualcomm" },
};

    
static const struct driconf_option application_696_options[] = {
    { .name = "force_gl_renderer", .value = "Adreno (TM) 630" },
    { .name = "force_gl_vendor", .value = "Qualcomm" },
};


static const struct driconf_application device_686_applications[] = {
    { .name = "Call of Duty Mobile",
      .executable = "com.activision.callofduty.shooter",
      .num_options = 2,
      .options = application_687_options,
    },
    { .name = "Asphalt 8",
      .executable = "com.gameloft.android.ANMP.GloftA8HM",
      .num_options = 2,
      .options = application_690_options,
    },
    { .name = "Asphalt 9",
      .executable = "com.gameloft.android.ANMP.GloftA9HM",
      .num_options = 2,
      .options = application_693_options,
    },
    { .name = "PUBG Mobile",
      .executable = "com.tencent.ig",
      .num_options = 2,
      .options = application_696_options,
    },
};

static const struct driconf_device device_686 = {
    .driver = "msm",
    .device = "FD618",
    .num_engines = 0,
    .num_applications = 4,
    .applications = device_686_applications,
};


    
static const struct driconf_option application_700_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_702_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_704_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_706_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_708_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_710_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_712_options[] = {
    { .name = "force_gl_vendor", .value = "angleisbroken" },
};

    
static const struct driconf_option application_714_options[] = {
    { .name = "disable_explicit_sync_heuristic", .value = "true" },
};


static const struct driconf_application device_699_applications[] = {
    { .name = "Chromium",
      .executable = "chromium",
      .num_options = 1,
      .options = application_700_options,
    },
    { .name = "Chromium",
      .executable = "chromium-browser",
      .num_options = 1,
      .options = application_702_options,
    },
    { .name = "Chromium",
      .executable = "chrome",
      .num_options = 1,
      .options = application_704_options,
    },
    { .name = "VS Code",
      .executable = "code",
      .num_options = 1,
      .options = application_706_options,
    },
    { .name = "element-desktop",
      .executable = "element-desktop",
      .num_options = 1,
      .options = application_708_options,
    },
    { .name = "vivaldi-bin",
      .executable = "vivaldi-bin",
      .num_options = 1,
      .options = application_710_options,
    },
    { .name = "code",
      .executable = "vivaldi-bin",
      .num_options = 1,
      .options = application_712_options,
    },
    { .name = "Xwayland",
      .executable = "Xwayland",
      .num_options = 1,
      .options = application_714_options,
    },
};

static const struct driconf_device device_699 = {
    .driver = "msm",
    .num_engines = 0,
    .num_applications = 8,
    .applications = device_699_applications,
};
    
static const struct driconf_option engine_725_options[] = {
    { .name = "tu_allow_oob_indirect_ubo_loads", .value = "true" },
};

    
static const struct driconf_option engine_727_options[] = {
    { .name = "tu_disable_d24s8_border_color_workaround", .value = "true" },
    { .name = "tu_use_tex_coord_round_nearest_even_mode", .value = "true" },
    { .name = "tu_emulate_alpha_to_coverage", .value = "true" },
    { .name = "tu_autotune_algorithm", .value = "prefer_sysmem" },
};

    
static const struct driconf_option engine_732_options[] = {
    { .name = "tu_enable_softfloat32", .value = "true" },
};


static const struct driconf_engine device_716_engines[] = {
    { .engine_name_match = "DXVK",
      .engine_versions = "0:8400896",
      .num_options = 1,
      .options = engine_725_options,
    },
    { .engine_name_match = "DXVK|vkd3d",
      .num_options = 4,
      .options = engine_727_options,
    },
    { .engine_name_match = "vkd3d",
      .num_options = 1,
      .options = engine_732_options,
    },
};

    
static const struct driconf_option application_717_options[] = {
    { .name = "tu_ignore_frag_depth_direction", .value = "true" },
};

    
static const struct driconf_option application_719_options[] = {
    { .name = "tu_allow_oob_indirect_ubo_loads", .value = "true" },
};

    
static const struct driconf_option application_721_options[] = {
    { .name = "tu_ignore_frag_depth_direction", .value = "true" },
};

    
static const struct driconf_option application_723_options[] = {
    { .name = "tu_emulate_alpha_to_coverage", .value = "true" },
};


static const struct driconf_application device_716_applications[] = {
    { .name = "Sons Of The Forest",
      .executable = "SonsOfTheForest.exe",
      .num_options = 1,
      .options = application_717_options,
    },
    { .name = "Yooka-Laylee",
      .application_name_match = "YookaLaylee.x86_64",
      .num_options = 1,
      .options = application_719_options,
    },
    { .name = "Creed: Rise to Glory",
      .executable = "Creed-Win64-Shipping.exe",
      .num_options = 1,
      .options = application_721_options,
    },
    { .name = "Half-Life: Alyx",
      .application_name_match = "hlvr",
      .num_options = 1,
      .options = application_723_options,
    },
};

static const struct driconf_device device_716 = {
    .driver = "turnip",
    .num_engines = 3,
    .engines = device_716_engines,
    .num_applications = 4,
    .applications = device_716_applications,
};


    
static const struct driconf_option application_735_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_737_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_739_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_741_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_743_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_745_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_747_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_749_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_751_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_753_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_755_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};

    
static const struct driconf_option application_757_options[] = {
    { .name = "force_gl_renderer", .value = "AGX G13/G14" },
};


static const struct driconf_application device_734_applications[] = {
    { .name = "Firefox",
      .executable = "firefox",
      .num_options = 1,
      .options = application_735_options,
    },
    { .name = "Firefox ESR",
      .executable = "firefox-esr",
      .num_options = 1,
      .options = application_737_options,
    },
    { .name = "Chromium",
      .executable = "chromium",
      .num_options = 1,
      .options = application_739_options,
    },
    { .name = "Chromium",
      .executable = "chromium-browser",
      .num_options = 1,
      .options = application_741_options,
    },
    { .name = "Google Chrome",
      .executable = "chrome",
      .num_options = 1,
      .options = application_743_options,
    },
    { .name = "vivaldi-bin",
      .executable = "vivaldi-bin",
      .num_options = 1,
      .options = application_745_options,
    },
    { .name = "Iceweasel",
      .executable = "iceweasel",
      .num_options = 1,
      .options = application_747_options,
    },
    { .name = "Epiphany",
      .executable = "epiphany",
      .num_options = 1,
      .options = application_749_options,
    },
    { .name = "Konqueror",
      .executable = "konqueror",
      .num_options = 1,
      .options = application_751_options,
    },
    { .name = "Falkon",
      .executable = "falkon",
      .num_options = 1,
      .options = application_753_options,
    },
    { .name = "Seamonkey",
      .executable = "seamonkey",
      .num_options = 1,
      .options = application_755_options,
    },
    { .name = "Waterfox",
      .executable = "waterfox",
      .num_options = 1,
      .options = application_757_options,
    },
};

static const struct driconf_device device_734 = {
    .driver = "asahi",
    .num_engines = 0,
    .num_applications = 12,
    .applications = device_734_applications,
};
    
static const struct driconf_option engine_760_options[] = {
    { .name = "hk_disable_border_emulation", .value = "true" },
    { .name = "hk_enable_vertex_pipeline_stores_atomics", .value = "true" },
};

    
static const struct driconf_option engine_763_options[] = {
    { .name = "hk_fake_minmax", .value = "true" },
    { .name = "hk_image_view_min_lod", .value = "true" },
};


static const struct driconf_engine device_759_engines[] = {
    { .engine_name_match = "DXVK|vkd3d",
      .num_options = 2,
      .options = engine_760_options,
    },
    { .engine_name_match = "vkd3d",
      .num_options = 2,
      .options = engine_763_options,
    },
};



static const struct driconf_device device_759 = {
    .driver = "hk",
    .num_engines = 2,
    .engines = device_759_engines,
    .num_applications = 0,
};
    
static const struct driconf_option engine_767_options[] = {
    { .name = "pan_enable_vertex_pipeline_stores_atomics", .value = "true" },
};


static const struct driconf_engine device_766_engines[] = {
    { .engine_name_match = "ANGLE",
      .num_options = 1,
      .options = engine_767_options,
    },
};



static const struct driconf_device device_766 = {
    .driver = "panvk",
    .num_engines = 1,
    .engines = device_766_engines,
    .num_applications = 0,
};


    
static const struct driconf_option application_770_options[] = {
    { .name = "allow_rgb16_configs", .value = "false" },
};


static const struct driconf_application device_769_applications[] = {
    { .name = "all-default",
      .num_options = 1,
      .options = application_770_options,
    },
};

static const struct driconf_device device_769 = {
    .driver = "panfrost",
    .num_engines = 0,
    .num_applications = 1,
    .applications = device_769_applications,
};

static const struct driconf_device *driconf[] = {
    &device_1,
    &device_405,
    &device_412,
    &device_457,
    &device_472,
    &device_487,
    &device_494,
    &device_627,
    &device_637,
    &device_640,
    &device_651,
    &device_680,
    &device_683,
    &device_686,
    &device_699,
    &device_716,
    &device_734,
    &device_759,
    &device_766,
    &device_769,
};
