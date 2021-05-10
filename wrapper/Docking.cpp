#include "ConfiguredImGui.h"

#include "Docking.h"
#include "WrapperConverter.h"

IggID iggDockSpace(IggID id, IggVec2 const *pSize, int flags)
{
  Vec2Wrapper pSizeArg(pSize);
  return ImGui::DockSpace(id, *pSizeArg, flags, NULL);
}

IggID iggDockSpaceOverViewport(IggViewport handle, int flags)
{
  ImGuiViewport *viewport = reinterpret_cast<ImGuiViewport *>(handle);
  return ImGui::DockSpaceOverViewport(viewport, flags, NULL);
}

void iggSetNextWindowDockID(IggID dock_id, int cond)
{
  ImGui::SetNextWindowDockID(dock_id, cond);
}

IggID iggGetWindowDockID()
{
  return ImGui::GetWindowDockID();
}

IggBool iggIsWindowDocked()
{
  return ImGui::IsWindowDocked() ? 1 : 0;
}
