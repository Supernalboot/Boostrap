#include "Binary_TreeApp.h"

int main() {
	
	// allocation
	auto app = new Binary_TreeApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}