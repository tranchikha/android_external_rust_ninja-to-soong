/*
 * Copyright © 2021 Igalia S.L.
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
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef _PANVK_TRACEPOINTS_PERFETTO_H
#define _PANVK_TRACEPOINTS_PERFETTO_H

#ifndef ANDROID_LIBPERFETTO
#include <perfetto.h>
#else
#include <perfetto/tracing.h>
#include <perfetto/trace/clock_snapshot.pbzero.h>
#include <perfetto/trace/gpu/gpu_render_stage_event.pbzero.h>
#include <perfetto/trace/gpu/vulkan_api_event.pbzero.h>
#endif


UNUSED static const char *tracepoint_names[] = {
   "begin_cmdbuf",
   "end_cmdbuf",
   "begin_meta",
   "end_meta",
   "begin_render",
   "end_render",
   "begin_dispatch",
   "end_dispatch",
   "begin_dispatch_indirect",
   "end_dispatch_indirect",
   "begin_barrier",
   "end_barrier",
   "begin_sync32_add",
   "end_sync32_add",
   "begin_sync64_add",
   "end_sync64_add",
   "begin_sync32_wait",
   "end_sync32_wait",
   "begin_sync64_wait",
   "end_sync64_wait",
   "begin_flush_cache",
   "end_flush_cache",
};

typedef void (*trace_payload_as_extra_func)(perfetto::protos::pbzero::GpuRenderStageEvent *, const void*, const void*);

static void UNUSED
trace_payload_as_extra_begin_cmdbuf(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_cmdbuf *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_cmdbuf(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_cmdbuf *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("flags", 5);

      const int slen = sprintf(buf, "0x%x", payload->flags);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_meta(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_meta *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_meta(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_meta *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_begin_render(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_render *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_render(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_render *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("flags", 5);

      const int slen = sprintf(buf, "0x%x", payload->flags);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("width", 5);

      const int slen = sprintf(buf, "%u", payload->width);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("height", 6);

      const int slen = sprintf(buf, "%u", payload->height);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("nr_samples", 10);

      const int slen = sprintf(buf, "%u", payload->nr_samples);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("rt_count", 8);

      const int slen = sprintf(buf, "%u", payload->rt_count);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("rt0_format", 10);

      const int slen = sprintf(buf, "%s", util_format_description((enum pipe_format)payload->rt0_format)->name);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("zs_format", 9);

      const int slen = sprintf(buf, "%s", util_format_description((enum pipe_format)payload->zs_format)->name);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("s_format", 8);

      const int slen = sprintf(buf, "%s", util_format_description((enum pipe_format)payload->s_format)->name);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("tile_size", 9);

      const int slen = sprintf(buf, "%u", payload->tile_size);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_dispatch(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_dispatch *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_dispatch(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_dispatch *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("base_group_x", 12);

      const int slen = sprintf(buf, "%u", payload->base_group_x);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("base_group_y", 12);

      const int slen = sprintf(buf, "%u", payload->base_group_y);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("base_group_z", 12);

      const int slen = sprintf(buf, "%u", payload->base_group_z);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_count_x", 13);

      const int slen = sprintf(buf, "%u", payload->group_count_x);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_count_y", 13);

      const int slen = sprintf(buf, "%u", payload->group_count_y);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_count_z", 13);

      const int slen = sprintf(buf, "%u", payload->group_count_z);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_size_x", 12);

      const int slen = sprintf(buf, "%u", payload->group_size_x);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_size_y", 12);

      const int slen = sprintf(buf, "%u", payload->group_size_y);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("group_size_z", 12);

      const int slen = sprintf(buf, "%u", payload->group_size_z);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_dispatch_indirect(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_dispatch_indirect *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_dispatch_indirect(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_dispatch_indirect *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("group_count", 11);

      const VkDispatchIndirectCommand* __group_count = (const VkDispatchIndirectCommand*)((uint8_t *)indirect_data + 0);
      const int slen = sprintf(buf, "%ux%ux%u", __group_count->x, __group_count->y, __group_count->z);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_barrier(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_barrier *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_barrier(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_barrier *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("sb_wait", 7);

      const int slen = sprintf(buf, "0x%x", payload->sb_wait);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("sync_wait", 9);

      const int slen = sprintf(buf, "0x%x", payload->sync_wait);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_sync32_add(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_sync32_add *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_sync32_add(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_sync32_add *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("sync_addr", 9);

      const uint64_t* __sync_addr = (const uint64_t*)((uint8_t *)indirect_data + 0);
      const int slen = sprintf(buf, "0x%" PRIx64 "", *__sync_addr);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("sync_val", 8);

      const uint32_t* __sync_val = (const uint32_t*)((uint8_t *)indirect_data + sizeof(uint64_t));
      const int slen = sprintf(buf, "%u", *__sync_val);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_sync64_add(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_sync64_add *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_sync64_add(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_sync64_add *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("sync_addr", 9);

      const uint64_t* __sync_addr = (const uint64_t*)((uint8_t *)indirect_data + 0);
      const int slen = sprintf(buf, "0x%" PRIx64 "", *__sync_addr);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("sync_val", 8);

      const uint64_t* __sync_val = (const uint64_t*)((uint8_t *)indirect_data + sizeof(uint64_t));
      const int slen = sprintf(buf, "%" PRIu64 "", *__sync_val);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_sync32_wait(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_sync32_wait *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_sync32_wait(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_sync32_wait *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("sync_addr", 9);

      const uint64_t* __sync_addr = (const uint64_t*)((uint8_t *)indirect_data + 0);
      const int slen = sprintf(buf, "0x%" PRIx64 "", *__sync_addr);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("sync_val", 8);

      const uint32_t* __sync_val = (const uint32_t*)((uint8_t *)indirect_data + sizeof(uint64_t));
      const int slen = sprintf(buf, "%u", *__sync_val);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("cond", 4);

      const int slen = sprintf(buf, "%u", payload->cond);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_sync64_wait(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_sync64_wait *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_sync64_wait(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_sync64_wait *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("sync_addr", 9);

      const uint64_t* __sync_addr = (const uint64_t*)((uint8_t *)indirect_data + 0);
      const int slen = sprintf(buf, "0x%" PRIx64 "", *__sync_addr);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("sync_val", 8);

      const uint64_t* __sync_val = (const uint64_t*)((uint8_t *)indirect_data + sizeof(uint64_t));
      const int slen = sprintf(buf, "%" PRIu64 "", *__sync_val);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("cond", 4);

      const int slen = sprintf(buf, "%u", payload->cond);

      data->set_value(buf, slen);
   }

}
static void UNUSED
trace_payload_as_extra_begin_flush_cache(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_begin_flush_cache *payload,
                                     const void *indirect_data)
{
}
static void UNUSED
trace_payload_as_extra_end_flush_cache(perfetto::protos::pbzero::GpuRenderStageEvent *event,
                                     const struct trace_end_flush_cache *payload,
                                     const void *indirect_data)
{
   char buf[128];

   {
      auto data = event->add_extra_data();
      data->set_name("l2", 2);

      const int slen = sprintf(buf, "%u", payload->l2);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("lsc", 3);

      const int slen = sprintf(buf, "%u", payload->lsc);

      data->set_value(buf, slen);
   }
   {
      auto data = event->add_extra_data();
      data->set_name("other", 5);

      const int slen = sprintf(buf, "%u", payload->other);

      data->set_value(buf, slen);
   }

}

#endif /* _PANVK_TRACEPOINTS_PERFETTO_H */
