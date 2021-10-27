#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern IggID iggDockSpace(IggID id, IggVec2 const *size, int flags);
extern IggID iggDockSpaceOverViewport(IggViewport handle, int flags);
extern void iggSetNextWindowDockID(IggID dock_id, int cond);
extern IggID iggGetWindowDockID();
extern IggBool iggIsWindowDocked();
extern void iggDockBuilderDockWindow(const char *window_name, IggID node_id);
extern IggDockNode iggDockBuilderGetNode(IggID node_id);
extern void iggDockBuilderSetNodePos(IggID node_id, IggVec2 const *pos);
extern void iggDockBuilderSetNodeSize(IggID node_id, IggVec2 const *size);
extern void iggDockBuilderSetNodeSize(IggID node_id, IggVec2 const *size);
extern IggID iggDockBuilderAddNode(IggID id, int flags);
extern IggID iggDockBuilderSplitNode(IggID id, int split_dir, float size_ratio_for_node_at_dir, IggID* out_id_at_dir, IggID* out_id_at_opposite_dir);
extern void iggDockBuilderFinish(IggID id);

#ifdef __cplusplus
}
#endif
