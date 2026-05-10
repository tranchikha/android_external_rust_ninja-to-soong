/* Copyright (C) 2020 Google, Inc.
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

#include "panvk_tracepoints.h"

#include "pan_fb.h"
#include "util/format/u_format.h"

#define __NEEDS_TRACE_PRIV
#include "util/u_debug.h"
#include "util/perf/u_trace_priv.h"


/*
 * begin_cmdbuf
 */
#define __print_begin_cmdbuf NULL
#define __print_json_begin_cmdbuf NULL
static const struct u_tracepoint __tp_begin_cmdbuf = {
    "begin_cmdbuf",
    ALIGN_POT(sizeof(struct trace_begin_cmdbuf), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    0,
    __print_begin_cmdbuf,
    __print_json_begin_cmdbuf,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_cmdbuf,
#endif
};
void __trace_begin_cmdbuf(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_cmdbuf entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_cmdbuf *__entry =
      queueing ?
      (struct trace_begin_cmdbuf *)u_trace_appendv(ut, cs, &__tp_begin_cmdbuf,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_cmdbuf
 */
static void __print_end_cmdbuf(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_cmdbuf *__entry =
      (const struct trace_end_cmdbuf *)arg;
   fprintf(out, ""
      "flags=0x%x, "
         "\n"
   ,__entry->flags
   );
}

static void __print_json_end_cmdbuf(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_cmdbuf *__entry =
      (const struct trace_end_cmdbuf *)arg;
   fprintf(out, ""
      "\"flags\": \"0x%x\""
   ,__entry->flags
   );
}

static const struct u_tracepoint __tp_end_cmdbuf = {
    "end_cmdbuf",
    ALIGN_POT(sizeof(struct trace_end_cmdbuf), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    1,
    __print_end_cmdbuf,
    __print_json_end_cmdbuf,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_cmdbuf,
#endif
};
void __trace_end_cmdbuf(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , VkCommandBufferUsageFlags flags
) {
   struct trace_end_cmdbuf entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_cmdbuf *__entry =
      queueing ?
      (struct trace_end_cmdbuf *)u_trace_appendv(ut, cs, &__tp_end_cmdbuf,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
   __entry->flags = flags;
}

/*
 * begin_meta
 */
#define __print_begin_meta NULL
#define __print_json_begin_meta NULL
static const struct u_tracepoint __tp_begin_meta = {
    "begin_meta",
    ALIGN_POT(sizeof(struct trace_begin_meta), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    2,
    __print_begin_meta,
    __print_json_begin_meta,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_meta,
#endif
};
void __trace_begin_meta(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_meta entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_meta *__entry =
      queueing ?
      (struct trace_begin_meta *)u_trace_appendv(ut, cs, &__tp_begin_meta,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_meta
 */
#define __print_end_meta NULL
#define __print_json_end_meta NULL
static const struct u_tracepoint __tp_end_meta = {
    "end_meta",
    ALIGN_POT(sizeof(struct trace_end_meta), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    3,
    __print_end_meta,
    __print_json_end_meta,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_meta,
#endif
};
void __trace_end_meta(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_end_meta entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_meta *__entry =
      queueing ?
      (struct trace_end_meta *)u_trace_appendv(ut, cs, &__tp_end_meta,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * begin_render
 */
#define __print_begin_render NULL
#define __print_json_begin_render NULL
static const struct u_tracepoint __tp_begin_render = {
    "begin_render",
    ALIGN_POT(sizeof(struct trace_begin_render), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    4,
    __print_begin_render,
    __print_json_begin_render,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_render,
#endif
};
void __trace_begin_render(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_render entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_render *__entry =
      queueing ?
      (struct trace_begin_render *)u_trace_appendv(ut, cs, &__tp_begin_render,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_render
 */
static void __print_end_render(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_render *__entry =
      (const struct trace_end_render *)arg;
   fprintf(out, ""
      "flags=0x%x, "
      "width=%u, "
      "height=%u, "
      "nr_samples=%u, "
      "rt_count=%u, "
      "rt0_format=%s, "
      "zs_format=%s, "
      "s_format=%s, "
      "tile_size=%u, "
         "\n"
   ,__entry->flags
   ,__entry->width
   ,__entry->height
   ,__entry->nr_samples
   ,__entry->rt_count
   ,util_format_description((enum pipe_format)__entry->rt0_format)->name
   ,util_format_description((enum pipe_format)__entry->zs_format)->name
   ,util_format_description((enum pipe_format)__entry->s_format)->name
   ,__entry->tile_size
   );
}

static void __print_json_end_render(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_render *__entry =
      (const struct trace_end_render *)arg;
   fprintf(out, ""
      "\"flags\": \"0x%x\""
         ", "
      "\"width\": \"%u\""
         ", "
      "\"height\": \"%u\""
         ", "
      "\"nr_samples\": \"%u\""
         ", "
      "\"rt_count\": \"%u\""
         ", "
      "\"rt0_format\": \"%s\""
         ", "
      "\"zs_format\": \"%s\""
         ", "
      "\"s_format\": \"%s\""
         ", "
      "\"tile_size\": \"%u\""
   ,__entry->flags
   ,__entry->width
   ,__entry->height
   ,__entry->nr_samples
   ,__entry->rt_count
   ,util_format_description((enum pipe_format)__entry->rt0_format)->name
   ,util_format_description((enum pipe_format)__entry->zs_format)->name
   ,util_format_description((enum pipe_format)__entry->s_format)->name
   ,__entry->tile_size
   );
}

static const struct u_tracepoint __tp_end_render = {
    "end_render",
    ALIGN_POT(sizeof(struct trace_end_render), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    5,
    __print_end_render,
    __print_json_end_render,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_render,
#endif
};
void __trace_end_render(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , VkRenderingFlags flags
   , const struct pan_fb_layout * fb
) {
   struct trace_end_render entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_render *__entry =
      queueing ?
      (struct trace_end_render *)u_trace_appendv(ut, cs, &__tp_end_render,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
   __entry->width = fb->width_px;
   __entry->height = fb->height_px;
   __entry->nr_samples = fb->sample_count;
   __entry->rt_count = fb->rt_count;
   __entry->rt0_format = fb->rt_formats[0];
   __entry->zs_format = fb->z_format;
   __entry->s_format = fb->s_format;
   __entry->tile_size = fb->tile_size_px;
   __entry->flags = flags;
}

/*
 * begin_dispatch
 */
#define __print_begin_dispatch NULL
#define __print_json_begin_dispatch NULL
static const struct u_tracepoint __tp_begin_dispatch = {
    "begin_dispatch",
    ALIGN_POT(sizeof(struct trace_begin_dispatch), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    6,
    __print_begin_dispatch,
    __print_json_begin_dispatch,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_dispatch,
#endif
};
void __trace_begin_dispatch(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_dispatch entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_dispatch *__entry =
      queueing ?
      (struct trace_begin_dispatch *)u_trace_appendv(ut, cs, &__tp_begin_dispatch,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_dispatch
 */
static void __print_end_dispatch(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_dispatch *__entry =
      (const struct trace_end_dispatch *)arg;
   fprintf(out, ""
      "base_group_x=%u, "
      "base_group_y=%u, "
      "base_group_z=%u, "
      "group_count_x=%u, "
      "group_count_y=%u, "
      "group_count_z=%u, "
      "group_size_x=%u, "
      "group_size_y=%u, "
      "group_size_z=%u, "
         "\n"
   ,__entry->base_group_x
   ,__entry->base_group_y
   ,__entry->base_group_z
   ,__entry->group_count_x
   ,__entry->group_count_y
   ,__entry->group_count_z
   ,__entry->group_size_x
   ,__entry->group_size_y
   ,__entry->group_size_z
   );
}

static void __print_json_end_dispatch(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_dispatch *__entry =
      (const struct trace_end_dispatch *)arg;
   fprintf(out, ""
      "\"base_group_x\": \"%u\""
         ", "
      "\"base_group_y\": \"%u\""
         ", "
      "\"base_group_z\": \"%u\""
         ", "
      "\"group_count_x\": \"%u\""
         ", "
      "\"group_count_y\": \"%u\""
         ", "
      "\"group_count_z\": \"%u\""
         ", "
      "\"group_size_x\": \"%u\""
         ", "
      "\"group_size_y\": \"%u\""
         ", "
      "\"group_size_z\": \"%u\""
   ,__entry->base_group_x
   ,__entry->base_group_y
   ,__entry->base_group_z
   ,__entry->group_count_x
   ,__entry->group_count_y
   ,__entry->group_count_z
   ,__entry->group_size_x
   ,__entry->group_size_y
   ,__entry->group_size_z
   );
}

static const struct u_tracepoint __tp_end_dispatch = {
    "end_dispatch",
    ALIGN_POT(sizeof(struct trace_end_dispatch), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    7,
    __print_end_dispatch,
    __print_json_end_dispatch,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_dispatch,
#endif
};
void __trace_end_dispatch(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , uint16_t base_group_x
   , uint16_t base_group_y
   , uint16_t base_group_z
   , uint16_t group_count_x
   , uint16_t group_count_y
   , uint16_t group_count_z
   , uint16_t group_size_x
   , uint16_t group_size_y
   , uint16_t group_size_z
) {
   struct trace_end_dispatch entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_dispatch *__entry =
      queueing ?
      (struct trace_end_dispatch *)u_trace_appendv(ut, cs, &__tp_end_dispatch,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
   __entry->base_group_x = base_group_x;
   __entry->base_group_y = base_group_y;
   __entry->base_group_z = base_group_z;
   __entry->group_count_x = group_count_x;
   __entry->group_count_y = group_count_y;
   __entry->group_count_z = group_count_z;
   __entry->group_size_x = group_size_x;
   __entry->group_size_y = group_size_y;
   __entry->group_size_z = group_size_z;
}

/*
 * begin_dispatch_indirect
 */
#define __print_begin_dispatch_indirect NULL
#define __print_json_begin_dispatch_indirect NULL
static const struct u_tracepoint __tp_begin_dispatch_indirect = {
    "begin_dispatch_indirect",
    ALIGN_POT(sizeof(struct trace_begin_dispatch_indirect), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    8,
    __print_begin_dispatch_indirect,
    __print_json_begin_dispatch_indirect,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_dispatch_indirect,
#endif
};
void __trace_begin_dispatch_indirect(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_dispatch_indirect entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_dispatch_indirect *__entry =
      queueing ?
      (struct trace_begin_dispatch_indirect *)u_trace_appendv(ut, cs, &__tp_begin_dispatch_indirect,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_dispatch_indirect
 */
static void __print_end_dispatch_indirect(FILE *out, const void *arg, const void *indirect) {
   const VkDispatchIndirectCommand *__group_count = (const VkDispatchIndirectCommand *) ((char *)indirect + 0);
   fprintf(out, ""
      "group_count=%ux%ux%u, "
         "\n"
   ,__group_count->x, __group_count->y, __group_count->z
   );
}

static void __print_json_end_dispatch_indirect(FILE *out, const void *arg, const void *indirect) {
   const VkDispatchIndirectCommand *__group_count = (const VkDispatchIndirectCommand *) ((char *)indirect + 0);
   fprintf(out, ""
      "\"group_count\": \"%ux%ux%u\""
   ,__group_count->x, __group_count->y, __group_count->z
   );
}

static const struct u_tracepoint __tp_end_dispatch_indirect = {
    "end_dispatch_indirect",
    ALIGN_POT(sizeof(struct trace_end_dispatch_indirect), 8),   /* keep size 64b aligned */
    0
    + sizeof(VkDispatchIndirectCommand)
    ,
    0,
    9,
    __print_end_dispatch_indirect,
    __print_json_end_dispatch_indirect,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_dispatch_indirect,
#endif
};
void __trace_end_dispatch_indirect(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , struct u_trace_address group_count
) {
   struct trace_end_dispatch_indirect entry;
   struct u_trace_address indirects[] = {
      group_count,
   };
   uint8_t indirect_sizes[] = {
      sizeof(VkDispatchIndirectCommand),
   };
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_dispatch_indirect *__entry =
      queueing ?
      (struct trace_end_dispatch_indirect *)u_trace_appendv(ut, cs, &__tp_end_dispatch_indirect,
                                                    0
                                                    ,
                                                    ARRAY_SIZE(indirects), indirects, indirect_sizes
                                                    ) :
      &entry;
}

/*
 * begin_barrier
 */
#define __print_begin_barrier NULL
#define __print_json_begin_barrier NULL
static const struct u_tracepoint __tp_begin_barrier = {
    "begin_barrier",
    ALIGN_POT(sizeof(struct trace_begin_barrier), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    10,
    __print_begin_barrier,
    __print_json_begin_barrier,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_barrier,
#endif
};
void __trace_begin_barrier(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_barrier entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_barrier *__entry =
      queueing ?
      (struct trace_begin_barrier *)u_trace_appendv(ut, cs, &__tp_begin_barrier,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_barrier
 */
static void __print_end_barrier(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_barrier *__entry =
      (const struct trace_end_barrier *)arg;
   fprintf(out, ""
      "sb_wait=0x%x, "
      "sync_wait=0x%x, "
         "\n"
   ,__entry->sb_wait
   ,__entry->sync_wait
   );
}

static void __print_json_end_barrier(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_barrier *__entry =
      (const struct trace_end_barrier *)arg;
   fprintf(out, ""
      "\"sb_wait\": \"0x%x\""
         ", "
      "\"sync_wait\": \"0x%x\""
   ,__entry->sb_wait
   ,__entry->sync_wait
   );
}

static const struct u_tracepoint __tp_end_barrier = {
    "end_barrier",
    ALIGN_POT(sizeof(struct trace_end_barrier), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    11,
    __print_end_barrier,
    __print_json_end_barrier,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_barrier,
#endif
};
void __trace_end_barrier(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , uint8_t sb_wait
   , uint8_t sync_wait
) {
   struct trace_end_barrier entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_barrier *__entry =
      queueing ?
      (struct trace_end_barrier *)u_trace_appendv(ut, cs, &__tp_end_barrier,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
   __entry->sb_wait = sb_wait;
   __entry->sync_wait = sync_wait;
}

/*
 * begin_sync32_add
 */
#define __print_begin_sync32_add NULL
#define __print_json_begin_sync32_add NULL
static const struct u_tracepoint __tp_begin_sync32_add = {
    "begin_sync32_add",
    ALIGN_POT(sizeof(struct trace_begin_sync32_add), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    12,
    __print_begin_sync32_add,
    __print_json_begin_sync32_add,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_sync32_add,
#endif
};
void __trace_begin_sync32_add(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_sync32_add entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_sync32_add *__entry =
      queueing ?
      (struct trace_begin_sync32_add *)u_trace_appendv(ut, cs, &__tp_begin_sync32_add,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_sync32_add
 */
static void __print_end_sync32_add(FILE *out, const void *arg, const void *indirect) {
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint32_t *__sync_val = (const uint32_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "sync_addr=0x%" PRIx64 ", "
      "sync_val=%u, "
         "\n"
   ,*__sync_addr
   ,*__sync_val
   );
}

static void __print_json_end_sync32_add(FILE *out, const void *arg, const void *indirect) {
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint32_t *__sync_val = (const uint32_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "\"sync_addr\": \"0x%" PRIx64 "\""
         ", "
      "\"sync_val\": \"%u\""
   ,*__sync_addr
   ,*__sync_val
   );
}

static const struct u_tracepoint __tp_end_sync32_add = {
    "end_sync32_add",
    ALIGN_POT(sizeof(struct trace_end_sync32_add), 8),   /* keep size 64b aligned */
    0
    + sizeof(uint64_t)
    + sizeof(uint32_t)
    ,
    0,
    13,
    __print_end_sync32_add,
    __print_json_end_sync32_add,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_sync32_add,
#endif
};
void __trace_end_sync32_add(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
) {
   struct trace_end_sync32_add entry;
   struct u_trace_address indirects[] = {
      sync_addr,
      sync_val,
   };
   uint8_t indirect_sizes[] = {
      sizeof(uint64_t),
      sizeof(uint32_t),
   };
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_sync32_add *__entry =
      queueing ?
      (struct trace_end_sync32_add *)u_trace_appendv(ut, cs, &__tp_end_sync32_add,
                                                    0
                                                    ,
                                                    ARRAY_SIZE(indirects), indirects, indirect_sizes
                                                    ) :
      &entry;
}

/*
 * begin_sync64_add
 */
#define __print_begin_sync64_add NULL
#define __print_json_begin_sync64_add NULL
static const struct u_tracepoint __tp_begin_sync64_add = {
    "begin_sync64_add",
    ALIGN_POT(sizeof(struct trace_begin_sync64_add), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    14,
    __print_begin_sync64_add,
    __print_json_begin_sync64_add,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_sync64_add,
#endif
};
void __trace_begin_sync64_add(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_sync64_add entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_sync64_add *__entry =
      queueing ?
      (struct trace_begin_sync64_add *)u_trace_appendv(ut, cs, &__tp_begin_sync64_add,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_sync64_add
 */
static void __print_end_sync64_add(FILE *out, const void *arg, const void *indirect) {
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint64_t *__sync_val = (const uint64_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "sync_addr=0x%" PRIx64 ", "
      "sync_val=%" PRIu64 ", "
         "\n"
   ,*__sync_addr
   ,*__sync_val
   );
}

static void __print_json_end_sync64_add(FILE *out, const void *arg, const void *indirect) {
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint64_t *__sync_val = (const uint64_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "\"sync_addr\": \"0x%" PRIx64 "\""
         ", "
      "\"sync_val\": \"%" PRIu64 "\""
   ,*__sync_addr
   ,*__sync_val
   );
}

static const struct u_tracepoint __tp_end_sync64_add = {
    "end_sync64_add",
    ALIGN_POT(sizeof(struct trace_end_sync64_add), 8),   /* keep size 64b aligned */
    0
    + sizeof(uint64_t)
    + sizeof(uint64_t)
    ,
    0,
    15,
    __print_end_sync64_add,
    __print_json_end_sync64_add,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_sync64_add,
#endif
};
void __trace_end_sync64_add(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
) {
   struct trace_end_sync64_add entry;
   struct u_trace_address indirects[] = {
      sync_addr,
      sync_val,
   };
   uint8_t indirect_sizes[] = {
      sizeof(uint64_t),
      sizeof(uint64_t),
   };
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_sync64_add *__entry =
      queueing ?
      (struct trace_end_sync64_add *)u_trace_appendv(ut, cs, &__tp_end_sync64_add,
                                                    0
                                                    ,
                                                    ARRAY_SIZE(indirects), indirects, indirect_sizes
                                                    ) :
      &entry;
}

/*
 * begin_sync32_wait
 */
#define __print_begin_sync32_wait NULL
#define __print_json_begin_sync32_wait NULL
static const struct u_tracepoint __tp_begin_sync32_wait = {
    "begin_sync32_wait",
    ALIGN_POT(sizeof(struct trace_begin_sync32_wait), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    16,
    __print_begin_sync32_wait,
    __print_json_begin_sync32_wait,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_sync32_wait,
#endif
};
void __trace_begin_sync32_wait(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_sync32_wait entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_sync32_wait *__entry =
      queueing ?
      (struct trace_begin_sync32_wait *)u_trace_appendv(ut, cs, &__tp_begin_sync32_wait,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_sync32_wait
 */
static void __print_end_sync32_wait(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_sync32_wait *__entry =
      (const struct trace_end_sync32_wait *)arg;
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint32_t *__sync_val = (const uint32_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "sync_addr=0x%" PRIx64 ", "
      "sync_val=%u, "
      "cond=%u, "
         "\n"
   ,*__sync_addr
   ,*__sync_val
   ,__entry->cond
   );
}

static void __print_json_end_sync32_wait(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_sync32_wait *__entry =
      (const struct trace_end_sync32_wait *)arg;
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint32_t *__sync_val = (const uint32_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "\"sync_addr\": \"0x%" PRIx64 "\""
         ", "
      "\"sync_val\": \"%u\""
         ", "
      "\"cond\": \"%u\""
   ,*__sync_addr
   ,*__sync_val
   ,__entry->cond
   );
}

static const struct u_tracepoint __tp_end_sync32_wait = {
    "end_sync32_wait",
    ALIGN_POT(sizeof(struct trace_end_sync32_wait), 8),   /* keep size 64b aligned */
    0
    + sizeof(uint64_t)
    + sizeof(uint32_t)
    ,
    0,
    17,
    __print_end_sync32_wait,
    __print_json_end_sync32_wait,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_sync32_wait,
#endif
};
void __trace_end_sync32_wait(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
   , unsigned cond
) {
   struct trace_end_sync32_wait entry;
   struct u_trace_address indirects[] = {
      sync_addr,
      sync_val,
   };
   uint8_t indirect_sizes[] = {
      sizeof(uint64_t),
      sizeof(uint32_t),
   };
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_sync32_wait *__entry =
      queueing ?
      (struct trace_end_sync32_wait *)u_trace_appendv(ut, cs, &__tp_end_sync32_wait,
                                                    0
                                                    ,
                                                    ARRAY_SIZE(indirects), indirects, indirect_sizes
                                                    ) :
      &entry;
   __entry->cond = cond;
}

/*
 * begin_sync64_wait
 */
#define __print_begin_sync64_wait NULL
#define __print_json_begin_sync64_wait NULL
static const struct u_tracepoint __tp_begin_sync64_wait = {
    "begin_sync64_wait",
    ALIGN_POT(sizeof(struct trace_begin_sync64_wait), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    18,
    __print_begin_sync64_wait,
    __print_json_begin_sync64_wait,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_sync64_wait,
#endif
};
void __trace_begin_sync64_wait(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_sync64_wait entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_sync64_wait *__entry =
      queueing ?
      (struct trace_begin_sync64_wait *)u_trace_appendv(ut, cs, &__tp_begin_sync64_wait,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_sync64_wait
 */
static void __print_end_sync64_wait(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_sync64_wait *__entry =
      (const struct trace_end_sync64_wait *)arg;
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint64_t *__sync_val = (const uint64_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "sync_addr=0x%" PRIx64 ", "
      "sync_val=%" PRIu64 ", "
      "cond=%u, "
         "\n"
   ,*__sync_addr
   ,*__sync_val
   ,__entry->cond
   );
}

static void __print_json_end_sync64_wait(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_sync64_wait *__entry =
      (const struct trace_end_sync64_wait *)arg;
   const uint64_t *__sync_addr = (const uint64_t *) ((char *)indirect + 0);
   const uint64_t *__sync_val = (const uint64_t *) ((char *)indirect + sizeof(uint64_t));
   fprintf(out, ""
      "\"sync_addr\": \"0x%" PRIx64 "\""
         ", "
      "\"sync_val\": \"%" PRIu64 "\""
         ", "
      "\"cond\": \"%u\""
   ,*__sync_addr
   ,*__sync_val
   ,__entry->cond
   );
}

static const struct u_tracepoint __tp_end_sync64_wait = {
    "end_sync64_wait",
    ALIGN_POT(sizeof(struct trace_end_sync64_wait), 8),   /* keep size 64b aligned */
    0
    + sizeof(uint64_t)
    + sizeof(uint64_t)
    ,
    0,
    19,
    __print_end_sync64_wait,
    __print_json_end_sync64_wait,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_sync64_wait,
#endif
};
void __trace_end_sync64_wait(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
   , unsigned cond
) {
   struct trace_end_sync64_wait entry;
   struct u_trace_address indirects[] = {
      sync_addr,
      sync_val,
   };
   uint8_t indirect_sizes[] = {
      sizeof(uint64_t),
      sizeof(uint64_t),
   };
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_sync64_wait *__entry =
      queueing ?
      (struct trace_end_sync64_wait *)u_trace_appendv(ut, cs, &__tp_end_sync64_wait,
                                                    0
                                                    ,
                                                    ARRAY_SIZE(indirects), indirects, indirect_sizes
                                                    ) :
      &entry;
   __entry->cond = cond;
}

/*
 * begin_flush_cache
 */
#define __print_begin_flush_cache NULL
#define __print_json_begin_flush_cache NULL
static const struct u_tracepoint __tp_begin_flush_cache = {
    "begin_flush_cache",
    ALIGN_POT(sizeof(struct trace_begin_flush_cache), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    20,
    __print_begin_flush_cache,
    __print_json_begin_flush_cache,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_begin_flush_cache,
#endif
};
void __trace_begin_flush_cache(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
) {
   struct trace_begin_flush_cache entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_begin_flush_cache *__entry =
      queueing ?
      (struct trace_begin_flush_cache *)u_trace_appendv(ut, cs, &__tp_begin_flush_cache,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
}

/*
 * end_flush_cache
 */
static void __print_end_flush_cache(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_flush_cache *__entry =
      (const struct trace_end_flush_cache *)arg;
   fprintf(out, ""
      "l2=%u, "
      "lsc=%u, "
      "other=%u, "
         "\n"
   ,__entry->l2
   ,__entry->lsc
   ,__entry->other
   );
}

static void __print_json_end_flush_cache(FILE *out, const void *arg, const void *indirect) {
   const struct trace_end_flush_cache *__entry =
      (const struct trace_end_flush_cache *)arg;
   fprintf(out, ""
      "\"l2\": \"%u\""
         ", "
      "\"lsc\": \"%u\""
         ", "
      "\"other\": \"%u\""
   ,__entry->l2
   ,__entry->lsc
   ,__entry->other
   );
}

static const struct u_tracepoint __tp_end_flush_cache = {
    "end_flush_cache",
    ALIGN_POT(sizeof(struct trace_end_flush_cache), 8),   /* keep size 64b aligned */
    0
    ,
    0,
    21,
    __print_end_flush_cache,
    __print_json_end_flush_cache,
#ifdef HAVE_PERFETTO
    (void (*)(void *pctx, uint64_t, uint16_t, const void *, const void *, const void *))panvk_utrace_perfetto_end_flush_cache,
#endif
};
void __trace_end_flush_cache(
     struct u_trace *ut
   , enum u_trace_type enabled_traces
   , void *cs
   , uint8_t l2
   , uint8_t lsc
   , uint8_t other
) {
   struct trace_end_flush_cache entry;
   const bool queueing = enabled_traces & U_TRACE_TYPE_REQUIRE_QUEUING;
   UNUSED struct trace_end_flush_cache *__entry =
      queueing ?
      (struct trace_end_flush_cache *)u_trace_appendv(ut, cs, &__tp_end_flush_cache,
                                                    0
                                                    ,
                                                    0, NULL, NULL
                                                    ) :
      &entry;
   __entry->l2 = l2;
   __entry->lsc = lsc;
   __entry->other = other;
}

