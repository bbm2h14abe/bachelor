#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class InputManager
{
public:
	static InputManager &GetInstance();
	
	void UpdateInput();
	
	/* single press */ 
	int GetPressed_Arrow(){	 return m_arrow; };		// pressed arrow
	int GetPressed_Button(){ return m_button;  };	// pressed button

	/* hold down */
	bool GetHold_Up();			// hold down Up
	bool GetHold_Down();		// hold down Down
	bool GetHold_Left();		// hold down Left
	bool GetHold_Right();		// hold down Right

	/* keys */
	enum ARROW{  NO_ARROW,  UP, DOWN, LEFT,  RIGHT  };	// arrows
	enum BUTTON{ NO_BUTTON, A,  B,	  START, SELECT };	// buttons

private:
	static int m_arrow;
	static int m_button;

	static bool m_pressed_arrow;
	static bool m_pressed_button;

};

