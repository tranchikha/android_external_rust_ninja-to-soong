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


#ifndef _PANVK_TRACEPOINTS_H
#define _PANVK_TRACEPOINTS_H

#include "vulkan/vulkan_core.h"

#include "util/perf/u_trace.h"

#ifdef __cplusplus
extern "C" {
#endif

struct pan_fb_layout;
struct panvk_device;



/*
 * begin_cmdbuf
 */
struct trace_begin_cmdbuf {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_cmdbuf) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_cmdbuf(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_cmdbuf *payload,
   const void *indirect_data);
#endif
void __trace_begin_cmdbuf(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_cmdbuf(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_cmdbuf(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_cmdbuf
 */
struct trace_end_cmdbuf {
   VkCommandBufferUsageFlags flags;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_cmdbuf(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_cmdbuf *payload,
   const void *indirect_data);
#endif
void __trace_end_cmdbuf(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , VkCommandBufferUsageFlags flags
);
static ALWAYS_INLINE void trace_end_cmdbuf(
     struct u_trace *ut
   , void *cs
   , VkCommandBufferUsageFlags flags
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_cmdbuf(
        ut
      , enabled_traces
      , cs
      , flags
   );
}

/*
 * begin_meta
 */
struct trace_begin_meta {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_meta) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_meta(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_meta *payload,
   const void *indirect_data);
#endif
void __trace_begin_meta(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_meta(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_meta(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_meta
 */
struct trace_end_meta {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_end_meta) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_meta(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_meta *payload,
   const void *indirect_data);
#endif
void __trace_end_meta(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_end_meta(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_meta(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * begin_render
 */
struct trace_begin_render {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_render) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_render(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_render *payload,
   const void *indirect_data);
#endif
void __trace_begin_render(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_render(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_render(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_render
 */
struct trace_end_render {
   uint16_t width;
   uint16_t height;
   uint8_t nr_samples;
   uint8_t rt_count;
   uint16_t rt0_format;
   uint16_t zs_format;
   uint16_t s_format;
   uint32_t tile_size;
   VkRenderingFlags flags;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_render(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_render *payload,
   const void *indirect_data);
#endif
void __trace_end_render(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , VkRenderingFlags flags
     , const struct pan_fb_layout * fb
);
static ALWAYS_INLINE void trace_end_render(
     struct u_trace *ut
   , void *cs
   , VkRenderingFlags flags
   , const struct pan_fb_layout * fb
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_render(
        ut
      , enabled_traces
      , cs
      , flags
      , fb
   );
}

/*
 * begin_dispatch
 */
struct trace_begin_dispatch {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_dispatch) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_dispatch(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_dispatch *payload,
   const void *indirect_data);
#endif
void __trace_begin_dispatch(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_dispatch(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_dispatch(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_dispatch
 */
struct trace_end_dispatch {
   uint16_t base_group_x;
   uint16_t base_group_y;
   uint16_t base_group_z;
   uint16_t group_count_x;
   uint16_t group_count_y;
   uint16_t group_count_z;
   uint16_t group_size_x;
   uint16_t group_size_y;
   uint16_t group_size_z;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_dispatch(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_dispatch *payload,
   const void *indirect_data);
#endif
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
);
static ALWAYS_INLINE void trace_end_dispatch(
     struct u_trace *ut
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
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_dispatch(
        ut
      , enabled_traces
      , cs
      , base_group_x
      , base_group_y
      , base_group_z
      , group_count_x
      , group_count_y
      , group_count_z
      , group_size_x
      , group_size_y
      , group_size_z
   );
}

/*
 * begin_dispatch_indirect
 */
struct trace_begin_dispatch_indirect {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_dispatch_indirect) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_dispatch_indirect(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_dispatch_indirect *payload,
   const void *indirect_data);
#endif
void __trace_begin_dispatch_indirect(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_dispatch_indirect(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_dispatch_indirect(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_dispatch_indirect
 */
struct trace_end_dispatch_indirect {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_end_dispatch_indirect) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_dispatch_indirect(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_dispatch_indirect *payload,
   const void *indirect_data);
#endif
void __trace_end_dispatch_indirect(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , struct u_trace_address group_count
);
static ALWAYS_INLINE void trace_end_dispatch_indirect(
     struct u_trace *ut
   , void *cs
   , struct u_trace_address group_count
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_dispatch_indirect(
        ut
      , enabled_traces
      , cs
      , group_count
   );
}

/*
 * begin_barrier
 */
struct trace_begin_barrier {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_barrier) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_barrier(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_barrier *payload,
   const void *indirect_data);
#endif
void __trace_begin_barrier(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_barrier(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_barrier(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_barrier
 */
struct trace_end_barrier {
   uint8_t sb_wait;
   uint8_t sync_wait;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_barrier(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_barrier *payload,
   const void *indirect_data);
#endif
void __trace_end_barrier(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , uint8_t sb_wait
     , uint8_t sync_wait
);
static ALWAYS_INLINE void trace_end_barrier(
     struct u_trace *ut
   , void *cs
   , uint8_t sb_wait
   , uint8_t sync_wait
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_barrier(
        ut
      , enabled_traces
      , cs
      , sb_wait
      , sync_wait
   );
}

/*
 * begin_sync32_add
 */
struct trace_begin_sync32_add {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_sync32_add) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_sync32_add(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_sync32_add *payload,
   const void *indirect_data);
#endif
void __trace_begin_sync32_add(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_sync32_add(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_sync32_add(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_sync32_add
 */
struct trace_end_sync32_add {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_end_sync32_add) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_sync32_add(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_sync32_add *payload,
   const void *indirect_data);
#endif
void __trace_end_sync32_add(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , struct u_trace_address sync_addr
     , struct u_trace_address sync_val
);
static ALWAYS_INLINE void trace_end_sync32_add(
     struct u_trace *ut
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_sync32_add(
        ut
      , enabled_traces
      , cs
      , sync_addr
      , sync_val
   );
}

/*
 * begin_sync64_add
 */
struct trace_begin_sync64_add {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_sync64_add) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_sync64_add(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_sync64_add *payload,
   const void *indirect_data);
#endif
void __trace_begin_sync64_add(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_sync64_add(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_sync64_add(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_sync64_add
 */
struct trace_end_sync64_add {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_end_sync64_add) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_sync64_add(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_sync64_add *payload,
   const void *indirect_data);
#endif
void __trace_end_sync64_add(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , struct u_trace_address sync_addr
     , struct u_trace_address sync_val
);
static ALWAYS_INLINE void trace_end_sync64_add(
     struct u_trace *ut
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_sync64_add(
        ut
      , enabled_traces
      , cs
      , sync_addr
      , sync_val
   );
}

/*
 * begin_sync32_wait
 */
struct trace_begin_sync32_wait {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_sync32_wait) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_sync32_wait(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_sync32_wait *payload,
   const void *indirect_data);
#endif
void __trace_begin_sync32_wait(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_sync32_wait(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_sync32_wait(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_sync32_wait
 */
struct trace_end_sync32_wait {
   unsigned cond;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_sync32_wait(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_sync32_wait *payload,
   const void *indirect_data);
#endif
void __trace_end_sync32_wait(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , struct u_trace_address sync_addr
     , struct u_trace_address sync_val
     , unsigned cond
);
static ALWAYS_INLINE void trace_end_sync32_wait(
     struct u_trace *ut
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
   , unsigned cond
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_sync32_wait(
        ut
      , enabled_traces
      , cs
      , sync_addr
      , sync_val
      , cond
   );
}

/*
 * begin_sync64_wait
 */
struct trace_begin_sync64_wait {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_sync64_wait) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_sync64_wait(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_sync64_wait *payload,
   const void *indirect_data);
#endif
void __trace_begin_sync64_wait(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_sync64_wait(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_sync64_wait(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_sync64_wait
 */
struct trace_end_sync64_wait {
   unsigned cond;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_sync64_wait(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_sync64_wait *payload,
   const void *indirect_data);
#endif
void __trace_end_sync64_wait(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , struct u_trace_address sync_addr
     , struct u_trace_address sync_val
     , unsigned cond
);
static ALWAYS_INLINE void trace_end_sync64_wait(
     struct u_trace *ut
   , void *cs
   , struct u_trace_address sync_addr
   , struct u_trace_address sync_val
   , unsigned cond
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_sync64_wait(
        ut
      , enabled_traces
      , cs
      , sync_addr
      , sync_val
      , cond
   );
}

/*
 * begin_flush_cache
 */
struct trace_begin_flush_cache {
#ifdef __cplusplus
   /* avoid warnings about empty struct size mis-match in C vs C++..
    * the size mis-match is harmless because (a) nothing will deref
    * the empty struct, and (b) the code that cares about allocating
    * sizeof(struct trace_begin_flush_cache) (and wants this to be zero
    * if there is no payload) is C
    */
   uint8_t dummy;
#endif
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_begin_flush_cache(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_begin_flush_cache *payload,
   const void *indirect_data);
#endif
void __trace_begin_flush_cache(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
);
static ALWAYS_INLINE void trace_begin_flush_cache(
     struct u_trace *ut
   , void *cs
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_begin_flush_cache(
        ut
      , enabled_traces
      , cs
   );
}

/*
 * end_flush_cache
 */
struct trace_end_flush_cache {
   uint8_t l2;
   uint8_t lsc;
   uint8_t other;
};
#ifdef HAVE_PERFETTO
void panvk_utrace_perfetto_end_flush_cache(
   struct panvk_device *dev,
   uint64_t ts_ns,
   uint16_t tp_idx,
   const void *flush_data,
   const struct trace_end_flush_cache *payload,
   const void *indirect_data);
#endif
void __trace_end_flush_cache(
       struct u_trace *ut
     , enum u_trace_type enabled_traces
     , void *cs
     , uint8_t l2
     , uint8_t lsc
     , uint8_t other
);
static ALWAYS_INLINE void trace_end_flush_cache(
     struct u_trace *ut
   , void *cs
   , uint8_t l2
   , uint8_t lsc
   , uint8_t other
) {
   enum u_trace_type enabled_traces = p_atomic_read_relaxed(&ut->utctx->enabled_traces);
   if (!unlikely(enabled_traces != 0 &&
                 true))
      return;
   __trace_end_flush_cache(
        ut
      , enabled_traces
      , cs
      , l2
      , lsc
      , other
   );
}

#ifdef __cplusplus
}
#endif

#endif /* _PANVK_TRACEPOINTS_H */
