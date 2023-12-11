#pragma once

#include "Application.h"

extern Bb::Application* CreateApplication();

int main() {

	Bb::Application* app = CreateApplication();
	app->Run();
	delete app;

}