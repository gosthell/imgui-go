package imgui

// #include "wrapper/Docking.h"
import "C"

type ID uint

type DockNodeFlags int

type DockNode uintptr

func DockSpace(id ID, size Vec2, flags DockNodeFlags) ID {
	sizeArg, _ := size.wrapped()
	return ID(C.iggDockSpace(C.IggID(id), sizeArg, C.int(flags)))
}

func DockSpaceOverViewport(viewport Viewport, flags DockNodeFlags) ID {
	return ID(C.iggDockSpaceOverViewport(viewport.handle(), C.int(flags)))
}

func SetNextWindowDockID(id ID) {
	C.iggSetNextWindowDockID(C.IggID(id), 0)
}

func SetNextWindowDockIDV(id ID, cond Condition) {
	C.iggSetNextWindowDockID(C.IggID(id), C.int(cond))
}

func GetWindowDockID() ID {
	return ID(C.iggGetWindowDockID())
}

func IsWindowDocked() bool {
	return C.iggIsWindowDocked() != 0
}

func DockBuilderDockWindow(windowName string, nodeID ID) {
	wnArg, wnFin := wrapString(windowName)
	defer wnFin()
	C.iggDockBuilderDockWindow(wnArg, C.IggID(nodeID))
}

func DockBuilderGetNode(nodeID ID) DockNode {
	return DockNode(C.iggDockBuilderGetNode(C.IggID(nodeID)))
}

func DockBuilderSetNodePos(nodeID ID, pos Vec2) {
	posArg, _ := pos.wrapped()
	C.iggDockBuilderSetNodePos(C.IggID(nodeID), posArg)
}

func DockBuilderSetNodeSize(nodeID ID, size Vec2) {
	sizeArg, _ := size.wrapped()
	C.iggDockBuilderSetNodeSize(C.IggID(nodeID), sizeArg)
}

func DockBuilderAddNode(nodeID ID, flags DockNodeFlags) ID {
	return ID(C.iggDockBuilderAddNode(C.IggID(nodeID), C.int(flags)))
}

func DockBuilderFinish(rootID ID) {
	C.iggDockBuilderFinish(C.IggID(rootID))
}
