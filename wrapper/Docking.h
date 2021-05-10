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

#ifdef __cplusplus
}
#endif
