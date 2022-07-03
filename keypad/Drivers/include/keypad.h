/*
 * keypad.h
 *
 *  Created on: May 16, 2022
 *      Author: Gemy
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
int KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);

#endif /* INCLUDE_KEYPAD_H_ */
