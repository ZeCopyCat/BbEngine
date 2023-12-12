#include <Bb.h>

class Runtime : public Bb::Application {



};

Bb::Application* CreateApplication() {

	return new Runtime();

}
