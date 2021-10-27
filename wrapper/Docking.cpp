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

void iggDockBuilderDockWindow(const char *window_name, IggID node_id)
{
  ImGui::DockBuilderDockWindow(window_name, node_id);
}

IggDockNode iggDockBuilderGetNode(IggID node_id)
{
  return reinterpret_cast<IggDockNode>(ImGui::DockBuilderGetNode(node_id));
}

void iggDockBuilderSetNodePos(IggID node_id, IggVec2 const *pos)
{
  Vec2Wrapper posArg(pos);
  ImGui::DockBuilderSetNodePos(node_id, *posArg);
}

void iggDockBuilderSetNodeSize(IggID node_id, IggVec2 const *size)
{
  Vec2Wrapper sizeArg(size);
  ImGui::DockBuilderSetNodeSize(node_id, *sizeArg);
}

IggID iggDockBuilderAddNode(IggID id, int flags)
{
  return ImGui::DockBuilderAddNode(id, flags);
}

IggID iggDockBuilderSplitNode(IggID id, int split_dir, float size_ratio_for_node_at_dir, IggID* out_id_at_dir, IggID* out_id_at_opposite_dir)
{
  return ImGui::DockBuilderSplitNode(id, split_dir, size_ratio_for_node_at_dir, out_id_at_dir, out_id_at_opposite_dir);
}

void iggDockBuilderFinish(IggID id)
{
  return ImGui::DockBuilderFinish(id);
}
