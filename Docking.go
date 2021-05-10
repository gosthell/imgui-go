package imgui

// #include "wrapper/Docking.h"
import "C"

type ID uint

type DockingFlags int

func DockSpace(id ID, size Vec2, flags DockingFlags) ID {
	sizeArg, _ := size.wrapped()
	return ID(C.iggDockSpace(C.IggID(id), sizeArg, C.int(flags)))
}

func DockSpaceOverViewport(viewport Viewport, flags DockingFlags) ID {
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
