#pragma once
#include "Button.h"
#include <Windows.h>
class Trash : public Button
{
public:
	Trash();
	void push() override;
};

